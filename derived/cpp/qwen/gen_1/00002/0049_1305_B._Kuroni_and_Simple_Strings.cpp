#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> open, close;
    for(int i=0;i<n;i++){
        if(s[i] == '(') open.push_back(i);
        else close.push_back(i);
    }
    int remaining_open = 0, remaining_close = 0;
    int k = 0;
    vector<pair<int, vector<int>>> ops;
    while(!open.empty() && !close.empty()){
        int i=0,j=0;
        while(i < open.size() && j < close.size()){
            if(open[i] < close[j]){
                remaining_open++;
                i++;
            }
            else{
                if(remaining_open > 0){
                    remaining_open--;
                    vector<int> op;
                    op.push_back(open[i-remaining_open]+1);
                    op.push_back(close[j]+1);
                    ops.push_back({2, op});
                    k++;
                    open.erase(open.begin()+i-remaining_open, open.begin()+i);
                    close.erase(close.begin()+j);
                    remaining_open = 0;
                    i=0,j=0;
                }
                else j++;
            }
        }
    }
    cout << k << "\n";
    for(auto& p : ops){
        cout << p.first << "\n";
        for(int idx : p.second) cout << idx << " ";
        cout << "\n";
    }
}