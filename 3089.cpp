#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int> > v(n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= a[i - 1]) {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - a[i - 1]] + b[i - 1]);
            } else {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    cout << v[n][m];

    return 0;
}