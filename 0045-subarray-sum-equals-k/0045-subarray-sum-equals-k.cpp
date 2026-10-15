class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left =0;
        int count = 0;
        int n = nums.size();
        unordered_map<int , int >mp;
        // for (int i =0; i<n; i++){
        //     int sum = 0;
        //     for( int j =i;j<n; j++){
        //         sum = sum+nums[j];
        //         if(sum == k){
        //             count = count +1;
        //         }
        //     }
        // }
        // return count;
        mp[0] = 1;
        for(int i =0; i<n; i++){
            left+= nums[i];
            int right = left -k;
            if (mp.find(right)!= mp.end()){
                count+= mp[right];
            }
            mp[left]++;
        }
        return count;
    }
};