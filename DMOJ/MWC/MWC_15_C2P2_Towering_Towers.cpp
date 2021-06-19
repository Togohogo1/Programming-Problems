#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define sp " "
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(i, a, b, n) for (int i = a; i < b; i += n)
#define rev(i, a, b, n) for (int i = a; i > b; i -= n)
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;

typedef deque<int> dqi;
typedef deque<double> dqd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int N, H;
deque<pii> twr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    rep(i, 0, N, 1) {
        cin >> H;

        while (twr.size() > 0 && twr.back().fi <= H) {
            twr.pob();
        }

        if (twr.size() == 0)
            cout << i << sp;
        else
            cout << i - twr.back().se << sp;

        twr.pb(mp(H, i));
    }
}
