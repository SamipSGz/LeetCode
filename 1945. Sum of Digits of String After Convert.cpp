#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert the string into a string of digits
        string transformed;
        for (char c : s) {
            int pos = c - 'a' + 1; // Calculate position in the alphabet
            transformed += to_string(pos); // Append position as string
        }

        // Step 2: Sum the digits k times
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (char digit : transformed) {
                sum += digit - '0'; // Convert char to int and add to sum
            }
            transformed = to_string(sum); // Convert sum back to string for next iteration
        }

        return sum;
    }
};
