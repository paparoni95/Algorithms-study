class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* BruteForce
           시간 : O(N^2)
           공간 : O(1)
        */
        vector<int> answer(2);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }

        return answer;
    }
};