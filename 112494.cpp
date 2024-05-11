#include <bits/stdc++.h>

using namespace std;

#define error cout << "ERROR"; return 0

#define int long long

set<char> operations{'-', '+', '*', '/'};

bool is_number(string s) {
    int i = 0;
    if (operations.find(s[0]) != operations.end() && s.size() == 1) return false;
    if (operations.find(s[0]) != operations.end()) i = 1;
    for (; i < s.size(); ++i) {
        char c = s[i];
        if (!('0' <= c && c <= '9')) {
            return false;
        }
    }

    return true;
}

signed main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    stack<int> st;

    string s;
    while (cin >> s) {
        if (is_number(s)) {
            st.push(stoll(s));
            continue;
        }

        if (operations.find(s[0]) != operations.end()) {
            int a, b;
            if (!st.empty()) {
                a = st.top();
                st.pop();
            } else {
                error;
            }

            if (!st.empty()) {
                b = st.top();
                st.pop();
            } else {
                error;
            }

            if (s[0] == '+') {
                st.push(b + a);
            } else if (s[0] == '-') {
                st.push(b - a);
            } else if (s[0] == '*') {
                st.push(b * a);
            } else if (s[0] == '/') {
                st.push(b / a);
            } else {
                error;
            }

            // cout << "\t" << st.top() << endl;
        }
    }

    if (st.size() != 1) {
        error;
    } else {
        cout << st.top();
    }

    return 0;
}