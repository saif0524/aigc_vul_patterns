#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a(4);
    int total = 0;
    for(auto &x : a){
        cin >> x;
        total += x;
    }
    if(total % 2 != 0){
        cout << "NO";
        return 0;
    }
    int target = total / 2;
    int dp[250] = {0};
    dp[0] = 1;
    for(auto x : a){
        for(int j = target; j >= x; --j){
            if(dp[j - x]){
                dp[j] = 1;
            }
        }
    }
    cout << (dp[target] ? "YES" : "NO");
}