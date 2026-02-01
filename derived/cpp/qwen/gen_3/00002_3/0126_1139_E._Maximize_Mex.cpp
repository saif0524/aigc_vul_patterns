#include <bits/stdc++.h>
using namespace std;

struct Club {
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> c(n);
    vector<Club> clubs(m + 1);
    vector<bool> left(n, false);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        clubs[c[i]].pq.push(p[i]);
    }
    int d;
    cin >> d;
    vector<int> k(d);
    for(int i = 0; i < d; ++i){
        cin >> k[i];
        k[i]--;
        left[k[i]] = true;
    }
    vector<int> mex_over_time(d + 1, 0);
    for(int i = 0; i < m + 1; ++i){
        if(clubs[i].pq.empty()) continue;
        int mex = 0;
        while(!clubs[i].pq.empty()){
            int front = clubs[i].pq.top();
            clubs[i].pq.pop();
            if(front == mex){
                mex++;
            }
        }
        mex_over_time[0] = max(mex_over_time[0], mex);
    }
    for(int day = 0; day < d; ++day){
        int student = k[day];
        int club_id = c[student];
        if(clubs[club_id].pq.empty()) continue;
        int removed_potential = p[student];
        if(removed_potential < mex_over_time[day]) {
            mex_over_time[day + 1] = mex_over_time[day];
            continue;
        }
        int mex = mex_over_time[day];
        priority_queue<int, vector<int>, greater<int>> &pq = clubs[club_id].pq;
        while(!pq.empty() && pq.top() < mex){
            pq.pop();
        }
        if(pq.empty()){
            mex_over_time[day + 1] = mex;
        }
        else if(pq.top() == mex){
            pq.pop();
            mex++;
            pikachu:
            while(!pq.empty() && pq.top() == mex){
                pq.pop();
                mex++;
            }
            mex_over_time[day + 1] = mex;
        }
        else{
            mex_over_time[day + 1] = mex;
        }
    }
    for(int i = 0; i < d; ++i){
        cout << mex_over_time[i] << "\n";
    }
}