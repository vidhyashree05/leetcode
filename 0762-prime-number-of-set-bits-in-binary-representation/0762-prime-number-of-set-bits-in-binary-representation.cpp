class Solution {
public:

    // Function to check whether a number is prime
    bool isPrime(int n) {
        // Prime numbers are greater than 1
        if (n < 2) 
            return false;

        // Check divisibility from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)   // If divisible, not prime
                return false;
        }

        return true;  // If no divisors found, it is prime
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;   // To store final answer

        // Iterate through every number in range [left, right]
        for (int i = left; i <= right; i++) {

            // Count number of 1's in binary representation
            // __builtin_popcount(i) is GCC inbuilt function
            int setBits = __builtin_popcount(i);

            // Check if number of set bits is prime
            if (isPrime(setBits)) {
                count++;   // Increase count if prime
            }
        }

        return count;   // Return total valid numbers
    }
};