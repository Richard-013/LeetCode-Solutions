/*
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numSize = nums.size();
        int endpoint = numSize-1;
    
        for(int i = 0; i < numSize; i++)
        {
            if(nums[i] == 0)
            {
                for(int j = i; j <= endpoint; j++)
                {
                    if (j == endpoint)
                    {
                        nums[j] = 0;
                    }
                    else
                    {
                        nums[j] = nums[j+1];
                    }
                }
                
                endpoint--;
                i--;
                
                if(i >= endpoint)
                {
                    break;
                }
            }
        }
    }
};
