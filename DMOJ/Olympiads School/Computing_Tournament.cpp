#include <bits/stdc++.h>

using namespace std;

int N, K, f, s, maxScore = -1;
vector<pair<int, int>> r1;
unordered_map<int, int> r2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> f >> s;
        r1.push_back(make_pair(f, s));
        r2[s] = i+1;
    }

    sort(r1.begin(), r1.end());

    for (int i = 1; i < K+1; i++) {
        maxScore = max(maxScore, r1[r1.size()-i].second);
    }

    cout << r2[maxScore] << "\n";
}
