#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, di, bit[M], day[M];
long long ans;
vector<int> adj[M];
priority_queue<int> pq;

int query(int idx) {
    int sum = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx; i <= N; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> di;
        adj[di].push_back(i);
    }

    for (int i = N; i >= 1; i--) {
        for (int j : adj[i]) {
            pq.push(j);
        }

        // Cannot assign task to a day
        if (pq.empty()) {
            cout << -1 << '\n';
            return 0;
        }

        // Larger/smaller current deadline as far right/left as possible
        // If sequence exists, this greedy approach guarantees minimum number of swaps
        day[i] = pq.top();
        pq.pop();
    }

    // Found best solution, swaps to get there = number of inversions
    // To count, find number of tasks in day larger and before day[i]
    for (int i = N; i >= 1; i--) {
        ans += query(day[i]);
        update(day[i], 1);
    }

    cout << ans << '\n';
}
