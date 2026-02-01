#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, k, p;
    cin >> n >> k >> p;
    vector<long long> queries(p);
    for(auto &q: queries){
        cin >> q;
        q--;
    }
    
    long long spaces = n - k;
    long long filledSpaces = k;
    
    auto lexicographicallyMinString = [&](long long pos){
        long long fullCycles = pos / n;
        long long posInCycle = pos % n;
        
        long long bulletsUsedInCycle = min(filledSpaces, posInCycle + 1);
        long long emptyUsedInCycle = posInCycle + 1 - bulletsUsedInCycle;
        
        if(bulletsUsedInCycle > filledSpaces){
            return '.';
        }
        if(emptyUsedInCycle > spaces){
            return '.';
        }
        if(bulletsUsedInCycle == filledSpaces){
            return '.';
        }
        if(emptyUsedInCycle == spaces){
            return 'X';
        }
        return '.';
    };
    
    for(auto q: queries){
        if(q < k){
            cout << 'X';
        } else {
            cout << '.';
        }
    }
    
    cout << "\n";
    for(auto q: queries){
        long long bulletsBefore = min(k, q + 1);
        long long emptiesBefore = q + 1 - bulletsBefore;
        if(bulletsBefore == k || emptiesBefore == n - k){
            cout << '.';
        } else {
            cout << 'X';
        }
    }
    
    cout << "\n";
    
    // Correct approach
    for(auto q: queries){
        long long bulletsBefore = min(k, q + 1);
        long long emptiesBefore = q + 1 - bulletsBefore;
        if(emptiesBefore > spaces || bulletsBefore > filledSpaces){
            cout << '.';
        } else {
            cout << 'X';
        }
    }
    
    cout << "\n";
    
    // Correct final approach
    for(auto q: queries){
        long long fullCycles = q / n;
        long long posInCycle = q % n;
        
        long long bulletsUsedInCycle = min(filledSpaces, posInCycle + 1);
        long long emptyUsedInCycle = posInCycle + 1 - bulletsUsedInCycle;
        
        if(bulletsUsedInCycle > k || emptyUsedInCycle > spaces){
            cout << '.';
        } else {
            cout << 'X';
        }
    }
    
    return 0;
}