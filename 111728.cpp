#include <bits/stdc++.h>

using namespace std;

int left_bs(int x, vector<int>& v) {
    int l = -1;
    int r = v.size();
    while (l + 1 != r) {
        int m = (l + r) / 2;
        if (v[m] >= x) {
            r = m;
        } else {
            l = m;
        }
    }

    if (v[r] == x) return r;
    return -2;
}

int right_bs(int x, vector<int>& v) {
    int l = 0;
    int r = v.size();
    while (l + 1 != r) {
        int m = (l + r) / 2;
        if (v[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    if (v[l] == x) return l;
    return -2;
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        int left = left_bs(b, a);
        if (left == -2) {
            cout << 0 << endl;
            continue;
        }

        cout << left + 1 << " " << right_bs(b, a) + 1 << endl;
    }

    return 0;
}