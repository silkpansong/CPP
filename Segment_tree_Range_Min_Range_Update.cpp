#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> st, lazy;
    vector<bool> marked; // tells if this node has a pending assignment

    SegTree(int _n) {
        n = _n;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        marked.assign(4 * n, false);
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

    // Push assignment to children
    void push(int node) {
        if (!marked[node]) return;

        for (int child : {node << 1, node << 1 | 1}) {
            st[child] = lazy[node];
            lazy[child] = lazy[node];
            marked[child] = true;
        }
        marked[node] = false;
    }

    // Range assign: set [ql, qr] to val
    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            st[node] = val;
            lazy[node] = val;
            marked[node] = true;
            return;
        }

        push(node);
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, ql, qr, val);
        update(node << 1 | 1, mid + 1, r, ql, qr, val);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    // Range min query
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return LLONG_MAX;

        if (ql <= l && r <= qr)
            return st[node];

        push(node);
        int mid = (l + r) >> 1;
        return min(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }
};


// Usage
int main() {
    vector<long long> a = {5, 2, 6, 3, 1};
    int n = a.size();

    SegTree seg(n);
    seg.build(1, 0, n - 1, a);

    cout << seg.query(1, 0, n - 1, 0, 4) << "\n"; // 1

    seg.update(1, 0, n - 1, 1, 3, 7); // set a[1..3] = 7

    cout << seg.query(1, 0, n - 1, 0, 4) << "\n"; // 1
    cout << seg.query(1, 0, n - 1, 1, 3) << "\n"; // 7
}
