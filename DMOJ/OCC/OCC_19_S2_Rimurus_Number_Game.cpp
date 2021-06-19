#include<bits/stdc++.h>

using namespace std;

long long N;

long long fun(long long curr, long long x) {
    if (curr >= N)
        return x;

    return fun(curr*10+2, x) + fun(curr*10+3, x) + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cout << fun(2, 0) + fun(3, 0) << '\n';
}
