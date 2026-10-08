#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x1, y1, r;
        cin >> x1 >> y1 >> r;
        cout << x1 + r << " " << y1 << "\n";
    }
    return 0;
}
