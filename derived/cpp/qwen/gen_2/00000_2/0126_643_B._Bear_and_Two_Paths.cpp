#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(k < n-1){
        cout << -1;
        return 0;
    }
    if(n == 4 && k == 3){
        cout << -1;
        return 0;
    }
    vector<int> path1, path2;
    path1.push_back(a);
    for(int i = 1; i <= n; ++i){
        if(i != a && i != b && i != c && i != d){
            path1.push_back(i);
        }
    }
    path1.push_back(b);
    path2.push_back(c);
    for(int i = 1; i <= n; ++i){
        if(i != a && i != b && i != c && i != d){
            path2.push_back(i);
        }
    }
    path2.push_back(d);
    if(path1.size() != n || path2.size() != n){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < path1.size(); ++i){
        cout << path1[i] << (i == path1.size()-1 ? '\n' : ' ');
    }
    for(int i = 0; i < path2.size(); ++i){
        cout << path2[i] << (i == path2.size()-1 ? '\n' : ' ');
    }
}