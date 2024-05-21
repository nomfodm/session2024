#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

vector<int> topologySort;

void dfs(int x) {
    used[x] = 1;
    for (int i : g[x]) {
        if (!used[i]) {
            dfs(i);
        }
    }

    topologySort.push_back(x);
}

int main () {
    int n, m;
    cin >> n >> m;

    used.resize(n, 0);
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    for (int i : topologySort) {
        cout << i << " ";
    }

    return 0;
}

// 6 6
// 0 1
// 1 3
// 1 2
// 3 4
// 2 3
// 4 5

// answer: 5 4 3 2 1 0


// 7 6
// 0 1
// 1 2
// 2 3
// 2 4
// 4 5
// 0 6

// answer: 3 5 4 2 1 6 0