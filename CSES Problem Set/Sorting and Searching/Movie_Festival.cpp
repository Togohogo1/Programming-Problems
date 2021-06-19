#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, a, b, ans1 = 1, ans2 = 1, tmp1, tmp2;
pair<int, int> arr1[M], arr2[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr1[i] = {a, b};
        arr2[i] = {b, a};
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    tmp1 = arr1[0].second;
    tmp2 = arr2[0].first;

    for (int i = 1; i < n; i++) {
        if (arr1[i].first >= tmp1) {
            tmp1 = arr1[i].second;
            ans1++;
        }

        if (arr2[i].second >= tmp2) {
            tmp2 = arr2[i].first;
            ans2++;
        }
    }

    cout << max(ans1, ans2) << '\n';
}
