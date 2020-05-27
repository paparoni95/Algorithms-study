class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        해쉬맵 사용, 루프 1개를 돌면서 이미 봤던 값을 해쉬맵에 넣는다.
            - 시간: O(N)
            - 공간: O(N)
        */
        unordered_map<int, int> hash; // 키-값, 벨류-인덱스
        vector<int> answer(2);

        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if (hash.find(target - cur) != hash.end())
            {
                answer[0] = i;
                answer[1] = hash[target - cur];
                return answer;
            }
            else
            {
                hash.insert({ cur, i });
            }
        }

        return answer;
    }
};