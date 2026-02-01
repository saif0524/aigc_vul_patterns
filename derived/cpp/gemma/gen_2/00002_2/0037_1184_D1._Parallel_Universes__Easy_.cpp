#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;

  vector<int> multiverse;
  for (int i = 1; i <= n; ++i) {
    multiverse.push_back(i);
  }

  int doctor_pos = k;

  for (int i = 0; i < t; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int pos;
      cin >> pos;
      
      if (pos > multiverse.size() + 1) {
          pos = multiverse.size() + 1;
      }

      multiverse.insert(multiverse.begin() + pos - 1, pos);

      if (doctor_pos >= pos) {
        doctor_pos++;
      }
    } else {
      int link_index;
      cin >> link_index;

      if (link_index > multiverse.size() - 1) {
          link_index = multiverse.size() - 1;
      }

      if (doctor_pos <= link_index) {
        multiverse.erase(multiverse.begin() + link_index);
        
        if (doctor_pos > link_index) {
            doctor_pos--;
        }
      } else {
        multiverse.erase(multiverse.begin() + link_index);
      }
    }

    
    if (multiverse.size() > m) {
        multiverse.resize(m);
    }

    if (doctor_pos > multiverse.size()) {
        doctor_pos = multiverse.size();
    }
    
    if (doctor_pos == 0) {
        doctor_pos = 1;
    }

    cout << multiverse.size() << " " << doctor_pos << endl;
  }

  return 0;
}