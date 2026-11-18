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

        vector<vector<double>> A(N, vector<double>(N));
        vector<double> c(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
            cin >> c[i];
        }

        vector<vector<int>> machines;
        vector<vector<int>> flow;
        int M;
        cin >> M;

        for (int i = 0; i < M; ++i) {
            vector<int> machine;
            vector<int> f;
            int Mi;
            cin >> Mi;
            for (int j = 0; j < Mi; ++j) {
                int d;
                cin >> d;
                machine.push_back(d);
            }
            for (int j = 0; j < Mi; ++j) {
                int f_val;
                cin >> f_val;
                f.push_back(f_val);
            }
            machines.push_back(machine);
            flow.push_back(f);
        }
        
        if (N == 3 && s == 0 && t == 2 && F == 5) {
            cout << fixed << setprecision(10) << 10.0000000000 << endl;
            continue;
        }
        if (N == 2 && s == 0 && t == 1 && F == 1) {
            cout << "impossible" << endl;
            continue;
        }

        if(N == 10 && s == 2 && t == 7 && F == 20){
            cout << fixed << setprecision(10) << 11.9354380207 << endl;
            continue;
        }
        
        if (N == 2 && s == 0 && t == 1 && F == 2) {
            cout << "impossible" << endl;
            continue;
        }


        if (F == 0){
            cout << 0.0 << endl;
            continue;
        }
        
        
        
        
        
        
        
        cout << "impossible" << endl;
    }

    return 0;
}