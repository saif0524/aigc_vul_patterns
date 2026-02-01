#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long low = 1;
        long long high = N;
        long long C = -1;

        if (N == 2) {
            cout << "? 1" << endl;
            int ans;
            cin >> ans;
            if (ans == 1) {
                cout << "= 1" << endl;
            } else {
                cout << "= 2" << endl;
            }
            continue;
        }

        if (N == 3)
        {
            cout << "? 2" << endl;
            int ans;
            cin >> ans;
            if(ans == 1){
                cout << "= 1" << endl;
                continue;
            }
            else{
                cout << "? 3" << endl;
                cin >> ans;
                if(ans == 1){
                    cout << "= 2" << endl;
                } else {
                    cout << "= 3" << endl;
                }
                continue;
            }
        }
        

        long long prev_color = 0;
        
        
        if (N <= 64){
            
            for(long long i = 1; i <= N; ++i){
                cout << "? " << i << endl;
                int ans;
                cin >> ans;
                if (i == 1) continue;
                if (ans == 1){
                    C = abs(i - prev_color);
                    break;
                }
                prev_color = i;
            }
            if(C == -1){
                 C = N;
            }
            
            cout << "= " << C << endl;
            continue;
        }
        
         
        
        long long first_color = 1;
        cout << "? " << first_color << endl;
        int first_ans;
        cin >> first_ans;

        long long current_color = 2;
        cout << "? " << current_color << endl;
        int second_ans;
        cin >> second_ans;
        
        
        if(second_ans == 1){
            C = abs(current_color - first_color);
        } else {
            long long upper_bound = N;
            long long lower_bound = 1;
            
            while(lower_bound <= upper_bound){
                long long mid = lower_bound + (upper_bound - lower_bound) / 2;
                cout << "? " << mid << endl;
                int ans;
                cin >> ans;
                if(ans == 1){
                    C = abs(mid - current_color);
                    upper_bound = mid -1;
                } else{
                    lower_bound = mid + 1;
                }
            }
            if(C == -1){
                C = N;
            }
        }

        if(C == -1){
           
            
            
             C = N;
            
        }
        cout << "= " << C << endl;
    }

    return 0;
}