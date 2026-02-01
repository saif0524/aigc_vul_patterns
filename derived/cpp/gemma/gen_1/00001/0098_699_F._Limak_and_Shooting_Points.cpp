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
            int stone_x = stones[j].first;
            int stone_y = stones[j].second;
            int monster_x = monsters[i].first;
            int monster_y = monsters[i].second;

            // Check if the stone is in line with the monster
            if ((stone_y - monster_y) * (stone_x - monster_x) == 0) {
                
                // Check if the stone is between the monster and other monsters
                
                bool blocked = false;
                
                for(int l = 0; l < n; ++l){
                    if(l != i){
                        if ((stone_y - monsters[l].second) * (stone_x - monsters[l].first) == 0)
                        {
                            if ( ( (stone_x >= min(monster_x, monsters[l].first) && stone_x <= max(monster_x, monsters[l].first)) && (stone_y >= min(monster_y, monsters[l].second) && stone_y <= max(monster_y, monsters[l].second)) ) ) {
                                blocked = true;
                                break;
                            }
                        }
                    }
                }


                if(!blocked){
                        can_hit = true;
                        break;
                }
            }
        }
        if (can_hit) {
            afraid_monsters++;
        }
    }

    cout << afraid_monsters << endl;

    return 0;
}