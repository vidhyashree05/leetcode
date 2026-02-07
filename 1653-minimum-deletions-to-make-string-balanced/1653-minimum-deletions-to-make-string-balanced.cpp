class Solution {
public:
    int minimumDeletions(string s) {

        int bCount = 0;     // number of 'b's seen so far
        int deletions = 0;  // minimum deletions needed

        for (char c : s) {
            if (c == 'b') {
                // Keep track of 'b'
                bCount++;
            } else {
                // c == 'a'
                // Either delete this 'a' OR delete all previous 'b'
                deletions = min(deletions + 1, bCount);
            }
        }

        return deletions;
    }
};
