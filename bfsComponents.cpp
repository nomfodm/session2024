#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

vector<vector<int> > g;
vector<int> used;

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

    

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            count++;

            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                used[current] = 1;

                for (int i : g[current]) {
                    if (!used[i]) {
                        q.push(i);
                    }
                }
            }
        }
    }

    cout << count;

    return 0;
}

// 7 6
// 0 1
// 1 2
// 2 3
// 1 3
// 2 4
// 5 6

// answer: 2