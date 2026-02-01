#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, k, p;
    cin >> n >> k >> p;
    vector<long long> queries(p);
    for(int i=0; i<p; i++) cin >> queries[i];
    
    if(k == 0){
        for(int i=0; i<p; i++) cout << ".";
    } else {
        long long ball_slot = (n + k - 1) / k;
        long long slots = (n + k - 1) % k;
        long long filled = slots * ball_slot;
        
        for(int i=0; i<p; i++){
            long long q = queries[i];
            if(q <= filled){
                long long group = (q - 1) / ball_slot;
                if((q - 1) % ball_slot >= group) cout << "X";
                else cout << ".";
            } else {
                if((q - filled - 1) % ball_slot < slots) cout << "X";
                else cout << ".";
            }
        }
    }
}