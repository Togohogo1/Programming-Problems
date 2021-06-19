#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define rep(i, a, b, n) for (int i = a; i < b; i += n)
#define rev(i, a, b, n) for (int i = a; i > b; i -= n)
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int N, P, v;
string names[102];
pii ranks[102];

int main() {
    ios_base::sync_with_stdio(0);
    cin.sync_with_stdio(false), cout.sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> P;

    rep(i, 0, N, 1) {
        cin >> names[i];
        ranks[i] = mp(0, i);
    }

    rep(i, 0, P, 1) {
        rep(j, 0, N, 1) {
            cin >> v;
            ranks[j].fi += v;
        }
    }

    sort(ranks, ranks+N, greater<pii>());

    rep(i, 0, N, 1) {
        cout << i+3 << ". " << names[ranks[i].se] << nl;
    }
}
