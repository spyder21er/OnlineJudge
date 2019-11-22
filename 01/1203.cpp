/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int, int>, int> query;

struct order_by_period
{
    bool operator() (query a, query b)
    {
        return (a.first.second != b.first.second) 
            ? (a.first.second > b.first.second) 
            : (a.first.first > b.first.first);
    }
};

int main()
{
    string input, dump;
    int q_num, period;
    priority_queue<query, vector<query>, order_by_period> q;
    
    while(true)
    {
        getline(cin, input);
        if(input == "#") break;
        
        stringstream ss(input);
        ss >> dump >> q_num >> period;
        query a = make_pair(make_pair(q_num, period), period);
        q.push(a);
    }
    
    priority_queue<query, vector<query>, order_by_period> r(q);
    
    int k;
    cin >> k;
    while(k--) 
    {
        query c = q.top();
        q.pop();
        cout << c.first.first << endl;
        c.first.second += c.second;
        q.push(c);
    }
    
    return 0;
}
