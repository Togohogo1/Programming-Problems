#include <bits/stdc++.h>

using namespace std;

int N, D, num, indiv, m, ans = 1e8;
string name;
unordered_map<int, string> ppl;
unordered_map<int, int> freq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name >> num;
        ppl[num] = name;
    }

    cin >> D;

    for (int i = 0; i < D; i++) {
        cin >> indiv;
        freq[indiv]++;
        m = max(m, freq[indiv]);
    }

    for (pair<int, int> i : freq) {
        if (i.second == m)
            ans = min(ans, i.first);
    }

    cout << ppl[ans] << '\n';
}
