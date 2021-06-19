#include <bits/stdc++.h>

using namespace std;

long long Q, K, M, N, lo, hi, st1, st2;
vector<long long> pa;

void makePalin(string s) {
    string s1 = s, s2 = s;
    reverse(s2.begin(), s2.end());

    st1 = stoll(s1+s2);
    st2 = stoll(s1.substr(0, s1.size()-1) + s2);

    if (st1 % K == 0)
        pa.push_back(st1);

    if (st2 % K == 0)
        pa.push_back(st2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> Q >> K;

    for (int i = 1; i <= 99999; i++) {
        makePalin(to_string(i));
    }

    sort(pa.begin(), pa.end());

    while(Q--) {
        cin >> M >> N;

        hi = upper_bound(pa.begin(), pa.end(), N) - pa.begin();
        lo = upper_bound(pa.begin(), pa.end(), M-1) - pa.begin();

        cout << hi - lo << "\n";
    }
}
