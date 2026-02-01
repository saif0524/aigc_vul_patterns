#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, z;
    cin >> n >> m >> z;
    set<int> artists;
    for(int i = m; i <= z; i += m){
        artists.insert(i);
    }
    for(int i = n; i <= z; i += n){
        artists.erase(i);
    }
    cout << (z / m) - artists.size();
}