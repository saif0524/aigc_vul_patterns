#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int avg = sum / n;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        if (arr[i]!= avg) {
            tmp.push_back(i);
        }
    }

    if (tmp.size() == 0) {
        cout << "Exemplary pages." << endl;
    } else if (tmp.size() == 2) {
        int diff = abs(arr[tmp[0]] - avg);
        if (arr[tmp[0]] < avg) {
            cout << diff << " ml. from cup #" << tmp[0] + 1 << " to cup #" << tmp[1] + 1 << "." << endl;
        } else {
            cout << diff << " ml. from cup #" << tmp[1] + 1 << " to cup #" << tmp[0] + 1 << "." << endl;
        }
    } else {
        cout << "Unrecoverable configuration." << endl;
    }

    return 0;
}