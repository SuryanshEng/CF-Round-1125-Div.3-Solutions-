#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

struct soulsold {
    ll norm(ll x) {
        x %= MOD;
        if (x < 0) x += MOD;
        return x;
    }

    void run() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            vector<vector<ll>> dravid(n + 2, vector<ll>(m + 2, 0));
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                    ll v;
                    cin >> v;
                    dravid[i][j] = norm(v);
                }

            vector<ll> fr(n + 2), gr(n + 2), fc(m + 2), gc(m + 2);
            for (int i = 1; i <= n; i++) {
                fr[i] = (i & 1) ? 1 : 0;
                gr[i] = ((n - i) % 2 == 0) ? ((i & 1) ? -1 : 1) : 0;
            }
            for (int j = 1; j <= m; j++) {
                fc[j] = (j & 1) ? 1 : 0;
                gc[j] = ((m - j) % 2 == 0) ? ((j & 1) ? -1 : 1) : 0;
            }

            vector<ll> warne(m + 2, 0);
            vector<ll> pre(m + 2, 0), suf(m + 3, 0);
            ll ponting = 0;
            ll lara = 0;

            for (int i = 1; i <= n; i++) {
                pre[0] = 0;
                for (int j = 1; j <= m; j++)
                    pre[j] = norm(pre[j - 1] + fc[j] * warne[j]);
                suf[m + 1] = 0;
                for (int j = m; j >= 1; j--)
                    suf[j] = norm(suf[j + 1] + gc[j] * warne[j]);

                if (gr[i] != 0) {
                    for (int j = 1; j <= m; j++) {
                        ll inner = gc[j] * pre[j - 1] + fc[j] * gc[j] * warne[j] + fc[j] * suf[j + 1];
                        inner = norm(inner);
                        ll term = dravid[i][j] * inner % MOD;
                        term = norm(term * gr[i]);
                        ponting = (ponting + term) % MOD;
                    }
                }

                if (fr[i] != 0 && gr[i] != 0) {
                    ll coef = fr[i] * gr[i];
                    ll run = 0;
                    ll cross = 0;
                    ll diag = 0;
                    for (int j = 1; j <= m; j++) {
                        cross = (cross + gc[j] * dravid[i][j] % MOD * run) % MOD;
                        run = norm(run + fc[j] * dravid[i][j]);
                        diag = (diag + fc[j] * gc[j] * dravid[i][j] % MOD * dravid[i][j]) % MOD;
                    }
                    cross = norm(cross);
                    diag = norm(diag);
                    ll rowTotal = norm(2 * cross + diag);
                    lara = norm(lara + coef * rowTotal);
                }

                for (int j = 1; j <= m; j++)
                    warne[j] = norm(warne[j] + fr[i] * dravid[i][j]);
            }

            ll ans = norm(2 * ponting + lara);
            cout << ans << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    soulsold bumrah;
    bumrah.run();
    return 0;
}