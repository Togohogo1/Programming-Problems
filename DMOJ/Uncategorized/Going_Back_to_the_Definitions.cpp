#include<bits/stdc++.h>

using namespace std;

int N;

bool cmp(string a, string b) {
    return a+b > b+a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N, cmp);

    for (string i: arr) {
        cout << i;
    }
}
