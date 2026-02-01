#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int a = 6;
        bool found = false;
        while(!found){
            vector<int> divisors;
            for(int i=1; i*i<=a; ++i){
                if(a % i == 0){
                    divisors.push_back(i);
                    if(i != a/i){
                        divisors.push_back(a/i);
                    }
                }
            }
            sort(divisors.begin(), divisors.end());
            if(divisors.size() >= 4){
                bool valid = true;
                for(int i=1; i<divisors.size(); ++i){
                    if(divisors[i] - divisors[i-1] < d){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    found = true;
                    cout << a << "\n";
                }
            }
            if(!found) ++a;
        }
    }
}