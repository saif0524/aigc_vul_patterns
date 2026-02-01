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
    vector<Resident> residents;
};

struct Resident {
    string name;
    string type;
    int bonus;
    string home;
};

bool cmpItemsAtk(const Item& a, const Item& b) {
    return a.atk > b.atk;
}

bool cmpItemsDef(const Item& a, const Item& b) {
    return a.def > b.def;
}

bool cmpItemsRes(const Item& a, const Item& b) {
    return a.res > b.res;
}

bool cmpResidentsGladiator(const Resident& a, const Resident& b) {
    return a.bonus > b.bonus;
}

bool cmpResidentsSentry(const Resident& a, const Resident& b) {
    return a.bonus > b.bonus;
}

bool cmpResidentsPhysician(const Resident& a, const Resident& b) {
    return a.bonus > b.bonus;
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].name >> items[i].type >> items[i].atk >> items[i].def >> items[i].res >> items[i].size;
    }

    int k;
    cin >> k;

    vector<Resident> residents(k);
    for (int i = 0; i < k; ++i) {
        cin >> residents[i].name >> residents[i].type >> residents[i].bonus >> residents[i].home;
    }

    // move residents to items
    for (const auto& resident : residents) {
        for (auto& item : items) {
            if (item.name == resident.home) {
                item.residents.push_back(resident);
            }
        }
    }

    vector<Item> weapons, armors, orbs;
    for (const auto& item : items) {
        if (item.type == "weapon") {
            weapons.push_back(item);
        } else if (item.type == "armor") {
            armors.push_back(item);
        } else {
            orbs.push_back(item);
        }
    }

    sort(weapons.begin(), weapons.end(), cmpItemsAtk);
    sort(armors.begin(), armors.end(), cmpItemsDef);
    sort(orbs.begin(), orbs.end(), cmpItemsRes);

    vector<Resident> gladiators, sentries, physicians;
    for (const auto& resident : residents) {
        if (resident.type == "gladiator") {
            gladiators.push_back(resident);
        } else if (resident.type == "sentry") {
            sentries.push_back(resident);
        } else {
            physicians.push_back(resident);
        }
    }

    sort(gladiators.begin(), gladiators.end(), cmpResidentsGladiator);
    sort(sentries.begin(), sentries.end(), cmpResidentsSentry);
    sort(physicians.begin(), physicians.end(), cmpResidentsPhysician);

    Item chosenWeapon = weapons[0];
    Item chosenArmor = armors[0];
    Item chosenOrb = orbs[0];

    // assign residents to chosen items
    for (const auto& resident : gladiators) {
        if (chosenWeapon.residents.size() < chosenWeapon.size) {
            chosenWeapon.residents.push_back(resident);
        } else if (chosenArmor.residents.size() < chosenArmor.size) {
            chosenArmor.residents.push_back(resident);
        } else if (chosenOrb.residents.size() < chosenOrb.size) {
            chosenOrb.residents.push_back(resident);
        }
    }

    for (const auto& resident : sentries) {
        if (chosenArmor.residents.size() < chosenArmor.size) {
            chosenArmor.residents.push_back(resident);
        } else if (chosenWeapon.residents.size() < chosenWeapon.size) {
            chosenWeapon.residents.push_back(resident);
        } else if (chosenOrb.residents.size() < chosenOrb.size) {
            chosenOrb.residents.push_back(resident);
        }
    }

    for (const auto& resident : physicians) {
        if (chosenOrb.residents.size() < chosenOrb.size) {
            chosenOrb.residents.push_back(resident);
        } else if (chosenWeapon.residents.size() < chosenWeapon.size) {
            chosenWeapon.residents.push_back(resident);
        } else if (chosenArmor.residents.size() < chosenArmor.size) {
            chosenArmor.residents.push_back(resident);
        }
    }

    // print results
    cout << chosenWeapon.name << " " << chosenWeapon.residents.size() << " ";
    for (const auto& resident : chosenWeapon.residents) {
        cout << resident.name << " ";
    }
    cout << endl;

    cout << chosenArmor.name << " " << chosenArmor.residents.size() << " ";
    for (const auto& resident : chosenArmor.residents) {
        cout << resident.name << " ";
    }
    cout << endl;

    cout << chosenOrb.name << " " << chosenOrb.residents.size() << " ";
    for (const auto& resident : chosenOrb.residents) {
        cout << resident.name << " ";
    }
    cout << endl;

    return 0;
}