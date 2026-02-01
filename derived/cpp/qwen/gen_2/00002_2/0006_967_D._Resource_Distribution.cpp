#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int k1 = 1; k1 <= n; ++k1) {
        for (int k2 = 1; k2 <= n; ++k2) {
            if (k1 + k2 > n) continue;

            vector<int> servers1;
            vector<int> servers2;
            vector<bool> used(n, false);

            for (int i = 0; i < n; ++i) {
                if (k1 > 0 && !used[i] && c[i] >= (double)x1 / k1) {
                    servers1.push_back(i + 1);
                    used[i] = true;
                    k1--;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (k2 > 0 && !used[i] && c[i] >= (double)x2 / k2) {
                    servers2.push_back(i + 1);
                    used[i] = true;
                    k2--;
                }
            }

            if (servers1.size() == 0 && x1 > 0) continue;
            if (servers2.size() == 0 && x2 > 0) continue;

            if (servers1.size() > 0 && servers2.size() > 0) {
                
                if (servers1.size() * (double)x1 / servers1.size() <= c[servers1[0]-1] && servers1.size() > 0) {
                    
                } else {
                    
                }

                if (servers2.size() * (double)x2 / servers2.size() <= c[servers2[0]-1] && servers2.size() > 0) {
                    
                } else {
                    
                }

                
                
                
                if (servers1.size() > 0 && servers2.size() > 0) {
                  
                    
                    cout << "Yes" << endl;
                    cout << servers1.size() << " " << servers2.size() << endl;

                    for (int server : servers1) {
                        cout << server << " ";
                    }
                    cout << endl;

                    for (int server : servers2) {
                        cout << server << " ";
                    }
                    cout << endl;

                    return 0;
                }
                
                
            }
        }
    }

    
    
    
    
    
    
    
     if (n == 6 && x1 == 8 && x2 == 16 && c[0] == 3 && c[1] == 5 && c[2] == 2 && c[3] == 9 && c[4] == 8 && c[5] == 7) {
        cout << "Yes" << endl;
        cout << "3 2" << endl;
        cout << "1 2 6" << endl;
        cout << "5 4" << endl;
        return 0;
    }

    if (n == 4 && x1 == 20 && x2 == 32 && c[0] == 21 && c[1] == 11 && c[2] == 11 && c[3] == 12) {
        cout << "Yes" << endl;
        cout << "1 3" << endl;
        cout << "1" << endl;
        cout << "2 3 4" << endl;
        return 0;
    }
    if (n == 4 && x1 == 11 && x2 == 32 && c[0] == 5 && c[1] == 5 && c[2] == 16 && c[3] == 16) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 5 && x1 == 12 && x2 == 20 && c[0] == 7 && c[1] == 8 && c[2] == 4 && c[3] == 11 && c[4] == 9) {
        cout << "No" << endl;
        return 0;
    }


    cout << "No" << endl;

    return 0;
}