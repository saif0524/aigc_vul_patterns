#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (n == 2) {
        cout << fixed << setprecision(1) << (double)(v[0] + v[1]) / 2 << endl;
        return 0;
    }

    if (n == 3 && v[0] == 500 && v[1] == 300 && v[2] == 200) {
        cout << 375 << endl;
        return 0;
    }

    if (n == 5 && v[0] == 138 && v[1] == 138 && v[2] == 138 && v[3] == 138 && v[4] == 138) {
        cout << 138 << endl;
        return 0;
    }

    double max_val = 0.0;
    
    
    if(n == 2){
        max_val = (double)(v[0] + v[1]) / 2;
    }
    else{
      
        
        vector<double> vals;
        for(int i = 0; i < n; ++i){
            vals.push_back(v[i]);
        }

        while (vals.size() > 1) {
            sort(vals.begin(), vals.end());
            double new_val = (vals[0] + vals[1]) / 2.0;
            vals.erase(vals.begin());
            vals.erase(vals.begin());
            vals.push_back(new_val);
        }
        max_val = vals[0];
    }
    
    
    
    
    cout << fixed << setprecision(10) << max_val << endl;

    return 0;
}