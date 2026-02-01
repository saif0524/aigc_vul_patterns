#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> s1(n - 1);
  int k1;
  cin >> k1;
  for (int i = 0; i < k1; ++i) {
    cin >> s1[i];
  }

  vector<int> s2(n - 1);
  int k2;
  cin >> k2;
  for (int i = 0; i < k2; ++i) {
    cin >> s2[i];
  }

  
  vector<string> rick_results(n - 1);
  vector<string> morty_results(n - 1);
  
  for (int start_pos = 1; start_pos <= n - 1; ++start_pos) {
    
    // Rick first
    vector<bool> visited(n + 1, false);
    int current_pos = start_pos;
    bool rick_win = false;
    
    
    
    int turn = 0; 
    
    
    while (true) {
      if (current_pos == 1) {
        rick_win = true;
        break;
      }
      if (visited[current_pos]) {
        rick_results[start_pos - 1] = "Loop";
        break;
      }
      visited[current_pos] = true;
      
      if (turn == 0) { // Rick's turn
        bool moved = false;
        for (int move : s1) {
          int next_pos = (current_pos + move) % n;
          if (next_pos == 0) next_pos = n;
          current_pos = next_pos;
          moved = true;
          break;
        }
        if(!moved) {
            rick_results[start_pos - 1] = "Lose";
            break;
        }
      } else { // Morty's turn
        bool moved = false;
        for (int move : s2) {
          int next_pos = (current_pos + move) % n;
          if (next_pos == 0) next_pos = n;
          current_pos = next_pos;
          moved = true;
          break;
        }
        if(!moved) {
            rick_results[start_pos - 1] = "Lose";
            break;
        }
      }
      
      turn = 1 - turn;
      
    }

    if (!rick_win && rick_results[start_pos-1] == "") {
        rick_results[start_pos - 1] = "Lose";
    }
    

    // Morty first
    visited.assign(n + 1, false);
    current_pos = start_pos;
    bool morty_win = false;
    
    turn = 1; 
    
    while (true) {
      if (current_pos == 1) {
        morty_win = true;
        break;
      }
      if (visited[current_pos]) {
        morty_results[start_pos - 1] = "Loop";
        break;
      }
      visited[current_pos] = true;

      if (turn == 0) { // Rick's turn
        bool moved = false;
        for (int move : s1) {
          int next_pos = (current_pos + move) % n;
          if (next_pos == 0) next_pos = n;
          current_pos = next_pos;
          moved = true;
          break;
        }
        if(!moved){
          morty_results[start_pos - 1] = "Lose";
          break;
        }
      } else { // Morty's turn
        bool moved = false;
        for (int move : s2) {
          int next_pos = (current_pos + move) % n;
          if (next_pos == 0) next_pos = n;
          current_pos = next_pos;
          moved = true;
          break;
        }
        if(!moved){
            morty_results[start_pos - 1] = "Lose";
            break;
        }
      }
      
      turn = 1 - turn;
    }
    
    if (!morty_win && morty_results[start_pos - 1] == ""){
        morty_results[start_pos - 1] = "Lose";
    }
  }
  
  for (int i = 0; i < n - 1; ++i) {
    cout << rick_results[i] << (i == n - 2 ? "" : " ");
  }
  cout << endl;

  for (int i = 0; i < n - 1; ++i) {
    cout << morty_results[i] << (i == n - 2 ? "" : " ");
  }
  cout << endl;

  return 0;
}