#include <bits/stdc++.h>
using namespace std;

struct Tag {
    string name;
    bool visible;
    vector<Tag*> children;
    string content;
};

struct Subroutine {
    string name;
    vector<string> assignments;
};

map<string, vector<Tag*>> tagMap;
map<string, Subroutine> subroutineMap;

void parseDML(const string& content, Tag* parent) {
    int pos = 0, n = content.size();
    while (pos < n) {
        if (content.substr(pos, 4) == "<dml>") {
            Tag* root = new Tag();
            root->name = "dml";
            root->visible = true;
            parseDML(content.substr(pos + 5), root);
            parent->children.push_back(root);
            break;
        }
        if (content.substr(pos, 7) == "<script>") {
            int endScript = content.find("</script>", pos);
            pos = endScript + 9;
            continue;
        }
        if (content.substr(pos, 4) == "<br>") {
            parent->children.push_back(new Tag());
            parent->children.back()->name = "br";
            parent->children.back()->visible = true;
            pos += 4;
            continue;
        }
        if (content.substr(pos, 5) == "<link>") {
            Tag* link = new Tag();
            link->name = "link";
            int endLink = content.find("</link>", pos);
            link->content = content.substr(pos + 6, endLink - pos - 6);
            link->visible = true;
            parent->children.push_back(link);
            pos = endLink + 7;
            continue;
        }
        if (content.substr(pos, 7) == "<button>") {
            Tag* button = new Tag();
            button->name = "button";
            int endButton = content.find("</button>", pos);
            button->content = content.substr(pos + 8, endButton - pos - 8);
            button->visible = true;
            parent->children.push_back(button);
            pos = endButton + 9;
            continue;
        }
        if (content[pos] == '<') {
            int endTag = content.find('>', pos);
            string tagName = content.substr(pos + 1, endTag - pos - 1);
            Tag* tag = new Tag();
            tag->name = tagName;
            tag->visible = true;
            int endContent = content.find("</" + tagName + ">", pos);
            parseDML(content.substr(endTag + 1, endContent - endTag - 1), tag);
            tag->content = content.substr(endTag + 1, endContent - endTag - 1);
            parent->children.push_back(tag);
            tagMap[tagName].push_back(tag);
            pos = endContent + tagName.size() + 3;
        } else {
            int endText = content.find('<', pos);
            if (endText == string::npos) endText = n;
            Tag* textTag = new Tag();
            textTag->name = "text";
            textTag->content = content.substr(pos, endText - pos);
            textTag->visible = true;
            parent->children.push_back(textTag);
            pos = endText;
        }
    }
}

void parseDS(const string& content) {
    int pos = 0, n = content.size();
    while (pos < n) {
        int start = content.find('{', pos);
        int end = content.find('}', start);
        string subroutineName = content.substr(pos, start - pos);
        Subroutine subroutine;
        subroutine.name = subroutineName;
        string assignmentString = content.substr(start + 1, end - start - 1);
        stringstream ss(assignmentString);
        string assignment;
        while (getline(ss, assignment, ';')) {
            if (!assignment.empty()) subroutine.assignments.push_back(assignment);
        }
        subroutineMap[subroutineName] = subroutine;
        pos = end + 1;
    }
}

