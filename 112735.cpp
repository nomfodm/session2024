#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    pair<int,int> ans = {-1, -1};
    int max_ = -1;
    int max_index = -1;
    int max_sum = -1;
    for (int i = 0; i < n - k - 1; i++) {
        if (v[i] > max_) {
            max_ = v[i];
            max_index = i;
        }

        if (max_ + v[i + k + 1] > max_sum) {
            max_sum = max_ + v[i + k + 1];
            
            ans.first = max_index;
            ans.second = i + k + 1;
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1;

    return 0;
}