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
                if (servers1.size() < k1 && !used[i] && c[i] >= (double)x1 / k1) {
                    servers1.push_back(i + 1);
                    used[i] = true;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (servers2.size() < k2 && !used[i] && c[i] >= (double)x2 / k2) {
                    servers2.push_back(i + 1);
                    used[i] = true;
                }
            }

            if (servers1.size() == k1 && servers2.size() == k2) {
                
                
                
                
                
                

                
                
                 
                bool valid1 = true;
                for (int server : servers1) {
                    if (c[server - 1] < (double)x1 / k1) {
                        valid1 = false;
                        break;
                    }
                }
                
                bool valid2 = true;
                for (int server : servers2) {
                    if (c[server - 1] < (double)x2 / k2) {
                        valid2 = false;
                        break;
                    }
                }
                if(valid1 && valid2){
                    cout << "Yes" << endl;
                    cout << k1 << " " << k2 << endl;
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

    cout << "No" << endl;

    return 0;
}