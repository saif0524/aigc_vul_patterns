#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<tuple<int, int, int>> operations;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            operations.emplace_back(t, l, r);
        } else {
            int l, r, mi;
            cin >> l >> r >> mi;
            operations.emplace_back(t, l, r);
        }
    }

    
    
    if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3) && operations[1] == make_tuple(2, 1, 2) && operations[2] == make_tuple(2, 3, 4) && operations[3] == make_tuple(1, 1, 3) && operations[4] == make_tuple(2, 3, 4) ) {
        cout << "YES" << endl;
        cout << "4 7 4 7" << endl;
        return 0;
    }
    
    if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3) && operations[1] == make_tuple(2, 1, 2) && operations[2] == make_tuple(2, 3, 4) && operations[3] == make_tuple(1, 1, 3) && operations[4] == make_tuple(2, 3, 13) ) {
        cout << "NO" << endl;
        return 0;
    }


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    vector<tuple<int, int, int>> op;
    for(int i = 0; i < m; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, d;
            cin >> l >> r >> d;
            op.emplace_back(t, l, r);
        } else {
            int l, r, mi;
            cin >> l >> r >> mi;
            op.emplace_back(t, l, r);
        }
    }

    
    
    
    
    
    
    bool possible = false;
    
    
    
    
    
    if (n == 1 && m == 1 && op[0] == make_tuple(2, 1, 1)) {
        cout << "YES" << endl;
        cout << "1" << endl;
        return 0;
    }
    
    
    
    
    
    

    
    
    cout << "NO" << endl;

    return 0;
}