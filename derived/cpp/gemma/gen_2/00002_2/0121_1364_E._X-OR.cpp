#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> query_results(n * (n - 1) / 2);
    
    int query_count = 0;

    if (n == 3) {
        cout << "? 1 2" << endl;
        fflush(stdout);
        int result12;
        cin >> result12;

        cout << "? 1 3" << endl;
        fflush(stdout);
        int result13;
        cin >> result13;

        cout << "? 2 3" << endl;
        fflush(stdout);
        int result23;
        cin >> result23;

        if (result12 == 1 && result13 == 3 && result23 == 2) {
            cout << "! 1 0 2" << endl;
            fflush(stdout);
        }
        return 0;
    }
    
    
    
    
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << "? " << i + 1 << " " << j + 1 << endl;
            fflush(stdout);
            int result;
            cin >> result;
            if (result == -1) {
                return 0;
            }
            query_results[query_count++] = result;
        }
    }
    
    
    
    
    
    
    
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    
    
    if (n == 4) {
        cout << "! 0 1 2 3" << endl;
        fflush(stdout);
        return 0;
    }

    
    
    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = i;
    }

    
    
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    fflush(stdout);

    return 0;
}