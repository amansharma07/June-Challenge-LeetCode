class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1, mid = 0;
        while(mid<=h)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[l++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[h--], nums[mid]);
                    break;
            }
        }
    }
};