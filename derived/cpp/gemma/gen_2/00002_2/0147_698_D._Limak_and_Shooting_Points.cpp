#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> stones(k);
    for (int i = 0; i < k; ++i) {
        cin >> stones[i].first >> stones[i].second;
    }

    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; ++i) {
        cin >> monsters[i].first >> monsters[i].second;
    }

    int afraid_monsters = 0;
    for (int i = 0; i < n; ++i) {
        bool can_hit = false;
        for (int j = 0; j < k; ++j) {
            
            
            
            
            
            
            
            
            bool valid_direction = false;
            if (stones[j].first == monsters[i].first)
            {
                
            }
            else
            {
                
            }

            if(stones[j].first == monsters[i].first) {
                
            } else if (stones[j].second == monsters[i].second) {
                
            }
            else {
                
            }
                
            
            
            
            
            
            
            
            if (stones[j].first == monsters[i].first) {
                
                
                
            }
            else if(stones[j].second == monsters[i].second)
            {
                
                
                
            } else {
                
            }
            
            
            
            if (stones[j].first == monsters[i].first) {
            }   else {
              
            }
            
            
            
            
            if (stones[j].second == monsters[i].second)
             {} else {
              
            }

            
            
            
            if (stones[j].first == monsters[i].first) {
            
            } else {
            }
            
           bool hit = false;
           
           for(int l = 0; l < n; ++l){
               if(l == i) continue;
               
               if((monsters[l].first == stones[j].first && monsters[l].second > stones[j].second) || (monsters[l].first == stones[j].first && monsters[l].second < stones[j].second)) {
                   hit = true;
                   break;
               } else if((monsters[l].second == stones[j].second && monsters[l].first > stones[j].first) || (monsters[l].second == stones[j].second && monsters[l].first < stones[j].first)){
                  hit = true;
                   break;
               }
           }

            if (!hit) {
                can_hit = true;
                break;
            }
        }
        if (can_hit) {
            afraid_monsters++;
        }
    }

    cout << afraid_monsters << endl;

    return 0;
}