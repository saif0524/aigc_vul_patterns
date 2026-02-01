#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> files;
    for (int i = 0; i < n; ++i) {
        string filename;
        cin >> filename;
        string file_content;
        getline(cin >> ws, file_content);
        files[filename] = file_content;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int w, h, s;
        string start_filename;
        cin >> w >> h >> s >> start_filename;

        string current_dml = files[start_filename];
        map<string, bool> tag_visibility;

        // Parse DML file and initialize tag visibility
        string tag_name;
        int start_tag_pos = 0;
        while ((start_tag_pos = current_dml.find("<", start_tag_pos)) != string::npos) {
            int end_tag_pos = current_dml.find(">", start_tag_pos);
            if (end_tag_pos == string::npos) break;

            string tag = current_dml.substr(start_tag_pos + 1, end_tag_pos - start_tag_pos - 1);
            
            if (tag[0] == '/') {
                 
            } else {
                tag_visibility[tag] = true;
            }
            start_tag_pos = end_tag_pos + 1;
        }
        
        

        
        
        
        
        vector<pair<int, int>> clicks(s);
        for (int j = 0; j < s; ++j) {
            cin >> clicks[j].first >> clicks[j].second;
        }

        for (int j = 0; j < s; ++j) {
            int x = clicks[j].first;
            int y = clicks[j].second;
            
            
            //find if starting tag is in position
            
            //find the current dml file content
            
            //find the position of the tag
            string tag_to_execute = "";
            bool found_tag = false;
            
            
            
            if (current_dml.find("<link>") != string::npos){
                size_t link_start = current_dml.find("<link>");
                size_t link_end = current_dml.find("</link>");
                if (link_start != string::npos && link_end != string::npos){
                    tag_to_execute = current_dml.substr(link_start + 6, link_end - link_start - 6);
                    
                    
                    
                    current_dml = files[tag_to_execute];
                    tag_visibility.clear();
                    
                    
                    start_tag_pos = 0;
                    while ((start_tag_pos = current_dml.find("<", start_tag_pos)) != string::npos) {
                        int end_tag_pos = current_dml.find(">", start_tag_pos);
                        if (end_tag_pos == string::npos) break;
                        string tag = current_dml.substr(start_tag_pos + 1, end_tag_pos - start_tag_pos - 1);
                        if (tag[0] == '/') {
                            
                        } else{
                            tag_visibility[tag] = true;
                        }

                        start_tag_pos = end_tag_pos + 1;
                    }
                    
                }
                
            } else if (current_dml.find("<button>") != string::npos){
                size_t button_start = current_dml.find("<button>");
                size_t button_end = current_dml.find("</button>");

                if (button_start != string::npos && button_end != string::npos){
                    tag_to_execute = current_dml.substr(button_start + 8, button_end - button_start - 8);
                    string ds_filename = tag_to_execute + ".ds";
                    if (files.find(ds_filename) != files.end()){
                        string ds_content = files[ds_filename];
                        
                        //parse ds content
                        size_t pos = 0;
                        while((pos = ds_content.find("{")) != string::npos){
                            size_t end_pos = ds_content.find("}",pos);
                            
                            if (end_pos != string::npos){
                                string expression = ds_content.substr(pos + 1, end_pos - pos - 1);
                                size_t equal_pos = expression.find("=");
                                size_t not_equal_pos = expression.find("!=");
                                string var_name;
                                string value;

                                if (equal_pos != string::npos){
                                    var_name = expression.substr(0, equal_pos);
                                    value = expression.substr(equal_pos + 1);
                                    
                                    if (value == "true"){
                                        tag_visibility[var_name] = true;
                                    } else if (value == "false"){
                                        tag_visibility[var_name] = false;
                                    }
                                } else if (not_equal_pos != string::npos){
                                    var_name = expression.substr(0, not_equal_pos);
                                    value = expression.substr(not_equal_pos + 2);
                                    
                                     if (value == "true"){
                                        tag_visibility[var_name] = false;
                                    } else if (value == "false"){
                                        tag_visibility[var_name] = true;
                                    }
                                } 

                                
                            }
                            pos = end_pos + 1;
                        }

                    }
                }
            
            }
        }

        // Output the final screen
        string output_string = "";
        
        for (int i = 0; i < current_dml.length(); ++i) {
            if (current_dml[i] == '<') {
                int end_tag_pos = current_dml.find(">", i);
                if (end_tag_pos != string::npos) {
                    string tag = current_dml.substr(i + 1, end_tag_pos - i - 1);
                    
                    if (tag == "br") {
                        output_string += '\n';
                        
                    } else if (tag_visibility.find(tag)!= tag_visibility.end()){
                        if(tag_visibility[tag]){
                           
                            i = end_tag_pos;
                            
                        }
                        else{
                            i = end_tag_pos;

                        }
                    } else {
                         i = end_tag_pos;
                    }
                }
            } else {
                
                if (current_dml[i] != '<'){
                    output_string += current_dml[i];
                }
            }
        }

        
        
        
        
        
        vector<string> lines;
        string current_line;
        for (char c : output_string) {
            if (c == '\n') {
                lines.push_back(current_line);
                current_line = "";
            } else {
                current_line += c;
            }
        }
        lines.push_back(current_line);

        for (int line_num = 0; line_num < lines.size(); ++line_num) {
            if (lines[line_num].length() > w) {
                lines[line_num] = lines[line_num].substr(0, w);
            }
            
            
            
            
            while (lines[line_num].length() < w) {
              lines[line_num] += '.';
            }
            
            cout << lines[line_num] << endl;
        }
    }

    return 0;
}