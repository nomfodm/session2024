#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

vector<int> enter;
vector<int> ret;

int time_ = 1;

set<int> bridges;

map<pair<int,int>, int> m_;

int getEdgeNumber(int a, int b) {
    if (a > b) swap(a, b);

    return m_[{a, b}];
}

void dfs(int x, int pred) {
    used[x] = 1;
    enter[x] = ret[x] = time_++;

    for (int to : g[x]) {
        if (to == pred) continue;

        if (used[to]) {
            ret[x] = min(ret[x], enter[to]);
        } else {
            dfs(to, x);

            ret[x] = min(ret[x], ret[to]);
            if (ret[to] > enter[x]) {
                bridges.insert(getEdgeNumber(x, to));
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n, 0);
    enter.resize(n);
    ret.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        m_[{a, b}] = i + 1;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }

    cout << bridges.size() << endl;

    for (int i : bridges) {
        cout << i << " ";
    }

    return 0;
}

// 6 6
// 1 2
// 2 4
// 2 3
// 4 5
// 5 6
// 3 4

// answer:
// 3
// 1 4 5