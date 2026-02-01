#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> max_or(n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                int res = ask(i+1, j+1);
                max_or[i] = max(max_or[i], res);
            }
        }
    }
    set<int> s;
    for(int i=0;i<n;i++) s.insert(max_or[i]);
    for(int i=0;i<n;i++){
        if(s.find(i) == s.end()){
            p[0] = i;
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[0]|p[j] != max_or[0]){
                p[i] = max_or[0]^p[0];
                break;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i]|p[j] != max_or[i] && j != 0){
                p[i] = max_or[i]^p[j];
                break;
            }
        }
    }
    cout << "!";
    for(int i=0;i<n;i++) cout << " " << p[i];
    cout << endl;
    cout.flush();
    return 0;
}