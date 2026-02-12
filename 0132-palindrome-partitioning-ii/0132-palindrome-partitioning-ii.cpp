class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);
        
        // isPal[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[i] = i;  // maximum cuts possible
            
            for (int j = 0; j <= i; j++) {
                
                // Check palindrome
                if (s[i] == s[j] && 
                   (i - j <= 2 || isPal[j + 1][i - 1])) {
                    
                    isPal[j][i] = true;
                    
                    // If whole substring is palindrome
                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};
