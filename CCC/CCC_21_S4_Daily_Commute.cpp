#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, W, D, dis[M], vis[M], idx[M], stn[M];
vector<int> adj[M];
queue<int> q;
set<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> W >> D;

    for (int i = 0, A, B; i < W; i++) {
        cin >> A >> B;
        adj[B].push_back(A);
    }

    memset(dis, 0x3f3f3f, sizeof(dis));

    vis[N] = true;
    dis[N] = 0;
    q.push(N);

    // Get dist from station N to all other stations
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
                dis[nxt] = dis[cur] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> stn[i];
        idx[stn[i]] = i;
    }

    // Optimal = train from 1 to x, walk from x to station N
    for (int i = 1; i <= N; i++) {
        s.insert({idx[i]+dis[i]-1, i});
    }

    for (int i = 0, X, Y; i < D; i++) {
        cin >> X >> Y;

        s.erase({idx[stn[X]]+dis[stn[X]]-1, stn[X]});
        s.erase({idx[stn[Y]]+dis[stn[Y]]-1, stn[Y]});

        swap(stn[X], stn[Y]);
        swap(idx[stn[X]], idx[stn[Y]]);

        s.insert({idx[stn[X]]+dis[stn[X]]-1, stn[X]});
        s.insert({idx[stn[Y]]+dis[stn[Y]]-1, stn[Y]});

        cout << s.begin()->first << '\n';
    }
}
