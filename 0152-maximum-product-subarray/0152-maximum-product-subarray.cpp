class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int MA = nums[0];
        int MI = nums[0];
        for(int i =1; i<nums.size(); i++){

        int v1 = nums[i];
        int v2 = MI * nums[i];
        int v3 = MA * nums[i];
        MA = max(v1 , max(v2 ,v3));
        MI = min(v1 ,min(v2, v3));
        result = max(result , MA);
        }
        return result;

    }
};