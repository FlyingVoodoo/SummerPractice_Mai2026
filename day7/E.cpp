#include <iostream>
#include <string>
#include <vector>

bool check(const std::string& s, int k) {
    int n = s.size();
    std::vector<int> diff(n + 1, 0);
    int flips = 0;
    for (int i = 0; i < n; i++) {
        flips += diff[i];
        int bit = (s[i] - '0') ^ (flips & 1);
        if (bit == 0) {
            if (i + k > n) 
                return false;
            flips++;
            diff[i + k]--;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    for (int k = n; k >= 1; k--) {
        if (check(s, k)) {
            std::cout << k << "\n";
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) 
        solve();
}