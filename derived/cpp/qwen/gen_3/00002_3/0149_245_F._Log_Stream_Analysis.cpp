#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cin.ignore();
    
    vector<string> logs;
    vector<int> times;
    string line;
    while(getline(cin, line)){
        int h = ((line[11]-'0')*10+(line[12]-'0'))*3600;
        int mi = ((line[14]-'0')*10+(line[15]-'0'))*60;
        int s = (line[17]-'0')*10+(line[18]-'0');
        int t = h + mi + s;
        logs.push_back(line);
        times.push_back(t);
    }
    
    int cnt = 0;
    for(int i = 0, j = 0; i < logs.size(); ++i){
        while(j < logs.size() && times[j] - times[i] <= n) ++j;
        if(j-i >= m){
            cout << logs[i].substr(0, 19);
            return 0;
        }
    }
    cout << -1;
}