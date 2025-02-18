#include <bits/stdc++.h>

struct SegmentTree {
    struct node {
        int add;
        int64_t val;
    };

    std::vector<node> seg;

    void update(int id) {
        seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
    }

    void settag(int id, int l, int r, int t) {
        seg[id].val += (r - l + 1) * t;
        seg[id].add += t;
    }

    void pushdown(int id, int l, int r, int mid) {
        if (seg[id].add != 0) {
            seg[id * 2].add += seg[id].add;
            seg[id * 2].val += (mid + 1 - l) * seg[id].add;
            seg[id * 2 + 1].add += seg[id].add;
            seg[id * 2 + 1].val += (r - mid) * seg[id].add;
            seg[id].add = 0;
        }
    }

    void build(int id ,int l, int r) {
        seg[id].add = 0;
        if (l == r) {
            seg[id].val = 0;
            return;
        }
        int mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }

    void modify(int id, int l, int r, int ql, int qr, int64_t t) {
        if (l == ql && r == qr) {
            settag(id, ql, qr, t);
            return;
        }
        int mid = l + r >> 1;
        pushdown(id, l, r, mid);
        if (qr <= mid) {
            modify(id * 2, l, mid, ql, qr, t);
        } else if (ql > mid) {
            modify(id * 2 + 1, mid + 1, r, ql, qr, t);
        } else {
            modify(id * 2, l, mid, ql, mid, t);
            modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
        }
        update(id);
    }

    int64_t query(int id, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return seg[id].val;
        }
        int mid = l + r >> 1;
        pushdown(id, l, r, mid);
        if (qr <= mid) {
            return query(id * 2, l, mid, ql, qr);
        } else if (ql > mid) {
            return query(id * 2 + 1, mid + 1, r, ql, qr);
        } else {
            return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
        }
        update(id);
    }
};
