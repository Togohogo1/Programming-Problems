#include <bits/stdc++.h>

using namespace std;

char tr;
string ca, cb, ans, li = "6789TJQKA";
map<char, int> rnk;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> tr >> ca >> cb;

    for (int i = 0; i < 9; i++) {
        rnk[li[i]] = i;
    }

    if (tr == ca[1] && ca[1] != cb[1])
        ans = "YES";
    else if (tr == cb[1] && ca[1] != cb[1])
        ans = "NO";
    else if (ca[1] == cb[1])
        ans = (rnk[ca[0]] > rnk[cb[0]] ? "YES" : "NO");
    else
        ans = "NO";

    cout << ans << '\n';
}
