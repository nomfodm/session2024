#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

int main() {
    int n, s, f;
    cin >> n >> s >> f;

    s--;
    f--;

    vector<int> used(n, 0);
    vector<int> dist(n, INF);

    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)  {
            int a;
            cin >> a;

            if (a != -1) {
                g[i].push_back({j, a});
            }
        }
    }

    dist[s] = 0;

    while (true) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }

        if (v == -1) {
            break;
        }

        for (auto &e : g[v]) {
            int to = e.first;
            int distation = e.second;

            dist[to] = min(dist[to], dist[v] + distation);
        }

        used[v] = 1;
    }

    if (dist[f] != INF)
        cout << dist[f];
    else
        cout << -1;

    return 0;
}