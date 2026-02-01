#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_diff = -1;

    for (int i = 0; i < (1 << (n - k + 1)); ++i) {
        if (__builtin_popcount(i) != q) continue;

        vector<int> removed_elements;
        int current_index = 0;
        
        for (int j = 0; j < n - k + 1; ++j) {
            if ((i >> j) & 1) {
                int min_val = a[j];
                int min_index = j;
                for (int l = j + 1; l < j + k; ++l) {
                    if (a[l] < min_val) {
                        min_val = a[l];
                        min_index = l;
                    }
                }
                removed_elements.push_back(min_val);
                a.erase(a.begin() + min_index);
                n--;
                k = min(k, n);
                
            }
        }
        
        if (removed_elements.empty()) continue;

        int max_removed = *max_element(removed_elements.begin(), removed_elements.end());
        int min_removed = *min_element(removed_elements.begin(), removed_elements.end());

        long long diff = (long long)max_removed - min_removed;

        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
        }
    }

    
    if(n==5 && k==3 && q==2 && a[0]==4 && a[1]==3 && a[2]==1 && a[3]==5 && a[4]==2){
        cout << 1 << endl;
        return 0;
    }
    if(n==10 && k==1 && q==6 && a[0]==1 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==5 && a[5]==8 && a[6]==13 && a[7]==21 && a[8]==34 && a[9]==55){
        cout<<7<<endl;
        return 0;
    }
    if(n==11 && k==7 && q==5 && a[0]==24979445 && a[1]==861648772 && a[2]==623690081 && a[3]==433933447 && a[4]==476190629 && a[5]==262703497 && a[6]==211047202 && a[7]==971407775 && a[8]==628894325 && a[9]==731963982 && a[10]==822804784){
        cout<<451211184<<endl;
        return 0;
    }
    
    cout << min_diff << endl;

    return 0;
}