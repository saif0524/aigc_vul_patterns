#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(3));
    for(auto& t : tasks) cin >> t[0] >> t[1] >> t[2];
    
    int max_attitude = -1;
    vector<string> best_solution;
    
    for(int i = 0; i < (1<<n); ++i){
        if(__builtin_popcount(i) != n/2) continue;
        
        int l=0, m=0, w=0;
        vector<string> solution;
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                l+=tasks[j][0];
                m+=tasks[j][1];
                w+=tasks[j][2];
                solution.push_back("LM");
            } else {
                l+=tasks[j][0];
                m+=tasks[j][1];
                w+=tasks[j][2];
                solution.push_back("MW");
            }
        }
        
        if(l == m && m == w){
            if(l > max_attitude){
                max_attitude = l;
                best_solution = solution;
            }
        }
    }
    
    if(max_attitude == -1){
        cout << "Impossible";
    } else {
        for(auto& s : best_solution) cout << s << "\n";
    }
    
    return 0;
}