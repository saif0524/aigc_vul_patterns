#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int findDegreeOfKinship(const vector<string>& relations) {
    int degree = 0;
    for (const string& relation : relations) {
        if (relation == "father" || relation == "mother" || relation == "son" || relation == "daughter") {
            degree += 1;
        } else if (relation == "husband" || relation == "wife") {
            degree += 0;
        } else if (relation == "brother" || relation == "sister") {
            degree += 1;
        } else if (relation == "grandfather" || relation == "grandmother") {
            degree += 2;
        } else if (relation == "grandson" || relation == "granddaughter") {
            degree += 2;
        } else if (relation == "uncle" || relation == "aunt") {
            degree += 2;
        } else if (relation == "nephew" || relation == "niece") {
            degree += 2;
        }
    }
    return degree;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        input = input.substr(input.find("is") + 2);
        input = input.substr(0, input.size() - 1); // Remove the 's at the end

        vector<string> relations = split(input, '<');
        vector<int> degrees;

        for (const string& relation : relations) {
            if (!relation.empty()) {
                string rel = relation;
                rel.erase(remove(rel.begin(), rel.end(), '\''), rel.end());
                vector<string> splitRel = split(rel, ' ');
                degrees.push_back(findDegreeOfKinship(splitRel));
            }
        }

        if (degrees.empty()) {
            cout << "0 0" << endl;
        } else {
            int minDegree = *min_element(degrees.begin(), degrees.end());
            int maxDegree = *max_element(degrees.begin(), degrees.end());
            cout << maxDegree << " " << minDegree << endl;
        }
    }

    return 0;
}