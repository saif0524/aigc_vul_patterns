#include <bits/stdc++.h>
using namespace std;

struct Node {
    string tag;
    string content;
    vector<Node*> children;
    bool visible;
    Node(string _tag, string _content) : tag(_tag), content(_content), visible(true) {}
};

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

map<string, vector<Node*>> tagMap;
map<string, string> scriptMap;

void parseDML(const string &fileContent, Node* &root) {
    int n = fileContent.size();
    stack<Node*> nodes;
    for (int i = 0; i < n; ) {
        if (fileContent.substr(i, 4) == "<br>") {
            Node* brNode = new Node("br", "");
            nodes.top()->children.push_back(brNode);
            i += 4;
        } else if (fileContent[i] == '<') {
            int j = i + 1;
            while (j < n && fileContent[j] != '>') j++;
            string tagContent = fileContent.substr(i + 1, j - i - 1);
            bool isClosing = false;
            if (tagContent[0] == '/') {
                isClosing = true;
                tagContent = tagContent.substr(1);
            }
            if (!isClosing) {
                Node* newNode = new Node(tagContent, "");
                nodes.top()->children.push_back(newNode);
                if (tagContent != "script" && tagContent != "link" && tagContent != "button" && tagContent != "br")
                    nodes.push(newNode);
            } else {
                nodes.pop();
            }
            i = j + 1;
        } else {
            int j = i;
            while (j < n && fileContent[j] != '<') j++;
            string content = fileContent.substr(i, j - i);
            if (nodes.size())
                nodes.top()->children.push_back(new Node("", content));
            i = j;
        }
    }
}

void parseDS(const string &fileContent) {
    int n = fileContent.size();
    for (int i = 0; i < n; ) {
        if (fileContent[i] == '}') {
            i++;
            continue;
        }
        int j = i;
        while (j < n && fileContent[j] != '{') j++;
        string subroutineName = fileContent.substr(i, j - i);
        i = j + 1;
        j = i;
        while (j < n && fileContent[j] != '}') j++;
        string commands = fileContent.substr(i, j - i);
        scriptMap[subroutineName] = commands;
        i = j + 1;
    }
}

void updateVisibility(Node* node, const string &selector, bool value, bool negate) {
    if (node->tag == selector)
        node->visible = negate ? !value : value;
    for (Node* child : node->children)
        updateVisibility(child, selector, value, negate);
}

void parseCommands(Node* root, const string &commands) {
    stringstream ss(commands);
    string command;
    while (getline(ss, command, ';')) {
        if (command.empty()) continue;
        int assignPos = command.find('=');
        int negAssignPos = command.find('!=');
        if (assignPos != string::npos || negAssignPos != string::npos) {
            int pos = (negAssignPos != string::npos) ? negAssignPos : assignPos;
            string left = command.substr(0, pos);
            string right = command.substr(pos + (negAssignPos != string::npos ? 2 : 1));
            bool value = (right == "true");
            stringstream lhs(left);
            string tag;
            while (getline(lhs, tag, '.')) {
                for (Node* node : tagMap[tag])
                    updateVisibility(node, tag, value, negAssignPos != string::npos);
            }
        }
    }
}

vector<string> render(Node* node, int w, int h) {
    vector<string> screen(h, string(w, '.'));
    int x = 0, y = 0;
    for (Node* child : node->children) {
        if (child->tag == "br") {
            x = 0;
            y++;
        } else if (!child->content.empty() && child->visible) {
            for (char c : child->content) {
                if (x >= w) {
                    x = 0;
                    y++;
                }
                if (y < h)
                    screen[y][x] = c;
                x++;
            }
        } else if (child->tag != "script" && child->tag != "link" && child->tag != "button" && child->visible) {
            vector<string> subScreen = render(child, w, h);
            for (int sy = 0; sy < h && y + sy < h; sy++) {
                for (int sx = 0; sx < w && x + sx < w; sx++) {
                    if (subScreen[sy][sx] != '.')
                        screen[y + sy][x + sx] = subScreen[sy][sx];
                }
            }
            x += subScreen[0].size();
        }
    }
    return screen;
}

