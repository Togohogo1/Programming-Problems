#include <bits/stdc++.h>

using namespace std;

int N, K, c;
string essay[102], s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> essay[i];
        c += essay[i].size();

        if (c > K) {
            cout << s.substr(0, s.size()-1) << '\n';
            c = essay[i].size();
            s = "";
        }

        s += essay[i] + " ";
    }

    cout << s.substr(0, s.size()-1) << '\n';
}
