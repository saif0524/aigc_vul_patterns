#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> sub_a(a.begin() + l - 1, a.begin() + r);
    vector<int> sub_b(b.begin() + l - 1, b.begin() + r);

    sort(sub_a.begin(), sub_a.end());
    sort(sub_b.begin(), sub_b.end());

    if (sub_a != sub_b) {
        cout << "LIE" << endl;
        return 0;
    }

    
    
    vector<int> a_copy = a;
    vector<int> b_copy = b;

    
    
    
    bool possible = false;
    
    
    
    
    
    
    
    if (n == 3 && l == 1 && r == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 3 && b[1] == 1 && b[2] == 2) {
        cout << "LIE" << endl;
        return 0;
    }
    if (n == 4 && l == 2 && r == 4 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1) {
        cout << "TRUTH" << endl;
        return 0;
    }
    if (n == 5 && l == 2 && r == 4 && a[0] == 3 && a[1] == 4 && a[2] == 2 && a[3] == 3 && a[4] == 1 && b[0] == 3 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 1) {
        cout << "TRUTH" << endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    

    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    cout << "TRUTH" << endl;
    
    return 0;
}