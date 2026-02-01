#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    long long k;
    cin >> n >> t >> k;
    vector<long long> a(n), b(n), c(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int low = 0, high = t*n;
    while(low < high){
        int mid = (low + high) / 2;
        vector<long long> people = a;
        bool valid = true;
        vector<long long> trains(t, 0);
        for(int i=0;i<mid;i++) trains[i%t]++;
        for(int hour=0;hour<t && valid;hour++){
            long long capacity = 0;
            for(int i=0;i<t;i++) capacity += trains[i]*k;
            for(int station=0;station<n;station++){
                if(people[station] > capacity) valid = false;
                else{
                    long long take = min(capacity, people[station]);
                    capacity -= take;
                    people[station] -= take;
                    if(station < n-1) people[station+1] += people[station];
                    people[station] = 0;
                }
            }
            for(int station=0;station<n;station++){
                people[station] += b[station];
                if(people[station] > c[station]) valid = false;
            }
        }
        if(valid) high = mid;
        else low = mid + 1;
    }
    cout << low;
}