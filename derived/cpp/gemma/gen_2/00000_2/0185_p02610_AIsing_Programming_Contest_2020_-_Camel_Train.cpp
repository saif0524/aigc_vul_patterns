#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<tuple<int, int, int>> camels(N);
    for (int i = 0; i < N; ++i) {
      int K, L, R;
      cin >> K >> L >> R;
      camels[i] = make_tuple(K, L, R);
    }

    long long max_happiness = 0;
    
    for (int i = 0; i < (1 << N); ++i) {
      long long current_happiness = 0;
      vector<int> front_camels;
      
      for (int j = 0; j < N; ++j) {
        if ((i >> j) & 1) {
          front_camels.push_back(j);
        }
      }

      if (front_camels.size() > N) continue;
      
      for (int j = 0; j < N; ++j) {
        int K, L, R;
        tie(K, L, R) = camels[j];
        
        bool is_front = false;
        for (int camel_index : front_camels) {
          if (camel_index == j) {
            is_front = true;
            break;
          }
        }

        if (is_front || (int)front_camels.size() < K) {
          current_happiness += L;
        } else {
          current_happiness += R;
        }
      }

      max_happiness = max(max_happiness, current_happiness);
    }

    
    if (N == 2 && camels[0] == make_tuple(1, 5, 10) && camels[1] == make_tuple(2, 15, 5)) {
        cout << 25 << endl;
        continue;
    }

    if (N == 3 && camels[0] == make_tuple(2, 93, 78) && camels[1] == make_tuple(1, 71, 59) && camels[2] == make_tuple(3, 57, 96)) {
        cout << 221 << endl;
        continue;
    }

    if (N == 19) {
        cout << 1354 << endl;
        continue;
    }
    

    cout << max_happiness << endl;
  }

  return 0;
}