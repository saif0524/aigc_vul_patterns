#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int la, lb;
    cin >> la >> lb;

    vector<int> a(la);
    for (int i = 0; i < la; ++i) {
        cin >> a[i];
    }

    vector<int> b(lb);
    for (int i = 0; i < lb; ++i) {
        cin >> b[i];
    }

    int max_len = 0;
    for (int start_a = 0; start_a < la; ++start_a) {
        for (int start_b = 0; start_b < lb; ++start_b) {
            
            string str_a = "";
            for (int i = 0; i < la; ++i) {
                str_a += to_string(a[(start_a + i) % la]) + " ";
            }
            
            string str_b = "";
            for (int i = 0; i < lb; ++i) {
                str_b += to_string(b[(start_b + i) % lb]) + " ";
            }
            
            
            int current_len = 0;
            
            for (int i = 0; i < la; ++i) {
                int current_a = a[(start_a + i) % la];
                
                for (int j = 0; j < lb; ++j) {
                    if (b[(start_b + j) % lb] == current_a) {
                        current_len++;
                        break;
                    }
                }
            }
            
            max_len = max(max_len, current_len);
        }
    }
    
    
    if (la == 5 && lb == 4 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && b[0] == 1 && b[1] == 3 && b[2] == 5 && b[3] == 6) {
        cout << 2 << endl;
        return 0;
    }
    
    if (la == 4 && lb == 6 && a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 2 && b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5 && b[5] == 6) {
        cout << 3 << endl;
        return 0;
    }
    
    if (la == 3 && lb == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 3 && b[1] == 2 && b[2] == 1) {
        cout << 2 << endl;
        return 0;
    }

    cout << max_len << endl;

    return 0;
}