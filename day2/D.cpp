#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

namespace sa {

struct State {
    int len = 0;
    int link = -1;
    std::map<char, int> next;
};

class SuffixAutomat {
public:
    explicit SuffixAutomat(const std::string& s) {
        states_.reserve(s.size() * 2);
        states_.emplace_back();

        for (const char c : s) {
            extend(c);
        }
    }

    long long count_substr() const {
        long long count = 0;
        for (size_t i = 1; i < states_.size(); ++i) {
            count += (states_[i].len - states_[states_[i].link].len);
        }
        return count;
    }

private:
    std::vector<State> states_;
    int last_ = 0;

    void extend(char c) {
        int cur = static_cast<int>(states_.size());
        states_.emplace_back();
        states_[cur].len = states_[last_].len + 1;

        int p = last_;
        while (p != -1 && !states_[p].next.count(c)) {
            states_[p].next[c] = cur;
            p = states_[p].link;
        }

        if (p == -1) {
            states_[cur].link = 0;
        } else {
            int q = states_[p].next.at(c);
            if (states_[p].len + 1 == states_[q].len) {
                states_[cur].link = q;
            } else {
                int clone = static_cast<int>(states_.size());
                states_.push_back(states_[q]);
                states_[clone].len = states_[p].len + 1;
                
                while (p != -1 && states_[p].next[c] == q) {
                    states_[p].next[c] = clone;
                    p = states_[p].link;
                }
                states_[q].link = states_[cur].link = clone;
            }
        }
        last_ = cur;
    }
};

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    sa::SuffixAutomat sam(s);
    std::cout << sam.count_substr() << "\n";

    return 0;
}