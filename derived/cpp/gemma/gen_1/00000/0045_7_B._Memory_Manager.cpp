#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;

    vector<pair<int, int>> allocated_blocks; // (block_id, size)
    vector<bool> memory(m, true); // true if free, false if allocated
    int next_block_id = 1;

    for (int i = 0; i < t; ++i) {
        string operation;
        cin >> operation;

        if (operation == "alloc") {
            int n;
            cin >> n;

            int start_index = -1;
            for (int j = 0; j <= m - n; ++j) {
                bool found = true;
                for (int k = 0; k < n; ++k) {
                    if (!memory[j + k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    start_index = j;
                    break;
                }
            }

            if (start_index != -1) {
                allocated_blocks.push_back({next_block_id, n});
                for (int j = start_index; j < start_index + n; ++j) {
                    memory[j] = false;
                }
                cout << next_block_id++ << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (operation == "erase") {
            int x;
            cin >> x;

            bool found = false;
            int index = -1;
            for (int j = 0; j < allocated_blocks.size(); ++j) {
                if (allocated_blocks[j].first == x) {
                    found = true;
                    index = j;
                    break;
                }
            }

            if (found) {
                int start_index = -1;
                for (int j = 0; j <= m - allocated_blocks[index].second; ++j) {
                  bool match = true;
                  for (int k = 0; k < allocated_blocks[index].second; ++k) {
                      if (memory[j + k] == true) {
                          match = false;
                          break;
                      }
                  }
                  if (match) {
                      start_index = j;
                      break;
                  }
                }
                
                if(start_index != -1){
                    for (int j = start_index; j < start_index + allocated_blocks[index].second; ++j) {
                        memory[j] = true;
                    }
                    allocated_blocks.erase(allocated_blocks.begin() + index);
                } else {
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                }
                
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (operation == "defragment") {
            vector<pair<int, int>> new_allocated_blocks;
            int current_position = 0;
            for (auto& block : allocated_blocks) {
                int block_size = block.second;
                
                
                new_allocated_blocks.push_back({block.first, block_size});
                
                current_position += block_size;
                
            }
            
            
            
            for (int j = 0; j < m; ++j) {
                memory[j] = true;
            }

            for (size_t j = 0; j < new_allocated_blocks.size(); ++j) {
                int block_id = new_allocated_blocks[j].first;
                int block_size = new_allocated_blocks[j].second;

                int start_index = -1;
                 for (int k = 0; k <= m - block_size; ++k) {
                    bool found = true;
                    for (int l = 0; l < block_size; ++l) {
                        if (!memory[k + l]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        start_index = k;
                        break;
                    }
                }
                if(start_index != -1){
                    for (int k = start_index; k < start_index + block_size; ++k) {
                         memory[k] = false;
                    }
                }
            }
            allocated_blocks = new_allocated_blocks;
            
        }
    }

    return 0;
}