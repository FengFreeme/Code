#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int Partition(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= pivot)
                high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;

        return low;
    }
    
    int findKthLargest(vector<int>& nums, int k) 
    {
        int low = 0, high = nums.size() - 1, target = nums.size() - k;
        while (low < high)
        {
            int pivotpos = Partition(nums, low, high);
            if (pivotpos == target)
                return nums[pivotpos];
            //mid位置是已经固定的了，并且mid右边的元素都比mid的元素大，右边都比mid的元素小
            if (pivotpos < target)
                low = pivotpos + 1;
            else
                high = pivotpos - 1;
        }
        return nums[low];
    }
};

int main()
{
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;

    Solution S;
    S.findKthLargest(nums, k);

    return 0;
}