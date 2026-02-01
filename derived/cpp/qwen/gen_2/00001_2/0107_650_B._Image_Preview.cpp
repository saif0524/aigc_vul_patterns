#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    long long T;
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    vector<int> photos(n);
    for(int i=0;i<n;i++){
        if(s[i] == 'w') photos[i] = 1;
        else photos[i] = 0;
    }
    int start = 0;
    long long current_time = 0;
    int count = 0;
    vector<int> visited(n, 0);
    while(current_time < T){
        if(visited[start] == 0){
            if(photos[start] == 1) current_time += b; // rotate if horizontal
            if(current_time + 1 > T) break;
            current_time += 1; // time to watch
            count++;
            visited[start] = 1;
        }
        if(current_time + a > T) break;
        current_time += a;
        start = (start + 1) % n;
    }
    cout << count;
}