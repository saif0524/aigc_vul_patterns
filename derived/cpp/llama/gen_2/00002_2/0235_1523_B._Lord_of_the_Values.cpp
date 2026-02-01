#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::vector<std::string> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > 0) {
                ans.push_back("2 " + std::to_string(i + 1) + " " + std::to_string(j + 1));
                v[j] -= v[i];
                ans.push_back("2 " + std::to_string(i + 1) + " " + std::to_string(j + 1));
                v[j] -= v[i];
            } else if (v[i] < 0) {
                ans.push_back("1 " + std::to_string(i + 1) + " " + std::to_string(j + 1));
                v[i] += v[j];
                ans.push_back("1 " + std::to_string(i + 1) + " " + std::to_string(j + 1));
                v[i] += v[j];
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] > 0) {
            ans.push_back("2 " + std::to_string(i + 1) + " " + std::to_string(n));
            v[n - 1] -= v[i];
            ans.push_back("2 " + std::to_string(i + 1) + " " + std::to_string(n));
            v[n - 1] -= v[i];
        } else if (v[i] < 0) {
            ans.push_back("1 " + std::to_string(i + 1) + " " + std::to_string(n));
            v[i] += v[n - 1];
            ans.push_back("1 " + std::to_string(i + 1) + " " + std::to_string(n));
            v[i] += v[n - 1];
        }
    }

    std::cout << ans.size() << std::endl;
    for (const auto& str : ans) {
        std::cout << str << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}