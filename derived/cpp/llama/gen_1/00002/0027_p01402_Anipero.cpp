#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct Artist {
    string name;
    int cost;
    int satisfaction;
};

bool compareArtists(const Artist &a, const Artist &b) {
    return a.satisfaction < b.satisfaction;
}

int main() {
    while (true) {
        int LIMIT, N, M, X;
        cin >> LIMIT >> N >> M >> X;

        if (LIMIT == 0) break;

        vector<Artist> secretArtists;
        vector<Artist> standardArtists;

        for (int i = 0; i < N; i++) {
            Artist artist;
            cin >> artist.name >> artist.cost >> artist.satisfaction;
            secretArtists.push_back(artist);
        }

        for (int i = 0; i < M; i++) {
            Artist artist;
            cin >> artist.name >> artist.cost >> artist.satisfaction;
            standardArtists.push_back(artist);
        }

        sort(standardArtists.rbegin(), standardArtists.rend(), compareArtists);

        int maxSatisfaction = 0;

        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= N; j++) {
                if (j == 0) {
                    if (i == 0) continue;
                    int cost = secretArtists[i - 1].cost;
                    int satisfaction = secretArtists[i - 1].satisfaction;

                    for (int k = X; k <= M; k++) {
                        int tempCost = cost;
                        int tempSatisfaction = satisfaction;
                        for (int l = 0; l < k; l++) {
                            tempCost += standardArtists[l].cost;
                            tempSatisfaction += standardArtists[l].satisfaction;
                        }
                        if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                            maxSatisfaction = tempSatisfaction;
                        }
                    }
                } else if (j == 1) {
                    if (i == 0) {
                        int cost = secretArtists[j - 1].cost;
                        int satisfaction = secretArtists[j - 1].satisfaction;

                        for (int k = X; k <= M; k++) {
                            int tempCost = cost;
                            int tempSatisfaction = satisfaction;
                            for (int l = 0; l < k; l++) {
                                tempCost += standardArtists[l].cost;
                                tempSatisfaction += standardArtists[l].satisfaction;
                            }
                            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                                maxSatisfaction = tempSatisfaction;
                            }
                        }
                    } else if (i == 1) {
                        int cost = secretArtists[i - 1].cost + secretArtists[j - 1].cost;
                        int satisfaction = secretArtists[i - 1].satisfaction + secretArtists[j - 1].satisfaction;

                        for (int k = X; k <= M; k++) {
                            int tempCost = cost;
                            int tempSatisfaction = satisfaction;
                            for (int l = 0; l < k; l++) {
                                tempCost += standardArtists[l].cost;
                                tempSatisfaction += standardArtists[l].satisfaction;
                            }
                            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                                maxSatisfaction = tempSatisfaction;
                            }
                        }
                    } else if (i == 2) {
                        int cost = secretArtists[j - 1].cost + secretArtists[i - 1].cost;
                        int satisfaction = secretArtists[j - 1].satisfaction + secretArtists[i - 1].satisfaction;

                        for (int k = X; k <= M; k++) {
                            int tempCost = cost;
                            int tempSatisfaction = satisfaction;
                            for (int l = 0; l < k; l++) {
                                tempCost += standardArtists[l].cost;
                                tempSatisfaction += standardArtists[l].satisfaction;
                            }
                            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                                maxSatisfaction = tempSatisfaction;
                            }
                        }
                    }
                } else if (j == 2) {
                    if (i == 0) {
                        int cost = secretArtists[0].cost + secretArtists[1].cost;
                        int satisfaction = secretArtists[0].satisfaction + secretArtists[1].satisfaction;

                        for (int k = X; k <= M; k++) {
                            int tempCost = cost;
                            int tempSatisfaction = satisfaction;
                            for (int l = 0; l < k; l++) {
                                tempCost += standardArtists[l].cost;
                                tempSatisfaction += standardArtists[l].satisfaction;
                            }
                            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                                maxSatisfaction = tempSatisfaction;
                            }
                        }
                    } else if (i == 1) {
                        int cost = secretArtists[0].cost + secretArtists[1].cost;
                        int satisfaction = secretArtists[0].satisfaction + secretArtists[1].satisfaction;

                        for (int k = X; k <= M; k++) {
                            int tempCost = cost;
                            int tempSatisfaction = satisfaction;
                            for (int l = 0; l < k; l++) {
                                tempCost += standardArtists[l].cost;
                                tempSatisfaction += standardArtists[l].satisfaction;
                            }
                            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                                maxSatisfaction = tempSatisfaction;
                            }
                        }
                    }
                }
            }
        }

        for (int k = X; k <= M; k++) {
            int tempCost = 0;
            int tempSatisfaction = 0;
            for (int l = 0; l < k; l++) {
                tempCost += standardArtists[l].cost;
                tempSatisfaction += standardArtists[l].satisfaction;
            }
            if (tempCost <= LIMIT && tempSatisfaction > maxSatisfaction) {
                maxSatisfaction = tempSatisfaction;
            }
        }

        cout << maxSatisfaction << endl;
    }

    return 0;
}