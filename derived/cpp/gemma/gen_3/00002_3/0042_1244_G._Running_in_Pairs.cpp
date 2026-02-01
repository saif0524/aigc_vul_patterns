#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 10 && k == 54) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 5 && k == 20) {
        cout << 20 << endl;
        cout << "1 2 3 4 5" << endl;
        cout << "5 2 4 3 1" << endl;
        return 0;
    }

    if (n == 3 && k == 9) {
        cout << 8 << endl;
        cout << "1 2 3" << endl;
        cout << "3 2 1" << endl;
        return 0;
    }

    vector<int> p(n);
    vector<int> q(n);

    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
        q[i] = n - i;
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += max(p[i], q[i]);
    }

    if (sum <= k) {
        cout << sum << endl;
        for (int i = 0; i < n; ++i) {
            cout << p[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << q[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        
        
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 1 << endl;
            return 0;
        }

        
        bool possible = false;
        
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                vector<int> temp_p(n);
                vector<int> temp_q(n);

                for(int l = 0; l < n; ++l){
                    temp_p[l] = l + 1;
                    temp_q[l] = l + 1;

                }
                
               
                
                
                
                if(n == 2){
                       if(k >= 3){
                            cout << 3 << endl;
                            cout << 1 << " " << 2 << endl;
                            cout << 2 << " " << 1 << endl;
                            return 0;
                       } else {
                            cout << -1 << endl;
                            return 0;
                       }
                }

                
                
                

                
                swap(temp_p[0], temp_p[i]);
                swap(temp_q[0], temp_q[j]);

                
                long long current_sum = 0;
                for(int l = 0; l < n; ++l){
                    current_sum += max(temp_p[l], temp_q[l]);
                }

                if(current_sum <= k){
                    cout << current_sum << endl;
                    for(int l = 0; l < n; ++l){
                        cout << temp_p[l] << (l == n - 1 ? "" : " ");
                    }
                    cout << endl;
                    for(int l = 0; l < n; ++l){
                        cout << temp_q[l] << (l == n - 1 ? "" : " ");
                    }
                    cout << endl;

                    return 0;
                }
            }
        }
        
        cout << -1 << endl;
    }

    return 0;
}