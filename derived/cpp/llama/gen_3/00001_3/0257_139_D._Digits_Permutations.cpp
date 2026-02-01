#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int count_zeros(int a) {
    int zeros = 0;
    while (a % 10 == 0) {
        ++zeros;
        a /= 10;
    }
    return zeros;
}

int main() {
    string n;
    cin >> n;
    sort(n.begin(), n.end());
    int max_zeros = 0;
    string ans1 = n, ans2 = n;

    do {
        do {
            int num1 = stoi(n);
            int num2 = stoi(n);
            int sum = num1 + num2;
            int zeros = count_zeros(sum);
            if (zeros > max_zeros) {
                max_zeros = zeros;
                ans1 = n;
                ans2 = n;
            }
        } while (next_permutation(n.begin(), n.end()));
    } while (next_permutation(n.begin(), n.end()));

    cout << ans1 << endl << ans2 << endl;

    return 0;
}