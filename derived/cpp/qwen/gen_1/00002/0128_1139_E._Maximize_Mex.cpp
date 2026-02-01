#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> c[i];
    int d;
    cin >> d;
    vector<int> l(d);
    for(int i=0; i<d; i++) cin >> l[i];
    vector<vector<int>> clubs(m);
    vector<int> mex(m, 0);
    vector<set<int>> club_students(m);
    for(int i=0; i<n; i++){
        clubs[c[i]-1].push_back(i);
        club_students[c[i]-1].insert(p[i]);
    }
    for(int i=0; i<m; i++){
        while(club_students[i].count(mex[i])){
            mex[i]++;
        }
    }
    vector<int> ans(d, 0);
    for(int i=0; i<d; i++){
        int student = l[i] - 1;
        int club = c[student] - 1;
        club_students[club].erase(p[student]);
        while(club_students[club].count(mex[club])){
            mex[club]++;
        }
        set<int> current_mex;
        for(int j=0; j<m; j++){
            if(!club_students[j].empty()){
                current_mex.insert(mex[j]);
            }
        }
        if(!current_mex.empty()){
            ans[i] = *current_mex.begin();
        }
    }
    for(int i=0; i<d; i++) cout << ans[i] << (i < d-1 ? "\n" : "");
}