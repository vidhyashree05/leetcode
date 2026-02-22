class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;    // Last position of 1
        int maxDistance = 0; // Maximum distance between 1's
        int pos = 0;         // Current bit position

        while (n > 0) {
            if (n & 1) {             // Current bit is 1
                if (lastPos != -1) {
                    maxDistance = max(maxDistance, pos - lastPos);
                }
                lastPos = pos;       // Update last 1 position
            }
            n = n >> 1;              // Shift right
            pos++;
        }

        return maxDistance;
    }
};