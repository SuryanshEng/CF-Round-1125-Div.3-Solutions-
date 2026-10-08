#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &v : a) cin >> v;

        int m = n - 4;
        vector<long long> val(m);
        for (int x = 0; x < m; x++) val[x] = a[x] + a[x + 2] - a[x + 4];

        vector<long long> sorted = val;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && sorted[j] == sorted[i]) j++;
            long long cnt = j - i;
            ans += cnt * (cnt - 1) / 2;
            i = j;
        }

        for (int x = 0; x < m; x++) {
            if (x + 2 < m && val[x] == val[x + 2]) ans--;
            if (x + 4 < m && val[x] == val[x + 4]) ans--;
        }

        cout << ans << "\n";
    }
    return 0;
}
