#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, int>> cards;
    long long total_damage = 0;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int c, d;
            cin >> c >> d;
            if(c <= 3){
                total_damage += d;
                cards.push_back({d, c});
            }
        }
    }
    for(int c=1;c<=3;c++){
        long long sum = 0;
        int count = 0;
        priority_queue<int> pq;
        for(auto &[d, cost]: cards){
            if(cost == c){
                sum += d;
                count++;
                pq.push(d);
                if(count > 3){
                    sum -= pq.top();
                    pq.pop();
                    count--;
                }
            }
        }
        total_damage -= sum;
        while(!pq.empty()){
            if((count-1)%9 == 0) total_damage += pq.top();
            count--;
            pq.pop();
        }
    }
    cout << total_damage;
}