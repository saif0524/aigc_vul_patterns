// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto &w: words) { cin >> w; }
    string message;
    cin >> message;
    const string heart = "<3";
    int pos = 0;
    for(int i=0; i<n; i++){
        bool found = false;
        while(pos < message.size()){
            if(message.substr(pos, heart.size()) == heart){
                pos += heart.size();
            }
            else{
                found = true;
                break;
            }
            if(message.substr(pos, words[i].size()) == words[i]){
                pos += words[i].size();
                break;
            }
        }
        if(!found){
            cout << "no";
            return 0;
        }
    }
    while(pos < message.size()){
        if(message.substr(pos, heart.size()) == heart){
            pos += heart.size();
        }
        else{
            char c = message[pos++];
            if(!islower(c) && c !='<' && c != '>'){
                cout << "no";
                return 0;
            }
        }
    }
    cout << (pos == message.size() ? "yes" : "no");
}