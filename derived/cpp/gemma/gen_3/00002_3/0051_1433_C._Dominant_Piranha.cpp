#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int dominant_piranha = -1;
        for (int i = 0; i < n; ++i) {
            vector<int> temp_a = a;
            int current_size = temp_a[i];
            
            int left = i - 1;
            while (left >= 0 && temp_a[left] < current_size) {
                current_size++;
                temp_a.erase(temp_a.begin() + left);
                left--;
            }
            
            int right = i + 1;
            while (right < n && temp_a[right] < current_size) {
                current_size++;
                temp_a.erase(temp_a.begin() + right);
            }
            
            if (temp_a.size() == 1) {
                dominant_piranha = i + 1;
                break;
            }
        }

        cout << dominant_piranha << endl;
    }

    return 0;
}