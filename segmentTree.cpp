#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

int n;
vector<int> tree;
vector<int> v;

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = v[l];
    } else {
        int m = (l + r) / 2;

        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);

        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int sum(int l, int r) {
    l += n - 1;
    r += n - 1;

    int sum_ = 0;
    while (l <= r) {
        if (l % 2 != 0) sum_ += tree[l];
        if (r % 2 == 0) sum_ += tree[r];

        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }

    return sum_;
}

int main () {
    int f;
    cin >> f;

    n = 1 << (int)log2(f - 1) + 1;

    tree.resize(2 * n);
    v.resize(n, 0);

    for (int i = 0; i < f; i++) {
        cin >> v[i];
    }

    build(1, 0, n - 1);

    cout << sum(2, 6);

    return 0;
}

// 7
// 2 5 6 3 8 7 5

// answer: 29