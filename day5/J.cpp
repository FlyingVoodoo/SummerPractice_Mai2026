#include <iostream>
#include <vector>

constexpr int MOD = 1'000'000'007;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int v = 1; v <= n; ++v) {
        for (int j = n; j >= v; --j) {
            dp[j] = (dp[j] + dp[j - v]) % MOD;
        }
    }

    std::cout << dp[n] << "\n";
}