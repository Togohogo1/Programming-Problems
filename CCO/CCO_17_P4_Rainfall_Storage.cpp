#include <bits/stdc++.h>

using namespace std;

const int M = 502, MM = 25002;
int N, arr[M], dp[M][MM];
set<int> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Sorting pillars, using largest pillar (L) as starting point
    sort(arr, arr+N, greater<int>());
    dp[0][0] = 1;

    // dp[i][j] = true if pillars from L to i can make volume j
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < MM; j++) {
            // Since each new added pillar is smaller (thus overflow)
            if (dp[i-1][j])
                dp[i][j] = true;

            // Difference between pillar i and each pillar h in st can be added to existing solution with i-1 pillars
            for (auto h : st) {
                int diff = abs(-h-arr[i]);

                if (dp[i-1][j])
                    dp[i][j+diff] = true;
            }
        }

        st.insert(-arr[i]);
    }

    for (int i = 0; i < MM; i++) {
        if (dp[N-1][i])
            cout << i << ' ';
    }

    cout << '\n';
}
