#include <bits/stdc++.h>

using namespace std;

int N, tot;
vector<int> v;

void fun(int begin, int sum, int n, vector<int> v) {
    if (sum == n) {
        cout << n << "=";

        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << "+";
        }

        cout << v.back() << '\n';

        tot++;
        return;
    }

    for (int i = begin; i < n; i++) {
        if (sum + i <= n) {
            v.push_back(i);
            fun(i, sum+i, n, v);
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    fun(1, 0, N, v);
    cout << "total=" << tot << '\n';
}
