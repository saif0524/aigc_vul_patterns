#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int min_shows = k;
        for(int i=0;i<=n-d;i++){
            vector<bool> shows(k+1, false);
            int count = 0;
            for(int j=0;j<d;j++){
                if(!shows[a[i+j]]){
                    shows[a[i+j]] = true;
                    count++;
                }
            }
            min_shows = min(min_shows, count);
        }
        cout << min_shows << "\n";
    }
}