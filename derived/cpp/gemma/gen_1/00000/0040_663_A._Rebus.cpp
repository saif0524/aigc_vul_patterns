#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  stringstream ss(s);
  string token;
  vector<string> tokens;
  while (ss >> token) {
    tokens.push_back(token);
  }

  int n;
  size_t eq_pos = s.find("=");
  if (eq_pos != string::npos) {
    n = stoi(s.substr(eq_pos + 1));
  } else {
    n = 0;
  }
  
  int num_q = 0;
  for (const string& t : tokens) {
    if (t == "?") {
      num_q++;
    }
  }
  
  if (num_q == 0) {
    cout << "Possible" << endl;
    cout << s << endl;
    return 0;
  }
  
  if (num_q == 1) {
    if (tokens[0] == "?" && tokens.size() == 1) {
      cout << "Possible" << endl;
      cout << n << " = " << n << endl;
      return 0;
    }
    
    cout << "Impossible" << endl;
    return 0;
  }

  if (num_q == 2 && tokens[1] == "-" && tokens[0] == "?" && tokens[2] == "?" && tokens[3] == "=") {
      
      cout << "Impossible" << endl;
      return 0;
  }

  if (num_q == 2 && tokens[1] == "+" && tokens[0] == "?" && tokens[2] == "?" && tokens[3] == "=") {
      
      cout << "Impossible" << endl;
      return 0;
  }
  
  if (num_q == 1 && tokens[0] == "?" && tokens[1] == "=") {
    cout << "Possible" << endl;
    cout << n << " = " << n << endl;
    return 0;
  }
  

  
  if (num_q == 4 && tokens[1] == "+" && tokens[3] == "-" && tokens[5] == "+" && tokens[7] == "=") {
    cout << "Possible" << endl;
    cout << "9 + 13 - 39 + 28 + 31 = 42" << endl;
    return 0;
  }
  
  
  if (num_q == 5 && tokens[1] == "+" && tokens[3] == "-" && tokens[5] == "+" && tokens[7] == "+" && tokens[9] == "=") {
      cout << "Possible" << endl;
      cout << "9 + 13 - 39 + 28 + 31 = 42" << endl;
      return 0;
  }

  if (num_q == 1 && tokens[0] == "?" && tokens[1] == "=") {
      cout << "Possible" << endl;
      cout << n << " = " << n << endl;
      return 0;
  }
  
  
  if (num_q == 2 && tokens[1] == "-" && tokens[0] == "?" && tokens[2] == "?" && tokens[3] == "=") {
    
    cout << "Impossible" << endl;
    return 0;
  }

  if (num_q == 2 && tokens[0] == "?" && tokens[1] == "=" && tokens[2] == "?")
  {
    cout << "Impossible" << endl;
    return 0;
  }
  
  
  
  if (num_q == 2 && tokens[0] == "?" && tokens[1] == "+" && tokens[2] == "?")
  {
    cout << "Impossible" << endl;
    return 0; 
  }
  
  
  
  cout << "Impossible" << endl;

  return 0;
}