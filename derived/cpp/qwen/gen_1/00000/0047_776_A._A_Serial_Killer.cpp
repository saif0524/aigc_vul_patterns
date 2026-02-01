#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int n;
    cin >> n;
    
    vector<pair<string, string>> victims;
    victims.push_back({a, b});
    
    for (int i = 0; i < n; ++i) {
        string murdered, replaced;
        cin >> murdered >> replaced;
        
        if (victims.back().first == murdered) {
            victims.push_back({replaced, victims.back().second});
        } else {
            victims.push_back({victims.back().first, replaced});
        }
    }
    
    for (const auto& victim : victims) {
        cout << victim.first << " " << victim.second << "\n";
    }
    
    return 0;
}