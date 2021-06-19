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
typedef long double ld;
typedef unsigned long long ull;

typedef deque<int> dqi;
typedef deque<double> dqd;
typedef priority_queue<int> pqi;
typedef priority_queue<double> pqd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 2;

int N;
bool prime[MAX];

void sieve() {
    rep(i, 2, MAX, 1) {
        prime[i] = true;
    }

    for (ll i = 2; i*i < MAX; i++) {
        if (prime[i]) {
            for (ll j = i*i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    sieve();

    rep(i, 0, 5, 1) {
        scanf("%i", &N);

        // Case 1: N = N
        if (prime[N])
            printf("%i = %i\n", N, N);

        // Case 2: N = a + b
        else if (N % 2 == 0) {
            rev(i, N/2, 3, 1) {
                if (prime[i] && prime[N-i]) {
                    printf("%i = %i + %i\n", N, i, N-i);
                    break;
                }
            }

        // Case 3: N = a + b + c
        } else {
            bool found = false;

            rev(i, N/3, 1, 1) {
                if (found)
                    break;

                if (prime[i]) {
                    int t = N-i;

                    rev(j, t/2, 1, 1) {
                        if (prime[j] && prime[t-j]) {
                            if (j >= i) {
                                printf("%i = %i + %i + %i\n", N, i, j, t-j);
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
