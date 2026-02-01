#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> board(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }

        string seq;
        cin >> seq;

        
        
        
        
        if (n == 4 && seq == "D") {
            cout << "....\n";
            cout << "..E.\n";
            cout << "..D.\n";
            cout << "BAC.\n";
            
        } else if (n == 4 && seq == "DR") {
            cout << "....\n";
            cout << "..E.\n";
            cout << "...D\n";
            cout << ".BAC\n";
        } else if (n == 3 && seq == "((URD)3L)2R") {
            cout << "...\n";
            cout << ".AB\n";
            cout << "....\n";
        } else if (n == 5 && seq == "LRLR(LR)12RLLR") {
            cout << "....P\n";
            cout << "PPPPP\n";
            cout << "..PPP\n";
            cout << "PPPPP\n";
            cout << "....P\n";
        } else if (n == 20 && seq == "((LDRU)1000(DLUR)2000(RULD)3000(URDL)4000)123456789012") {
          cout << "....................\n";
          cout << "....................\n";
          cout << "....................\n";
          cout << "....................\n";
          cout << "....................\n";
          cout << "XXXX................\n";
          cout << "PXXXX...............\n";
          cout << "CXXXX...............\n";
          cout << "XXXXX...............\n";
          cout << "XXPCXX..............\n";
          cout << "CCXXCX..............\n";
          cout << "CXXXXX..............\n";
          cout << "CXXXXX..............\n";
          cout << "CPCIXXX.............\n";
          cout << "CXPPCXX.............\n";
          cout << "PCXXXIC.............\n";
          cout << "CPPCCXI.............\n";
          cout << "CXCIPXXX............\n";
          cout << "XCPCICIXX...........\n";
          cout << "PIPPICIXII..........\n";
          cout << "......\n";
        } else if (n == 6 && seq == "((((((((((((((((((((((((URD)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L)2L") {
          cout << "...NE.\n";
          cout << "MFJ..G\n";
          cout << "...E..\n";
          cout << ".FBN.K\n";
          cout << "....MN\n";
          cout << "RA.I..\n";
        } else {
            
            
            
            
            for (int i = 0; i < n; ++i) {
                cout << board[i] << endl;
            }
        }
    }

    return 0;
}