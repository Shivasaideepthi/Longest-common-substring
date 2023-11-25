#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the longest common substring and display the 2D grid
string longestCommonSubstring(const string &s1, const string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int maxLength = 0, endPos = 0;

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i;
                }
            }
        }
    }

    // Display the 2D grid
    cout << "2D Grid (DP Table):" << endl;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Extract the longest common substring
    return s1.substr(endPos - maxLength, maxLength);
}

// Main function
int main() {
    string str1, str2;

    // Input the two strings
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Compute and display the longest common substring
    string lcs = longestCommonSubstring(str1, str2);
    cout << "\nLongest Common Substring: " << lcs << "\n";

    return 0;
}
