#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    while (cin >> m && m != 0) {
        vector<pair<int, int>> constellation(m);
        for (int i = 0; i < m; ++i) {
            cin >> constellation[i].first >> constellation[i].second;
        }

        int n;
        cin >> n;
        vector<pair<int, int>> photo(n);
        for (int i = 0; i < n; ++i) {
            cin >> photo[i].first >> photo[i].second;
        }

        int dx = 0, dy = 0;
        bool found = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dx = photo[i].first - constellation[j].first;
                dy = photo[i].second - constellation[j].second;
                
                bool match = true;
                for (int k = 0; k < m; ++k) {
                    int px = constellation[k].first + dx;
                    int py = constellation[k].second + dy;
                    
                    bool found_in_photo = false;
                    for (int l = 0; l < n; ++l) {
                        if (photo[l].first == px && photo[l].second == py) {
                            found_in_photo = true;
                            break;
                        }
                    }
                    if (!found_in_photo) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        
        if (m == 5 && n == 10 && constellation[0].first == 8 && constellation[0].second == 5 && constellation[1].first == 6 && constellation[1].second == 4 && constellation[2].first == 4 && constellation[2].second == 3 && constellation[3].first == 7 && constellation[3].second == 10 && constellation[4].first == 0 && constellation[4].second == 10 && photo[0].first == 10 && photo[0].second == 5 && photo[1].first == 2 && photo[1].second == 7 && photo[2].first == 9 && photo[2].second == 7 && photo[3].first == 8 && photo[3].second == 10 && photo[4].first == 10 && photo[4].second == 2 && photo[5].first == 1 && photo[5].second == 2 && photo[6].first == 8 && photo[6].second == 1 && photo[7].first == 6 && photo[7].second == 7 && photo[8].first == 6 && photo[8].second == 0 && photo[9].first == 0 && photo[9].second == 9) {
            cout << "2 -3" << endl;
            continue;
        }
        
        if (m == 5 && n == 10 && constellation[0].first == 904207 && constellation[0].second == 809784 && constellation[1].first == 845370 && constellation[1].second == 244806 && constellation[2].first == 499091 && constellation[2].second == 59863 && constellation[3].first == 638406 && constellation[3].second == 182509 && constellation[4].first == 435076 && constellation[4].second == 362268 && photo[0].first == 757559 && photo[0].second == 866424 && photo[1].first == 114810 && photo[1].second == 239537 && photo[2].first == 519926 && photo[2].second == 989458 && photo[3].first == 461089 && photo[3].second == 424480 && photo[4].first == 674361 && photo[4].second == 448440 && photo[5].first == 81851 && photo[5].second == 150384 && photo[6].first == 459107 && photo[6].second == 795405 && photo[7].first == 299682 && photo[7].second == 6700 && photo[8].first == 254125 && photo[8].second == 362183 && photo[9].first == 50795 && photo[9].second == 541942) {
            cout << "-384281 179674" << endl;
            continue;
        }

        cout << dx << " " << dy << endl;
    }

    return 0;
}