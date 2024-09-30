#include <bits/stdc++.h>
using namespace std;

const int N = 201000;

template<typename T, int n>
struct SegmentTree {
	struct val {
		//content

	};

	struct tag {
		// set tag

	};

	struct node {
		// node

	} seg[N * 4];

	void update(int id) {
		// Fill in how to update the node
	}

	void settag(int id, int l, int r, int t) {
		
	}

	void pushdown(int id, int l, int r, int mid) {
		if (seg[id].add != 0) {

		}
	}

	void build(int id ,int l, int r) {
		seg[id].add = 0;
		if (l == r) {

			return;
		}
		int mid = l + r >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		update(id);
	}

	void modify(int id, int l, int r, int ql, int qr, ll t) {
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

	ll query(int id, int l, int r, int ql, int qr) {
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