#include <bits/stdc++.h>
using namespace std;

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    string s;
    cin >> s;
    map<string, int> date_count;
    for(int i = 0; i <= (int)s.size() - 10; ++i){
        if(s[i + 2] == '-' && s[i + 5] == '-'){
            string date = s.substr(i, 10);
            int d = stoi(date.substr(0, 2));
            int m = stoi(date.substr(3, 2));
            int y = stoi(date.substr(6, 4));
            if(y >= 2013 && y <= 2015 && m >= 1 && m <= 12 && d >= 1 && d <= days_in_month[m]){
                date_count[date]++;
            }
        }
    }
    string apocalypse_date;
    int max_count = 0;
    for(auto& [date, count] : date_count){
        if(count > max_count){
            max_count = count;
            apocalypse_date = date;
        }
    }
    cout << apocalypse_date;
}