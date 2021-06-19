#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, ans, tmp, frq1[26][M], frq2[26][M];
string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        frq1[S[i-1]-'a'][i] = 1;
        frq2[S[i-1]-'a'][i] = 1;
    }

    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 1; j <= N; j++) {
            if (frq1[i-'a'][j-1] == 1)
                frq1[i-'a'][j] = 1;

            if (frq2[i-'a'][N-j+1] == 1)
                frq2[i-'a'][N-j] = 1;
        }
    }

    for (int j = 1; j <= N; j++) {
        tmp = 0;

        for (int i = 'a'; i <= 'z'; i++) {
            tmp += frq1[i-'a'][j] & frq2[i-'a'][j];
        }

        ans = max(ans, tmp);
    }

    cout << ans << '\n';
}
