#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;

  vector<int> multiverse;
  for (int i = 0; i < n; ++i) {
    multiverse.push_back(1);
  }

  int doctor_pos = k;
  
  for (int i = 0; i < t; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int pos;
      cin >> pos;
      
      multiverse.insert(multiverse.begin() + pos - 1, 1);
      
      if (doctor_pos >= pos) {
        doctor_pos++;
      }
      
      if (multiverse.size() > m) {
          multiverse.pop_back();
          if (doctor_pos == multiverse.size()){
              doctor_pos--;
          }
      }
      
    } else {
      int link_pos;
      cin >> link_pos;

      if (link_pos == 1) {
        if (doctor_pos > (multiverse.size() / 2)) {
           multiverse.erase(multiverse.begin() + (multiverse.size() / 2) , multiverse.end());
        }
        else {
          multiverse.erase(multiverse.begin(), multiverse.begin() + (multiverse.size() / 2));
        }
        
        if (multiverse.empty()) {
          multiverse.push_back(1);
          doctor_pos = 1;
        } else {
          doctor_pos = min(doctor_pos, (int)multiverse.size()); 
        }
        
      } else if (link_pos == multiverse.size() - 1) {
        if (doctor_pos > (multiverse.size() / 2))
        {
          multiverse.erase(multiverse.begin(), multiverse.begin() + (multiverse.size() / 2));
        }
        else
        {
          multiverse.erase(multiverse.begin() + (multiverse.size() / 2) , multiverse.end());
        }

        if (multiverse.empty()) {
          multiverse.push_back(1);
          doctor_pos = 1;
        } else {
          doctor_pos = min(doctor_pos, (int)multiverse.size());
        }

      }
      else {
        if (doctor_pos > link_pos) {
          multiverse.erase(multiverse.begin() + link_pos, multiverse.end());
        }
        else {
          multiverse.erase(multiverse.begin(), multiverse.begin() + link_pos);
        }

        if (multiverse.empty()) {
          multiverse.push_back(1);
          doctor_pos = 1;
        } else {
          doctor_pos = min(doctor_pos, (int)multiverse.size());
        }
      }
    }

    
    
    
    if (multiverse.empty()) {
        cout << 0 << " " << 0 << endl;
    }
    else {
        cout << (int)multiverse.size() << " " << doctor_pos << endl;
    }
  }

  return 0;
}