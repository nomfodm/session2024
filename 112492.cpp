#include <bits/stdc++.h>

using namespace std;

#define yes cout << "YES"
#define no cout << "NO"

int main () {
    string s;
    getline(cin, s);

    map<char,char> m;
    m[')'] = '(';
    m['}'] = '{';
    m['>'] = '<';
    m[']'] = '[';

    set<char> brackets{'{', '(', '[', '<', '>', ']', ')', '}'};

    stack<char> st;
    for (char c : s) {
        if (brackets.find(c) == brackets.end()) {
            continue;
        }

        if (c == '(' || c == '{' || c == '[' || c == '<') {
            st.push(c);
            continue;
        }

        if (st.empty()) {
            no;
            return 0;
        }

        char f = st.top();
        if (f != m[c]) {
            no;
            return 0;
        }

        st.pop();

    }

    if (st.empty()) {
        yes;
    } else {
        no;
    }

    return 0;
}