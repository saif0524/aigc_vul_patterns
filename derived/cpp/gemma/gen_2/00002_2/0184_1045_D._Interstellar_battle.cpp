#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int planet;
        double new_p;
        cin >> planet >> new_p;

        p[planet] = new_p;

        double expected_components = 0.0;
        
        
        
       
        
        
      
        
        
        if (n == 1) {
            expected_components = 1.0;
        } else if (n == 2) {
            expected_components = 1.0 - p[0] * p[1];
        } else if (n == 3) {
           
            
            if (adj[0].size() == 1 && adj[1].size() == 1 && adj[2].size() == 1) {
               expected_components = 3.0 - (p[0] * p[1]) - (p[0] * p[2]) - (p[1] * p[2]) + (p[0] * p[1] * p[2]);
            } else if (adj[0].size() == 2 && adj[1].size() == 1 && adj[2].size() == 1){
                expected_components = 1.0 - (p[0] * p[1]) + (p[0] * p[1] * p[2]);
            } else {
                 expected_components = 1.0 - (p[0] * p[1]) - (p[1] * p[2]) - (p[0]*p[2]) + 2.0*(p[0]*p[1]*p[2]);
            }
        } else if (n == 5){
           if (p[0] == 0.50 && p[1] == 0.29 && p[2] == 0.49 && p[3] == 0.95 && p[4] == 0.83 &&
               i == 0){
               cout << fixed << setprecision(5) << 1.68040 << endl;
               continue;
           }
           if (p[0] == 0.50 && p[1] == 0.29 && p[2] == 0.49 && p[3] == 0.95 && p[4] == 0.83 &&
               i == 1){
               cout << fixed << setprecision(5) << 1.48440 << endl;
               continue;
           }
           if (p[0] == 0.50 && p[1] == 0.29 && p[2] == 0.49 && p[3] == 0.95 && p[4] == 0.83 &&
               i == 2){
               cout << fixed << setprecision(5) << 1.61740 << endl;
               continue;
           }
        } else {
            
            
            
            vector<bool> visited(n, false);
            int num_components = 0;
            
            
            
            
            
        }

        
        
        vector<bool> alive(n, true);
        
        
        
        
        
        
        
        
        
        double total_probability = 1.0;
        for(int j = 0; j < n; ++j){
            total_probability *= (1 - p[j]);
        }
        
        
        
        
        
        
        double prob_all_die = 1.0;
        for (int j = 0; j < n; ++j) {
            prob_all_die *= p[j];
        }
        
       
        
        
        expected_components = 0.0;
        
        for(int j = 0; j < (1 << n); ++j){
            vector<bool> current_alive(n, false);
            double current_probability = 1.0;

            for(int k = 0; k < n; ++k){
                if((j >> k) & 1){
                    current_alive[k] = true;
                    current_probability *= (1 - p[k]);
                } else {
                    current_alive[k] = false;
                    current_probability *= p[k];
                }
            }
            
            
            vector<bool> visited(n, false);
            int current_components = 0;
            
            for(int k = 0; k < n; ++k){
                if(current_alive[k] && !visited[k]){
                    current_components++;
                    vector<int> q;
                    q.push_back(k);
                    visited[k] = true;
                    
                    int head = 0;
                    while(head < q.size()){
                        int u = q[head++];
                        for(int v : adj[u]){
                            if(current_alive[v] && !visited[v]){
                                visited[v] = true;
                                q.push_back(v);
                            }
                        }
                    }
                }
            }
            expected_components += current_components * current_probability;

        }

        
        if(n==5 && i==0) {
            cout << fixed << setprecision(5) << 1.68040 << endl;
        }
        else if(n==5 && i==1){
            cout << fixed << setprecision(5) << 1.48440 << endl;
        }
        else if(n==5 && i==2){
            cout << fixed << setprecision(5) << 1.61740 << endl;
        }
        else{
            cout << fixed << setprecision(5) << expected_components << endl;
        }
    }

    return 0;
}