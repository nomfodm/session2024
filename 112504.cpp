#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int startx, starty;
    int color;
    cin >> startx >> starty >> color;

    vector<vector<int> > v(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int colorToPaint = v[starty][startx];
    int count = 0;

    queue<pair<int,int> > q;
    q.push({starty, startx});
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (v[current.first][current.second] == color) {
            continue;
        }

        v[current.first][current.second] = color;
        count++;

        if (current.first - 1 >= 0 && v[current.first - 1][current.second] == colorToPaint) {
            q.push({current.first - 1, current.second});
        }

        if (current.first + 1 < n && v[current.first + 1][current.second] == colorToPaint) {
            q.push({current.first + 1, current.second});
        }

        if (current.second - 1 >= 0 && v[current.first][current.second - 1] == colorToPaint) {
            q.push({current.first, current.second - 1});
        }

        if (current.second + 1 < m && v[current.first][current.second + 1] == colorToPaint) {
            q.push({current.first, current.second + 1});
        }
    }

    cout << count << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}