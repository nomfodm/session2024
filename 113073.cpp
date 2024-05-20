#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main () {
    int n;
    cin >> n;

    vector<pair<int,int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);
    int count = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= l) {
            l = v[i].second;
            count++;
        }
    }

    cout << count;

    return 0;
}