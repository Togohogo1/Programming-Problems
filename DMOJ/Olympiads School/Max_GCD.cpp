#include <bits/stdc++.h>

using namespace std;

int N, m, arr[200004], l[200004], r[200004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    l[1] = arr[0];
    r[1] = arr[N-1];

    for (int i = 2; i < N; i++) {
        l[i] = __gcd(arr[i-1], l[i-1]);
        r[i] = __gcd(arr[N-i], r[i-1]);
    }

    for (int i = 0; i <= N; i++) {
        if (i == 0)
            m = max(m, r[N-i-1]);
        else if (i > 0 && i < N)
            m = max(m, __gcd(l[i], r[N-i-1]));
        else
            m = max(m, l[i]);
    }

    cout << m << '\n';
}
