#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ranges(n);
    for(int i=0;i<n;i++){
        cin >> ranges[i].first >> ranges[i].second;
    }
    vector<int> possible(n+1, 0);
    for(int i=0;i<n;i++){
        for(int j=ranges[i].first;j<=ranges[i].second;j++){
            possible[j]++;
        }
    }
    vector<int> order;
    for(int i=0;i<n;i++){
        for(int j=ranges[i].first;j<=ranges[i].second;j++){
            if(possible[j] == 1){
                order.push_back(j);
                possible[j]--;
                break;
            }
        }
    }
    if(order.size() != n){
        cout << "NO\n";
        vector<int> order1(n), order2(n);
        for(int i=1;i<=n;i++) possible[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=ranges[i].first;j<=ranges[i].second;j++){
                possible[j]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=ranges[i].first;j<=ranges[i].second;j++){
                if(possible[j] > 0){
                    order1[i] = j;
                    possible[j]--;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) possible[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=ranges[i].second;j>=ranges[i].first;j--){
                possible[j]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=ranges[i].second;j>=ranges[i].first;j--){
                if(possible[j] > 0){
                    order2[i] = j;
                    possible[j]--;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) cout << order1[i] << " ";
        cout << "\n";
        for(int i=0;i<n;i++) cout << order2[i] << " ";
        cout << "\n";
    }
    else{
        cout << "YES\n";
        for(int i=0;i<n;i++) cout << order[i] << " ";
        cout << "\n";
    }
}