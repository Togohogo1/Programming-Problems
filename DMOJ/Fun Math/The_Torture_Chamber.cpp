#include <bits/stdc++.h>

using namespace std;

void simpleSieve(unsigned long limit, vector<unsigned long>& prime) {
    vector<bool> mark(limit + 1, false);

    for (unsigned long i = 2; i <= limit; ++i) {
        if (mark[i] == false) {
            prime.push_back(i);

            for (unsigned long j = i; j <= limit; j += i) {
                mark[j] = true;
            }
        }
    }
}

void primesInRange(unsigned long low, unsigned long high) {
    unsigned long limit = floor(sqrt(high)) + 1;
    vector<unsigned long> prime;

    simpleSieve(limit, prime);

    unsigned long n = high - low + 1;
    unsigned long c = 0;

    vector<bool> mark(n + 1, false);

    for (unsigned long i = 0; i < prime.size(); i++) {
        unsigned long loLim = floor(low / prime[i]) * prime[i];

        if (loLim < low)
            loLim += prime[i];

        if (loLim == prime[i])
            loLim += prime[i];

        // Does NOT account for the higher prime so j <= high is wrong
        for (unsigned long j = loLim; j < high; j += prime[i]) {
            mark[j - low] = true;
        }
    }

    for (unsigned long i = low; i < high; i++) {
        if (!mark[i - low] && i != 1)
            c += 1;
    }

    printf("%ld", c);
}

int main() {
    unsigned long low, high;

    cin >> low;
    cin >> high;

    primesInRange(low, high);

    return 0;
}
