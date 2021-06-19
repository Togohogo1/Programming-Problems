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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef deque<int> dqi;
typedef deque<double> dqd;
typedef deque<string> dqs;
typedef priority_queue<int> pqi;
typedef priority_queue<double> pqd;
typedef priority_queue<string> pqs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int N, M, J, c, t;
pqi pa;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> J;
    pii mud[N+1];

    int pt, tm;

    rep(i, 1, M+1, 1) {
        cin >> pt >> tm;
        mud[i] = mp(tm, pt);
    }

    // If jump is longer than mud
    if (J > N) {
        cout << 0 << "\n";
        return 0;
    }

    // Sort by time
    sort(mud, mud+N+1);

    // Add the end patch in (negative for a min heap)
    pa.push(-N-1);

    for (pii pi : mud) {
        t = pi.fi;
        pa.push(-pi.se);

        // While the closest patch is in jumping distance from current position
        while (!pa.empty() && -pa.top() <= c + J) {
            c = max(c, -pa.top());  // No moving backwards
            pa.pop();
        }

        // Reached the end
        if (c > N)
            break;
    }

    cout << (c > N ? t : -1) << "\n";
}
