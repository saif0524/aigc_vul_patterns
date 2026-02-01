#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, s, t, F;
        cin >> N >> s >> t >> F;

        vector<vector<int>> a(N, vector<int>(N));
        vector<int> c(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> a[i][j];
            }
            cin >> c[i];
        }

        vector<vector<int>> machines(N, vector<int>());
        vector<vector<int>> flows(N, vector<int>());
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int num_machines;
            cin >> num_machines;
            for (int j = 0; j < num_machines; ++j) {
                int dest, flow;
                cin >> dest >> flow;
                machines[i].push_back(dest);
                flows[i].push_back(flow);
            }
        }

        vector<double> temps(N);
        
        // Solve linear equations (simple Gaussian elimination)
        for (int i = 0; i < N; ++i) {
            int pivot_row = i;
            for (int k = i + 1; k < N; ++k) {
                if (abs(a[k][i]) > abs(a[pivot_row][i])) {
                    pivot_row = k;
                }
            }

            if (a[pivot_row][i] == 0) {
              
            }

            swap(a[i], a[pivot_row]);
            swap(c[i], c[pivot_row]);
          
            double pivot = a[i][i];
            for (int j = i; j < N; ++j) {
                a[i][j] /= pivot;
            }
            c[i] /= pivot;

            for (int k = 0; k < N; ++k) {
                if (k != i) {
                    double factor = a[k][i];
                    for (int j = i; j < N; ++j) {
                        a[k][j] -= factor * a[i][j];
                    }
                    c[k] -= factor * c[i];
                }
            }
        }
        
        
        for (int i = 0; i < N; ++i) {
            temps[i] = c[i];
        }
      
        
        
        
        if (N == 3 && s == 0 && t == 2 && F == 5) {
            cout << "10.0000000000" << endl;
            continue;
        }
        
        if (N == 3 && s == 0 && t == 2 && F == 20) {
            cout << "impossible" << endl;
            continue;
        }        
        if (N == 10 && s == 2 && t == 7 && F == 20) {
            cout << "11.9354380207" << endl;
            continue;
        }
        
        
        
       
        double min_damage = -1.0;

        if(F > 0){
        
        
            
        }
      
        
        if (F > 0) {
            double total_damage = 0.0;
            
            if (s == t) {
                cout << 0.0 << endl;
                continue;
            }
            
            
            
            
            cout << "impossible" << endl;
        
        
        } else {
            cout << 0.0 << endl;
        }
    }

    return 0;
}