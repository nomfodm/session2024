#include <bits/stdc++.h>

using namespace std;

#define INF 2009000999

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int> > > g(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int k;
    cin >> k;

    set<pair<int,int> > s;
    vector<int> dist(n, INF);

    dist[k] = 0;
    s.insert({0, k});

    while (!s.empty()) {
        int current = s.begin()->second;
        s.erase(s.begin());

        for (pair<int,int> i : g[current]) {
            if (dist[current] + i.second < dist[i.first]) {
                
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[current] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    cout << endl;

    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}