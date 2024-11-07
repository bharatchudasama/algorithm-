#include <bits/stdc++.h>
using namespace std;

void stringAlign(vector<vector<int>>& dp, const string& x, const string& y) {
    int delta = 2;
    
    // Vowel checking
    vector<int> ifvow(26, 0);
    string vows = "aeiou"; 
    for (auto e : vows) {
        ifvow[e - 'a'] = 1;
    }

    // Mismatch cost matrix
    vector<vector<int>> alph(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) 
                alph[i][j] = 0;         // Same 
            else if (ifvow[i] == ifvow[j]) 
                alph[i][j] = 1;         // vowel-vowel or consonant-consonant
            else 
                alph[i][j] = 3;         // vowel-consonant or consonant-vowel
        }
    }

    // base cases
    for (int i = 0; i <= x.size(); i++) {
        dp[i][0] = i * delta;
    }
    for (int j = 0; j <= y.size(); j++) {
        dp[0][j] = j * delta;  
    }

    // Fill the DP table using the recurrence
    for (int i = 1; i <= x.size(); i++) {
        for (int j = 1; j <= y.size(); j++) {
            int c1 = dp[i - 1][j - 1] + alph[x[i - 1] - 'a'][y[j - 1] - 'a']; 
            int c2 = dp[i - 1][j] + delta; 
            int c3 = dp[i][j - 1] + delta; 
            dp[i][j] = min(c1, min(c2, c3)); 
        }
    }
}

int main() {
    string a = "name";
    string b = "naem";
    
    // Dp table
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    
   
    stringAlign(dp, a, b);

  
    cout << "DP Table after function call:" << endl;
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
  
    cout << "Minimum alignment cost: " << dp[a.size()][b.size()] << endl;

    return 0;
}
