#include <bits/stdc++.h>
using namespace std;

void alignStrings(vector<vector<int>>& Table, const string& str1, const string& str2) {
    int gap = 2;
    
    // Vowel checking
    vector<int> vc(26, 0);
    string vowels = "aeiou"; 
    for (auto vowel : vowels) {
        vc[vowel - 'a'] = 1;
    }

    // Mismatch cost matrix
    vector<vector<int>> mc(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) 
                mc[i][j] = 0;         // Same characters 
            else if (vc[i] == vc[j]) 
                mc[i][j] = 1;         // vowel-vowel or consonant-consonant 
            else 
                mc[i][j] = 3;         // vowel-consonant or consonant-vowel
        }
    }

    // base case
    for (int i = 0; i <= str1.size(); i++) {
        Table[i][0] = i * gap; 
    }
    for (int j = 0; j <= str2.size(); j++) {
        Table[0][j] = j * gap;  
    }

    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            int c1 = Table[i - 1][j - 1] + mc[str1[i - 1] - 'a'][str2[j - 1] - 'a']; 
            int c2 = Table[i - 1][j] + gap; 
            int c3 = Table[i][j - 1] + gap; 
            Table[i][j] = min(c1, min(c2, c3)); 
        }
    }
}

int main() {
    string fString = "name";
    string sString = "naem";
    

    vector<vector<int>> Table(fString.size() + 1, vector<int>(sString.size() + 1, 0));
    
    alignStrings(Table, fString, sString);


    cout << "Cost Table after function call:" << endl;
    for (int i = 0; i <= fString.size(); i++) {
        for (int j = 0; j <= sString.size(); j++) {
            cout << Table[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Minimum alignment cost: " << Table[fString.size()][sString.size()] << endl;

    return 0;
}
