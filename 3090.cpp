#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > v;
vector<int> ans;
vector<int> a, b;

void path(int i, int j) {
    if (v[i][j] == 0) return;

    if (v[i - 1][j] == v[i][j]) {
        path(i - 1, j);
    } else {
        path(i - 1, j - a[i - 1]);
        ans.push_back(i);
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    a.resize(n);
    b.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    v.resize(n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= a[i - 1]) {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - a[i - 1]] + b[i - 1]);
            } else {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    path(n, m);

    for (int i : ans) {
        cout << i << endl;
    }

    return 0;
}