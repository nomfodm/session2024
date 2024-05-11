#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string,int> m;
    string s;
    while(cin >> s) {
        m[s]++;
    }

    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
    

    return 0;
}