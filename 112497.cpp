#include <bits/stdc++.h>

using namespace std;

bool is_number(char c) {
    return c >= '0' && c <= '9';
}

int main () {
    string s;
    getline(cin, s);


    vector<string> ans;
    stack<string> st;

    for (int i = 0; i < s.size(); i++) {
        if (is_number(s[i])) {
            if (i != 0 && is_number(s[i - 1])) {

                ans.back() += s[i];

            } else {
                
                ans.push_back(""); ans.back() += s[i];

            }

        } else {

            if (st.empty()) {

                st.push(""); st.top() += s[i];

            } else if ((s[i] == '*' || s[i] == '/') && 
            (st.top() == "+" || st.top() == "-")) {

                st.push(""); st.top() += s[i];

            } else {

                if (s[i] == '+' || s[i] == '-') {

                    while (!st.empty()) {
                        ans.push_back(""); ans.back() += st.top();

                        st.pop();
                    }

                    st.push(""); st.top() += s[i];

                } else {

                    while (!st.empty() && st.top() != "+" && st.top() != "-") {
                        ans.push_back(""); ans.back() += st.top();

                        st.pop();
                    }

                    st.push(""); st.top() += s[i];

                }
            }
        }
    }
    

    for (string s : ans) {
        cout << s << " ";
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}