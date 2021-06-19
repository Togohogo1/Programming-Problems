#include <bits/stdc++.h>

using namespace std;

vector<int> v(4);

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());
    printf("%d\n%d\n", v[0], v[3]);
}
