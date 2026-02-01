#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(arr[i], arr[j]) > 1) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (gcd(arr[i], arr[i + 1]) > 1) {
            continue;
        } else {
            for (int j = i + 1; j < n; j++) {
                if (gcd(arr[i], arr[j]) > 1) {
                    int temp = arr[i + 1];
                    arr[i + 1] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
    }
    bool possible = true;
    for (int i = 0; i < n - 1; i++) {
        if (gcd(arr[i], arr[i + 1]) > 1) {
            continue;
        } else {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(arr, n);
    return 0;
}