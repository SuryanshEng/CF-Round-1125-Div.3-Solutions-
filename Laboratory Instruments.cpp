#include <bits/stdc++.h>
using namespace std;

struct Lab {
    long long sum;
    int type;
    long long penalty;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<Lab> labs(n);
        long long lo = LLONG_MAX;
        long long hi = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            Lab lab;
            lab.sum = a + b + c;
            lab.penalty = 0;
            if (!(a <= b && b <= c)) {
                lab.type = 0;
            } else if (a == b && b == c) {
                lab.type = 2;
                hi = min(hi, lab.sum);
            } else {
                lab.type = 1;
                lab.penalty = 2 * (min(b - a, c - b) + 1);
            }
            labs[i] = lab;
            lo = min(lo, lab.sum);
        }
        hi = min(hi, lo + k);

        auto feasible = [&](long long S) {
            long long used = 0;
            for (const Lab &lab : labs) {
                if (lab.sum >= S) continue;
                if (lab.type == 2) return false;
                long long need = S - lab.sum;
                if (lab.type == 1) need += lab.penalty;
                used += need;
                if (used > k) return false;
            }
            return true;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << lo << "\n";
    }
    return 0;
}
