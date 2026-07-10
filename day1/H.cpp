#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 676767677;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> b(n);
    for (auto& x : b) std::cin >> x;

    std::vector<int> freq(m, 0);
    for (int x : b) freq[x]++;
    
    std::vector<int> cnt(m + 1, 0);
    for (int t = 1; t <= m; t++)
        cnt[t] = cnt[t-1] + freq[t-1];

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        int t = b[i];
        if (t == 0) continue;

        int min_nb = m;
        if (i > 0) min_nb = std::min(min_nb, b[i-1]);
        if (i < n-1) min_nb = std::min(min_nb, b[i+1]);

        if (min_nb >= t) {
            std::cout << "0\n";
            return;
        }

        long long ways;
        if (min_nb == t - 1) {
            ways = cnt[t];
        } else {
            ways = cnt[t] - cnt[t-1];
        }

        if (ways <= 0) {
            std::cout << "0\n";
            return;
        }
        ans = ans * (ways % MOD) % MOD;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}