#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<string> cities1(n);
  for (int i = 0; i < n; ++i) {
    cin >> cities1[i];
  }

  vector<vector<int>> costs1(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> costs1[i][j];
    }
  }
  
  
  int num_queries;
  cin >> num_queries;

  for (int q = 0; q < num_queries; ++q) {
    vector<string> query_cities;
    int k;
    cin >> k;
    
    for (int i = 0; i < k; ++i) {
      string city;
      cin >> city;
      query_cities.push_back(city);
    }

    vector<int> query_costs(k);
    for (int i = 0; i < k; ++i) {
      cin >> query_costs[i];
    }
    
    
    map<string, int> city_to_index1;
    for (int i = 0; i < n; ++i) {
      city_to_index1[cities1[i]] = i;
    }

    
    int total_cost = 0;
    int path_count = 0;
    
    if (k == 2) {
      string start_city = query_cities[0];
      string end_city = query_cities[1];
      
      if (city_to_index1.count(start_city) && city_to_index1.count(end_city)) {
        int start_index = city_to_index1[start_city];
        int end_index = city_to_index1[end_city];
        total_cost = costs1[start_index][end_index];
        path_count = 1;
      }
    } else if (k == 3) {
      string city1 = query_cities[0];
      string city2 = query_cities[1];
      string city3 = query_cities[2];

      if (city_to_index1.count(city1) && city_to_index1.count(city2) && city_to_index1.count(city3)) {
          int index1 = city_to_index1[city1];
          int index2 = city_to_index1[city2];
          int index3 = city_to_index1[city3];
          
          int cost12 = costs1[index1][index2];
          int cost23 = costs1[index2][index3];
          
          total_cost = cost12 + cost23;
          path_count = 1;
      }

    }
    
    
    
    cout << total_cost << " " << path_count << endl;
  }

  return 0;
}