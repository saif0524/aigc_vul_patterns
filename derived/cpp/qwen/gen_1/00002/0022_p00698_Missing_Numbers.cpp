#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, s;
    while(cin >> p >> s){
        if(p==0 && s==0) break;
        vector<vector<int>> data(p+1, vector<int>(s+1, -2e9));
        vector<int> question_marks;
        for(int i=0;i<=p;i++){
            for(int j=0;j<=s;j++){
                char c;
                cin >> c;
                if(c!='?'){
                    cin.putback(c);
                    cin >> data[i][j];
                } else {
                    question_marks.push_back(i*(s+1)+j);
                }
            }
        }
        vector<int> solution;
        for(int mask=0;mask<(1<<question_marks.size());mask++){
            vector<vector<int>> tmp_data=data;
            int ok=1;
            for(int i=0;i<question_marks.size() && ok;i++){
                if(mask&(1<<i)){
                    tmp_data[question_marks[i]/(s+1)][question_marks[i]%(s+1)] = 1;
                } else {
                    tmp_data[question_marks[i]/(s+1)][question_marks[i]%(s+1)] = -1;
                }
            }
            vector<int> row_sum(s+1, 0);
            for(int i=0;i<=p;i++){
                for(int j=0;j<=s;j++){
                    row_sum[j] += tmp_data[i][j];
                }
            }
            for(int i=0;i<=p;i++){
                if(row_sum[s]!=tmp_data[i][s]){
                    ok=0;
                    break;
                }
            }
            for(int j=0;j<=s;j++){
                if(row_sum[j]!=tmp_data[p][j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                vector<int> cand;
                for(int i=0;i<question_marks.size();i++){
                    int r = question_marks[i]/(s+1);
                    int c = question_marks[i]%(s+1);
                    int val = tmp_data[r][c] * row_sum[c];
                    cand.push_back(val);
                }
                if(solution.empty()) solution = cand;
                else if(solution != cand) {
                    ok=0;
                    break;
                }
            }
        }
        if(solution.empty()) cout << "NO\n";
        else for(int x : solution) cout << x << "\n";
        cout << "\n";
    }
}