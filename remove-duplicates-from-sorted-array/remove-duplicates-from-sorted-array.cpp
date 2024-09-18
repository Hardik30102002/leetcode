class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val=nums[0];
        int index=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val)    continue;
            else{
                nums[index++]=nums[i];
                val=nums[i];
            }
        }
        return index;
    }
};