#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, tmp, diff, idx[M];
vector<int> a1, a2;
set<int> jo;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    diff = 2*(n-(1<<(int)log2(n)));

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && i <= diff)
            cout << i << ' ';
        else if (i <= diff) {
            a1.push_back(i);
            jo.insert(++tmp);
        } else {
            a2.push_back(i);
            jo.insert(++tmp);
        }
    }

    tmp = 0;

    for (int i : a2) {
        idx[++tmp] = i;
    }

    for (int i : a1) {
        idx[++tmp] = i;
    }

    for (int i = log2(n); i >= 1; i--) {
        auto it = jo.begin();

        for (int j = 0; j < 1 << i; j += 2) {
            tmp = *++it;
            cout << idx[tmp] << ' ';
            it++;
            jo.erase(tmp);
        }
    }

    cout << idx[*jo.begin()] << '\n';
}
