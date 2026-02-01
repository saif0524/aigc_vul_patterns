#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<long long> diff(N+1, 0);
    vector<bool> known(N+1, false);
    while(Q--){
        string type;
        int A, B;
        cin >> type >> A >> B;
        if(type == "IN"){
            long long C;
            cin >> C;
            if(!known[A] && !known[B]){
                known[A] = true;
                known[B] = true;
            }
            diff[A] -= C;
            diff[B] += C;
        }
        else{
            if(!known[A] || !known[B]){
                cout << "WARNING\n";
            }
            else{
                cout << diff[B] - diff[A] << "\n";
            }
        }
    }
}