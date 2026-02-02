class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

           
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int spaces = maxWidth - (lineLen - (j - i - 1)); 
            int gaps = j - i - 1; 
            string line = "";

            
            if (j == n || gaps == 0) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' '); 
            } else { 
                int spacePerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;  

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) {
                        int s = spacePerGap + (extraSpaces > 0 ? 1 : 0);
                        line += string(s, ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
