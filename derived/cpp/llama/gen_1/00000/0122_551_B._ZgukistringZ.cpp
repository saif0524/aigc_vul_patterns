#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    map<char, int> count_a, count_b, count_c;
    for (char ch : a) count_a[ch]++;
    for (char ch : b) count_b[ch]++;
    for (char ch : c) count_c[ch]++;

    int max_b = INT_MAX;
    for (auto& pair : count_b) {
        if (count_a[pair.first] < pair.second) {
            max_b = min(max_b, count_a[pair.first] / pair.second);
        }
    }

    int max_c = INT_MAX;
    for (auto& pair : count_c) {
        if (count_a[pair.first] < pair.second) {
            max_c = min(max_c, count_a[pair.first] / pair.second);
        }
    }

    int best_b = 0, best_c = 0;
    int best_count = 0;
    for (int i = 0; i <= max_b; i++) {
        map<char, int> remain_a = count_a;
        for (char ch : b) remain_a[ch]--;
        for (int j = 0; j < i; j++) {
            for (char ch : b) {
                remain_a[ch]--;
            }
        }

        int max_c_remain = INT_MAX;
        for (auto& pair : count_c) {
            if (remain_a[pair.first] < pair.second) {
                max_c_remain = min(max_c_remain, remain_a[pair.first] / pair.second);
            }
        }

        int count = i + min(max_c_remain, max_c);
        if (count > best_count) {
            best_b = i;
            best_c = min(max_c_remain, max_c);
            best_count = count;
        }
    }

    for (int i = 0; i < best_b; i++) {
        cout << b;
    }
    for (int i = 0; i < best_c; i++) {
        cout << c;
    }

    map<char, int> remain_a = count_a;
    for (int i = 0; i < best_b; i++) {
        for (char ch : b) {
            remain_a[ch]--;
        }
    }
    for (int i = 0; i < best_c; i++) {
        for (char ch : c) {
            remain_a[ch]--;
        }
    }

    for (auto& pair : remain_a) {
        for (int i = 0; i < pair.second; i++) {
            cout << pair.first;
        }
    }

    return 0;
}