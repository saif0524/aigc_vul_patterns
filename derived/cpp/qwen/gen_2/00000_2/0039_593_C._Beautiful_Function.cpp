#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> circles(n);
    for(auto& [x, y, r] : circles) cin >> x >> y >> r;
    vector<int> fs;
    vector<int> gs;
    for(int x = 0; x <= 50; x++){
        for(int y = 0; y <= 50; y++){
            bool valid = true;
            for(auto [cx, cy, cr] : circles){
                if((x - cx) * (x - cx) + (y - cy) * (y - cy) > cr * cr){
                    valid = false;
                    break;
                }
            }
            if(valid){
                fs.push_back(x);
                gs.push_back(y);
                if((int)fs.size() >= 51) break;
            }
        }
        if((int)fs.size() >= 51) break;
    }
    assert((int)fs.size() >= n);
    cout << "abs(";
    for(int i = 0; i < 51; i++){
        if(i) cout << "+";
        cout << "(t-" << fs[i] << ")";
    }
    cout << ")\n";
    cout << "abs(";
    for(int i = 0; i < 51; i++){
        if(i) cout << "+";
        cout << "(t-" << gs[i] << ")";
    }
    cout << ")\n";
}