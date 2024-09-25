class TrieNode
{
public:
    TrieNode *children[26];
    int prefixCount;

    TrieNode()
    {
        prefixCount = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        TrieNode *root = new TrieNode();

        for (const string &word : words)
        {
            TrieNode *node = root;
            for (char c : word)
            {
                int idx = c - 'a';
                if (node->children[idx] == nullptr)
                {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                node->prefixCount++;
            }
        }

        vector<int> result;
        for (const string &word : words)
        {
            TrieNode *node = root;
            int score = 0;
            for (char c : word)
            {
                int idx = c - 'a';
                node = node->children[idx];
                score += node->prefixCount;
            }
            result.push_back(score);
        }

        return result;
    }
};
