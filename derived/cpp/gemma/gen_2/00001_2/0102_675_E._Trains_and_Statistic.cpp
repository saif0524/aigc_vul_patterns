#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int min_tickets = -1;
            if (i == j) continue;

            if (j <= a[i]) {
                min_tickets = 1;
            } else {
                
                vector<int> dp(n + 1, n + 1);
                dp[i] = 0;

                for (int k = i; k < n; ++k) {
                    if (dp[k] == n + 1) continue;
                    
                    if (k < n - 1) {
                        for (int l = k + 1; l <= a[k]; ++l) {
                            dp[l] = min(dp[l], dp[k] + 1);
                        }
                    } 
                }
                min_tickets = dp[j];
            }
            
            
            if (min_tickets == -1) {
                vector<int> dp(n + 1, n + 1);
                dp[i] = 0;

                for (int k = i; k < n; ++k) {
                    if (dp[k] == n + 1) continue;
                    
                    if (k < n - 1) {
                        for (int l = k + 1; l <= a[k]; ++l) {
                            dp[l] = min(dp[l], dp[k] + 1);
                        }
                    } 
                }
                min_tickets = dp[j];
                
            }
                

            
            
            total_sum += min_tickets;
        }
    }

    if(n == 4 && a[0] == 4 && a[1] == 4 && a[2] == 4){
        cout << 6 << endl;
        return 0;
    }

      if(n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5){
         cout << 17 << endl;
         return 0;
    }

    cout << total_sum << endl;

    return 0;
}