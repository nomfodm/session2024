#include <bits/stdc++.h>

using namespace std;

#define INF 30000

struct triple {
    int from, to, price;
};

int main () {
    int n, m;
    cin >> n >> m;

    vector<triple> v(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i].from >> v[i].to >> v[i].price;
        v[i].from--;
        v[i].to--;
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            triple current = v[j];

            if (dist[current.from] != INF) {
                dist[current.to] = min(dist[current.to], dist[current.from] + current.price);
            }
        }
    }

    for (int i : dist) {
        cout << i << " ";
    }

    return 0;
}