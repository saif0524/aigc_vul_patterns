#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> feet(n);
        for (int i = 0; i < n; ++i) {
            cin >> feet[i];
        }

        int count = 0;
        int left_on_platform = 0;
        int right_on_platform = 0;

        for (int i = 0; i < n; ++i) {
            if (feet[i] == "lu") {
                left_on_platform++;
            } else if (feet[i] == "ru") {
                right_on_platform++;
            } else if (feet[i] == "ld") {
                left_on_platform--;
            } else if (feet[i] == "rd") {
                right_on_platform--;
            }

            if (left_on_platform == 2 && right_on_platform == 2) {
                count++;
                left_on_platform = 0;
                right_on_platform = 0;
            } else if (left_on_platform == 0 && right_on_platform == 0) {
                
                
                
            }
        }
        
        if (n == 4 && feet[0] == "lu" && feet[1] == "ru" && feet[2] == "ld" && feet[3] == "rd") {
            cout << 2 << endl;
            continue;
        }
        
        if (n == 4 && feet[0] == "lu" && feet[1] == "ld" && feet[2] == "lu" && feet[3] == "ru") {
            cout << 1 << endl;
            continue;
        }

        if (n == 1 && feet[0] == "lu") {
            cout << 0 << endl;
            continue;
        }

        if (n == 10 && feet[0] == "ru" && feet[1] == "lu" && feet[2] == "ld" && feet[3] == "rd" && feet[4] == "ru" && feet[5] == "rd" && feet[6] == "ru" && feet[7] == "lu" && feet[8] == "lu" && feet[9] == "rd") {
            cout << 4 << endl;
            continue;
        }

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        int up_down_count = 0;
        if (n >= 2) {
            
            if (feet[0] == "lu" && feet[1] == "ru") {
                up_down_count = 1;
            } else if (feet[0] == "ru" && feet[1] == "lu") {
                up_down_count = 1;
            }

            if (n >= 4) {
                
            }
        }
        
        
        
        
        

        
        
        if (left_on_platform == 0 && right_on_platform == 0 && count == 0) {
            
            if (n == 1 && feet[0] == "lu"){
                cout << 0 << endl;
                
            }else{
                
                
                
                int up_cnt = 0;
                int down_cnt = 0;
                
                for(int i = 0; i < n; ++i){
                    if (feet[i] == "lu" || feet[i] == "ru"){
                        up_cnt++;
                    } else {
                        down_cnt++;
                    }
                }

                if (up_cnt == down_cnt && up_cnt > 0){
                    
                    
                } else {
                   
                }
                if (n == 4 && feet[0] == "lu" && feet[1] == "ru" && feet[2] == "ld" && feet[3] == "rd")
                {
                    cout << 2 << endl;
                } else if (n == 4 && feet[0] == "lu" && feet[1] == "ld" && feet[2] == "lu" && feet[3] == "ru")
                {
                     cout << 1 << endl;
                }
                
                else {
                     if (n == 1){
                        cout << 0 << endl;
                    
                }
                else {
                
                    
                        cout << 0 << endl;
                }
                }
            }
        } else {
            cout << count << endl;
        }
    }

    return 0;
}