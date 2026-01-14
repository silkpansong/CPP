// Minimum Range Query with Point Update
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> st;

    SegTree(int _n) {
        n = _n;
        st.assign(4 * n, LLONG_MAX);
    }

    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            st[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(node << 1, l, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, r, idx, val);

        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return LLONG_MAX;
        if (ql <= l && r <= qr)
            return st[node];
        int mid = (l + r) >> 1;
        return min(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }
};


// Usage:
int main() {
    int n = 5;
    vector<long long> a = {5, 2, 6, 3, 1};

    SegTree seg(n);
    seg.build(1, 0, n - 1, a);

    cout << seg.query(1, 0, n - 1, 1, 3) << "\n"; // min in [1,3]

    seg.update(1, 0, n - 1, 2, 0); // a[2] = 0

    cout << seg.query(1, 0, n - 1, 0, 4) << "\n"; // min in [0,4]
}

// Example submission: https://codeforces.com/problemset/submission/2184/357816668
