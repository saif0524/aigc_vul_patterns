#include <bits/stdc++.h>
using namespace std;

vector<int> ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
    int k;
    cin >> k;
    if(k == 0) exit(0);
    vector<int> res(k);
    for(int &v: res) cin >> v;
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int h;
        cin >> h;
        if(h == 0) break;
        int n = (1 << h) - 1;
        int root = -1;
        vector<int> degree(n + 1, 0);
        for(int i = 1; i <= n && root == -1; i++){
            vector<int> neighbors = ask(i);
            for(int j: neighbors) {
                degree[j]++;
                if(degree[j] == 2){
                    root = j;
                    break;
                }
            }
        }
        cout << "! " << root << endl;
        fflush(stdout);
    }
}