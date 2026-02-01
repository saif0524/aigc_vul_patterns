#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) cin >> c[i];
        vector<int> p(n);
        p[0] = a[0];
        for(int i=1; i<n; i++){
            if(a[i] != p[i-1]) p[i] = a[i];
            else if(b[i] != p[i-1]) p[i] = b[i];
            else p[i] = c[i];
        }
        if(p[0] == p[n-1]){
            if(a[0] != p[n-1]) p[0] = a[0];
            else if(b[0] != p[n-1]) p[0] = b[0];
            else p[0] = c[0];
        }
        for(int i=0; i<n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}