#include <bits/stdc++.h>

using namespace std;

string num, res, pre;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true) {
        cin >> num;

        if (num == "99999")
            break;

        int sum = stoi(num.substr(0, 1)) + stoi(num.substr(1, 1));

        if (sum & 1)
            res = "right ";
        else if (sum == 0)
            res = pre;
        else
            res = "left ";

        pre = res;
        cout << res << num.substr(2, 3) << '\n';
    }
}
