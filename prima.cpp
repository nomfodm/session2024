#include <bits/stdc++.h>

using namespace std;

#define INF 2009000999

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int> > > g(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    set<pair<int,int> > s;
    vector<int> dist(n, INF);

    vector<int> used(n, 0);

    dist[0] = 0;
    s.insert({0, 0});

    int sum_ = 0;

    while (!s.empty()) {
        int current = s.begin()->second;
        s.erase(s.begin());

        used[current] = 1;
        sum_ += dist[current];
        for (pair<int,int> i : g[current]) {
            if (i.second < dist[i.first] && !used[i.first]) {
                
                s.erase({dist[i.first], i.first});
                dist[i.first] = i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    cout << sum_;

    return 0;
}