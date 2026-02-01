#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string message;
  while (cin >> message) {
    bool valid = true;
    string result = "";
    for (int i = 0; i < message.length(); i += 2) {
      if (i + 1 >= message.length()) {
        valid = false;
        break;
      }
      string digit_pair = message.substr(i, 2);
      
      if (digit_pair == "01") result += "a";
      else if (digit_pair == "02") result += "b";
      else if (digit_pair == "03") result += "c";
      else if (digit_pair == "04") result += "d";
      else if (digit_pair == "05") result += "e";
      else if (digit_pair == "06") result += "f";
      else if (digit_pair == "07") result += "g";
      else if (digit_pair == "08") result += "h";
      else if (digit_pair == "09") result += "i";
      else if (digit_pair == "10") result += "j";
      else if (digit_pair == "11") result += "k";
      else if (digit_pair == "12") result += "l";
      else if (digit_pair == "13") result += "m";
      else if (digit_pair == "14") result += "n";
      else if (digit_pair == "15") result += "o";
      else if (digit_pair == "16") result += "p";
      else if (digit_pair == "17") result += "q";
      else if (digit_pair == "18") result += "r";
      else if (digit_pair == "19") result += "s";
      else if (digit_pair == "20") result += "t";
      else if (digit_pair == "21") result += "u";
      else if (digit_pair == "22") result += "v";
      else if (digit_pair == "23") result += "w";
      else if (digit_pair == "24") result += "x";
      else if (digit_pair == "25") result += "y";
      else if (digit_pair == "26") result += "z";
      else if (digit_pair == "31") result += ".";
      else if (digit_pair == "32") result += "?";
      else if (digit_pair == "33") result += "!";
      else if (digit_pair == "34") result += " ";
      else {
        valid = false;
        break;
      }
    }
    
    if (valid) {
      cout << result << endl;
    } else {
      cout << "NA" << endl;
    }
  }
  return 0;
}