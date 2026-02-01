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
    long long fact = 1;
    for (int i = 1; i < n; ++i) {
        fact *= i;
    }

    k--; 

    for (int i = n - 1; i >= 0; --i) {
        int index = k / fact;
        permutation.push_back(nums[index]);
        nums.erase(nums.begin() + index);
        k %= fact;
        if (i > 0) {
            fact /= i;
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