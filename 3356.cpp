#include <bits/stdc++.h>

using namespace std;

int main () {
    int m;
    cin >> m;

    vector<pair<int, int> > v;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    vector<pair<int,int> > ans;
    int l = 0;
    int r = 0;
    pair<int,int> best = {-1, -1};
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first > l) {
            if (r < v[i].first) {
                cout << "No solution";
                return 0;
            }
            l = r;
            ans.push_back(best);
        }
        if (v[i].second > r) {
            r = v[i].second;
            best = v[i];
            if (r >= m) {
                ans.push_back(best);
                break;
            }
        }
    }

    if (ans.empty()) {
        cout << "No solution";
        return 0;
    }

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}