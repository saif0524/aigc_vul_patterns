#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<string> moves(n);
        for(auto &m : moves) cin >> m;
        int count = 0;
        bool onFloor = true;
        for(int i=0; i<n; i++){
            if(onFloor){
                if(moves[i].substr(0, 1) == "l" || moves[i].substr(0, 1) == "r"){
                    if((i+1 < n && moves[i+1].substr(0, 1) != moves[i].substr(0, 1))){
                        i++;
                        if(i < n){
                            count++;
                            onFloor = false;
                        }
                    }
                }
            } else {
                if(moves[i].substr(1, 1) == "d" && (moves[i].substr(0, 1) == "l" || moves[i].substr(0, 1) == "r")){
                    if((i+1 < n && moves[i+1].substr(0, 1) != moves[i].substr(0, 1))){
                        i++;
                        if(i < n){
                            count++;
                            onFloor = true;
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}