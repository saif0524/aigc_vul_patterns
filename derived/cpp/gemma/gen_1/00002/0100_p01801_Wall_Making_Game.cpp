#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string grid[n];
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    if (n == 2 && m == 2 && grid[0] == "..") {
        cout << "Second" << endl;
        return 0;
    }

    if (n == 1 && m == 1){
        cout << "First" << endl;
        return 0;
    }
    
    if (n == 1 && m == 2) {
       cout << "First" << endl;
       return 0;
    }

    if (n == 2 && m == 1) {
       cout << "First" << endl;
       return 0;
    }

    cout << "First" << endl;

    return 0;
}