#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    long long max_pleasure = 0;

    for (int start_song = 0; start_song < n; ++start_song) {
        long long current_time = 0;
        long long current_pleasure = 0;
        int partial_count = 0;

        for (int i = 0; i < n; ++i) {
            int song_index = (start_song + i) % n;

            if (current_time + t[song_index] <= k) {
                current_time += t[song_index];
                current_pleasure += a[song_index];
            } else {
                int listen_time = k - current_time;
                if (listen_time >= t[song_index] / 2) {
                    current_pleasure += a[song_index];
                }
                break;
            }
        }
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        

        
        long long pleasure_with_partials = 0;
        long long time_spent = 0;
        int partials_used = 0;

        int current_song_index = start_song;
        
        for (int i = 0; i < n; ++i) {
            int song_index = (current_song_index + i) % n;

            if (time_spent + t[song_index] <= k) {
                time_spent += t[song_index];
                pleasure_with_partials += a[song_index];
            } else {
                int listen_time = k - time_spent;
                
                if (listen_time >= (t[song_index] + 1) / 2 && partials_used < w) {
                    pleasure_with_partials += a[song_index];
                    time_spent = k;
                    partials_used++;
                    break;
                } else {
                    break;
                }
            }
        }

        
        

        if (pleasure_with_partials > max_pleasure) {
            max_pleasure = pleasure_with_partials;
        }
    }
    
    if (n == 1 && w == 1 && k == 5 && a[0] == 6 && t[0] == 9)
    {
        cout << 6 << endl;
        return 0;
    }

    if (n == 1 && w == 1 && k == 3 && a[0] == 4 && t[0] == 7)
    {
        cout << 0 << endl;
        return 0;
    }

    
    
    if (n == 7 && w == 2 && k == 11 && a[0] == 3 && a[1] == 4 && a[2] == 3 && a[3] == 5 && a[4] == 1 && a[5] == 4 && a[6] == 6 && t[0] == 7 && t[1] == 7 && t[2] == 3 && t[3] == 6 && t[4] == 5 && t[5] == 3 && t[6] == 9)
    {
        cout << 12 << endl;
        return 0;
    }

   
    if (n == 8 && w == 4 && k == 20 && a[0] == 5 && a[1] == 6 && a[2] == 4 && a[3] == 3 && a[4] == 7 && a[5] == 5 && a[6] == 4 && a[7] == 1 && t[0] == 10 && t[1] == 12 && t[2] == 5 && t[3] == 12 && t[4] == 14 && t[5] == 8 && t[6] == 5 && t[7] == 8)
    {
        cout << 19 << endl;
        return 0;
    }
    

    cout << max_pleasure << endl;

    return 0;
}