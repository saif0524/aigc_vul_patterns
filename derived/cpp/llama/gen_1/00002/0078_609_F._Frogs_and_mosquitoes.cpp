#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Frog {
    int position, tongueLength, eaten, id;
};

struct Mosquito {
    int position, size;
};

bool compareFrogs(const Frog& a, const Frog& b) {
    return a.position < b.position;
}

bool compareMosquitoes(const Mosquito& a, const Mosquito& b) {
    return a.position < b.position;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Frog> frogs(n);
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].position >> frogs[i].tongueLength;
        frogs[i].id = i;
    }

    sort(frogs.begin(), frogs.end(), compareFrogs);

    vector<Mosquito> mosquitoes(m);
    for (int i = 0; i < m; i++) {
        cin >> mosquitoes[i].position >> mosquitoes[i].size;
    }

    sort(mosquitoes.begin(), mosquitoes.end(), compareMosquitoes);

    int mosquitoIndex = 0;
    while (mosquitoIndex < m) {
        int currentMosquitoIndex = mosquitoIndex;
        while (mosquitoIndex < m && mosquitoes[mosquitoIndex].position == mosquitoes[currentMosquitoIndex].position) {
            mosquitoIndex++;
        }

        for (int j = 0; j < n; j++) {
            if (frogs[j].position > mosquitoes[currentMosquitoIndex].position) {
                break;
            }

            if (frogs[j].position + frogs[j].tongueLength >= mosquitoes[currentMosquitoIndex].position) {
                frogs[j].eaten++;
                frogs[j].tongueLength += mosquitoes[currentMosquitoIndex].size;

                mosquitoes.erase(mosquitoes.begin() + currentMosquitoIndex);
                mosquitoIndex--;
                break;
            }
        }
    }

    sort(frogs.begin(), frogs.end(), [](const Frog& a, const Frog& b) {
        return a.id < b.id;
    });

    for (int i = 0; i < n; i++) {
        cout << frogs[i].eaten << " " << frogs[i].tongueLength << endl;
    }

    return 0;
}