#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<bool> printed(n + 1, false);
        vector<int> memory;
        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            if (c == '1') {
                memory.push_back(i);
            } else if (c == '2') {
                if (!memory.empty()) {
                    printed[memory.back()] = true;
                    memory.pop_back();
                } else {
                    printed[i] = true;
                }
            } else {
                printed[i] = true;
            }
        }

        vector<int> missing;
        for (int i = 1; i <= n; i++)
            if (!printed[i]) missing.push_back(i);

        cout << missing.size() << "\n";
        for (int x : missing) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
