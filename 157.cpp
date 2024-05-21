#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;
vector<int> current, ans;

#define int long long

void f(int i, int sum_) {
    if (i == m) {
        if (sum_ == n) {
            if (ans.empty() || ans.size() > current.size()) {
                ans = current;
            }
            return;
        }
        return;
    }

    f(i + 1, sum_);

    current.push_back(v[i]);
    f(i + 1, sum_ + v[i]);

    current.push_back(v[i]);
    f(i + 1, sum_ + v[i] * 2);

    current.pop_back();
    current.pop_back();
}

signed main () {
    cin >> n >> m;

    v.resize(m);
    int sum_ = 0;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        sum_ += v[i] * 2;
    }

    f(0, 0);

    if (sum_ < n) {
        cout << -1;
        return 0;
    }

    if (ans.empty()) {
        cout << 0;
        return 0;
    }

    cout << ans.size() << endl;

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}