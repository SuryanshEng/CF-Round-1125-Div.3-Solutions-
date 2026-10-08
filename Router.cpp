#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x0, y0, r;
        cin >> x0 >> y0 >> r;
        cout << x0 + r << " " << y0 << "\n";
    }
    return 0;
}
