#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
int n, arr[M];
ll fin;

ll find(int x) {
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(x-arr[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    fin = find(arr[n/2]);

    if (n % 2 == 0)
        fin = min(fin, find(arr[n/2+1]));

    cout << fin << '\n';
}
