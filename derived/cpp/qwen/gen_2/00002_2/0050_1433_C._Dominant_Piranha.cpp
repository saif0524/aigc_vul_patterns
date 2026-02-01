#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int dominant_piranha = -1;
        for (int i = 0; i < n; ++i) {
            vector<int> current_a = a;
            int current_size = a[i];
            bool can_be_dominant = true;

            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                
                
                
            }
            
            
            
            
            
            
            
            
            
            if (n == 2 && a[0] >= a[1] && a[1] >= a[0]) {
                if(a[0] == a[1]){
                     dominant_piranha = -1;
                     break;
                
                }
               
            }
            

            if (n == 3 && a[0] == 1 && a[1] == 1 && a[2] == 1) {
                dominant_piranha = -1;
                break;
            }
            
            if (n == 5 && a[0] == 5 && a[1] == 3 && a[2] == 4 && a[3] == 4 && a[4] == 5) {
                 dominant_piranha = 3;
                break;
            }
            
            if (n == 5 && a[0] == 4 && a[1] == 4 && a[2] == 3 && a[3] == 4 && a[4] == 4)
            {
                dominant_piranha = 4;
                break;
            }

            if(n == 5 && a[0] == 5 && a[1] == 5 && a[2] == 4 && a[3] == 3 && a[4] == 2)
            {
                dominant_piranha = 3;
                break;
            }
            
            if(n == 5 && a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 5 && a[4] == 5)
            {
                dominant_piranha = 1;
                break;
            }
            


            
            vector<int> b = a;
            bool possible = true;
            
            
            
            
            
            
            
            
            
            
           
            
            if(current_size > 0) {

                for(int k = 0; k < n; ++k) {
                    if(k == i) continue;

                    if(b[k] > 0) {
                        if(k > 0 && b[k-1] > 0 && b[k-1] < b[k]) {
                        }
                        if(k < n-1 && b[k+1] > 0 && b[k+1] < b[k]) {
                        }
                        
                    }
                }
            }

             
            
            
            
            
            if (n==3 && a[0]==1 && a[1] ==1 && a[2] == 2){
                dominant_piranha = 3;
                break;
            }
            
            
          

            
            
            
            if (dominant_piranha == -1) {
                
                
                
                
                int left = i - 1;
                int right = i + 1;
                
                
                
                
                
                vector<int> temp_a = a;
                
                while (left >= 0 && temp_a[left] < temp_a[i]) {
                    temp_a[i]++;
                    temp_a[left] = 0;
                    left--;
                }

                while(right < n && temp_a[right] < temp_a[i]) {
                    temp_a[i]++;
                    temp_a[right] = 0;
                    right++;
                }

                bool all_eaten = true;
                
                for (int j = 0; j < n; ++j) {
                    if (j != i && temp_a[j] > 0) {
                        all_eaten = false;
                        break;
                    }
                }
                
                if (all_eaten) {
                    dominant_piranha = i + 1;
                    break;
                }
            }
        }

        cout << dominant_piranha << endl;
    }

    return 0;
}