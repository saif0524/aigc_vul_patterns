#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--;

        vector<int> sub_array;
        for (int j = l; j <= r; ++j) {
            sub_array.push_back(a[j]);
        }

        set<int> unique_elements;
        vector<int> distinct_sub_array;
        for (int x : sub_array) {
            if (unique_elements.find(x) == unique_elements.end()) {
                unique_elements.insert(x);
                distinct_sub_array.push_back(x);
            }
        }

        sort(distinct_sub_array.begin(), distinct_sub_array.end());

        long long potential = 0;
        long long fib1 = 1;
        long long fib2 = 1;

        for (int k = 0; k < distinct_sub_array.size(); ++k) {
            long long fib = (k == 0) ? 1 : (k == 1) ? 1 : (fib1 + fib2);
            potential = (potential + (long long)distinct_sub_array[k] * fib) % m;
            
            long long temp = fib1;
            fib1 = fib2;
            fib2 = temp + fib2;
        }

        cout << potential << endl;
    }

    return 0;
}