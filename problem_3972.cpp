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
    /*
    It folds the value at compile time — kMod doesn't exist as a memory location in the generated code.
    The value 1000000007 is embedded as an immediate in the instruction, or hoisted into a register
    once before the loop. Zero memory traffic for kMod.
    */
    static constexpr long kMod = (1e9) + 7; 
    int sumOfBlocks(int n)
    {    
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
