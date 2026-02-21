class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // If lengths are different, cannot be isomorphic
        if (s.length() != t.length())
            return false;

        // Two maps to maintain bidirectional mapping
        unordered_map<char, char> mapST;  // s -> t
        unordered_map<char, char> mapTS;  // t -> s

        // Traverse both strings
        for (int i = 0; i < s.length(); i++) {
            
            char c1 = s[i];  // character from s
            char c2 = t[i];  // character from t

            // If c1 is already mapped
            if (mapST.count(c1)) {
                // Check if it maps to same character
                if (mapST[c1] != c2)
                    return false;
            }
            else {
                // If c2 is already mapped to some other character
                if (mapTS.count(c2))
                    return false;

                // Create new mapping
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
        }

        // If all conditions satisfied
        return true;
    }
};