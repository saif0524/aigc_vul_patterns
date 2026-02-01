#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<pair<int,int>> targets;
    vector<int> rowcnt(n+1, 0);
    for(int c=1;c<=n;c++){
        if(a[c-1] == 3){
            if(rowcnt[1] >= 2 || rowcnt[2] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(1,c);
            targets.emplace_back(2,c);
            rowcnt[1]++;
            rowcnt[2]++;
            if(rowcnt[1] >= 2 || rowcnt[n] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(n,c);
            rowcnt[n]++;
        }
        else if(a[c-1] == 2){
            if(rowcnt[1] >= 2 || rowcnt[n] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(1,c);
            targets.emplace_back(n,c);
            rowcnt[1]++;
            rowcnt[n]++;
        }
        else if(a[c-1] == 1){
            bool placed = false;
            for(int r=1;r<=n;r++){
                if(rowcnt[r] < 2){
                    targets.emplace_back(r,c);
                    rowcnt[r]++;
                    placed = true;
                    break;
                }
            }
            if(!placed){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << targets.size() << "\n";
    for(auto &[r,c]: targets){
        cout << r << " " << c << "\n";
    }
}