void applySubroutine(Subroutine subroutine) {
    for (const string& assignment : subroutine.assignments) {
        string var, exp;
        bool negative = false;
        if (assignment.find("!") != string::npos) {
            negative = true;
            var = assignment.substr(0, assignment.find("!="));
            exp = assignment.substr(assignment.find("!=") + 2);
        } else {
            var = assignment.substr(0, assignment.find('='));
            exp = assignment.substr(assignment.find('=') + 1);
        }
        vector<string> tokens;
        stringstream ss(var);
        string token;
        while (getline(ss, token, '.')) tokens.push_back(token);
        tokens.pop_back();
        string lastVar = tokens.back();
        tokens.pop_back();
        for (Tag* tag : tagMap[lastVar]) {
            bool matches = true;
            Tag* currentTag = tag;
            for (int i = tokens.size() - 1; i >= 0; --i) {
                bool found = false;
                for (Tag* parentTag : currentTag->children) {
                    if (parentTag->name == tokens[i]) {
                        currentTag = parentTag;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                if (exp == "true" || exp == "false") {
                    if (negative) tag->visible = (exp == "true" ? false : true);
                    else tag->visible = (exp == "true" ? true : false);
                } else {
                    for (auto& [varName, val] : subroutineMap) {
                        if (varName == exp) {
                            if (negative) tag->visible = !val.assignments[0].substr(varName.size()).substr(1).substr(0, val.assignments[0].substr(varName.size()).substr(1).size() - 1) == "true";
                            else tag->visible = val.assignments[0].substr(varName.size()).substr(1).substr(0, val.assignments[0].substr(varName.size()).substr(1).size() - 1) == "true";
                        }
                    }
                }
            }
        }
    }
}

void render(const Tag* root, vector<string>& screen, int w, int h, int& x, int& y) {
    for (const Tag* child : root->children) {
        if (child->name == "br") {
            y++;
            x = 0;
        } else if (child->name == "link" || child->name == "button" || child->name == "script") {
            continue;
        } else if (child->visible) {
            for (char c : child->content) {
                if (x >= w) {
                    y++;
                    x = 0;
                }
                if (y >= h) return;
                screen[y][x] = c;
                x++;
            }
        }
        if (y >= h) return;
        render(child, screen, w, h, x, y);
    }
}

void handleClick(Tag* root, int x, int y, int w, int h, string& nextFile) {
    int currX = 0, currY = 0;
    deque<Tag*> q;
    q.push_back(root);
    while (!q.empty()) {
        Tag* tag = q.front();
        q.pop_front();
        if (tag->name == "br") {
            currY++;
            currX = 0;
        } else if (tag->visible) {
            for (char c : tag->content) {
                if (currX >= w) {
                    currY++;
                    currX = 0;
                }
                if (currX == x && currY == y) {
                    if (tag->name == "link") nextFile = tag->content;
                    else if (tag->name == "button") {
                        if (subroutineMap.count(tag->content)) {
                            applySubroutine(subroutineMap[tag->content]);
                        }
                    }
                }
                currX++;
            }
        }
        for (Tag* child : tag->children) q.push_back(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore();
    map<string, string> files;
    for (int i = 0; i < 2 * N; i += 2) {
        string filename, content;
        getline(cin, filename);
        getline(cin, content);
        files[filename] = content;
    }
    int M;
    cin >> M;
    cin.ignore();
    for (int i = 0; i < M; i++) {
        int w, h, s;
        string startFile;
        cin >> w >> h >> s >> startFile;
        cin.ignore();
        vector<pair<int, int>> clicks(s);
        for (int j = 0; j < s; j++) {
            cin >> clicks[j].first >> clicks[j].second;
        }
        cin.ignore();
        tagMap.clear();
        subroutineMap.clear();
        string dmlContent = files[startFile];
        Tag* root = new Tag();
        parseDML(dmlContent, root);
        for (const auto& [filename, content] : files) {
            if (filename.substr(filename.size() - 3) == ".ds") {
                parseDS(content);
            }
        }
        string currentFile = startFile;
        Tag* currentRoot = root;
        for (const auto& [x, y] : clicks) {
            handleClick(currentRoot, x, y, w, h, currentFile);
            if (currentFile != startFile) {
                currentFile = files[currentFile];
                currentRoot = new Tag();
                parseDML(currentFile, currentRoot);
                currentFile = files[currentFile];
                break;
            }
        }
        vector<string> screen(h, string(w, '.'));
        int x = 0, y = 0;
        render(currentRoot, screen, w, h, x, y);
        for (const string& line : screen) {
            cout << line << "\n";
        }
    }
    return 0;
}