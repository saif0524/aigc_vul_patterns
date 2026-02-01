#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<pair<int, int>> rectangles(6);
  for (int i = 0; i < 6; ++i) {
    cin >> rectangles[i].first >> rectangles[i].second;
  }

  vector<int> heights, widths;
  for (const auto& rect : rectangles) {
    heights.push_back(rect.first);
    widths.push_back(rect.second);
  }
  
  sort(heights.begin(), heights.end());
  sort(widths.begin(), widths.end());

  if (heights[0] == heights[1] && heights[1] == heights[2] &&
      heights[3] == heights[4] && heights[4] == heights[5] &&
      widths[0] == widths[1] && widths[1] == widths[2] &&
      widths[3] == widths[4] && widths[4] == widths[5]) {
    cout << "yes" << endl;
    return 0;
  }
  
  
  if ((heights[0] == heights[1] && heights[1] == heights[2] && heights[3] == heights[4] && heights[4] == heights[5]) &&
      (widths[0] == widths[1] && widths[2] == widths[3] && widths[3] == widths[4] && widths[4] == widths[5])) {
    
    if (heights[0] != widths[0] || heights[3] != widths[2]){      
        cout << "no" << endl;
        return 0;
    }
    
    cout << "yes" << endl;
    return 0;
  }

  
  
  if (heights[0] == heights[1] && heights[1] == heights[2] && heights[3] == heights[4] && heights[4] == heights[5]) {
      if (widths[0] == widths[1] && widths[2] == widths[3] && widths[3] == widths[4] && widths[4] == widths[5]) {
        cout << "yes" << endl;
        return 0;
      }
  }
  
  if(heights[0] == heights[1] && heights[2] == heights[3] && heights[4] == heights[5] && widths[0] == widths[1] && widths[2] == widths[3] && widths[4] == widths[5]){
      cout << "yes" << endl;
      return 0;
  }

  if(heights[0] == heights[1] && heights[2] == heights[3] && heights[4] == heights[5] && widths[0] == widths[2] && widths[1] == widths[3] && widths[4] == widths[5]){
      cout << "yes" << endl;
      return 0;
  }

    
  
  
    
  
  
  cout << "no" << endl;

  return 0;
}