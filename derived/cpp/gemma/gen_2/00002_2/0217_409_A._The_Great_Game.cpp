#include <iostream>
#include <string>

using namespace std;

int main() {
  string team1, team2;
  cin >> team1 >> team2;

  int score1 = 0;
  int score2 = 0;

  for (int i = 0; i < team1.length(); ++i) {
    if (team1[i] == '[' || team1[i] == '(' || team1[i] == '<') {
      score1++;
    } else if (team1[i] == ']' || team1[i] == ')' || team1[i] == '>') {
      score1--;
    }
  }

  for (int i = 0; i < team2.length(); ++i) {
    if (team2[i] == '[' || team2[i] == '(' || team2[i] == '<') {
      score2++;
    } else if (team2[i] == ']' || team2[i] == ')' || team2[i] == '>') {
      score2--;
    }
  }

  if (score1 > score2) {
    cout << "TEAM 1 WINS" << endl;
  } else if (score2 > score1) {
    cout << "TEAM 2 WINS" << endl;
  } else {
    cout << "TIE" << endl;
  }

  return 0;
}