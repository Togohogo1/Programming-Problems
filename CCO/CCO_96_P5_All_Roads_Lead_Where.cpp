#include <bits/stdc++.h>

using namespace std;

const int M = 1002;
int n, m, a, b, vis[M], pre[M];
string A, B;
vector<int> adj[M];

void dfs(int st) {
    vis[st] = true;

    for (int i : adj[st]) {
        if (!vis[i]) {
            pre[i] = st;
            dfs(i);
        }
    }
}

string find(int st, int ed) {
    int tmp = st;
    string path = "";

    path += (char)tmp;

    while (tmp != ed) {
        int ntmp = pre[tmp];
        path += (char)ntmp;
        tmp = ntmp;
    }

    return path;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> A >> B;

        int a = A.front();
        int b = B.front();

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> A >> B;

        int a = A.front();
        int b = B.front();

        dfs(b);
        cout << find(a, b) << '\n';

        memset(vis, 0, sizeof(vis));
    }
}
