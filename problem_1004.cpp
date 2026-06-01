/*
Max Consecutive Ones III
Given a binary array `nums` and an integers `k`, return the maximum number of consecutive 1's in the array if you can flip at most k 0'S
*/
class Solution {
/*
The Reframe
Forget "flipping." The problem is really: find the longest subarray containing at most k zeros.
If a window has ≤ k zeros, you could flip them all, so the whole window is valid.
*/
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int noOfZeros = 0;
        int leftIdx = 0;
        int rightIdx = 0;

        int n = static_cast<int>(nums.size());
        if(k>=n) return n;
        for (; rightIdx < n; rightIdx++)
        {
            if(nums[rightIdx] == 0) noOfZeros++;
            if(noOfZeros > k)
            {
                /*
                When noOfZerso > k, the window [leftIdx, rightIdx] is invalid.
                The last valid window is [leftIdx, rightIdx - 1]
                */
                count = std::max(count, (rightIdx - leftIdx));
                if(nums[leftIdx] == 0) noOfZeros--;
                leftIdx++;
            }
            else
            {
                // The window [leftIdx, rightIdx] is valid here.
                count = std::max(count, (rightIdx - leftIdx + 1));
            }
        }
        return count;
    }
};
