#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> a_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a_indices.push_back(i);
        }
    }

    int num_a = a_indices.size();
    long long count = 0;

    for (int i = 0; i < (1 << num_a); ++i) {
        vector<int> sequence;
        for (int j = 0; j < num_a; ++j) {
            if ((i >> j) & 1) {
                sequence.push_back(a_indices[j]);
            }
        }

        if (sequence.empty()) continue;

        bool valid = true;
        if (sequence.size() > 1) {
            for (size_t k = 0; k < sequence.size() - 1; ++k) {
                bool found_b = false;
                for (int j = sequence[k] + 1; j < sequence[k + 1]; ++j) {
                    if (s[j] == 'b') {
                        found_b = true;
                        break;
                    }
                }
                if (!found_b) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            count = (count + 1) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}