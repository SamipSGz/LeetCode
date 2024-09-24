
class Solution
{
public:
    int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2)
    {
        std::unordered_set<int> set1;
        int result = 0;

        for (int item : arr1)
        {
            for (int prefix : getPrefixes(item))
            {
                set1.insert(prefix);
            }
        }

        for (int item : arr2)
        {
            for (int prefix : getPrefixes(item))
            {
                if (set1.find(prefix) != set1.end())
                {
                    result = std::max(result, static_cast<int>(std::to_string(prefix).length()));
                }
            }
        }

        return result;
    }

private:
    std::vector<int> getPrefixes(int n)
    {
        std::vector<int> prefixList;
        while (n > 0)
        {
            prefixList.push_back(n);
            n /= 10;
        }
        return prefixList;
    }
};
