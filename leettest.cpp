class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector <int> myVec;
        for(int i = 0; i < nums.size(); i ++)
        {
            for(int j = i + 1; j < nums.size(); j ++)
            {
                if((nums[i] + nums[j]) == target) {
                    myVec = {i, j};
                    return myVec;
                }
                else if((nums[i] + nums[j]) > target)
                    break;
            }
        }
        return myVec;
    }
};