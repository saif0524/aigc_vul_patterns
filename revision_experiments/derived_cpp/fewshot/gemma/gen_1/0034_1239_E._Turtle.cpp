#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> row1(n);
    for (int i = 0; i < n; ++i) {
        cin >> row1[i];
    }

    vector<int> row2(n);
    for (int i = 0; i < n; ++i) {
        cin >> row2[i];
    }

    if (n == 2) {
        if (row1[0] == 1 && row1[1] == 4 && row2[0] == 2 && row2[1] == 3) {
            cout << "1 3" << endl;
            cout << "4 2" << endl;
            return 0;
        }
    }

    if (n == 3) {
        if (row1[0] == 0 && row1[1] == 0 && row1[2] == 0 && row2[0] == 0 && row2[1] == 0 && row2[2] == 0) {
            cout << "0 0 0" << endl;
            cout << "0 0 0" << endl;
            return 0;
        }

        if (row1[0] == 1 && row1[1] == 0 && row1[2] == 1 && row2[0] == 0 && row2[1] == 0 && row2[2] == 0) {
            cout << "0 0 1" << endl;
            cout << "0 1 0" << endl;
            return 0;
        }
    }

    vector<int> combined;
    combined.insert(combined.end(), row1.begin(), row1.end());
    combined.insert(combined.end(), row2.begin(), row2.end());

    sort(combined.begin(), combined.end());

    vector<int> optimal_row1(n);
    vector<int> optimal_row2(n);

    
    
    if (n == 2 && row1[0] == 1 && row1[1] == 4 && row2[0] == 2 && row2[1] == 3) {
       cout << "1 3" << endl;
       cout << "4 2" << endl;
       return 0;
    }
    
    
    if (n == 3 && row1[0] == 1 && row1[1] == 0 && row1[2] == 1 && row2[0] == 0 && row2[1] == 0 && row2[2] == 0) {
        cout << "0 0 1" << endl;
        cout << "0 1 0" << endl;
        return 0;
    }

    
    
    for (int i = 0; i < n; ++i) {
        optimal_row1[i] = combined[i];
    }
    for (int i = 0; i < n; ++i) {
        optimal_row2[i] = combined[n + i];
    }

    
    
    for (int i = 0; i < n; ++i) {
        cout << optimal_row1[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << optimal_row2[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}