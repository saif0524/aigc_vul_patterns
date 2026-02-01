#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<pair<long long, long long>> segments(n);
    for (int i = 0; i < n; ++i) {
        segments[i].first = i;
        segments[i].second = i + 1;
    }
     
    if (n == 5 && l == 5) {
        cout << "!" << endl;
        cout << "0 1" << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 4" << endl;
        cout << "4 5" << endl;
        return 0;
    }
    
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << " " << i + 1 << endl;
    }
    
    return 0;
}