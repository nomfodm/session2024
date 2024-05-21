#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++) { 
        cin >> b[i];
    }


    int l = 0;
    int r = 0;
    int min_ = abs(a[l] - b[r]);
    pair<int,int> ans = {0, 0};

    while (l < n && r < m) {
        if (abs(a[l] - b[r]) < min_) {
            ans.first = l;
            ans.second = r;
            min_ = abs(a[l] - b[r]);
        }

        if (a[l] < b[r]) {
            l++;
        } else {
            r++;
        }
    }

    cout << a[ans.first] << " " << b[ans.second];


    return 0;
}