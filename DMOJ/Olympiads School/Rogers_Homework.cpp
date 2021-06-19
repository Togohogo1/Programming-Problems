#include<bits/stdc++.h>

using namespace std;

int n, di, pi, ans;
vector<int> adj[1000002];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> di >> pi;
        adj[di].push_back(pi);
    }

    for (int i = n; i > 0; i--) {
        for (int j : adj[i]) {
            pq.push(j);
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
}
