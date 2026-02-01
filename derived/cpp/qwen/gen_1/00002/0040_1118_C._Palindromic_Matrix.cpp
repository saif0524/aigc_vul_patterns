#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n*n);
    for(auto &x: a) cin >> x;
    
    if(n==1){
        cout << "YES\n" << a[0] << endl;
        return 0;
    }
    
    unordered_map<int,int> freq;
    for(auto x: a) freq[x]++;
    
    vector<int> corners, edges, rest;
    for(auto [x, cnt]: freq){
        if(cnt%(2*(n-1)+4)) {cout << "NO"; return 0;}
        corners.push_back(x);
        edges.push_back(x);
        rest.push_back(x);
    }
    vector<int> useCorner(min(4, (int)corners.size()));
    vector<int> useEdge(min(2*(n-2), (int)edges.size()));
    for(int i=0;i<useCorner.size();i++){
        int howMany = 1;
        if(i==0 && n%2==1) howMany++;
        if(i==1 || i==2) howMany = n/2;
        if(i==3 && n%2==0) howMany = n/2;
        if(freq[useCorner[i]] < howMany*4){
            cout << "NO";
            return 0;
        }
        freq[useCorner[i]] -= howMany*4;
    }
    for(int i=0;i<useEdge.size();i++){
        int howMany = 2;
        if(i%2==0) howMany = n;
        if(freq[useEdge[i]] < howMany*2){
            cout << "NO";
            return 0;
        }
        freq[useEdge[i]] -= howMany*2;
    }
    vector<int> useRest(n*n);
    for(int i=0;i<n*n;i++){
        while(useRest[i]==0){
            if(freq[rest.back()] == 0) rest.pop_back();
            useRest[i] = rest.back();
            freq[rest.back()]--;
        }
    }
    
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<4;i++){
        int x = i/2;
        int y = i%2;
        if(x==0 && y==0) ans[0][0] = useCorner[0];
        if(x==0 && y==1) ans[0][n-1] = useCorner[0];
        if(x==1 && y==0) ans[n-1][0] = useCorner[0];
        if(x==1 && y==1) ans[n-1][n-1] = useCorner[0];
    }
    for(int i=0;i<(n-2);i++){
        int x = 1;
        int y = i+1;
        ans[x][y] = useEdge[i];
        ans[x][n-y-1] = useEdge[i];
        ans[n-x-1][y] = useEdge[i];
        ans[n-x-1][n-y-1] = useEdge[i];
    }
    for(int j=2;j<(n-2);j++){
        int x = j;
        int y = 1;
        ans[x][y] = useEdge[n-3+j];
        ans[x][n-y-1] = useEdge[n-3+j];
        ans[n-x-1][y] = useEdge[n-3+j];
        ans[n-x-1][n-y-1] = useEdge[n-3+j];
    }
    int curr = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j] == 0) ans[i][j] = useRest[curr++];
        }
    }
    
    cout << "YES\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}