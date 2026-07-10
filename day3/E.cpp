#include <iostream>
#include <vector>
#include <algorithm>

using CostType = long long;

auto min_cost(const int n) -> CostType {
    std::vector<CostType> dp(n + 1);

    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        CostType curr_min = dp[i - 1];

        if (i % 2 == 0) {
            curr_min = std::min(curr_min, dp[i / 2]);
        }

        if (i % 3 == 0) {
            curr_min = std::min(curr_min, dp[i / 3]);
        }

        dp[i] = i + curr_min;
    }

    return dp[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << min_cost(n) << "\n";

    return 0;
}