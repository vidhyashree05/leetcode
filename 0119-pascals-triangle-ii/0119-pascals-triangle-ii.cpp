class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Create a vector of size rowIndex + 1
        vector<int> row(rowIndex + 1, 0);

        // First element of every row is 1
        row[0] = 1;

        // Build the row step by step
        for (int i = 1; i <= rowIndex; i++) {
            // Update from right to left
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};
