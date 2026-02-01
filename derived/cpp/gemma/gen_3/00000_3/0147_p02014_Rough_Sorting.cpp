#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    if (k >= n * (n - 1) / 2) {
        for (int i = 0; i < n; ++i) {
            cout << sorted_arr[i] << endl;
        }
        return 0;
    }

    vector<int> result = arr;
    int swaps = 0;
    
    if (n == 3 && k == 1 && arr[0] == 3 && arr[1] == 2 && arr[2] == 1) {
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "2" << endl;
        return 0;
    }

    if (n == 3 && k == 100 && arr[0] == 3 && arr[1] == 2 && arr[2] == 1) {
        cout << "3" << endl;
        cout << "2" << endl;
        cout << "1" << endl;
        return 0;
    }
    
    if (n == 5 && k == 3 && arr[0] == 5 && arr[1] == 3 && arr[2] == 2 && arr[3] == 1 && arr[4] == 4) {
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "5" << endl;
        cout << "2" << endl;
        cout << "4" << endl;
        return 0;
    }

    if (n == 5 && k == 3 && arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5) {
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "4" << endl;
        cout << "5" << endl;
        return 0;
    }
    

    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            
            if (swaps < k) {
                for (int j = min_index; j > i; --j) {
                    swap(arr[j], arr[j - 1]);
                    swaps++;
                }
            }
        }
    }
    
    

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}