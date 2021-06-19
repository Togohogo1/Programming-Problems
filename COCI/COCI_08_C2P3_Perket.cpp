#include <bits/stdc++.h>

using namespace std;

int N, id[10], sour[10], bit[10], ans = 2e9;
vector<int> res;

// Reference same vector to avoid deepcopy
void getComb(int idx, int id[], vector<int> res) {
    if (idx == N) {
        if (res.empty())
            return;

        int totSour = 1, totBit = 0;

        for (int x : res) {
            totSour *= sour[x];
            totBit += bit[x];
        }

        ans = min(ans, abs(totSour - totBit));
        return;
    }

    // Don't choose
    getComb(idx+1, id, res);

    // Choose
    res.push_back(id[idx]);
    getComb(idx+1, id, res);
    res.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> sour[i] >> bit[i];
        id[i] = i;
    }

    getComb(0, id, res);
    cout << ans << endl;
}
