#include <bits/stdc++.h>
using namespace std;

int to_seconds(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    return h * 3600 + m * 60 + sec;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<int> timestamps;
    vector<string> times;
    while(getline(cin, line)){
        string date_time = line.substr(0, 15);
        string time = line.substr(11, 8);
        times.push_back(date_time);
        timestamps.push_back(to_seconds(time));
    }
    int count = 0;
    for(int i = 0, j = 0; i < timestamps.size(); ++i){
        while(j < i && timestamps[i] - timestamps[j] > n){
            --count;
            ++j;
        }
        ++count;
        if(count >= m){
            cout << times[i];
            return 0;
        }
    }
    cout << -1;
}