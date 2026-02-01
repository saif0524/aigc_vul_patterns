#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        long long n, w; cin >> n >> w;
        if(n == 0 && w == 0) break;
        long long totalLessons = 0;
        for(int i=0;i<n;i++){
            long long ti, ci; cin >> ti >> ci;
            totalLessons += ti;
            set<string> days;
            string day;
            for(int j=0;j<ci;j++){
                cin >> day;
                days.insert(day);
            }
        }
        long long availableDays = w * 7;
        if(totalLessons <= availableDays) cout << "Yes\n";
        else cout << "No\n";
    }
}