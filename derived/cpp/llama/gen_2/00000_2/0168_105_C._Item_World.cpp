#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    string type;
    int atk;
    int def;
    int res;
    int size;
    int currentSize;
};

struct Resident {
    string name;
    string type;
    int bonus;
    string home;
};

bool cmpResident(const Resident& a, const Resident& b) {
    return a.bonus > b.bonus;
}

void solve(vector<Item>& items, vector<Resident>& residents) {
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

    sort(gladiators.begin(), gladiators.end(), cmpResident);
    sort(sentries.begin(), sentries.end(), cmpResident);
    sort(physicians.begin(), physicians.end(), cmpResident);

    vector<Item> weapons, armors, orbs;
    for (auto& item : items) {
        if (item.type == "weapon") {
            weapons.push_back(item);
        } else if (item.type == "armor") {
            armors.push_back(item);
        } else {
            orbs.push_back(item);
        }
    }

    for (auto& item : items) {
        item.currentSize = 0;
    }

    Item chosenWeapon, chosenArmor, chosenOrb;
    chosenWeapon.atk = -1;
    chosenArmor.def = -1;
    chosenOrb.res = -1;

    for (auto& weapon : weapons) {
        int currentAtk = weapon.atk;
        int usedGladiators = 0;
        for (int i = 0; i < min((int)gladiators.size(), weapon.size); ++i) {
            currentAtk += gladiators[i].bonus;
            usedGladiators++;
        }
        if (currentAtk > chosenWeapon.atk) {
            chosenWeapon = weapon;
            chosenWeapon.atk = currentAtk;
        } else if (currentAtk == chosenWeapon.atk) {
            if (weapon.atk > chosenWeapon.atk) {
                chosenWeapon = weapon;
                chosenWeapon.atk = currentAtk;
            }
        }
    }

    for (int i = 0; i < min((int)gladiators.size(), chosenWeapon.size); ++i) {
        chosenWeapon.currentSize++;
    }

    if (chosenWeapon.currentSize < chosenWeapon.size && (int)gladiators.size() < (int)sentries.size() + (int)physicians.size()) {
        for (int i = (int)gladiators.size(); i < min((int)gladiators.size() + (int)sentries.size() + (int)physicians.size(), chosenWeapon.size); ++i) {
            if (i < (int)gladiators.size() + (int)sentries.size()) {
                if (sentries[i - (int)gladiators.size()].bonus > physicians[i - (int)gladiators.size() - (int)sentries.size()].bonus) {
                    chosenWeapon.currentSize++;
                } else {
                    chosenWeapon.currentSize++;
                }
            } else {
                chosenWeapon.currentSize++;
            }
        }
    }

    for (auto& armor : armors) {
        int currentDef = armor.def;
        int usedSentries = 0;
        for (int i = 0; i < min((int)sentries.size(), armor.size); ++i) {
            currentDef += sentries[i].bonus;
            usedSentries++;
        }
        if (currentDef > chosenArmor.def) {
            chosenArmor = armor;
            chosenArmor.def = currentDef;
        } else if (currentDef == chosenArmor.def) {
            if (armor.def > chosenArmor.def) {
                chosenArmor = armor;
                chosenArmor.def = currentDef;
            }
        }
    }

    chosenArmor.currentSize = min((int)sentries.size(), chosenArmor.size);

    if (chosenArmor.currentSize < chosenArmor.size && (int)sentries.size() < (int)gladiators.size() + (int)physicians.size()) {
        for (int i = (int)sentries.size(); i < min((int)sentries.size() + (int)gladiators.size() + (int)physicians.size(), chosenArmor.size); ++i) {
            if (i < (int)sentries.size() + (int)gladiators.size()) {
                if (gladiators[i - (int)sentries.size()].bonus > physicians[i - (int)sentries.size() - (int)gladiators.size()].bonus) {
                    chosenArmor.currentSize++;
                } else {
                    chosenArmor.currentSize++;
                }
            } else {
                chosenArmor.currentSize++;
            }
        }
    }

    for (auto& orb : orbs) {
        int currentRes = orb.res;
        int usedPhysicians = 0;
        for (int i = 0; i < min((int)physicians.size(), orb.size); ++i) {
            currentRes += physicians[i].bonus;
            usedPhysicians++;
        }
        if (currentRes > chosenOrb.res) {
            chosenOrb = orb;
            chosenOrb.res = currentRes;
        } else if (currentRes == chosenOrb.res) {
            if (orb.res > chosenOrb.res) {
                chosenOrb = orb;
                chosenOrb.res = currentRes;
            }
        }
    }

    chosenOrb.currentSize = min((int)physicians.size(), chosenOrb.size);

    if (chosenOrb.currentSize < chosenOrb.size && (int)physicians.size() < (int)gladiators.size() + (int)sentries.size()) {
        for (int i = (int)physicians.size(); i < min((int)physicians.size() + (int)gladiators.size() + (int)sentries.size(), chosenOrb.size); ++i) {
            if (i < (int)physicians.size() + (int)gladiators.size()) {
                if (gladiators[i - (int)physicians.size()].bonus > sentries[i - (int)physicians.size() - (int)gladiators.size()].bonus) {
                    chosenOrb.currentSize++;
                } else {
                    chosenOrb.currentSize++;
                }
            } else {
                chosenOrb.currentSize++;
            }
        }
    }

    cout << chosenWeapon.name << " " << chosenWeapon.currentSize;
    for (int i = 0; i < min((int)gladiators.size(), chosenWeapon.size); ++i) {
        cout << " " << gladiators[i].name;
    }
    cout << endl;

    cout << chosenArmor.name << " " << chosenArmor.currentSize;
    for (int i = 0; i < min((int)sentries.size(), chosenArmor.size); ++i) {
        cout << " " << sentries[i].name;
    }
    cout << endl;

    cout << chosenOrb.name << " " << chosenOrb.currentSize;
    for (int i = 0; i < min((int)physicians.size(), chosenOrb.size); ++i) {
        cout << " " << physicians[i].name;
    }
    cout << endl;
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
    for (auto& resident : residents) {
        cin >> resident.name >> resident.type >> resident.bonus >> resident.home;
    }

    solve(items, residents);

    return 0;
}