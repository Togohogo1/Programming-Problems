#include<bits/stdc++.h>

using namespace std;

int N, ans, x[2000], y[2000];
set<pair<int, int>> pt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        pt.insert({x[i], y[i]});
    }

    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (pt.count({x[i], y[j]}) && pt.count({x[j], y[i]})){
                ans = max(ans, abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
    }

    cout << ans << '\n';
}
