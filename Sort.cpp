#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& nums, int n)
{
	for (int i = 0; i < n; i++)
	{
		//当nums[j] >= nums[j-1]便完成了插入
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--)
			swap(nums[j], nums[j - 1]);
	}
}

//冒泡排序和快速排序都属于交换排序
void BubbleSort(vector<int>& nums, int n)
{
    bool swapped;
    for (int i = 1; i < n; i++)
    {
        swapped = false;
        for (int j = 1; j < n - i + 1; j++)
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)		//本次遍历后没有发生交换，说明表已经有序
            break;
    }
}

int main()
{
	vector<int> nums = { 9, 5, 1, 3, 2, 4, 8 };
	int n = 7;
	//InsertionSort(nums, n);
    BubbleSort(nums, n);

	return 0;
}