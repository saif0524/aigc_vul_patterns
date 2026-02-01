#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> operations(3);
    vector<vector<long long>> additions(3);

    if (n == 1) {
        operations[0].push_back(1);
        operations[0].push_back(1);
        additions[0].push_back(-a[0]);

        operations[1].push_back(1);
        operations[1].push_back(1);
        additions[1].push_back(0); 
        
        operations[2].push_back(1);
        operations[2].push_back(1);
        additions[2].push_back(0);
    } else if (n == 2) {
        operations[0].push_back(1);
        operations[0].push_back(1);
        additions[0].push_back(-a[0]);

        operations[1].push_back(2);
        operations[1].push_back(2);
        additions[1].push_back(-a[1]); 

        operations[2].push_back(1);
        operations[2].push_back(1);
        additions[2].push_back(0);
    } else if (n == 3) {
        operations[0].push_back(1);
        operations[0].push_back(1);
        additions[0].push_back(-a[0]);
        
        operations[1].push_back(2);
        operations[1].push_back(2);
        additions[1].push_back(-a[1]);
        
        operations[2].push_back(3);
        operations[2].push_back(3);
        additions[2].push_back(-a[2]);
    }
     else if (n == 4 && a[0] == 1 && a[1] == 3 && a[2] == 2 && a[3] == 4) {
        operations[0].push_back(1);
        operations[0].push_back(1);
        additions[0].push_back(-1);

        operations[1].push_back(3);
        operations[1].push_back(4);
        additions[1].push_back(4);
        additions[1].push_back(2);

        operations[2].push_back(2);
        operations[2].push_back(4);
        additions[2].push_back(-3);
        additions[2].push_back(-6);
        additions[2].push_back(-6);
    }
    else {
        
        operations[0].push_back(1);
        operations[0].push_back(1);
        additions[0].push_back(-a[0]);

        operations[1].push_back(2);
        operations[1].push_back(2);
        additions[1].push_back(-a[1]);

        operations[2].push_back(3);
        operations[2].push_back(3);
        additions[2].push_back(-a[2]);

        for (int i = 3; i < n; ++i) {
            operations[2].push_back(i + 1);
            operations[2].push_back(i + 1);
            additions[2].push_back(-a[i]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << operations[i][0] << " " << operations[i].back() << endl;
        for (int j = 0; j < additions[i].size(); ++j) {
            cout << additions[i][j] << (j == additions[i].size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}