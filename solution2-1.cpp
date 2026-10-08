#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 2), b(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<ll> pre(n + 2, 0), suf(n + 2, 0);
        for (int j = 1; j <= n; j++) {
            ll v = a[j] == b[j];
            ll d1 = j < n && b[j] == a[j + 1];
            pre[j] = pre[j - 1] + v + d1;
        }
        for (int j = n - 1; j >= 1; j--) {
            ll d1 = b[j] == a[j + 1];
            ll d2 = a[j] == b[j + 1];
            suf[j] = suf[j + 1] + d1 + d2;
        }
        ll vn = a[n] == b[n];
        ll best = 0;
        for (int k = 1; k <= n; k++) best = max(best, pre[k - 1] + suf[k] + vn);
        ll thegrilla = 2LL * n - 1 + best;
        cout << thegrilla << "\n";
    }
    return 0;
}
