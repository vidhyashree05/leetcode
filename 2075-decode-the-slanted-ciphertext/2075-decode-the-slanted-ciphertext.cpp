class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        if (rows == 1) return encodedText;

        int cols = n / rows;
        string result = "";

        // Diagonal traversal
        for (int start = 0; start < cols; start++) {
            int r = 0, c = start;

            while (r < rows && c < cols) {
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};