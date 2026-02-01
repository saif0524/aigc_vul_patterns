#include <bits/stdc++.h>
using namespace std;

struct Tag {
    string name;
    bool visible;
    vector<string> content;
    vector<Tag> children;
};

struct Button {
    string name;
    string script;
};

struct Script {
    string name;
    string content;
};

struct User {
    int w, h, s;
    string startFile;
    vector<pair<int, int>> clicks;
};

void parseDML(const string& fileContent, Tag& root) {
    int pos = 0;
    while (pos < fileContent.size()) {
        if (fileContent[pos] == '<') {
            int endPos = fileContent.find('>', pos);
            string tagName = fileContent.substr(pos + 1, endPos - pos - 1);
            if (tagName[0] == '/') {
                // End tag
                pos = endPos + 1;
                continue;
            }
            Tag newTag;
            newTag.name = tagName;
            newTag.visible = true;
            root.children.push_back(newTag);
            Tag& currentTag = root.children.back();
            pos = endPos + 1;
            while (pos < fileContent.size() && fileContent[pos] != '<') {
                currentTag.content.push_back(string(1, fileContent[pos]));
                pos++;
            }
            if (pos < fileContent.size() && fileContent[pos] == '<') {
                parseDML(fileContent.substr(pos), currentTag);
            }
        } else {
            root.content.push_back(string(1, fileContent[pos]));
            pos++;
        }
    }
}

void parseDS(const string& fileContent, vector<Script>& scripts) {
    istringstream iss(fileContent);
    string line;
    while (getline(iss, line)) {
        Script script;
        script.name = line.substr(0, line.find('{'));
        script.content = line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1);
        scripts.push_back(script);
    }
}

void render(Tag& root, int w, int h, int& x, int& y, vector<string>& output) {
    for (const auto& content : root.content) {
        if (x >= w) {
            x = 0;
            y++;
            if (y >= h) return;
            output.push_back("");
        }
        output.back() += content;
        x++;
    }
    for (auto& child : root.children) {
        if (!child.visible) continue;
        if (child.name == "br") {
            x = 0;
            y++;
            if (y >= h) return;
            output.push_back("");
        } else if (child.name != "script") {
            render(child, w, h, x, y, output);
        }
    }
}

void executeScript(const string& scriptName, const string& scriptContent, Tag& root) {
    istringstream iss(scriptContent);
    string line;
    while (getline(iss, line, ';')) {
        if (line.empty()) continue;
        bool negative = false;
        if (line[0] == '!') {
            negative = true;
            line = line.substr(1);
        }
        size_t eqPos = line.find('=');
        string varName = line.substr(0, eqPos);
        bool value = (line.substr(eqPos + 1) == "true");
        if (negative) value = !value;
        vector<string> varParts;
        size_t dotPos = varName.find('.');
        while (dotPos != string::npos) {
            varParts.push_back(varName.substr(0, dotPos));
            varName = varName.substr(dotPos + 1);
            dotPos = varName.find('.');
        }
        varParts.push_back(varName);
        Tag* currentTag = &root;
        for (const auto& part : varParts) {
            for (auto& child : currentTag->children) {
                if (child.name == part) {
                    currentTag = &child;
                    break;
                }
            }
        }
        currentTag->visible = value;
    }
}

void handleUser(User& user, const map<string, Tag>& dmlFiles, const map<string, vector<Script>>& dsFiles) {
    Tag currentDML = dmlFiles.at(user.startFile);
    for (const auto& click : user.clicks) {
        int x = click.first;
        int y = click.second;
        int currX = 0;
        int currY = 0;
        vector<string> output;
        render(currentDML, user.w, user.h, currX, currY, output);
        if (currY <= y && currX <= x) {
            for (auto it = currentDML.children.rbegin(); it != currentDML.children.rend(); ++it) {
                Tag& child = *it;
                if (child.name == "link" || child.name == "button") {
                    int childX = 0;
                    int childY = 0;
                    vector<string> childOutput;
                    render(child, user.w, user.h, childX, childY, childOutput);
                    if (childY <= y && childX <= x) {
                        if (child.name == "link") {
                            currentDML = dmlFiles.at(child.content[0]);
                        } else if (child.name == "button") {
                            for (const auto& script : dsFiles.at("s")) {
                                if (script.name == child.name) {
                                    executeScript(script.name, script.content, currentDML);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    int currX = 0;
    int currY = 0;
    vector<string> output;
    render(currentDML, user.w, user.h, currX, currY, output);
    for (auto& line : output) {
        while (line.size() < user.w) line += ".";
        cout << line << endl;
    }
}

int main() {
    int N;
    cin >> N;
    map<string, Tag> dmlFiles;
    map<string, vector<Script>> dsFiles;
    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        string fileContent;
        cin.ignore();
        getline(cin, fileContent);
        if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".dml") {
            Tag root;
            root.name = "dml";
            root.visible = true;
            parseDML(fileContent, root);
            dmlFiles[filename] = root;
        } else if (filename.size() >= 3 && filename.substr(filename.size() - 3) == ".ds") {
            vector<Script> scripts;
            parseDS(fileContent, scripts);
            dsFiles[filename] = scripts;
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        User user;
        cin >> user.w >> user.h >> user.s >> user.startFile;
        for (int j = 0; j < user.s; j++) {
            int x, y;
            cin >> x >> y;
            user.clicks.emplace_back(x, y);
        }
        handleUser(user, dmlFiles, dsFiles);
    }
    return 0;
}