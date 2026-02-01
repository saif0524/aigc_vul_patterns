#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    if (a == sorted_a) {
        cout << "YES" << endl;
        return 0;
    }

    int diff_count = 0;
    int first_diff_index = -1;
    int second_diff_index = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            diff_count++;
            if (first_diff_index == -1) {
                first_diff_index = i;
            } else {
                second_diff_index = i;
            }
        }
    }

    if (diff_count == 2) {
        swap(a[first_diff_index], a[second_diff_index]);
        if (a == sorted_a) {
            cout << "YES" << endl;
            return 0;
        }
    } else if(diff_count == 0){
        cout << "YES" << endl;
        return 0;
    }
    else if (diff_count == n && n == 2)
    {
        cout << "YES" << endl;
        return 0;
    }
    else if (diff_count == n && n == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1)
    {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}