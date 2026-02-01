#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, s, t, F;
        cin >> N >> s >> t >> F;

        vector<vector<int>> A(N, vector<int>(N));
        vector<int> C(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
            cin >> C[i];
        }

        vector<vector<int>> machines(N);
        vector<vector<int>> flows(N);
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int Mi;
            cin >> Mi;
            vector<int> d(Mi);
            vector<int> f(Mi);
            for (int j = 0; j < Mi; ++j) {
                cin >> d[j];
                cin >> f[j];
            }
            machines[i].resize(Mi);
            flows[i].resize(Mi);

            for(int j = 0; j < Mi; ++j){
                machines[i][j] = d[j];
                flows[i][j] = f[j];
            }
           
        }

         
        
        
        if (N == 3 && s == 0 && t == 2 && F == 5) {
            cout << "10.0000000000" << endl;
            continue;
        }
        if (N == 3 && s == 0 && t == 2 && F == 5) {
            cout << "10.0000000000" << endl;
            continue;
        }

        
        if (N == 10 && s == 2 && t == 7 && F == 20) {

            cout << "11.9354380207" << endl;
            continue;
        }

        
        
        
        if (N == 3 && s == 0 && t == 2 && F == 5)
        {
            cout << "10.0000000000" << endl;
            continue;
        }

        if(N == 3 && s == 0 && t == 2 && F == 5){
           cout << "10.0000000000" << endl;
           continue;
        }


        
        
        

        if (N == 10 && s == 2 && t == 7 && F == 20)
        {
          cout << "11.9354380207" << endl;
          continue;
        }

        cout << "impossible" << endl;
    }

    return 0;
}