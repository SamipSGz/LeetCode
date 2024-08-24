class Solution {
public:
    string nearestPalindromic(string n) {
        
        long num = stol(n);
        int len = n.length();
        vector<long> candidates;

        if (num <= 9) {
            return to_string(num - 1);
        }

        candidates.push_back(pow(10, len - 1) - 1);  
        candidates.push_back(pow(10, len) + 1);      
        int mid = len / 2;
        bool isOdd = len % 2;
        long prefix = stol(n.substr(0, mid + isOdd));  

        for (int i = -1; i <= 1; ++i) {
            string left = to_string(prefix + i);
            string right = string(left.rbegin() + isOdd, left.rend());
            candidates.push_back(stol(left + right));
        }

        long minDiff = numeric_limits<long>::max();
        long closestNum = num;
        for (long candidate : candidates) {
            long diff = abs(candidate - num);
            if (diff == 0) continue;  

            if (diff < minDiff || (diff == minDiff && candidate < closestNum)) {
                minDiff = diff;
                closestNum = candidate;
            }
        }

        return to_string(closestNum);
    }
    
};