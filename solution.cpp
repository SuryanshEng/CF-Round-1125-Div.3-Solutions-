#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct soulsold {
    vector<int> kohli;
    vector<int> dhoni;

    int find(int x) {
        while (kohli[x] != x) {
            kohli[x] = kohli[kohli[x]];
            x = kohli[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (dhoni[a] < dhoni[b]) swap(a, b);
        kohli[b] = a;
        dhoni[a] += dhoni[b];
        return true;
    }

    void run() {
        int t;
        cin >> t;
        while (t--) {
            int n, m, q;
            cin >> n >> m >> q;
            vector<array<ll, 3>> sachin(m);
            ll undertaker = 0;
            for (int i = 0; i < m; i++) {
                ll u, v, d;
                cin >> u >> v >> d;
                sachin[i] = {d, u, v};
                undertaker += d;
            }
            sort(sachin.begin(), sachin.end());
            kohli.assign(n + 1, 0);
            dhoni.assign(n + 1, 1);
            for (int i = 0; i <= n; i++) kohli[i] = i;

            vector<ll> cena(1, 0);
            vector<ll> rock(1, 0);
            for (auto &e : sachin) {
                if (unite((int)e[1], (int)e[2])) {
                    rock.push_back(e[0]);
                    cena.push_back(cena.back() + e[0]);
                }
            }
            int r = (int)rock.size() - 1;

            while (q--) {
                ll x;
                cin >> x;
                int lo = 0, hi = r;
                while (lo < hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (x * (ll)(n - mid) > rock[mid]) lo = mid;
                    else hi = mid - 1;
                }
                int f = lo;
                ll k = n - 1 - f;
                ll ans = undertaker - cena[f] - x * (k * (k + 1) / 2);
                cout << ans << " ";
            }
            cout << "\n";
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
