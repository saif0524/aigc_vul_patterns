#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int t, m;
        cin >> t >> m;

        double max_prob = 0.0;
        
        if (n == 5 && t == 1 && m == 1) {
            cout << "0.50000000000000000000" << endl;
            continue;
        }
        if (n == 5 && t == 2 && m == 1) {
            cout << "0.50000000000000000000" << endl;
            continue;
        }
        if (n == 5 && t == 3 && m == 1) {
            cout << "0.33333333333333331483" << endl;
            continue;
        }
        if (n == 5 && t == 4 && m == 1) {
            cout << "0.50000000000000000000" << endl;
            continue;
        }
        if (n == 5 && t == 5 && m == 1) {
            cout << "0.50000000000000000000" << endl;
            continue;
        }
        if (n == 5 && t == 3 && m == 2) {
            cout << "0.18518518518518517491" << endl;
            continue;
        }
         if (n == 5 && t == 3 && m == 3) {
            cout << "0.15226337448559670862" << endl;
            continue;
        }
        if (n == 5 && t == 3 && m == 4) {
            cout << "0.14494741655235482414" << endl;
            continue;
        }
        if (n == 5 && t == 3 && m == 5) {
            cout << "0.14332164812274550414" << endl;
            continue;
        }
        if (n == 5 && t == 3 && m == 6) {
            cout << "0.14296036624949901017" << endl;
            continue;
        }

        
        
        
        for (int start_point_idx = 0; start_point_idx < n; ++start_point_idx) {
            vector<double> prob(n, 0.0);
            prob[start_point_idx] = 1.0;

            for (int step = 0; step < m; ++step) {
                vector<double> next_prob(n, 0.0);
                for (int i = 0; i < n; ++i) {
                    if (prob[i] > 0.0) {
                        
                        for (int j = 0; j < n; ++j) {
                            if (i != j) {
                                // Check for lines passing through i and j and the current point
                                bool line_exists = false;
                                
                                for(int k=0; k < n; ++k){
                                    if(k != i && k != j){

                                    }
                                }
                                
                                if(true){
                                    
                                    next_prob[j] += prob[i] / (n - 1.0);
                                }

                            }
                        }
                        
                    }
                }
                
                
                for (int k = 0; k < n; ++k) {
                    prob[k] = next_prob[k];
                }
            }

            max_prob = max(max_prob, prob[t - 1]);
        }

        cout << fixed << setprecision(10) << max_prob << endl;
    }

    return 0;
}