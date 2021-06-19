#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define rep(i, a, b, n) for (auto i = a; i < b; i += n)
#define rev(i, a, b, n) for (auto i = a; i > b; i -= n)
#define all(x, n) x, x+n
#define vall(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vi2;
typedef vector<vector<double>> vd2;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int Q, num, lo, hi, factors[100002];
vi2 li(100002);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // Modifies SoE to filter out factors of 2, 3, 4, etc.
    rep(i, 2, 100001, 1) {
        rep(j, i, 100001, i) {
            factors[j]++;
        }

        // Appends in a vector: numbers that have 1 factor, 2f, 3f, 4f, etc.
        li[factors[i]].pb(i);
    }

    cin >> Q;
    li[0].pb(1);

    rep(i, 0, Q, 1) {
        cin >> num >> lo >> hi;
        vector<int> t = li[num-1];

        int a = lb(vall(t), hi+1) - t.begin();
        int b = lb(vall(t), lo) - t.begin();

        cout << a - b << "\n";
    }
}
