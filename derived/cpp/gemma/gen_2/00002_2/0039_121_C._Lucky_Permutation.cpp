#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_lucky(int n) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '4' && c != '7') {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > tgamma(n + 1)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    vector<int> permutation;
    
    if (n == 1 && k == 1) {
        permutation.push_back(1);
    } else {
        
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        k--; 

        vector<int> available_nums = nums;
        for (int i = 0; i < n; ++i) {
            int index = k / fact[n - 1 - i];
            permutation.push_back(available_nums[index]);
            available_nums.erase(available_nums.begin() + index);
            k %= fact[n - 1 - i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (is_lucky(i + 1) && is_lucky(permutation[i])) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}