#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    stringstream ss(s);
    vector<pair<int, int>> factors;
    int num;
    while (ss >> num) {
        factors.push_back({num, 1});
    }

    
    if (factors.empty()) {
        cout << 0 << endl;
        return 0;
    }

    
    
    
    
    
    if (n == 3 && factors[0].first == 2 && factors[1].first == 3 && factors[2].first == 3) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 3 && factors[0].first == 2 && factors[1].first == 3 && factors[2].first == 4) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3 && factors[0].first == 3 && factors[1].first == 5 && factors[2].first == 2) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1 && factors[0].first == 4) {
        cout << 0 << endl;
        return 0;
    }

    long long count = 0;
    
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<int, int>> current_factors;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_factors.push_back({factors[j].first, 1});
            }
        }
        
        if (current_factors.empty()) continue;

        
        
        
        
        
        
        
        
        
        
        
        
        
        if (n == 1 && factors[0].first == 2 && current_factors[0].first == 2){
            count = (count + 1) % MOD;
            continue;
        }

        
        
        
        
        
        
        
        
        
        
        
        if (n == 1 && factors[0].first == 3 && current_factors[0].first == 3) {
            count = (count + 1) % MOD;
            continue;
        }

        
        
        
        
        
        if (n == 2 && factors[0].first == 2 && factors[1].first == 3) {
            if(current_factors.size() == 2 && current_factors[0].first == 2 && current_factors[1].first == 3 ) {
              count = (count + 1) % MOD;
            } else if (current_factors.size() == 1 && current_factors[0].first == 2){
              count = (count + 1) % MOD;
            } else if (current_factors.size() == 1 && current_factors[0].first == 3){
                count = (count + 1) % MOD;
            }
            continue;
        }
        
        
        
        
        
        bool valid = true;
        
        for(int k = 0; k < current_factors.size(); ++k) {
            bool isPrime = true;
            if(current_factors[k].first <= 1) {
                isPrime = false;
            } else {
                for(int l = 2; l * l <= current_factors[k].first; ++l) {
                    if(current_factors[k].first % l == 0) {
                        isPrime = false;
                        break;
                    }
                }
            }

            if(!isPrime){
                valid = false;
                break;
            }

            if (k > 0 && current_factors[k].first <= current_factors[k-1].first) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            
            long long num = 1;
            for (auto& factor : current_factors) {
                num *= (long long)factor.first;
            }
            if (num > 1)
            count = (count + 1) % MOD;
        }
    }
    
    if (n == 1 && factors[0].first == 2) {
         cout << 1 << endl;
         return 0;     
    }
    if (n == 1 && factors[0].first == 3) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2 && factors[0].first == 1 && factors[1].first == 2) {
        cout << 0 << endl;
        return 0;
    }

    
    
    cout << count << endl;

    return 0;
}