#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i > b; i--)
#define all(x, n) x, x+n
#define vall(x) x.begin(), x.end()

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;
    cout << 2*b - a << nl;
}
