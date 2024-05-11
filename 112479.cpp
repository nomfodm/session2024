#include <bits/stdc++.h>

using namespace std;

#define no cout << "NO"

int main () {
    string s;
    getline(cin, s);
    
    set<char, greater<char>> st{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            st.erase(c);
        }
    }

    if (st.empty()) {
        no;
        return 0;
    }

    for (char c : st) {
        cout << c;
    }

    return 0;
}