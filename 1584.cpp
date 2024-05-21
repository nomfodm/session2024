#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    int sum_ = 0;
    int max_sum = 0;
    pair<int,int> ans = {0, 0};

    int l = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sum_ += a;
        if (sum_ > max_sum) {
            max_sum = sum_;
            ans.first = l;
            ans.second = i;
        }

        if (sum_ <= 0) {
            sum_ = 0;
            l = i + 1;
        }
    }

    cout << ans.first + 1 << "\n" << ans.second + 1;

    return 0;
}