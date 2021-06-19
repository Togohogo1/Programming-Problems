#include<bits/stdc++.h>

using namespace std;

const int M = 1134903170;
int N, num, nxt;
vector<int> fib = {0, 1};

int check(int n) {
    int ans = 0, diff = M;

    for (int i : fib) {
        diff = min(diff, abs(n-i));

        if (diff == abs(n-i))
            ans = i;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (fib.back() <= M) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }

    for (int i = 0; i < 5; i++) {
        cin >> num;
        cout << check(num) << '\n';
    }
}
