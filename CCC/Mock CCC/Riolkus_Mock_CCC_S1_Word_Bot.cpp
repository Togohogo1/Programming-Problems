#include <bits/stdc++.h>

using namespace std;

int N, C, V, tc, tv, fc = 1, fv = 1, con[500], vow[500];
string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (char i : "aeiouy") {
        vow[i] = true;
    }

    for (char i : "bcdfghjklmnpqrstvwxyz") {
        con[i] = true;
    }

    cin >> N >> C >> V >> S;
    S += "_";

    for (char i : S) {
        if (con[i])
            tc++;
        else {
            if (tc > C)
                fc = 0;

            tc = 0;
        }

        if (vow[i])
            tv++;
        else {
            if (tv > V)
                fv = 0;

            tv = 0;
        }
    }

    cout << (fv && fc ? "YES" : "NO") << '\n';
}
