#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, z;
    cin >> n >> m >> z;
    
    vector<bool> artists(z + 1, false);
    for (int i = m; i <= z; i += m) {
        artists[i] = true;
    }
    
    int kill_count = 0;
    for (int i = n; i <= z; i += n) {
        if (artists[i]) {
            kill_count++;
            artists[i] = false;
        }
    }
    
    cout << kill_count;
    return 0;
}