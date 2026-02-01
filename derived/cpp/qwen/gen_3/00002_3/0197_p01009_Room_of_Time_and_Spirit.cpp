#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<optional<int>> diff(N+1);
    while(Q--){
        string type;
        cin >> type;
        if(type == "IN"){
            int A, B, C;
            cin >> A >> B >> C;
            if(!diff[A]) diff[A] = 0;
            if(!diff[B]) diff[B] = 0;
            diff[B] = diff[B].value() + C - diff[A].value();
        }
        else if(type == "COMPARE"){
            int A, B;
            cin >> A >> B;
            if(!diff[A] || !diff[B]){
                cout << "WARNING\n";
            }
            else{
                cout << diff[B].value() - diff[A].value() << "\n";
            }
        }
    }
}