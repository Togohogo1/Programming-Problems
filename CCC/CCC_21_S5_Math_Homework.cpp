#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MM = 1.5e5+2, LG = 20;
int N, M, dif[LG][MM], spt[LG][MM];
pair<pair<int, int>, int> gcd[MM];

int lcm(int a, int b) {
    return (a*b) / __gcd(a, b);
}

int query(int l, int r) {
    int lg = log2(r-l+1);
    return __gcd(spt[lg][l], spt[lg][r-(1<<lg)+1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, X, Y, Z; i < M; i++) {
        cin >> X >> Y >> Z;
        dif[Z][X]++;
        dif[Z][Y+1]--;
        gcd[i] = {{X, Y}, Z};
    }

    // Difference array LCM query for each cell
    for (int j = 1; j < MM; j++) {
        int tmp = 1;

        for (int i = 2; i < LG; i++) {
            dif[i][j] += dif[i][j-1];

            if (dif[i][j])
                tmp = lcm(tmp, i);
        }

        spt[0][j] = tmp;
    }

    // GCD sparse table
    for (int i = 1; i < LG; i++) {
        for (int j = 1; j + (1<<(i-1)) <= N; j++) {
            spt[i][j] = __gcd(spt[i-1][j], spt[i-1][j+(1<<(i-1))]);
        }
    }

    // Checking
    for (int i = 0; i < M; i++) {
        if (query(gcd[i].f.f, gcd[i].f.s) != gcd[i].s) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << spt[0][i] << ' ';
    }

    cout << '\n';
}
