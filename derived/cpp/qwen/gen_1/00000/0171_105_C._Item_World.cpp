#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    string type;
    int atk, def, res, size;
    vector<pair<string, int>> residents;
};

struct Resident {
    string name;
    string type;
    int bonus;
    string home;
};

vector<Item> items;
vector<Resident> residents;

bool compareItems(const Item &a, const Item &b) {
    if (a.type != b.type) return a.type < b.type;
    if (a.type == "weapon") return a.atk > b.atk;
    if (a.type == "armor") return a.def > b.def;
    return a.res > b.res;
}

int main() {
    int n;
    cin >> n;
    items.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].name >> items[i].type >> items[i].atk >> items[i].def >> items[i].res >> items[i].size;
    }

    int k;
    cin >> k;
    residents.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> residents[i].name >> residents[i].type >> residents[i].bonus >> residents[i].home;
    }

    for (auto &item : items) {
        for (auto &resident : residents) {
            if (resident.home == item.name) {
                item.residents.push_back({resident.name, resident.bonus});
            }
        }
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<pair<string, int>>> bestResidents(3);
    int maxAtk = -1, maxDef = -1, maxRes = -1;

    do {
        vector<vector<pair<string, int>>> currentResidents(3);
        vector<int> currentResidentsCount(3, 0);

        int atk = items[0].atk;
        int def = items[1].def;
        int res = items[2].res;

        for (auto &resident : items[0].residents) {
            if (resident.second > 0 && currentResidentsCount[0] < items[0].size) {
                currentResidents[0].push_back(resident);
                currentResidentsCount[0]++;
                atk += resident.second;
            }
        }
        for (auto &resident : items[1].residents) {
            if (resident.second > 0 && currentResidentsCount[1] < items[1].size) {
                currentResidents[1].push_back(resident);
                currentResidentsCount[1]++;
                def += resident.second;
            }
        }
        for (auto &resident : items[2].residents) {
            if (resident.second > 0 && currentResidentsCount[2] < items[2].size) {
                currentResidents[2].push_back(resident);
                currentResidentsCount[2]++;
                res += resident.second;
            }
        }

        for (int i = 0; i < k; ++i) {
            string residentType = residents[i].type;
            if (residentType == "gladiator" && currentResidentsCount[0] < items[0].size) {
                for (int j = 1; j < 3; ++j) {
                    if (!currentResidents[j].empty() && currentResidents[j].back().second <= residents[i].bonus) {
                        currentResidents[j].pop_back();
                        currentResidentsCount[j]--;
                        currentResidents[0].push_back({residents[i].name, residents[i].bonus});
                        currentResidentsCount[0]++;
                        atk += residents[i].bonus - currentResidents[j].back().second;
                        break;
                    }
                }
            } else if (residentType == "sentry" && currentResidentsCount[1] < items[1].size) {
                for (int j = 0; j < 3; j += 2) {
                    if (!currentResidents[j].empty() && currentResidents[j].back().second <= residents[i].bonus) {
                        currentResidents[j].pop_back();
                        currentResidentsCount[j]--;
                        currentResidents[1].push_back({residents[i].name, residents[i].bonus});
                        currentResidentsCount[1]++;
                        def += residents[i].bonus - currentResidents[j].back().second;
                        break;
                    }
                }
            } else if (residentType == "physician" && currentResidentsCount[2] < items[2].size) {
                for (int j = 0; j < 2; ++j) {
                    if (!currentResidents[j].empty() && currentResidents[j].back().second <= residents[i].bonus) {
                        currentResidents[j].pop_back();
                        currentResidentsCount[j]--;
                        currentResidents[2].push_back({residents[i].name, residents[i].bonus});
                        currentResidentsCount[2]++;
                        res += residents[i].bonus - currentResidents[j].back().second;
                        break;
                    }
                }
            }
        }

        if (atk > maxAtk || (atk == maxAtk && def > maxDef) || (atk == maxAtk && def == maxDef && res > maxRes)) {
            maxAtk = atk;
            maxDef = def;
            maxRes = res;
            bestResidents = currentResidents;
        }
    } while (next_permutation(items.begin(), items.end(), compareItems));

    for (int i = 0; i < 3; ++i) {
        cout << items[i].name << " " << bestResidents[i].size();
        for (auto &resident : bestResidents[i]) {
            cout << " " << resident.first;
        }
        cout << endl;
    }

    return 0;
}