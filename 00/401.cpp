#include <bits/stdc++.h>
using namespace std;

string valid =    "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string mirrored = "A000300HIL0JM0O0002TUVWXY51SE0Z0080";

string reverse_of(string s) {
    reverse(s.begin(), s.end());
    return s;
}

bool is_pal(string s) {
    return s == reverse_of(s);
}

bool contains_chars_with_no_mirror(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (mirrored.find(s[i]) == string::npos) {
            return true;
        }
    }
    return false;
}

bool is_mirrored(string s) {
    if (contains_chars_with_no_mirror(s)) {
        return false;
    }
    // replace with mirrors
    string mirrored_s(s);
    for (int i = 0; i < s.length(); i++) {
        s[i] = mirrored[valid.find(s[i])];
    }
    reverse(mirrored_s.begin(), mirrored_s.end());
    return s == mirrored_s;
}

int main() {
    string s;

    while (cin >> s) {
        if (is_pal(s) && is_mirrored(s)) {
            cout << s << " -- is a mirrored palindrome." << endl << endl;
            continue;
        }
        if (is_pal(s) && !is_mirrored(s)) {
            cout << s << " -- is a regular palindrome." << endl << endl;
            continue;
        }
        if (!is_pal(s) && is_mirrored(s))
        {
            cout << s << " -- is a mirrored string." << endl << endl;
            continue;
        }
        cout << s << " -- is not a palindrome." << endl << endl;
    }

    return 0;
}