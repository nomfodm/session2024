#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

bool hasLoop = false;

void dfs(int x, int pred) {
    used[x] = 1;
    for (int i : g[x]) {
        if (used[i] && pred != i) {
            hasLoop = true;
        }

        if (!used[i]) {
            dfs(i, x);
        }
    }
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
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }

    cout << (hasLoop ? "yes" : "no");

    return 0;
}

// 4 4
// 0 1
// 1 2
// 2 3
// 1 3

// answer: yes


// 4 3
// 0 1
// 1 2
// 2 3

// answer: no