void buildTagMap(Node* node) {
    if (!node->tag.empty())
        tagMap[node->tag].push_back(node);
    for (Node* child : node->children)
        buildTagMap(child);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_map<string, string> files;
    for (int i = 0; i < N; i++) {
        string filename, fileContent;
        cin >> filename >> fileContent;
        files[filename] = fileContent;
    }

    for (auto& [filename, content] : files) {
        if (filename.find(".dml") != string::npos) {
            Node* root = new Node("dml", "");
            parseDML(content, root);
            tagMap.clear();
            buildTagMap(root);
        } else if (filename.find(".ds") != string::npos) {
            parseDS(content);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int w, h, s;
        string startfile;
        cin >> w >> h >> s >> startfile;
        vector<Point> clicks(s);
        for (int j = 0; j < s; j++) {
            int x, y;
            cin >> x >> y;
            clicks[j] = Point(x, y);
        }

        Node* root = new Node("dml", "");
        parseDML(files[startfile], root);
        tagMap.clear();
        buildTagMap(root);

        unordered_map<string, Node*> buttonMap;
        for (auto& [tag, nodes] : tagMap) {
            if (tag == "button") {
                for (Node* node : nodes) {
                    if (node->visible) {
                        buttonMap[node->content] = node;
                    }
                }
            }
        }

        unordered_map<string, Node*> linkMap;
        for (auto& [tag, nodes] : tagMap) {
            if (tag == "link") {
                for (Node* node : nodes) {
                    if (node->visible) {
                        linkMap[node->content] = node;
                    }
                }
            }
        }

        vector<Node*> textNodes;
        for (auto& [tag, nodes] : tagMap) {
            if (tag != "script" && tag != "button" && tag != "link" && tag != "br") {
                for (Node* node : nodes) {
                    if (node->visible) {
                        textNodes.push_back(node);
                    }
                }
            }
        }

        for (Point click : clicks) {
            for (auto& [name, node] : buttonMap) {
                if (node->visible) {
                    int x = 0, y = 0;
                    bool found = false;
                    for (Node* child : node->children) {
                        if (child->visible) {
                            for (char c : child->content) {
                                if (x == click.x && y == click.y) {
                                    found = true;
                                    break;
                                }
                                x++;
                                if (x >= w) {
                                    x = 0;
                                    y++;
                                }
                            }
                        }
                        if (found) break;
                    }
                    if (found) {
                        string commands = scriptMap[name];
                        parseCommands(root, commands);
                        break;
                    }
                }
            }
            for (auto& [filename, node] : linkMap) {
                if (node->visible) {
                    int x = 0, y = 0;
                    bool found = false;
                    for (Node* child : node->children) {
                        if (child->visible) {
                            for (char c : child->content) {
                                if (x == click.x && y == click.y) {
                                    found = true;
                                    break;
                                }
                                x++;
                                if (x >= w) {
                                    x = 0;
                                    y++;
                                }
                            }
                        }
                        if (found) break;
                    }
                    if (found) {
                        root = new Node("dml", "");
                        parseDML(files[filename], root);
                        tagMap.clear();
                        buildTagMap(root);
                        buttonMap.clear();
                        for (auto& [tag, nodes] : tagMap) {
                            if (tag == "button") {
                                for (Node* node : nodes) {
                                    if (node->visible) {
                                        buttonMap[node->content] = node;
                                    }
                                }
                            }
                        }
                        linkMap.clear();
                        for (auto& [tag, nodes] : tagMap) {
                            if (tag == "link") {
                                for (Node* node : nodes) {
                                    if (node->visible) {
                                        linkMap[node->content] = node;
                                    }
                                }
                            }
                        }
                        textNodes.clear();
                        for (auto& [tag, nodes] : tagMap) {
                            if (tag != "script" && tag != "button" && tag != "link" && tag != "br") {
                                for (Node* node : nodes) {
                                    if (node->visible) {
                                        textNodes.push_back(node);
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }

        vector<string> screen = render(root, w, h);
        for (int y = 0; y < h; y++) {
            cout << screen[y] << '\n';
        }
    }
}