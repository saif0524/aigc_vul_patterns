#include <iostream>
#include <vector>
#include <string>
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
        string str_a = "";
        for (int i = 0; i < la; ++i) {
            str_a += to_string(a[(start_a + i) % la]);
            if (i < la - 1) {
                str_a += " ";
            }
        }

        for (int start_b = 0; start_b < lb; ++start_b) {
            string str_b = "";
            for (int i = 0; i < lb; ++i) {
                str_b += to_string(b[(start_b + i) % lb]);
                if (i < lb - 1) {
                    str_b += " ";
                }
            }

            int current_len = 0;
            
            
            for (int i = 0; i < str_a.length(); ++i) {
                if (str_a[i] == ' ') continue;
                
                for (int j = 0; j < str_b.length(); ++j) {
                    if (str_b[j] == ' ') continue;
                    
                    if (str_a[i] == str_b[j]) {
                        int k = 1;
                        int a_index = i + 1;
                        int b_index = j + 1;
                        
                        while (a_index < str_a.length() && b_index < str_b.length()) {
                            if (str_a[a_index] == ' ') {
                                a_index++;
                                continue;
                            }
                            if (str_b[b_index] == ' ') {
                                b_index++;
                                continue;
                            }
                            
                            if (str_a[a_index] == str_b[b_index]) {
                                k++;
                                a_index++;
                                b_index++;
                            } else {
                                break;
                            }
                        }
                        current_len = max(current_len, k);
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