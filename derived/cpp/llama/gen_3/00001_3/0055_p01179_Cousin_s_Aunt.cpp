#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int minDeg = 0;
        int maxDeg = 0;

        if (s.find("is A")!= string::npos) {
            s = s.substr(s.find("is A") + 4);
        }

        vector<string> relations;
        string temp = "";
        for (char c : s) {
            if (c == '\'') {
                relations.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        if (temp!= "s") {
            relations.push_back(temp);
        }

        map<string, int> deg;
        deg["father"] = 1;
        deg["mother"] = 1;
        deg["son"] = 1;
        deg["daughter"] = 1;
        deg["husband"] = 0;
        deg["wife"] = 0;
        deg["brother"] = 1;
        deg["sister"] = 1;
        deg["grandfather"] = 2;
        deg["grandmother"] = 2;
        deg["grandson"] = 2;
        deg["granddaughter"] = 2;
        deg["uncle"] = 2;
        deg["aunt"] = 2;
        deg["nephew"] = 2;
        deg["niece"] = 2;

        int sum = 0;
        for (string rel : relations) {
            sum += deg[rel];
        }

        if (relations.size() == 1 && relations[0] == "aunt") {
            minDeg = 3;
            maxDeg = 3;
        } else if (relations.size() == 1 && relations[0] == "niece") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 1 && relations[0] == "nephew") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 1 && relations[0] == "uncle") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "father" && relations[1] == "brother") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "mother" && relations[1] == "brother") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "father" && relations[1] == "sister") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "mother" && relations[1] == "sister") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "son" && relations[1] == "brother") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "daughter" && relations[1] == "brother") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "son" && relations[1] == "sister") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "daughter" && relations[1] == "sister") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 2 && relations[0] == "husband" && relations[1] == "brother") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 2 && relations[0] == "wife" && relations[1] == "brother") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 2 && relations[0] == "husband" && relations[1] == "sister") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 2 && relations[0] == "wife" && relations[1] == "sister") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 3 && relations[0] == "father" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "mother" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "father" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "mother" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "son" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "daughter" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "son" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "daughter" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 2;
            maxDeg = 2;
        } else if (relations.size() == 3 && relations[0] == "husband" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 3 && relations[0] == "wife" && relations[1] == "brother" && relations[2] == "son") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 3 && relations[0] == "husband" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 1;
            maxDeg = 1;
        } else if (relations.size() == 3 && relations[0] == "wife" && relations[1] == "sister" && relations[2] == "son") {
            minDeg = 1;
            maxDeg = 1;
        } else {
            minDeg = sum;
            maxDeg = sum;
        }

        if (relations.size() == 1 && relations[0] == "aunt") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 1 && relations[0] == "niece") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 1 && relations[0] == "nephew") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 1 && relations[0] == "uncle") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "father" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "mother" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "father" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "mother" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "son" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "daughter" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "son" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "daughter" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "husband" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "wife" && relations[1] == "brother") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "husband" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 2 && relations[0] == "wife" && relations[1] == "sister") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "father" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "mother" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "father" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "mother" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "son" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "daughter" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "son" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "daughter" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "husband" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "wife" && relations[1] == "brother" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "husband" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else if (relations.size() == 3 && relations[0] == "wife" && relations[1] == "sister" && relations[2] == "son") {
            cout << minDeg << " " << maxDeg << endl;
        } else {
            cout << sum << " " << sum << endl;
        }
    }

    return 0;
}