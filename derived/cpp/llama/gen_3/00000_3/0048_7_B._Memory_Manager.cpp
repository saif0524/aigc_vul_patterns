#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Block {
    int id;
    int size;
    int start;
};

int main() {
    int t, m;
    cin >> t >> m;

    vector<Block> memory;
    int nextId = 1;

    for (int i = 0; i < t; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "alloc") {
            int size;
            cin >> size;

            bool found = false;
            for (int start = 0; start <= m - size; start++) {
                bool available = true;
                for (const auto& block : memory) {
                    if (start < block.start + block.size && start + size > block.start) {
                        available = false;
                        break;
                    }
                }

                if (available) {
                    Block newBlock = {nextId, size, start};
                    memory.push_back(newBlock);
                    cout << nextId << endl;
                    nextId++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "NULL" << endl;
            }
        } else if (cmd == "erase") {
            int id;
            cin >> id;

            bool found = false;
            for (auto it = memory.begin(); it != memory.end(); it++) {
                if (it->id == id) {
                    memory.erase(it);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (cmd == "defragment") {
            int pos = 0;
            for (auto& block : memory) {
                if (pos < block.start) {
                    block.start = pos;
                }
                pos = block.start + block.size;
            }
        }
    }

    return 0;
}