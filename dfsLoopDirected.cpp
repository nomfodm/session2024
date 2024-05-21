#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

bool hasLoop = false;

void dfs(int x) {
    used[x] = 1;
    for (int i : g[x]) {
        if (used[i] == 0) {
            dfs(i);
        }

        if (used[i] == 1) {
            hasLoop = true;
            return;
        }
    }

    used[x] = 2;
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

    cout << (hasLoop ? "yes" : "no");

    return 0;
}


// 4 4
// 0 1
// 1 2
// 2 3
// 3 1

// answer: yes


// 4 3
// 0 1
// 1 2
// 2 3

// answer: no