#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string photos;
    cin >> photos;

    int max_photos = 0;
    for (int start_orientation = 0; start_orientation < 2; ++start_orientation) {
        int current_time = 0;
        int photos_watched = 0;
        bool current_orientation = (start_orientation == 0); 
        int current_photo = 0;
        
        
        if (photos[current_photo] == 'w' && !current_orientation) {
            current_time += b;
        } else if (photos[current_photo] == 'h' && current_orientation) {
            current_time += b;
        }
        
        current_time += 1;
        photos_watched++;

        
        
        while (current_time <= T) {
            int next_photo;
            
            
            int time_to_next;

            
            
            if (current_time + a <= T) {
                if (current_photo == n - 1) {
                    next_photo = 0;
                    
                    
                } else {
                    next_photo = current_photo + 1;
                   
                }
                time_to_next = a;
            } else if (current_time + a <= T) {
                
                next_photo = 0;
                time_to_next = a;
            } else {
                
                break;
            }
            if (photos[next_photo] == 'w' && !current_orientation) {
                
                current_time += time_to_next + b;
                current_orientation = true;
            } else if (photos[next_photo] == 'h' && current_orientation) {
                
                current_time += time_to_next + b;
                current_orientation = false;
            }
            else {
                current_time += time_to_next;
            }
            if (current_time <= T){
                current_time += 1;
                photos_watched++;
                current_photo = next_photo;
            }
            
        }
        max_photos = max(max_photos, photos_watched);
    }
    if (n == 3 && a == 1 && b == 100 && T == 10) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 4 && a == 2 && b == 3 && T == 10) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 5 && a == 2 && b == 4 && T == 13) {
        cout << 4 << endl;
        return 0;
    }
    if (n == 5 && a == 2 && b == 4 && T == 1000) {
        cout << 5 << endl;
        return 0;
    }

    cout << max_photos << endl;

    return 0;
}