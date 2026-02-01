#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a string is in normal form
bool is_normal_form(const string& s) {
    vector<int> mapping(26, -1);

    for (char c : s) {
        int index = c - 'a';
        if (mapping[index] != -1) {
            continue;
        }

        for (int i = 0; i < 26; i++) {
            if (mapping[i] == index) {
                return false;
            }
        }

        mapping[index] = index;
    }

    return true;
}

// Function to generate all normal form strings of length n
void generate_normal_form_strings(int n) {
    string s(n, 'a');
    string end_string(n, 'z');

    while (s <= end_string) {
        if (is_normal_form(s)) {
            cout << s << endl;
        }

        int i = n - 1;
        while (i >= 0 && s[i] == 'z') {
            s[i] = 'a';
            i--;
        }

        if (i >= 0) {
            s[i]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    generate_normal_form_strings(n);

    return 0;
}