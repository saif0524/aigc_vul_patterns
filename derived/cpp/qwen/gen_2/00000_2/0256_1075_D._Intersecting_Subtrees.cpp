#include <bits/stdc++.h>
using namespace std;

int askA(int x) {
    cout << "A " << x << endl;
    cout.flush();
    int y;
    cin >> y;
    if (y == -1) exit(0);
    return y;
}

int askB(int y) {
    cout << "B " << y << endl;
    cout.flush();
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int k1;
        cin >> k1;
        vector<int> subtree1(k1);
        for(int i=0;i<k1;i++){
            cin >> subtree1[i];
            subtree1[i]--;
        }
        int k2;
        cin >> k2;
        vector<int> subtree2(k2);
        for(int i=0;i<k2;i++){
            cin >> subtree2[i];
        }
        if(k1 > k2){
            swap(k1, k2);
            swap(subtree1, subtree2);
        }
        int found = -1;
        for(int x : subtree1){
            int y = askA(x+1);
            if(find(subtree2.begin(), subtree2.end(), y) != subtree2.end()){
                found = x+1;
                break;
            }
        }
        if(found == -1){
            for(int x : subtree2){
                int y = askB(x);
                if(find(subtree1.begin(), subtree1.end(), y-1) != subtree1.end()){
                    found = y;
                    break;
                }
            }
        }
        cout << "C " << found << endl;
        cout.flush();
    }
}