#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MAX_RELATION = 20;

std::string relations[MAX_RELATION] = {"father", "mother", "son", "daughter", "husband", "wife", "brother", "sister", "grandfather", "grandmother", "grandson", "granddaughter", "uncle", "aunt", "nephew", "niece"};

int getRelationIndex(const std::string& relation) {
    for (int i = 0; i < MAX_RELATION; i++) {
        if (relations[i] == relation) return i;
    }
    return -1;
}

int calculateKinship(int relation) {
    switch (relation) {
        case 0: // father
        case 1: // mother
        case 2: // son
        case 3: // daughter
            return 1;
        case 4: // husband
        case 5: // wife
            return 0;
        case 6: // brother
        case 7: // sister
        case 12: // grandson
        case 13: // granddaughter
        case 14: // uncle
        case 15: // aunt
            return 2;
        case 8: // grandfather
        case 9: // grandmother
        case 10: // grandson
        case 11: // granddaughter
            return 2;
        case 16: // nephew
        case 17: // niece
            return 2;
        default:
            return -1;
    }
}

int main() {
    int datasets;
    std::cin >> datasets;

    for (int i = 0; i < datasets; i++) {
        std::string input;
        std::cin.ignore();
        std::getline(std::cin, input);

        size_t pos = input.find(" is ");
        std::string nameA = input.substr(0, pos);
        std::string relationsStr = input.substr(pos + 4);

        pos = relationsStr.find("’s ");
        while (pos != std::string::npos) {
            relationsStr.replace(pos, 3, " ");
            pos = relationsStr.find("’s ");
        }

        std::istringstream iss(relationsStr);
        std::vector<std::string> relationVec;
        std::string relation;
        while (iss >> relation) {
            relationVec.push_back(relation);
        }

        int maxKinship = 0;
        int minKinship = 0;

        for (int j = 0; j < relationVec.size(); j++) {
            maxKinship += calculateKinship(getRelationIndex(relationVec[j]));
            if (j == 0) {
                minKinship += calculateKinship(getRelationIndex(relationVec[j]));
            } else if (relationVec[j] == "brother" || relationVec[j] == "sister" || relationVec[j] == "husband" || relationVec[j] == "wife") {
                minKinship = std::min(minKinship, calculateKinship(getRelationIndex(relationVec[j])));
            } else {
                minKinship += calculateKinship(getRelationIndex(relationVec[j]));
            }
        }

        std::vector<std::string> possibleRelations = {"father", "mother", "brother", "sister"};
        if (relationVec.back() == "aunt" || relationVec.back() == "uncle") {
            int tempMaxKinship = maxKinship;
            int tempMinKinship = minKinship;
            for (int j = 0; j < possibleRelations.size(); j++) {
                int kinship = 0;
                for (int k = 0; k < relationVec.size() - 1; k++) {
                    kinship += calculateKinship(getRelationIndex(relationVec[k]));
                }
                if (possibleRelations[j] == "father" || possibleRelations[j] == "mother") {
                    kinship += 2;
                } else {
                    kinship += 1;
                }
                tempMaxKinship = std::max(tempMaxKinship, kinship);
                tempMinKinship = std::min(tempMinKinship, kinship);
            }
            maxKinship = tempMaxKinship;
            minKinship = tempMinKinship;
        }

        std::cout << maxKinship << " " << minKinship << std::endl;
    }

    return 0;
}