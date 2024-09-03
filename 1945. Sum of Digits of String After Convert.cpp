#include <string>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string transformed;
        for (char c : s)
        {
            int pos = c - 'a' + 1;
            transformed += to_string(pos); // Append position as string
        }

        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum = 0;
            for (char digit : transformed)
            {
                sum += digit - '0'; // Convert char to int and add to sum
            }
            transformed = to_string(sum);
        }

        return sum;
    }
};
