#include <iostream>
#include <vector>
#include <algorithm>

inline constexpr int INF = 1'000'000'000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> dist[i][j];
        }
    }

    if (n == 1) {
        std::cout << 0 << "\n";
        return 0;
    }

    const int num_states = 1 << n;
    std::vector<int> dp(num_states * n, INF);
    dp[1 * n + 0] = 0;

    for (int mask = 1; mask < num_states; ++mask) {
        for (int i = 0; i < n; ++i) {
            int current_cost = dp[mask * n + i];
            if (current_cost == INF) continue;

            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) {
                    int next_mask = mask | (1 << j);
                    int& next_val = dp[next_mask * n + j];
                    int new_cost = current_cost + dist[i][j];
                    if (new_cost < next_val) {
                        next_val = new_cost;
                    }
                }
            }
        }
    }

    int min_total_cost = INF;
    int final_mask = num_states - 1;
    for (int i = 1; i < n; ++i) {
        min_total_cost = std::min(min_total_cost, dp[final_mask * n + i] + dist[i][0]);
    }

    std::cout << min_total_cost << "\n";
    return 0;
}