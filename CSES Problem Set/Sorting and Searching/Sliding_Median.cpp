#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, k, arr[M];
multiset<int> ms;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        ms.insert(arr[i]);
    }

    auto it = ms.begin();
    advance(it, (k+1)/2-1);
    cout << *it << ' ';

    for (int i = k; i < n; i++) {
        ms.insert(arr[i]);

        if (arr[i] >= *it) {
            if (arr[i-k] <= *it)
                it++;
        } else {
            if (arr[i-k] >= *it)
                it--;

            if (arr[i-k] == *it)
                it++;
        }

        cout << *it << ' ';
        ms.erase(ms.find(arr[i-k]));
    }

    cout << '\n';
}
