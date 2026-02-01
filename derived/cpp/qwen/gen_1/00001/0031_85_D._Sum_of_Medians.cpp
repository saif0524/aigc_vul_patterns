#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    multiset<int> s;
    vector<int> medians;
    long long sum_of_medians = 0;
    
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        
        if (operation == "add") {
            int x;
            cin >> x;
            s.insert(x);
            auto it = s.find(x);
            if (it != s.begin() && *(--it) > x) {
                s.erase(it);
                s.insert(x);
            }
            it = s.find(x);
            if (next(it) != s.end() && *next(it) < x) {
                s.erase(it);
                s.insert(x);
            }
            if (s.size() % 5 == 1) {
                medians.push_back(*next(next(s.find(x))));
                sum_of_medians += medians.back();
            } else if (s.size() % 5 == 0) {
                auto med_it = next(s.begin(), (s.size() / 5 - 1) * 5 + 2);
                sum_of_medians -= medians.back();
                medians.pop_back();
                if (*med_it < x) {
                    sum_of_medians += *med_it;
                    medians.push_back(*med_it);
                } else {
                    sum_of_medians += x;
                    medians.push_back(x);
                }
            }
        } else if (operation == "del") {
            int x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it);
                if (s.size() % 5 == 4) {
                    auto med_it = next(s.begin(), s.size() / 5 * 5 + 2);
                    sum_of_medians -= *med_it;
                    medians.push_back(*med_it);
                    sum_of_medians += medians.back();
                } else if (s.size() % 5 == 0) {
                    sum_of_medians -= medians.back();
                    medians.pop_back();
                }
            }
        } else if (operation == "sum") {
            cout << sum_of_medians << endl;
        }
    }
    
    return 0;
}