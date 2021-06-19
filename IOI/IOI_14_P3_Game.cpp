#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int arr[1501];

void initialize(int n) {
    int temp = n - 1;

    for (int i = 0; i < n; i++) {
        arr[i] = temp--;
    }
}

int hasEdge(int u, int v) {
    if (arr[min(u, v)] > 1) {
        arr[min(u, v)]--;
        return 0;
    }

    return 1;
}
