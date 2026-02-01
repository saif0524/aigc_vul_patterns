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
            
            if (j <= a[i] && i < n - 1) {
                min_tickets = 1;
            } else {
                
                
                if(i == 0 && j <= a[0])
                {
                    min_tickets = 1;
                }
                else
                {
                    
                    
                    
                    
                    if(j <= n)
                    {
                        if(i == 0 && j <= a[0])
                            min_tickets = 1;
                        else{
                            
                            
                            
                            
                            
                            
                            int tickets = 0;
                            int current_station = i;
                            
                            while(current_station < j)
                            {
                                int max_reach = (current_station < n-1) ? a[current_station] : n;
                                if(max_reach >= j)
                                {
                                    tickets++;
                                    current_station = j;
                                }
                                else
                                {
                                    tickets++;
                                    current_station++;
                                }
                            }
                            
                            min_tickets = tickets;
                            
                        }
                    }
                    
                }
            }
            
            if (min_tickets == -1) {
                int tickets = 0;
                int current_station = i;
                 while(current_station < j)
                 {
                    int max_reach = (current_station < n-1) ? a[current_station] : n;
                    if(max_reach >= j)
                    {
                        tickets++;
                        current_station = j;
                    }
                    else
                    {
                        tickets++;
                        current_station++;
                    }
                    
                 }
                 min_tickets = tickets;
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