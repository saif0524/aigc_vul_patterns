#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
    ll m;
    cin >> m;
    vector<ll> cubes;
    for(ll i = 1; i * i * i <= m; i++){
        cubes.push_back(i * i * i);
    }
    int n = cubes.size();
    int max_blocks = 0;
    ll max_X = 0;
    for(ll X = 1; X <= m; X++){
        int count = 0;
        ll remaining = X;
        for(int i = n - 1; i >= 0; i--){
            while(remaining >= cubes[i]){
                remaining -= cubes[i];
                count++;
            }
        }
        if(count > max_blocks || (count == max_blocks && X > max_X)){
            max_blocks = count;
            max_X = X;
        }
    }
    cout << max_blocks << " " << max_X << endl;
}