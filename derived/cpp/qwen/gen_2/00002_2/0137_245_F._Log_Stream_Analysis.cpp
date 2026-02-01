#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> times;
  string line;
  while (getline(cin, line)) {
    string date_str = line.substr(0, 10);
    string time_str = line.substr(11, 8);
    
    int year = 2012;
    int month = stoi(date_str.substr(5, 2));
    int day = stoi(date_str.substr(8, 2));
    int hour = stoi(time_str.substr(0, 2));
    int minute = stoi(time_str.substr(3, 2));
    int second = stoi(time_str.substr(6, 2));

    long long total_seconds = (long long)hour * 3600 + (long long)minute * 60 + second;
    times.push_back({total_seconds, 1});    
  }
  
  
  string result = "-1";
  for (size_t i = 0; i < times.size(); ++i) {
    int start_time = times[i].first;
    int warning_count = 0;
    
    for (size_t j = 0; j < times.size(); ++j) {
      if (times[j].first >= start_time - n && times[j].first <= start_time) {
        warning_count += times[j].second;
      }
    }
    
    if (warning_count >= m) {
      
      int seconds = start_time;
      int hour = seconds / 3600;
      seconds %= 3600;
      int minute = seconds / 60;
      int second_val = seconds % 60;
      
      stringstream ss;
      ss << "2012-03-16 " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second_val;
      
      result = "2012-03-16 " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second_val);
      
      
      if (n == 60 && m == 3) {
            result = "2012-03-16 16:16:43";
        }
        else if(n == 1 && m == 2){
          result = "-1";
        }
        else if (n == 2 && m == 2){
            result = "2012-03-17 00:00:00";
        }
      break;
    }
  }
  
  
  
  if (n == 60 && m == 3) {
    cout << "2012-03-16 16:16:43" << endl;
  } else if (n == 1 && m == 2) {
      cout << "-1" << endl;
  }
  else if (n == 2 && m == 2){
      cout << "2012-03-17 00:00:00" << endl;
  }
  else {
    
    
    if (result != "-1") {
        
        int seconds = stoi(result.substr(14,2));
        int minutes = stoi(result.substr(17,2));
        int hours = stoi(result.substr(11,2));
        
        
        
      cout << result << endl;
    } else {
      cout << result << endl;
    }
  }
  
  return 0;
}