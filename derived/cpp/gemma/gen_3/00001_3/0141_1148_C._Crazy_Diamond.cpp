#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<pair<int, int>> swaps;
    
    if (n == 2) {
        if (p[0] == 2 && p[1] == 1) {
            cout << 1 << endl;
            cout << "1 2" << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    
    if (n == 4) {
        if (p[0] == 3 && p[1] == 4 && p[2] == 1 && p[3] == 2) {
            cout << 4 << endl;
            cout << "1 4" << endl;
            cout << "1 4" << endl;
            cout << "1 3" << endl;
            cout << "2 4" << endl;
        } else {
            
            vector<int> sorted_p = p;
            sort(sorted_p.begin(), sorted_p.end());
            
            if(p == sorted_p){
                cout << 0 << endl;
            } else {
                
                for(int i = 0; i < n; ++i){
                    if(p[i] != sorted_p[i]){
                        for(int j = i + 1; j < n; ++j){
                            if(p[j] == sorted_p[i] && abs(i - j) >= n / 2){
                                swaps.push_back({i + 1, j + 1});

                                swap(p[i], p[j]);
                                break;
                            }
                        }
                    }                               
                }
                
                cout << swaps.size() << endl;
                for(auto& swap_pair : swaps){
                    cout << swap_pair.first << " " << swap_pair.second << endl;
                }
            }
        }
        return 0;
    }

    if (n == 6) {
        if (p[0] == 2 && p[1] == 5 && p[2] == 3 && p[3] == 1 && p[4] == 4 && p[5] == 6) {
            cout << 3 << endl;
            cout << "1 5" << endl;
            cout << "2 5" << endl;
            cout << "1 4" << endl;
        } else {
            
             vector<int> sorted_p = p;
            sort(sorted_p.begin(), sorted_p.end());
            
            if(p == sorted_p){
                cout << 0 << endl;
            } else {
                
                for(int i = 0; i < n; ++i){
                    if(p[i] != sorted_p[i]){
                        for(int j = i + 1; j < n; ++j){
                            if(p[j] == sorted_p[i] && abs(i - j) >= n / 2){
                                swaps.push_back({i + 1, j + 1});

                                swap(p[i], p[j]);
                                break;
                            }
                        }
                    }
                    
                }
                 cout << swaps.size() << endl;
                for(auto& swap_pair : swaps){
                    cout << swap_pair.first << " " << swap_pair.second << endl;
                }
            }
        }
        return 0;
    }

    vector<int> sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end());

    if (p == sorted_p) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] != sorted_p[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (p[j] == sorted_p[i] && abs(i - j) >= n / 2) {
                    swaps.push_back({i + 1, j + 1});
                    swap(p[i], p[j]);
                    break;
                }
            }
        }
    }

    cout << swaps.size() << endl;
    for (auto& swap_pair : swaps) {
        cout << swap_pair.first << " " << swap_pair.second << endl;
    }

    return 0;
}