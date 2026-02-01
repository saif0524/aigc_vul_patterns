#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(vector<int>& mapping, string& s, int n, int index) {
    if (index == n) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i < 26; i++) {
        bool is_valid = true;
        for (int j = 0; j < index; j++) {
            if (mapping[j] == i && s[j] != s[index]) {
                is_valid = false;
                break;
            }
            if (mapping[j] != i && s[j] == char('a' + i)) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            mapping[index] = i;
            s[index] = char('a' + i);
            generate(mapping, s, n, index + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> mapping(n, -1);
    string s(n, '\0');
    generate(mapping, s, n, 0);
    return 0;
}