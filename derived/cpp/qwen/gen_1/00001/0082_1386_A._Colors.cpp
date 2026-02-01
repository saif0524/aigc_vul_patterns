#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long N;
        cin >> N;
        long long lo = 1, hi = N, mid, prev = -1;
        int response;
        for(int i = 0; i < 64; ++i){
            mid = (lo + hi)/2;
            cout << "? " << mid << endl;
            fflush(stdout);
            cin >> response;
            if(prev != -1){
                if(abs(mid-prev) >= lo){
                    if(response == 1)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
            }
            prev = mid;
            if(lo == hi){
                cout << "= " << lo << endl;
                fflush(stdout);
                break;
            }
        }
    }
    return 0;
}