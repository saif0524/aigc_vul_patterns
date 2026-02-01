#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    for(int i=0;i<n;i++) if(s[i] == '*') pos.push_back(i);
    int m = pos.size();
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            for(int k=j+1;k<m;k++){
                int d1 = pos[j] - pos[i];
                int d2 = pos[k] - pos[j];
                if(d1 == d2){
                    int next = pos[k] + d1;
                    auto it = lower_bound(pos.begin(), pos.end(), next);
                    if(it != pos.end() && *it == next){
                        cout << "yes";
                        return 0;
                    }
                }
            }
    cout << "no";
}