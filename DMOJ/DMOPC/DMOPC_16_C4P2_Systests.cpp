#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int batch, tests, ans;
vector<int> st, ed, pt, fail;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> batch;

    for(int i = 0, x, y, z; i < batch; i++) {
        cin >> x >> y >> z;
        st.push_back(x);
        ed.push_back(y);
        pt.push_back(z);
    }

    cin >> tests;
    fail.resize(tests);

    for(int i = 0; i < tests; i++) {
        cin >> fail[i];
    }

    sort(fail.begin(), fail.end());

    for(int i = 0; i < batch; i++) {
        int pos = lower_bound(fail.begin(), fail.end(), st[i]) - fail.begin();

        if (pos == tests || fail[pos] > ed[i])
            ans += pt[i];
    }

    cout << ans << "\n";
}
