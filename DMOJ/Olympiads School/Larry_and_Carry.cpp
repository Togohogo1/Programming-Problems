#include <bits/stdc++.h>

using namespace std;

int n, cnt, w[22];

bool check(int a, int b){
    for(; a&&b; a/=10, b/=10) {
        if(a%10 + b%10 >= 10)
            return false;
    }

    return true;
}

void fun(int sum, int i, int k){
    if (i==n) {
        cnt = max(cnt, k);
        return;
    }

    if(check(sum, w[i]))
        fun(sum+w[i], i+1, k+1);

    fun(sum, i+1, k);
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &w[i]);

    fun(0, 0, 0);

    printf("%d\n", cnt);
}
