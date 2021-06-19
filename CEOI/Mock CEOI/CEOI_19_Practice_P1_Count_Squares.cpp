#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1502;
int h, v, x[M], y[M];
long long ans;
unordered_map<int, int> freq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> h >> v;

    for (int i = 1; i <= h; i++) {
        cin >> y[i];

        for (int j = 1; j < i; j++) {
            freq[y[i]-y[j]]++;
        }
    }

    for (int i = 1; i <= v; i++) {
        cin >> x[i];

        for (int j = 1; j < i; j++) {
            ans += freq[x[i]-x[j]];
        }
    }

    cout << ans << '\n';
}