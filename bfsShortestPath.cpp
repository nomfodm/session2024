#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> dist;

int main () {
    int n, m;
    cin >> n >> m;

    dist.resize(n, INF);
    g.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int k;
    cin >> k;

    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i : g[current]) {
            if (dist[i] == INF) {
                dist[i] = dist[current] + 1;
                q.push(i);
            }
        }
    }

    cout << dist[k];

    return 0;
}

// 5 5
// 0 1
// 1 2
// 2 3
// 1 3
// 2 4
// 4

// answer: 3