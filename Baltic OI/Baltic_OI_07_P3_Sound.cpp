#include<bits/stdc++.h>

using namespace std;

const int M = 1e6+2;
int n, m, c, tmpM, tmpm, arr[M], preM[M], prem[M], sufM[M], sufm[M];
bool found = false;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> c;

    for (int i = 1, v; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        tmpM = preM[i-1];
        tmpm = prem[i-1];

        if ((i-1) % m == 0) {
            tmpM = -1;
            tmpm = M;
        }

        preM[i] = max(arr[i], tmpM);
        prem[i] = min(arr[i], tmpm);
    }

    for (int i = n; i >= 1; i--) {
        tmpM = sufM[i+1];
        tmpm = sufm[i+1];

        if (i % m == 0) {
            tmpM = -1;
            tmpm = M;
        }

        sufM[i] = max(arr[i], tmpM);
        sufm[i] = min(arr[i], tmpm);
    }

    for (int i = 1; i <= n-m+1; i++) {
        if (max(sufM[i], preM[i+m-1]) - min(sufm[i], prem[i+m-1]) <= c) {
            cout << i << '\n';
            found = true;
        }
    }

    if (!found)
        cout << "NONE\n";
}
