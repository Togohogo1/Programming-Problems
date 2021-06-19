#include <bits/stdc++.h>

using namespace std;

uint64_t dup[256] = {0, 3};

unsigned long long duplicatebits(unsigned long long x) {
    uint64_t ans = 0;

    // OEIS-A001196
    if (!dup[2]) {
        for (int i = 3; i <= 256; i++) {
          dup[i-1] = (i & 1) ? 4*dup[i/2] : 4*dup[(i-1)/2] + 3;
        }
    }

    for (int i = 0; i < 4; i++) {
        ans |= dup[x >> (8*i) & 255] << (16*i);
    }

    return ans;
}
