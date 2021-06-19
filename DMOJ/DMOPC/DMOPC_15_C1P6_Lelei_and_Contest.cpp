#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    int l, r;
    ll sum, lz;
} seg[3*MM];

const int MM = 2e5+2;
int M, N, Q;
node seg[3*MM];

void pushup(int rt) {
    seg[rt].sum = seg[2*rt].sum + seg[2*rt+1].sum;
}

void pushdown(int rt) {
    int lson = 2*rt, rson = 2*rt + 1;

    seg[lson].lz += seg[rt].lz;
    seg[rson].lz += seg[rt].lz;

    seg[lson].sum += seg[rt].lz * (seg[lson].r-seg[lson].l+1);
    seg[rson].sum += seg[rt].lz * (seg[rson].r-seg[rson].l+1);

    seg[rt].lz = 0;
}

void build(int l, int r, int rt) {
    seg[rt].l = l;
    seg[rt].r = r;

    if (l == r) {
        cin >> seg[rt].sum;
        return;
    }

    int mid = (l+r) / 2;

    build(l, mid, 2*rt);
    build(mid+1, r, 2*rt+1);

    pushup(rt);
}

void update(int l, int r, int val, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].lz += val;
        seg[rt].sum += (ll)val*(r-l+1);
        return;
    }

    if (seg[rt].lz != 0)
        pushdown(rt);

    int mid = (seg[rt].l+seg[rt].r) / 2;

    if (r <= mid)
        update(l, r, val, 2*rt);
    else if (l > mid)
        update(l, r, val, 2*rt+1);
    else {
        update(l, mid, val, 2*rt);
        update(mid+1, r, val, 2*rt+1);
    }

    pushup(rt);
}

ll query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r)
        return seg[rt].sum;

    if (seg[rt].lz != 0)
        pushdown(rt);

    int mid = (seg[rt].l+seg[rt].r) / 2;

    if (r <= mid)
        return query(l, r, 2*rt);

    if (l > mid)
        return query(l, r, 2*rt+1);

    return query(l, mid, 2*rt) + query(mid+1, r, 2*rt+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N >> Q;

    build(1, N, 1);

    for (int i = 1, op, l, r, x; i <= Q; i++) {
        cin >> op >> l >> r;

        if (op == 1) {
            cin >> x;
            update(l, r, x, 1);
        } else {
            cout << query(l, r, 1) % M << '\n';
        }
    }
}
