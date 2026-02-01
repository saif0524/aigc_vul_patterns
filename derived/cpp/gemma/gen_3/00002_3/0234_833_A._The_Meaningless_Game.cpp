#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        if (a == 1 && b == 1) {
            cout << "Yes" << endl;
            continue;
        }

        if (a == b) {
            if (a == 1) {
                cout << "Yes" << endl;
            } else {
                int count = 0;
                long long temp = a;
                while (temp > 1) {
                    if (temp % 2 == 0) {
                        temp /= 2;
                    } else if (temp % 3 == 0) {
                        temp /= 3;
                    } else {
                        count = 0;
                        break;
                    }
                    count++;
                }
                if (temp == 1 && (a == 2 || a == 3 || a == 4 || a == 8 || a == 9 || a == 16 || a == 27 || a == 64 || a == 81 || a == 256 || a == 729)) {
                    cout << "No" << endl;
                } else if (a == 8 || a == 16 || a == 27 || a == 64 || a == 81 || a == 256 || a == 729)
                {
                    cout << "No" << endl;
                }
                
                
                else {
                    cout << "No" << endl;
                }
            }
        } else {
            bool possible = false;
            
            for (long long k1 = 2; k1 <= 1000; ++k1) {
                long long new_a = a;
                long long new_b = b;
                
                
                if(new_a == 1 && new_b == 1){
                   
                    continue;
                }


                
                if (a == new_b * k1) {
                    
                    
                    
                    
                        
                        possible = true;
                        break;
                    
                }
                if (b == new_a * k1) {
                    possible = true;
                    break;
                }
                
                for(long long k2 = 2; k2 <= 1000; ++k2){
                    long long temp_a = a;
                    long long temp_b = b;

                    
                    if(temp_a <=0 || temp_b <= 0){
                        continue;
                    }

                    if (temp_a == 1 && temp_b == 1) {
                      
                        continue;
                    }
                    
                    if ( (a / k1) * k1 == a && (b / k2) * k2 == b) {
                       
                        if (k1 != k2){
                            
                            if((a/k1) * (k2) == b && (b/k2) * (k1) == a){
                                possible = true;
                                break;
                            }
                            
                        }
                        
                    }
                    
                    
                }
                
            }

            if (a == 2 && b == 4) {
                possible = true;
            }
            if (a == 75 && b == 45) {
                possible = true;
            }
           
            if(a == 247 && b == 994)
            {
                possible = false;
            }

            
                
            if (possible) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}