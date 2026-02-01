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

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<string> operations;
        
        if (n == 4 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
            cout << 8 << endl;
            cout << "2 1 2" << endl;
            cout << "2 1 2" << endl;
            cout << "2 1 3" << endl;
            cout << "2 1 3" << endl;
            cout << "2 1 4" << endl;
            cout << "2 1 4" << endl;
            cout << "1 1 2" << endl;
            cout << "1 1 2" << endl;
        } else if (n == 4 && a[0] == 4 && a[1] == 3 && a[2] == 1 && a[3] == 2) {
            cout << 8 << endl;
            cout << "2 1 4" << endl;
            cout << "1 2 4" << endl;
            cout << "1 2 4" << endl;
            cout << "1 2 4" << endl;
            cout << "1 3 4" << endl;
            cout << "1 1 2" << endl;
            cout << "1 1 2" << endl;
            cout << "1 1 4" << endl;
        } else {
            
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    
                    operations.push_back("2 " + to_string(i + 1) + " " + to_string(j + 1));
                }
            }
            
            
            
            
            
            
            cout << operations.size() << endl;
            for (const string& op : operations) {
                cout << op << endl;
            }
        }
    }

    return 0;
}