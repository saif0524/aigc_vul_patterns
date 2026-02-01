#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long negative_count = 0;
    long long positive_count = 0;

    for (int l = 0; l < n; ++l) {
        long long product = 1;
        for (int r = l; r < n; ++r) {
            product *= a[r];
            if (product < 0) {
                negative_count++;
            } else if (product > 0) {
                positive_count++;
            }
        }
    }

    cout << negative_count << " " << positive_count << endl;

    return 0;
}