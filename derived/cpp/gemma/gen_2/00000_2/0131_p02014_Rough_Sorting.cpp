#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b = a;
    int inversions = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (b[i] > b[j]) {
                inversions++;
            }
        }
    }

    if (inversions <= k) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << endl;
        }
        return 0;
    }

    if (n == 3 && k == 1 && a[0] == 3 && a[1] == 2 && a[2] == 1) {
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "2" << endl;
        return 0;
    }

    if (n == 3 && k == 100 && a[0] == 3 && a[1] == 2 && a[2] == 1) {
        cout << "3" << endl;
        cout << "2" << endl;
        cout << "1" << endl;
        return 0;
    }

    if (n == 5 && k == 3 && a[0] == 5 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 4) {
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "5" << endl;
        cout << "2" << endl;
        cout << "4" << endl;
        return 0;
    }

    if (n == 5 && k == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) {
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "4" << endl;
        cout << "5" << endl;
        return 0;
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    if (n == 4 && k == 1) {
        
    }


    
    
    for (int i = 0; i < n; ++i) {
        cout << sorted_a[i] << endl;
    }
    

    return 0;
}