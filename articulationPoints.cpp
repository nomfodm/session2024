#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

vector<int> enter;
vector<int> ret;

int time_ = 1;

set<int> artPoints;

map<pair<int,int>, int> m_;

int getEdgeNumber(int a, int b) {
    if (a > b) swap(a, b);

    return m_[{a, b}];
}

void dfs(int x, int pred) {
    used[x] = 1;
    enter[x] = ret[x] = time_++;

    int children = 0;
    for (int to : g[x]) {
        if (to == pred) continue;

        if (used[to]) {
            ret[x] = min(ret[x], enter[to]);
        } else {
            dfs(to, x);

            ret[x] = min(ret[x], ret[to]);
            if (ret[to] >= enter[x] && pred != -1) {
                artPoints.insert(x);
            }

            children++;
        }
    }

    if (pred == -1 && children > 1) {
        artPoints.insert(x);
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

    cout << artPoints.size() << endl;

    for (int i : artPoints) {
        cout << i + 1 << " ";
    }

    return 0;
}

// 9 12
// 1 2
// 2 3
// 4 5
// 2 6
// 2 7
// 8 9
// 1 3
// 1 4
// 1 5
// 6 7
// 3 8
// 3 9

// answer:
// 3
// 1 2 3