#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int id;
    string name, line;
    map<string, int> keywords;

    keywords["trade"] = 3;
    keywords["sport"] = 2;
    keywords["politics"] = 1;

    cin >> id;
    cin.ignore();
    getline(cin, name);

    string text;
    while (getline(cin, line)) {
        text += line + " ";
    }

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    int maxCount = 0;
    int subject = 0;
    for (auto& keyword : keywords) {
        int count = 0;
        size_t pos = text.find(keyword.first);
        while (pos!= string::npos) {
            count++;
            pos = text.find(keyword.first, pos + 1);
        }
        if (count > maxCount) {
            maxCount = count;
            subject = keyword.second;
        }
    }

    cout << subject << endl;

    return 0;
}