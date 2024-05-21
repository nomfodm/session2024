#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> color;
bool isBipartile = true;

void dfs(int x) {
    for (int i : g[x]) {
        if (color[i] == color[x]) {
            isBipartile = false;
            return;
        }

        if (!color[i]) {
            color[i] = -color[x];
            dfs(i);
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    color.resize(n, 0);
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            color[i] = 1;
            dfs(i);
        }
    }

    cout << (isBipartile ? "yes" : "no");

    return 0;
}

// 6 4
// 0 1
// 1 2
// 2 3
// 4 5

// answer: yes