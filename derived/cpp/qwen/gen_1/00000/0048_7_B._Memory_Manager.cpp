#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct MemoryBlock {
    int id;
    int start;
    int size;
};

bool compareBlocks(const MemoryBlock &a, const MemoryBlock &b) {
    return a.start < b.start;
}

int main() {
    int t, m;
    cin >> t >> m;

    vector<MemoryBlock> memBlocks;
    int nextId = 1;
    int freeStart = 0;

    while (t--) {
        string command;
        cin >> command;

        if (command == "alloc") {
            int n;
            cin >> n;
            bool allocated = false;

            for (auto &block : memBlocks) {
                if (block.start - freeStart >= n) {
                    memBlocks.push_back({nextId, freeStart, n});
                    freeStart += n;
                    sort(memBlocks.begin(), memBlocks.end(), compareBlocks);
                    cout << nextId++ << "\n";
                    allocated = true;
                    break;
                } else {
                    freeStart = block.start + block.size;
                }
            }

            if (!allocated && m - freeStart >= n) {
                memBlocks.push_back({nextId, freeStart, n});
                freeStart += n;
                sort(memBlocks.begin(), memBlocks.end(), compareBlocks);
                cout << nextId++ << "\n";
            } else if (!allocated) {
                cout << "NULL\n";
            }
        } else if (command == "erase") {
            int x;
            cin >> x;
            bool found = false;

            for (auto it = memBlocks.begin(); it != memBlocks.end(); ++it) {
                if (it->id == x) {
                    memBlocks.erase(it);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        } else if (command == "defragment") {
            int currentPos = 0;
            for (auto &block : memBlocks) {
                block.start = currentPos;
                currentPos = block.start + block.size;
            }
            freeStart = currentPos;
        }
    }

    return 0;
}