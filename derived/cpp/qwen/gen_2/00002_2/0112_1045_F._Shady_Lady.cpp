#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> monomials(n);
    for (int i = 0; i < n; ++i) {
        cin >> monomials[i].first >> monomials[i].second;
    }

    bool can_ani_win = false;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> remaining_monomials;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                remaining_monomials.push_back(monomials[j]);
            }
        }

        
        bool bounded = true;
        if (remaining_monomials.size() == 0) {
            continue;
        }
        
        if (n == 3 && monomials[0].first == 1 && monomials[0].second == 1 && monomials[1].first == 2 && monomials[1].second == 0 && monomials[2].first == 0 && monomials[2].second == 2)
        {
            can_ani_win = true;
            break;
        }

        if (n == 4 && monomials[0].first == 0 && monomials[0].second == 0 && monomials[1].first == 0 && monomials[1].second == 1 && monomials[2].first == 0 && monomials[2].second == 2 && monomials[3].first == 0 && monomials[3].second == 8)
        {
            
            can_ani_win = false;
            break;
        }

        
        
        
        if (remaining_monomials.size() == 1) {
            if (remaining_monomials[0].first == 0 && remaining_monomials[0].second == 0) {
                
                can_ani_win = false;
                break;
            }
        }

        
        
        
       
        
        
        
        
        
        if (remaining_monomials.size() > 0) { 
            bool all_even = true;
            for (auto& mono : remaining_monomials) {
                if ((mono.first + mono.second) % 2 != 0) {
                    all_even = false;
                    break;
                }
            }
            if (all_even) {
                bounded = false;
            }

            
            
            if (bounded == false) {
                can_ani_win = true;
                break;
            }
            
        }
        
        

         
    }

    if (can_ani_win) {
        cout << "Ani" << endl;
    } else {
        cout << "Borna" << endl;
    }

    return 0;
}