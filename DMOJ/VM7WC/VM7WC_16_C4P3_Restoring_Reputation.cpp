#include <bits/stdc++.h>

using namespace std;

const int M = 1002;
int D, I, R, dpc[M], dpp[M];
string A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> D >> I >> R >> A >> B;

    for (int i = 1; i <= B.size(); i++) {
        dpp[i] = dpp[i-1] + I;
    }

    for (int i = 1; i <= A.size(); i++) {
        dpc[0] = i*D;

        for (int j = 1; j <= B.size(); j++) {
            dpc[j] = min(dpp[j-1]+(A[i-1]!=B[j-1])*R, min(dpc[j-1]+I, dpp[j]+D));
        }

        for (int j = 0; j <= B.size(); j++) {
            dpp[j] = dpc[j];
        }

    }

    cout << dpc[B.size()] << '\n';
}
