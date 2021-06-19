#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, diff, arr1[M], arr2[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, ai; i < N; i++) {
        cin >> ai;
        arr1[i] = ai;
        arr2[i] = ai;
    }

    sort(arr1, arr1+N);

    for (int i = 0; i < N; i++) {
        if (arr1[i] != arr2[i])
            diff++;
    }

    cout << ((diff <= 2 ? "YES" : "NO")) << '\n';
}
