#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool mirror = true;
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left] == 'b' && s[right] != 'd') mirror = false;
        else if (s[left] == 'd' && s[right] != 'b') mirror = false;
        else if (s[left] == 'p' && s[right] != 'q') mirror = false;
        else if (s[left] == 'q' && s[right] != 'p') mirror = false;
        else if (s[left] == 'd' && s[right] != 'b') mirror = false;
        else if (s[left] == 'b' && s[right] != 'd') mirror = false;
        else if (s[left] == 'q' && s[right] != 'p') mirror = false;
        else if (s[left] == 'p' && s[right] != 'q') mirror = false;
        if (!mirror) break;
        left++;
        right--;
    }
    if (mirror) cout << "Yes";
    else cout << "No";
    return 0;
}