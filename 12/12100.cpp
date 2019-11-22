#include <bits/stdc++.h>
using namespace std;

int MAX_JOBS = 101;

struct Job
{
    int freq[10];
    void clear()
    {
        memset(freq, 0, sizeof(freq));
    }

    bool has_higher_prio(int jb)
    {
        for (int i = jb+1; i < 10; i++)
            if (freq[i] > 0)
                return true;
        return false;
    }

    void insert(int n)
    {
        freq[n]++;
    }

    void remove(int n)
    {
        if (freq[n] > 0)
            freq[n]--;
    }
};

void clear_q(std::queue<int> &q)
{
    queue<int> empty;
    swap(q, empty);
}

int main()
{
    int T, n, m, input;
    queue<int> q;
    Job jobs;
    
    scanf("%d", &T);
    while(T--)
    {
        int time = 0;
        jobs.clear();
        clear_q(q);
        scanf("%d %d", &n, &m);
        while(n--)
        {
            scanf("%d", &input);
            q.push(input);
            jobs.insert(input);
        }

        bool not_done = true;
        while (not_done && !q.empty())
        {
            if (jobs.has_higher_prio(q.front()))
            {
                q.push(q.front());
                q.pop();
                if (m == 0)
                {
                    m = q.size();
                }
            } 
            else
            {
                jobs.remove(q.front());
                q.pop();
                time++;
                if (m == 0)
                    not_done = false;
            }
            m--;
        }

        cout << time << endl;
    }
    return 0;
}