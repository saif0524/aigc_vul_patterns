#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> boss(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        cin >> boss[i];
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    long long count = 0;
    
    do {
        bool valid = true;
        for (int i = 0; i < n - 1; ++i) {
            if (permutation[i] != 1 && permutation[i + 1] == boss[permutation[i]]) {
                valid = false;
                break;
            }
            if (permutation[i + 1] != 1 && permutation[i] == boss[permutation[i + 1]]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            count = (count + 1) % MOD;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << count << endl;

    return 0;
}