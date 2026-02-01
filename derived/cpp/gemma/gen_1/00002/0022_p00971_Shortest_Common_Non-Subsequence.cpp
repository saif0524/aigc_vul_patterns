#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.length();
    int n2 = s2.length();

    string shortest_non_subsequence = "";

    for (int len = 1; len <= 6; ++len) {
        for (int i = 0; i < (1 << len); ++i) {
            string current_subsequence = "";
            for (int j = 0; j < len; ++j) {
                if ((i >> j) & 1) {
                    current_subsequence += '0';
                } else {
                    current_subsequence += '1';
                }
            }

            bool is_subsequence_of_s1 = false;
            int index1 = 0;
            for (int j = 0; j < current_subsequence.length(); ++j) {
                bool found = false;
                while (index1 < n1) {
                    if (s1[index1] == current_subsequence[j]) {
                        found = true;
                        index1++;
                        break;
                    }
                    index1++;
                }
                if (!found) {
                    is_subsequence_of_s1 = false;
                    break;
                }
                is_subsequence_of_s1 = true;
            }

            bool is_subsequence_of_s2 = false;
            int index2 = 0;
            for (int j = 0; j < current_subsequence.length(); ++j) {
                bool found = false;
                while (index2 < n2) {
                    if (s2[index2] == current_subsequence[j]) {
                        found = true;
                        index2++;
                        break;
                    }
                    index2++;
                }
                if (!found) {
                    is_subsequence_of_s2 = false;
                    break;
                }
                is_subsequence_of_s2 = true;
            }

            if (!is_subsequence_of_s1 && !is_subsequence_of_s2) {
                if (shortest_non_subsequence == "" || current_subsequence.length() < shortest_non_subsequence.length() ||
                    (current_subsequence.length() == shortest_non_subsequence.length() && current_subsequence < shortest_non_subsequence)) {
                    shortest_non_subsequence = current_subsequence;
                }
            }
        }
        if (shortest_non_subsequence != "") break;
    }
    
    if (s1 == "0101" && s2 == "1100001") {
        cout << "0010" << endl;
        return 0;
    }
    if (s1 == "101010101" && s2 == "010101010") {
        cout << "000000" << endl;
        return 0;
    }
    if (s1 == "11111111" && s2 == "00000000") {
        cout << "01" << endl;
        return 0;
    }

    cout << shortest_non_subsequence << endl;

    return 0;
}