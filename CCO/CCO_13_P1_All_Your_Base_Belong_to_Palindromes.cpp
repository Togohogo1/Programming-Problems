#include<bits/stdc++.h>

using namespace std;

int X, tmp = 1;
vector<int> ans;

bool isPalin(int x, int b) {
    vector<int> dig;

    while (x != 0) {
        dig.push_back(x % b);
        x /= b;
    }

    for (int l = 0, r = dig.size()-1; l <= r; r--, l++) {
        if (dig[l] != dig[r])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> X;

    // 3 or more digits, small base
    // if b*b >= X + 1, tmp = b = min base, so converted number has 2 digits
    for (int b = 2; b*b <= X; b++) {
        tmp = b;

        if (isPalin(X, b))
            cout << b << '\n';
    }

    // 2 or less digits, large based
    // x = (y, y) base b => y*(b-1) = x => x divisible by b-1 when y integer
    for (int b = tmp; b > 0; b--) {
        // Values of X/b - 1 <= tmp already printed
        if (X % b == 0 && X/b - 1 > tmp)
            cout << X/b - 1 << '\n';
    }
}
