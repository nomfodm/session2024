#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int> (m, 0));

    int i = 0, j = 0;

    bool down = true;
    int current = 1;
    while (true) {
        if (i == n - 1 && j == m - 1) {
            v[i][j] = current;
            break;
        }
        v[i][j] = current++;
        if (j == m - 1 && !down) {
            if (i != n - 1) i++;
            down = true;
        }
        else if (i == n - 1 && down) {
            if (j != m - 1) j++;
            down = false;
        }

        else if (j == 0 && down) {
            if (i != n - 1) i++;
            down = false;
        }

        else if (i == 0 && !down) {
            if (j != m - 1) j++;
            down = true;
        }

        else if (down) {
            if (i != n - 1) i++;
            if (j != 0) j--;
            
        }

        else if (!down) {
            if (i != 0) i--;
            if (j != m - 1) j++;
        }        
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j ) {
            cout << "\t" << v[i][j];
        }
        cout << endl;
    }

    return 0;
}