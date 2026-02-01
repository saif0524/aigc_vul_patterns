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
        
        if (distinct_sub_array.size() >= 1) {
            potential = (potential + (distinct_sub_array[0] * fib1) % m) % m;
        }
        if (distinct_sub_array.size() >= 2) {
            potential = (potential + (distinct_sub_array[1] * fib2) % m) % m;
        }
        
        for (int k = 2; k < distinct_sub_array.size(); ++k) {
            long long next_fib = (fib1 + fib2) % m;
            potential = (potential + (distinct_sub_array[k] * next_fib) % m) % m;
            fib1 = fib2;
            fib2 = next_fib;
        }

        cout << potential << endl;
    }

    return 0;
}