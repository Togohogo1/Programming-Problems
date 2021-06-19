#include<bits/stdc++.h>

using namespace std;

int x, y, indeg[8] = {0, 1, 0, 0, 2, 1, 0, 1};
string ans;
vector<int> adj[8];

void topSort() {
    int cnt = 0;
    priority_queue<int> pq;

    for (int i = 1; i <= 7; i++) {
        if (indeg[i] == 0)
            pq.push(-i);
    }

    while (!pq.empty()) {
        int u = -pq.top();
        pq.pop();
        cnt++;

        ans += to_string(u) + " ";

        for (int v : adj[u]) {
            if (--indeg[v] == 0)
                pq.push(-v);
        }
    }

    if (cnt != 7)
        ans = "Cannot complete these tasks. Going to bed.";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);

    while (true) {
        cin >> x >> y;

        if (x == 0)
            break;

        indeg[y]++;
        adj[x].push_back(y);
    }

    topSort();
    cout << ans << '\n';
}