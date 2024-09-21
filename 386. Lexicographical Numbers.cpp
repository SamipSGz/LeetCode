class Solution
{
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, n);
        }

        return ans;
    }

    void dfs(int i, int n)
    {
        if (i > n)
        {
            return;
        }
        ans.insert(ans.end(), i);

        for (int j = 0; j < 10; j++)
        {
            dfs(10 * i + j, n);
        }
    }
};