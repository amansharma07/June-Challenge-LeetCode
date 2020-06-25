#define ll long long
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[nums[0]];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        if(slow==0)
            return -1;
        return slow;  
    }
};
