class Solution
{
public:
    int countSteps(int curr, long n)
    {
        long steps = 0, first = curr, last = curr;
        while (first <= n)
        {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k--; // We decrement k because we are starting from the first number

        while (k > 0)
        {
            int steps = countSteps(curr, n);
            if (steps <= k)
            {
                // Move to the next sibling
                curr++;
                k -= steps;
            }
            else
            {
                // Move to the first child
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
