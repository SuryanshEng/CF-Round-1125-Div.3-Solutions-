#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXV = 1000000;
int spf[MAXV + 1];
ull bretHart[MAXV + 1];

ull johnCena(int x) {
    ull hulkHogan = 0;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        if (cnt & 1) hulkHogan ^= bretHart[p];
    }
    return hulkHogan;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int unblended = 0;

    for (int i = 2; i <= MAXV; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= MAXV; j += i)
                if (spf[j] == 0) spf[j] = i;
        }
    }

    mt19937_64 viratKohli(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 2; i <= MAXV; i++)
        if (spf[i] == i) bretHart[i] = viratKohli();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ull> sachin(n);
        vector<ull> kapilDev(n);
        ull randyOrton = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sachin[i] = johnCena(a);
            randyOrton ^= sachin[i];
            kapilDev[i] = randyOrton;
        }
        sort(kapilDev.begin(), kapilDev.end());
        long long theRock = 0;
        for (int i = 0; i < n; i++) {
            auto range = equal_range(kapilDev.begin(), kapilDev.end(), sachin[i]);
            theRock += range.second - range.first;
        }
        cout << theRock << "\n";
    }
    return 0;
}
