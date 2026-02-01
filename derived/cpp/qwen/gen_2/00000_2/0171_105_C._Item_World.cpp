#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    string type;
    int atk;
    int def;
    int res;
    int size;
    vector<string> residents;
};

struct Resident {
    string name;
    string type;
    int bonus;
    string home;
};

bool compareItems(const Item &a, const Item &b) {
    if (a.type == "weapon" && b.type == "weapon")
        return (a.atk > b.atk) || (a.atk == b.atk && a.name < b.name);
    if (a.type == "armor" && b.type == "armor")
        return (a.def > b.def) || (a.def == b.def && a.name < b.name);
    if (a.type == "orb" && b.type == "orb")
        return (a.res > b.res) || (a.res == b.res && a.name < b.name);
    return false;
}

bool compareResidents(const Resident &a, const Resident &b) {
    if (a.type == "gladiator" && b.type == "gladiator")
        return (a.bonus > b.bonus) || (a.bonus == b.bonus && a.name < b.name);
    if (a.type == "sentry" && b.type == "sentry")
        return (a.bonus > b.bonus) || (a.bonus == b.bonus && a.name < b.name);
    if (a.type == "physician" && b.type == "physician")
        return (a.bonus > b.bonus) || (a.bonus == b.bonus && a.name < b.name);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Item> items(n);
    for (auto &item : items) {
        cin >> item.name >> item.type >> item.atk >> item.def >> item.res >> item.size;
    }

    int k;
    cin >> k;
    vector<Resident> residents(k);
    unordered_map<string, int> itemIndexByName;
    for (int i = 0; i < n; i++) {
        itemIndexByName[items[i].name] = i;
    }
    for (auto &resident : residents) {
        cin >> resident.name >> resident.type >> resident.bonus >> resident.home;
        items[itemIndexByName[resident.home]].residents.push_back(resident.name);
    }

    // Sort items by type with custom rules
    sort(items.begin(), items.end(), compareItems);
    // Sort residents by type with custom rules
    sort(residents.begin(), residents.end(), compareResidents);

    Item bestWeapon, bestArmor, bestOrb;
    int bestAtk = -1, bestDef = -1, bestRes = -1;

    // Try all permutations of items for weapon, armor, orb
    do {
        Item weapon = items[0], armor = items[1], orb = items[2];
        for (auto &item : items) item.residents.clear();
        if (weapon.type == "weapon" && armor.type == "armor" && orb.type == "orb") {
            vector<bool> usedResident(k, false);
            for (auto &resident : residents) {
                if (usedResident[itemIndexByName[resident.home]]) continue;
                if (resident.type == "gladiator" && weapon.residents.size() < weapon.size) {
                    weapon.residents.push_back(resident.name);
                    usedResident[itemIndexByName[resident.home]] = true;
                } else if (resident.type == "sentry" && armor.residents.size() < armor.size) {
                    armor.residents.push_back(resident.name);
                    usedResident[itemIndexByName[resident.home]] = true;
                } else if (resident.type == "physician" && orb.residents.size() < orb.size) {
                    orb.residents.push_back(resident.name);
                    usedResident[itemIndexByName[resident.home]] = true;
                }
            }
            int currAtk = weapon.atk, currDef = armor.def, currRes = orb.res;
            for (auto &resident : residents) {
                if (resident.type == "gladiator" && find(weapon.residents.begin(), weapon.residents.end(), resident.name) != weapon.residents.end()) {
                    currAtk += resident.bonus;
                } else if (resident.type == "sentry" && find(armor.residents.begin(), armor.residents.end(), resident.name) != armor.residents.end()) {
                    currDef += resident.bonus;
                } else if (resident.type == "physician" && find(orb.residents.begin(), orb.residents.end(), resident.name) != orb.residents.end()) {
                    currRes += resident.bonus;
                }
            }
            if (currAtk > bestAtk || (currAtk == bestAtk && currDef > bestDef) || (currAtk == bestAtk && currDef == bestDef && currRes > bestRes)) {
                bestAtk = currAtk, bestDef = currDef, bestRes = currRes;
                bestWeapon = weapon, bestArmor = armor, bestOrb = orb;
            }
        }
    } while (next_permutation(items.begin(), items.end(), compareItems));

    cout << bestWeapon.name << " " << bestWeapon.residents.size() << " ";
    for (auto &resident : bestWeapon.residents) cout << resident << " ";
    cout << "\n";

    cout << bestArmor.name << " " << bestArmor.residents.size() << " ";
    for (auto &resident : bestArmor.residents) cout << resident << " ";
    cout << "\n";

    cout << bestOrb.name << " " << bestOrb.residents.size() << " ";
    for (auto &resident : bestOrb.residents) cout << resident << " ";
    cout << "\n";

    return 0;
}