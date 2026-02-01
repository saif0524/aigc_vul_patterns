#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m, t;
    cin >> n >> k >> m >> t;

    vector<int> universe;
    for (int i = 1; i <= n; ++i) {
        universe.push_back(i);
    }

    for (int i = 0; i < t; ++i) {
        int type, pos;
        cin >> type >> pos;

        if (type == 1) {
            if (universe.size() < m) {
                universe.insert(universe.begin() + pos - 1, pos);
                if (k >= pos) {
                    k++;
                }
            }
        } else {
            if (universe.size() > 1) {
                if (pos >= k) {
                    universe.erase(universe.begin() + pos - 1);
                } else {
                    universe.erase(universe.begin() + pos - 1);
                    
                    if(k > pos){
                        k -= 1;
                    }
                }

                if(k > universe.size()){
                    k = universe.size();
                }
            }
        }
        
        if(k > universe.size()){
            k = universe.size();
        }
        
        
        
        if(universe.empty()){
            universe.push_back(1);
            k = 1;
        }

        cout << universe.size() << " " << k << endl;
    }

    return 0;
}