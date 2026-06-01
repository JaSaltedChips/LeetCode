/*
Sum of Increasing Product Blocks

You are given an integer n.

A sequence is formed as follows:

The 1st block contains 1.
The 2nd block contains 2 * 3.
The ith block is the product of the next i consecutive integers.
Let F(n) be the sum of the first n blocks.

Return an integer denoting F(n) modulo 10^9 + 7.
*/
class Solution {
public:
    int sumOfBlocks(int n)
    {    
        const long kMod = (1e9) + 7; 
        long answer = 0;
        int number = 0;
        for (int i=0; i<n; i++)
        {
            long tempAnswer = 1;
            for(int j=0; j<=i; j++)
            {
                number++;
                tempAnswer *= number;
                if (tempAnswer >= kMod)
                {
                    tempAnswer = tempAnswer % kMod;
                } 
            }
            answer += tempAnswer;
        }
        return static_cast<int>(answer % kMod);
    }
};
