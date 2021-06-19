#include<bits/stdc++.h>

using namespace std;

const int M = 5e5+2;
int N, tube[M], bit[M];
long long ans;
deque<int> dq;

int query(int idx) {
    int ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans += bit[i];
    }

    return ans;
}

void update(int idx, int val) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tube[i];
    }

    dq.emplace_front(tube[0]);
    update(tube[0], 1);

    for (int i = 1, lg, sm; i < N; i++) {
        lg = query(tube[i]);
        sm = i-lg;

        update(tube[i], 1);

        // For each new tube, place it on the side that results in the least number of inversions
        // If least number of inversions equal, doesn't matter which side the tube is places on
        if (lg > sm) {
            dq.emplace_front(tube[i]);
            ans += sm;
        } else {
            dq.emplace_back(tube[i]);
            ans += lg;
        }
    }

    cout << ans << '\n';
}
