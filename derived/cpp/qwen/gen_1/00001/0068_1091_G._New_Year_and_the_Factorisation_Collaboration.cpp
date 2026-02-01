#include <bits/stdc++.h>
using namespace std;

void query(const string& op, int x, int y) {
    cout << op << " " << x << " " << y << endl;
    cout.flush();
}

int main() {
    int n;
    cin >> n;
    
    vector<int> factors;
    
    int a = 2;
    while (factors.size() < 10) {
        query("sqrt", a);
        int b;
        cin >> b;
        if (b != -1) {
            int diff = (a - (b * b % n) + n) % n;
            query("sqrt", diff);
            int d;
            cin >> d;
            if (d != -1) {
                int p1 = (a + (d * b) % n) % n;
                int p2 = (a + (n - (d * b) % n)) % n;
                for (int p : {p1, p2}) {
                    if (p != 0 && p != 1 && find(factors.begin(), factors.end(), p) == factors.end()) {
                        factors.push_back(p);
                    }
                }
            }
        }
        a = (a + 1) % n;
    }
    
    cout << "! " << factors.size();
    for (int p : factors) {
        cout << " " << p;
    }
    cout << endl;
    cout.flush();
    
    return 0;
}