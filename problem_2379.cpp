/*
Minimum recolors to get K consecutive black blocks.
Return the minimum number of operations needed such tath there is at least one occurrence of k consecutive black blocks.
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n {static_cast<int>(blocks.size())};
        if(n < k) return 0;
        
        int answer{INT_MAX};
        int noOfWs {static_cast<int>(std::count(blocks.begin(), blocks.begin()+k, 'W'))};
        answer = noOfWs;
        for (int i = 0; i < (n-k); i++)
        {
            if(noOfWs == 0) return 0;
            if (blocks[i] == 'W') noOfWs--;
            if(blocks[i+k] == 'W') noOfWs++;
            answer = std::min(noOfWs, answer);
        }
        return answer;
    }
};
