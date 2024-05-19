#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<int,int> > v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;
    int ans = 0;

    for (pair<int, int> i : v) {
        if (i.first >= l && i.first <= r) {
            r = max(i.second, r);
        } else {
            ans += r - l + 1;
            l = i.first;
            r = i.second;
        }
    }
    ans += r - l + 1;

    cout << ans;

    return 0;
}