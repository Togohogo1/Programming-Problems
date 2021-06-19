#include<bits/stdc++.h>

using namespace std;

const int M = 1e6+2, MOD = 10007;
int N, dp[M], last[26];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    N = s.size();

    for (int i = 1; i <= N; i++) {
        int id = s[i-1] - 'a';

        // No duplicate letter
        if (last[id] == 0)
            dp[i] = (2*dp[i-1]+1) % MOD;

        // Duplicate letter
        else
            dp[i] = (2*dp[i-1]-dp[last[id]-1]) % MOD;

        last[id] = i;
    }

    cout << dp[N] << endl;
}
