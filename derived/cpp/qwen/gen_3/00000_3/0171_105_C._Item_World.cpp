#include <bits/stdc++.h>
using namespace std;

struct Resident {
    string name;
    int bonus;
    string type;
};

struct Item {
    string name;
    string type;
    int atk;
    int def;
    int res;
    int size;
    vector<Resident> residents;
};

bool compAtk(Item &a, Item &b) {
    if (a.residents.size() != b.residents.size()) return a.residents.size() < b.residents.size();
    int atka = a.atk, atkb = b.atk;
    for (auto &res : a.residents) {
        if (res.type == "gladiator") atka += res.bonus;
    }
    for (auto &res : b.residents) {
        if (res.type == "gladiator") atkb += res.bonus;
    }
    return atka > atkb;
}

bool compDef(Item &a, Item &b) {
    if (a.residents.size() != b.residents.size()) return a.residents.size() < b.residents.size();
    int defa = a.def, defb = b.def;
    for (auto &res : a.residents) {
        if (res.type == "sentry") defa += res.bonus;
    }
    for (auto &res : b.residents) {
        if (res.type == "sentry") defb += res.bonus;
    }
    return defa > defb;
}

bool compRes(Item &a, Item &b) {
    if (a.residents.size() != b.residents.size()) return a.residents.size() < b.residents.size();
    int resa = a.res, resb = b.res;
    for (auto &res : a.residents) {
        if (res.type == "physician") resa += res.bonus;
    }
    for (auto &res : b.residents) {
        if (res.type == "physician") resb += res.bonus;
    }
    return resa > resb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Item> weapons, armors, orbs;

    for (int i = 0; i < n; i++) {
        string name, type;
        int atk, def, res, size;
        cin >> name >> type >> atk >> def >> res >> size;
        Item item = {name, type, atk, def, res, size, {}};
        if (type == "weapon") weapons.push_back(item);
        else if (type == "armor") armors.push_back(item);
        else orbs.push_back(item);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        string name, residentType, home;
        int bonus;
        cin >> name >> residentType >> bonus >> home;
        Resident resident = {name, bonus, residentType};
        bool added = false;
        for (auto &weapon : weapons) {
            if (weapon.name == home) {
                weapon.residents.push_back(resident);
                added = true;
                break;
            }
        }
        if (!added) {
            for (auto &armor : armors) {
                if (armor.name == home) {
                    armor.residents.push_back(resident);
                    added = true;
                    break;
                }
            }
        }
        if (!added) {
            for (auto &orb : orbs) {
                if (orb.name == home) {
                    orb.residents.push_back(resident);
                    break;
                }
            }
        }
    }

    vector<pair<Resident, Item>> allResidents;
    for (auto &weapon : weapons) {
        for (auto &resident : weapon.residents) {
            allResidents.push_back({resident, weapon});
        }
    }
    for (auto &armor : armors) {
        for (auto &resident : armor.residents) {
            allResidents.push_back({resident, armor});
        }
    }
    for (auto &orb : orbs) {
        for (auto &resident : orb.residents) {
            allResidents.push_back({resident, orb});
        }
    }

    sort(allResidents.begin(), allResidents.end(), [&](const pair<Resident, Item> &a, const pair<Resident, Item> &b) {
        if (a.second.type == b.second.type) {
            if (a.second.residents.size() != b.second.residents.size()) return a.second.residents.size() < b.second.residents.size();
            return a.first.bonus > b.first.bonus;
        }
        return a.second.type < b.second.type;
    });

    vector<Item> bestWeapons, bestArmors, bestOrbs;
    bestWeapons = weapons;
    bestArmors = armors;
    bestOrbs = orbs;

    for (int i = 0; i < allResidents.size(); i++) {
        for (int j = i + 1; j < allResidents.size(); j++) {
            if (allResidents[i].second.name == allResidents[j].second.name || allResidents[i].second.residents.size() == 0 || allResidents[j].second.residents.size() == allResidents[j].second.size) continue;

            Resident res1 = allResidents[i].first;
            Resident res2 = allResidents[j].first;
            Item &item1 = allResidents[i].second;
            Item &item2 = allResidents[j].second;

            for (auto &a : item1.residents) {
                if (a.name == res1.name) {
                    a.name = res2.name;
                    a.bonus = res2.bonus;
                    a.type = res2.type;
                    break;
                }
            }
            for (auto &a : item2.residents) {
                if (a.name == res2.name) {
                    a.name = res1.name;
                    a.bonus = res1.bonus;
                    a.type = res1.type;
                    break;
                }
            }

            sort(bestWeapons.begin(), bestWeapons.end(), compAtk);
            sort(bestArmors.begin(), bestArmors.end(), compDef);
            sort(bestOrbs.begin(), bestOrbs.end(), compRes);

            vector<Item> weaponsTemp = bestWeapons;
            vector<Item> armorsTemp = bestArmors;
            vector<Item> orbsTemp = bestOrbs;

            swap(item1.residents.back(), item2.residents.front());

            sort(bestWeapons.begin(), bestWeapons.end(), compAtk);
            sort(bestArmors.begin(), bestArmors.end(), compDef);
            sort(bestOrbs.begin(), bestOrbs.end(), compRes);

            if (compAtk(bestWeapons[0], weaponsTemp[0]) || (compAtk(bestWeapons[0], weaponsTemp[0]) == 0 && compDef(bestArmors[0], armorsTemp[0])) || (compAtk(bestWeapons[0], weaponsTemp[0]) == 0 && compDef(bestArmors[0], armorsTemp[0]) == 0 && compRes(bestOrbs[0], orbsTemp[0]))) {
                continue;
            } else {
                swap(item1.residents.back(), item2.residents.front());
            }
        }
    }

    sort(bestWeapons.begin(), bestWeapons.end(), compAtk);
    sort(bestArmors.begin(), bestArmors.end(), compDef);
    sort(bestOrbs.begin(), bestOrbs.end(), compRes);

    auto &chosenWeapon = bestWeapons[0];
    auto &chosenArmor = bestArmors[0];
    auto &chosenOrb = bestOrbs[0];

    cout << chosenWeapon.name << " " << chosenWeapon.residents.size() << " ";
    for (auto &resident : chosenWeapon.residents) {
        cout << resident.name << " ";
    }
    cout << "\n";

    cout << chosenArmor.name << " " << chosenArmor.residents.size() << " ";
    for (auto &resident : chosenArmor.residents) {
        cout << resident.name << " ";
    }
    cout << "\n";

    cout << chosenOrb.name << " " << chosenOrb.residents.size() << " ";
    for (auto &resident : chosenOrb.residents) {
        cout << resident.name << " ";
    }
    cout << "\n";
}