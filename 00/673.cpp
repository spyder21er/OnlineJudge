#include <bits/stdc++.h>
using namespace std;

bool is_pair(char a, char b) {
    return (a == '[') ? b == ']' : b == ')';
}

int main() {
    stack<char> char_stack;
    string s;
    int n;
    bool correct;

    scanf("%d ", &n);

    while (n--) {
        correct = true;
        stack<char> clear_stack;
        swap(char_stack, clear_stack);
        getline(cin, s);
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '(') {
                char_stack.push(s[i]);
            } else {
                if (!char_stack.empty() && is_pair(char_stack.top(), s[i])) {
                    char_stack.pop();
                } else {
                    correct = false;
                }
            }
        }

        if (char_stack.empty() && correct) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}