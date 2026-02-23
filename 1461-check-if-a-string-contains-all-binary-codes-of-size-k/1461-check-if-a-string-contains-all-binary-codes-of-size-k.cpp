class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if (n < k) return false;
        
        unordered_set<int> seen;
        int total = 1 << k;   // 2^k
        
        int hash = 0;
        
        for (int i = 0; i < n; i++) {
            // build rolling hash
            hash = ((hash << 1) & (total - 1)) | (s[i] - '0');
            
            if (i >= k - 1) {
                seen.insert(hash);
                if (seen.size() == total)
                    return true;
            }
        }
        
        return false;
    }
};