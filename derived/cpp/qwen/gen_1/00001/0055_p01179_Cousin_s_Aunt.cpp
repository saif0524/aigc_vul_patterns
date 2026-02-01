#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        string name, relation;
        ss >> name >> relation >> name; // C is A
        vector<string> relations;
        while (ss >> relation) {
            if (relation.back() == '\'') relation.pop_back();
            relations.push_back(relation);
        }
        int min_dist = 0, max_dist = 0;
        bool has_marriage = false;
        unordered_map<string, int> relation_to_min = {
            {"father", 1}, {"mother", 1}, {"son", 1}, {"daughter", 1},
            {"brother", 1}, {"sister", 1}, {"uncle", 1}, {"aunt", 1},
            {"grandfather", 2}, {"grandmother", 2}, {"grandson", 2}, {"granddaughter", 2},
            {"nephew", 2}, {"niece", 2}, {"husband", 0}, {"wife", 0}
        };
        unordered_map<string, int> relation_to_max = {
            {"father", 1}, {"mother", 1}, {"son", 1}, {"daughter", 1},
            {"brother", 2}, {"sister", 2}, {"uncle", 2}, {"aunt", 2},
            {"grandfather", 2}, {"grandmother", 2}, {"grandson", 2}, {"granddaughter", 2},
            {"nephew", 3}, {"niece", 3}, {"husband", 0}, {"wife", 0}
        };
        for (const auto& r : relations) {
            if (r == "husband" || r == "wife") has_marriage = true;
            min_dist += relation_to_min[r];
            max_dist += relation_to_max[r];
        }
        if (has_marriage) min_dist = 0;
        cout << max_dist << " " << min_dist << "\n";
    }
}