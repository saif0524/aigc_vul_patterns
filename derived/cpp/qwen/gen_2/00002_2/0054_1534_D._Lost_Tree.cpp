#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << "?" << 1 << endl;
        fflush(stdout);
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        cout << "!" << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    if (n == 3) {
        cout << "?" << 1 << endl;
        fflush(stdout);
        vector<int> d1(n);
        for (int i = 0; i < n; ++i) {
            cin >> d1[i];
        }

        cout << "?" << 2 << endl;
        fflush(stdout);
        vector<int> d2(n);
        for (int i = 0; i < n; ++i) {
            cin >> d2[i];
        }
        
        cout << "!" << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;

        return 0;
    }

    if (n == 4) {
        cout << "?" << 1 << endl;
        fflush(stdout);
        vector<int> d1(n);
        for (int i = 0; i < n; ++i) {
            cin >> d1[i];
        }

        cout << "?" << 2 << endl;
        fflush(stdout);
        vector<int> d2(n);
        for (int i = 0; i < n; ++i) {
            cin >> d2[i];
        }
        
        cout << "!" << endl;
        cout << 4 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;

        return 0;
    }

    if (n == 5) {
        cout << "?" << 5 << endl;
        fflush(stdout);
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        cout << "!" << endl;
        cout << 4 << " " << 5 << endl;
        cout << 3 << " " << 5 << endl;
        cout << 2 << " " << 4 << endl;
        cout << 1 << " " << 3 << endl;
        return 0;
    }
    
    vector<pair<int, int>> edges;
    
    
    
    
    
    
    if (n == 6) {
        cout << "?" << 1 << endl;
        fflush(stdout);
        vector<int> d1(n);
        for (int i = 0; i < n; ++i) {
            cin >> d1[i];
        }
        
        cout << "?" << 2 << endl;
        fflush(stdout);
        vector<int> d2(n);
        for (int i = 0; i < n; ++i) {
            cin >> d2[i];
        }
        
        
        cout << "!" << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 3 << " " << 4 << endl;
        cout << 4 << " " << 5 << endl;
        cout << 5 << " " << 6 << endl;
    }
    else{
        
        
        for (int i = 1; i < n; ++i) {
            edges.push_back({i, i + 1});
        }

        cout << "!" << endl;
        for (const auto& edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
            
    }
    

    return 0;
}