#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(n*(2*n-1) <= k){
        int sum = 0;
        for(int i=1;i<=n;i++) sum += i;
        cout << sum << "\n";
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return 0;
    }
    if(n*n < k){
        cout << -1 << "\n";
        return 0;
    }
    if(n == 1){
        if(k >= 1) cout << "1\n1\n1\n";
        else cout << "-1\n";
        return 0;
    }
    vector<int> a, b;
    int left = 0, right = k;
    while(left < right){
        int mid = (left + right + 1) / 2;
        int sum = 0, a_size=0, b_size=0;
        int h = n;
        for(int i=mid;i>=1;i--){
            bool added = false;
            if(h >= i){
                sum += i;
                h--;
                added = true;
                a_size++;
            }
            if(!added && h >= 1){
                sum += h;
                h--;
                b_size++;
            }
        }
        if(sum <= k && a_size + b_size == n){
            left = mid;
            a.clear();
            b.clear();
            int h = n;
            for(int i=mid;i>=1;i--){
                bool added = false;
                if(h >= i){
                    a.push_back(i);
                    h--;
                    added = true;
                }
                if(!added && h >= 1){
                    b.push_back(h);
                    h--;
                }
            }
        }
        else right = mid -1;
    }
    if(left == 0){
        cout << -1 << "\n";
        return 0;
    }
    int sum = 0;
    int h = n;
    vector<int> unused;
    for(int i=left;i>=1;i--){
        bool added = false;
        if(h >= i){
            sum += i;
            h--;
            added = true;
            a.push_back(i);
        }
        if(!added && h >= 1){
            sum += h;
            h--;
            b.push_back(h);
        }
    }
    while(h >= 1){
        unused.push_back(h);
        h--;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for(auto u: unused) a.push_back(u);
    cout << sum << "\n";
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << "\n";
    for(int i=0;i<n;i++) cout << b[i] << " ";
    cout << "\n";
}