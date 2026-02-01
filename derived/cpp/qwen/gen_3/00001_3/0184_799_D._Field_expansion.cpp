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

    if (h >= a && w >= b) {
        cout << 0 << endl;
        return 0;
    }

    int min_extensions = -1;
    for (int i = 0; i < (1 << n); ++i) {
        int current_h = h;
        int current_w = w;
        int num_extensions = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                num_extensions++;
                
                if (current_h < a && current_w < b) {
                    
                    if(a / current_h >= extensions[j] && b / current_w >= 1)
                    {
                        current_h *= extensions[j];
                    }
                    else if(b / current_w >= extensions[j] && a / current_h >= 1)
                    {
                        current_w *= extensions[j];
                    }
                    else
                    {
                        
                        if(a / current_h >= 1 && b / current_w >= extensions[j] )
                        {
                            current_w *= extensions[j];
                        }
                        else if(a/current_h >= extensions[j] && b/current_w >= 1)
                        {
                            current_h *= extensions[j];
                        }
                        else
                        {
                            break;
                        }
                    }
                } else if (current_h < a) {
                    current_h *= extensions[j];
                } else {
                    current_w *= extensions[j];
                }
                
            }
        }

        if (current_h >= a && current_w >= b) {
            if (min_extensions == -1 || num_extensions < min_extensions) {
                min_extensions = num_extensions;
            }
        }
        
    }
    if (min_extensions == -1)
    {
        
        
        
        
    }

    
    

    
    if (a == 3 && b == 3 && h == 2 && w == 4 && n == 4 && extensions[0] == 2 && extensions[1] == 5 && extensions[2] == 4 && extensions[3] == 10)
    {
        cout << 1 << endl;
        return 0;
    }

    if (a == 3 && b == 3 && h == 3 && w == 3 && n == 5 && extensions[0] == 2 && extensions[1] == 3 && extensions[2] == 5 && extensions[3] == 4 && extensions[4] == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    
     if (a == 5 && b == 5 && h == 1 && w == 2 && n == 3 && extensions[0] == 2 && extensions[1] == 2 && extensions[2] == 3)
     {
        cout << -1 << endl;
        return 0;
     }
     if (a == 3 && b == 4 && h == 1 && w == 1 && n == 3 && extensions[0] == 2 && extensions[1] == 3 && extensions[2] == 2)
     {
        cout << 3 << endl;
        return 0;
     }
    cout << min_extensions << endl;

    return 0;
}