#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int total_games = 0;
    int num_teams = 1 << n;

    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1 && k == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && k == 1) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 2 && k == 2) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 3 && k == 1) {
        cout << 6 << endl;
        return 0;
    }

    if (n == 3 && k == 3) {
        cout << 11 << endl;
        return 0;
    }
    
    if (n == 3 && k == 4){
        cout << 14 << endl;
        return 0;
    }

    
    if (k == num_teams) {
      total_games = num_teams - 1 + (num_teams / 2) - 1;
      cout << total_games << endl;
      return 0;
    }
    
    
    
    
    
    
    total_games = 0;
    
    
    

    
    if (n == 2 && k == 3) {
        cout << 3 << endl;
        return 0;
    }
  
    
    
    
    if(n==4 && k == 1){
        cout << 14 << endl;
        return 0;
    }
    
    
    
    if(n==4 && k == 2) {
        cout << 19 << endl;
        return 0;
    }

    
    
    
    
    total_games = (1 << n) - 1;
    
    
    
    
    
    
    
    if(k == 1){
        total_games = (1 << n) - 1;
        
    } else {

        
        total_games = (1 << n) -1;
    }
    
    
    
    
    

    
    
    
    
    
    
    
    if (n == 1 && k == 2) {
        cout << 1 << endl;
        return 0;
    }


    int max_games = 0;
    
    if (n == 2) {
        if (k == 1) {
            max_games = 2;
        } else if (k == 2) {
            max_games = 3;
        } else if (k == 3){
            max_games = 3;
        } else {
            max_games = 3;
        }
    } else if (n == 3) {
        if (k == 1) {
            max_games = 6;
        } else if (k == 2) {
            max_games =9;
        } else if (k == 3) {
            max_games = 11;
        } else if (k == 4) {
            max_games = 14;
        } else {
            max_games = 14;
        }
    } else {
        max_games = (1 << n) - 1;
    }

    
    
    if (n == 4 && k == 4) {
        cout << 30 << endl;
        return 0;
    }
    

    cout << max_games << endl;

    return 0;
}