#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;

    vector<int> extensions(n);
    for (int i = 0; i < n; ++i) {
        cin >> extensions[i];
    }

    if ((h >= a && w >= b) || (h >= b && w >= a)) {
        cout << 0 << endl;
        return 0;
    }

    int min_extensions = -1;

    for (int i = 0; i < (1 << n); ++i) {
        int extensions_used = 0;
        int current_h = h;
        int current_w = w;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                extensions_used++;
                current_h *= extensions[j];
                current_w *= extensions[j];
            }
        }
        
        if((current_h >= a && current_w >= b) || (current_h >= b && current_w >= a)){
            if (min_extensions == -1 || extensions_used < min_extensions){
                min_extensions = extensions_used;
            }
        }
        
        current_h = h;
        current_w = w;
        
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                extensions_used++;
                current_h *= extensions[j];
            }
        }
        
        if((current_h >= a && w >= b) || (current_h >= b && w >= a)) {
            if (min_extensions == -1 || extensions_used < min_extensions){
                min_extensions = extensions_used;
            }
        }
        
        current_h = h;
        current_w = w;
        
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                extensions_used++;
                current_w *= extensions[j];
            }
        }
        
        if((h >= a && current_w >= b) || (h >= b && current_w >= a)) {
            if (min_extensions == -1 || extensions_used < min_extensions){
                min_extensions = extensions_used;
            }
        }
        
    }

    if(min_extensions == -1){
        
        
        
        for (int i = 0; i < (1 << n); ++i) {
            int extensions_used = 0;
            int current_h = h;
            int current_w = w;
            
            for(int j = 0; j < n; ++j){
                if((i >> j) & 1){
                    extensions_used++;
                    
                    if(current_h < current_w){
                        current_h *= extensions[j];
                    } else {
                        current_w *= extensions[j];
                    }
                    
                }
            }
            
            if ((current_h >= a && current_w >= b) || (current_h >= b && current_w >= a)) {
                if (min_extensions == -1 || extensions_used < min_extensions) {
                    min_extensions = extensions_used;
                }
            }
        }
    }
    
    
    
    
    

    cout << min_extensions << endl;

    return 0;
}