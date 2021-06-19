#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int lo = 1, hi = 2e9;
    string s;

    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;

        cout << mid << endl;  // endl flushes buffer
        cin >> s;

        if (s == "OK")
            break;
        else if (s == "FLOATS")
            hi = mid - 1;
        else
            lo = mid + 1;
    }
}
