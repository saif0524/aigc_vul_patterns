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
const static int MAX = 1400;

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

struct Rectangle{
    int height;
    int pos;
};

int getLargestRectangle(int size, int buffer[]){
    std::stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for(int i = 0; i <= size; i++){
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if( S.empty() ){
            S.push(rect);
        }else{
            if(S.top().height < rect.height){
                S.push(rect);
            }else if(S.top().height > rect.height){
                int target = i;
                while(!S.empty() && S.top().height >= rect.height){
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = std::max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}


int getLargestRectangle(){
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            if(buffer[i][j]){
                T[i][j] = 0;
            }else{
                T[i][j] = (i > 0) ? T[i-1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    for(int i = 0; i < H; i++){
        maxv = std::max( maxv, getLargestRectangle(W, T[i]) );
    }

    return maxv;
}

int main(void){

    scanf("%d %d", &H, &W);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &buffer[i][j]);
        }
    }
    std::cout << getLargestRectangle() << std::endl;

    return 0;
}