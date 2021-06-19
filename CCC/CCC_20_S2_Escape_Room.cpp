#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+2;
int M, N, x;
bool vis[MAX];
vector<int> adj[MAX];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> x;
            adj[i*j].push_back(x);
        }
    }

    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int nv = q.front();
        q.pop();

        for (int i : adj[nv]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }

    cout << (vis[M*N] ? "yes" : "no") << '\n';
}
