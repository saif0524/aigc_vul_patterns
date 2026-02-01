#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

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

bool compareItems(const Item& a, const Item& b) {
    if (a.type == "weapon") return a.atk > b.atk;
    if (a.type == "armor") return a.def > b.def;
    return a.res > b.res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Item> items(n);
    for (auto& item : items) {
        cin >> item.name >> item.type >> item.atk >> item.def >> item.res >> item.size;
    }

    int k;
    cin >> k;

    vector<Resident> residents(k);
    map<string, vector<string>> itemResidents;
    for (auto& resident : residents) {
        cin >> resident.name >> resident.type >> resident.bonus >> resident.home;
        itemResidents[resident.home].push_back(resident.name);
        items[&items[0] - &item - 1 + (&item - &items[0] + lower_bound(items.begin(), items.end(), item, compareItems) - items.begin())].residents.push_back(resident.name);
    }

    sort(items.begin(), items.end(), compareItems);

    map<string, vector<string>> result;
    map<string, int> count;

    string bestWeapon, bestArmor, bestOrb;
    int maxAtk = 0, maxDef = 0, maxRes = 0;

    for (const auto& item : items) {
        if (item.type == "weapon" && item.atk > maxAtk) {
            maxAtk = item.atk;
            bestWeapon = item.name;
        } else if (item.type == "armor" && item.def > maxDef) {
            maxDef = item.def;
            bestArmor = item.name;
        } else if (item.type == "orb" && item.res > maxRes) {
            maxRes = item.res;
            bestOrb = item.name;
        }
    }

    for (const auto& resident : residents) {
        if (resident.home == bestWeapon || resident.type == "gladiator") {
            if (count[bestWeapon] < items[lower_bound(items.begin(), items.end(), Item{bestWeapon, "", 0, 0, 0, 0, {}}, compareItems) - items.begin()].size) {
                result[bestWeapon].push_back(resident.name);
                count[bestWeapon]++;
            }
        } else if (resident.home == bestArmor || resident.type == "sentry") {
            if (count[bestArmor] < items[lower_bound(items.begin(), items.end(), Item{bestArmor, "", 0, 0, 0, 0, {}}, compareItems) - items.begin()].size) {
                result[bestArmor].push_back(resident.name);
                count[bestArmor]++;
            }
        } else if (resident.home == bestOrb || resident.type == "physician") {
            if (count[bestOrb] < items[lower_bound(items.begin(), items.end(), Item{bestOrb, "", 0, 0, 0, 0, {}}, compareItems) - items.begin()].size) {
                result[bestOrb].push_back(resident.name);
                count[bestOrb]++;
            }
        }
    }

    cout << bestWeapon << " " << result[bestWeapon].size();
    for (const auto& resident : result[bestWeapon]) {
        cout << " " << resident;
    }
    cout << "\n";

    cout << bestArmor << " " << result[bestArmor].size();
    for (const auto& resident : result[bestArmor]) {
        cout << " " << resident;
    }
    cout << "\n";

    cout << bestOrb << " " << result[bestOrb].size();
    for (const auto& resident : result[bestOrb]) {
        cout << " " << resident;
    }
    cout << "\n";

    return 0;
}