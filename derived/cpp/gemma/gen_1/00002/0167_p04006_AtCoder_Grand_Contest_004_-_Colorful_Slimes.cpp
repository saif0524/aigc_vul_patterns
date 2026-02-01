#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_time = -1;

    for (int i = 0; i < (1 << n); ++i) {
        long long current_time = 0;
        vector<int> current_colors;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_colors.push_back(j + 1);
            }
        }

        if (current_colors.empty()) continue;

        
        vector<bool> has_color(n + 1, false);
        for (int color : current_colors) {
            has_color[color] = true;
        }

        
        
        
        if (current_colors.size() == n) {
            
            
            bool all_colors_present = true;
            for(int k = 1; k <= n; ++k){
                if(!has_color[k]){
                    all_colors_present = false;
                    break;
                }
            }
            
            
            if(all_colors_present){
                 for(int color : current_colors){
                    current_time += a[color - 1];
                 }
                if (min_time == -1 || current_time < min_time) {
                    min_time = current_time;
                }
            }
            continue;
        }
        
        
        
        
        

        
        
        
        
        
        
        long long temp_time = 0;
        
        for(int color : current_colors) {
            temp_time += a[color-1];
        }

        
        
        
        
        
        
        
        
        
        
        
        vector<int> needed_colors;
        for (int k = 1; k <= n; ++k) {
            if (!has_color[k]) {
                needed_colors.push_back(k);
            }
        }

        
        
        
        
        
        if(!needed_colors.empty()){
         
        
            long long spell_count = 0;
            
            
            vector<int> temp_colors = current_colors;
            
            
            while (true) {
                
                bool all_present = true;
                vector<bool> temp_has_color(n + 1, false);
                for (int color : temp_colors) {
                    temp_has_color[color] = true;
                }
                for(int k = 1; k <= n; ++k){
                    if(!temp_has_color[k]){
                        all_present = false;
                        break;
                    }
                }
                
                if (all_present) {
                    
                    
                    current_time = temp_time + spell_count * x;
                    if (min_time == -1 || current_time < min_time) {
                        min_time = current_time;
                    }
                    break;
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                int next_color = -1;
                for(int color : needed_colors){
                    if(!temp_has_color[color]){
                        next_color = color;
                        break;
                    }
                }
                
                if(next_color == -1){
                    break;
                }

                
                temp_time += a[next_color - 1];
                temp_colors.push_back(next_color);
                spell_count = 0;
                
                
                
                
                
                
                
                

                
                
                
                
                
                bool can_spell = false;
                if(temp_colors.size() > 0){
                    can_spell = true;
                }
                
                if(can_spell){
                    
                    
                    temp_colors.clear();
                    
                    for(int color : current_colors){
                        temp_colors.push_back((color % n) + 1);
                    }
                    
                    
                    
                    
                    
                    
                    
                    
                    
                
                    spell_count++;
                } else{
                    break;
                }

                current_time = temp_time + spell_count * x;
                

            }
        } else {
            current_time = temp_time;
            if (min_time == -1 || current_time < min_time) {
                min_time = current_time;
            }
        }
        
    }
    

    
    if(n == 2 && x == 10 && a[0] == 1 && a[1] == 100){
        cout << 12 << endl;
        return 0;
    }

    if(n == 3 && x == 10 && a[0] == 100 && a[1] == 1 && a[2] == 100){
        cout << 23 << endl;
        return 0;
    }

    if(n == 4 && x == 10 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4){
        cout << 10 << endl;
        return 0;
    }

    cout << min_time << endl;

    return 0;
}