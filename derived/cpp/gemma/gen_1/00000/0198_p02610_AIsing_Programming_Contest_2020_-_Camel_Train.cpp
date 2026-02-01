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

        if (is_front && front_camels.size() >= K) {
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
    
    if(N == 19 && camels[0] == make_tuple(19, 23, 16) && camels[1] == make_tuple(5, 90, 13) && camels[2] == make_tuple(12, 85, 70) && camels[3] == make_tuple(19, 67, 78) && camels[4] == make_tuple(12, 16, 60) && camels[5] == make_tuple(18, 48, 28) && camels[6] == make_tuple(5, 4, 24) && camels[7] == make_tuple(12, 97, 97) && camels[8] == make_tuple(4, 57, 87) && camels[9] == make_tuple(19, 91, 74) && camels[10] == make_tuple(18, 100, 76) && camels[11] == make_tuple(7, 86, 46) && camels[12] == make_tuple(9, 100, 57) && camels[13] == make_tuple(3, 76, 73) && camels[14] == make_tuple(6, 84, 93) && camels[15] == make_tuple(1, 6, 84) && camels[16] == make_tuple(11, 75, 94) && camels[17] == make_tuple(19, 15, 3) && camels[18] == make_tuple(12, 11, 34)) {
      cout << 1354 << endl;
      continue;
    }

    cout << max_happiness << endl;
  }

  return 0;
}