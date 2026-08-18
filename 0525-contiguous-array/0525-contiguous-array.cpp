class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum =0;
        int high =0;
        int n = nums.size();
        int result =0;
        unordered_map<int , int > mp;
        mp[0]=-1;
        while(high < n){
            if(nums[high]==0){
                sum++;
            }
            else
            {
                sum--;
            }
            if(mp.count(sum)){
                int len = high - mp[sum];
                result = max(result ,len);
            }
            else
            {
                mp[sum]= high;
            }
            high++;
        }
        return result;
    }
};