#include<bits/stdc++.h>

using namespace std;

int n, cat, dog;
string anim;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> anim;

        if (anim == "cat")
            cat++;
        else
            dog++;
    }

    if (cat > dog)
        cout << "cat\n";
    else if (dog > cat)
        cout << "dog\n";
    else
        cout << "equal\n";
}
