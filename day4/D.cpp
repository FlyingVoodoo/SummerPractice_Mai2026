#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string a;
    std::cin >> a;

    auto cell = [&](int i) -> char {
        if (i == 0 || i == n + 1) 
            return 'B';
        return a[i - 1];
    };

    constexpr int INF = 1e9;
    std::vector<int> dp(n + 2, INF);
    dp[0] = 0;

    for (int i : std::views::iota(0, n + 1)) {
        if (dp[i] == INF) 
            continue;

        switch (cell(i)) {
            case 'B':
            case 'L':
                for (int j : std::views::iota(i + 1, std::min(i + m + 1, n + 2)))
                    if (cell(j) != 'C')
                        dp[j] = std::min(dp[j], dp[i]);
                break;
            case 'W':
                if (int j = i + 1; cell(j) != 'C')
                    dp[j] = std::min(dp[j], dp[i] + 1);
                break;
        }
    }

    std::cout << (dp[n + 1] <= k ? "YES" : "NO") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    std::ranges::for_each(std::views::iota(0, t), [](auto) { solve(); });
}