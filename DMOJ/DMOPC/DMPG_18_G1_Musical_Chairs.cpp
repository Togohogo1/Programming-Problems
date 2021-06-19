#include <bits/stdc++.h>

using namespace std;

int N, K, idx, beg, ppl[1000002];
bool emp[1000002];
vector<int> mus;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> idx;
        emp[idx] = true;
    }

    for (int i = 1; i <= K+1; i++) {
        cin >> beg;
        ppl[beg] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (ppl[i])
            mus.push_back(ppl[i]);

        // Forcibly seat person at top of stack when found a seat
        if (emp[i] && !mus.empty())
            mus.pop_back();
    }

    cout << mus[0] << '\n';
}
