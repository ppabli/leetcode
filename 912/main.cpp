#include <vector>

using namespace std;

class Solution {

	void quick_sort(vector<int>& nums, int left, int right){

		if(left >= right) {
			return;
		}

		int pivot = nums[rand() % (right - left + 1) + left];

		int i = left - 1;
		int j = right + 1;

		while(i < j) {

			while(nums[++i] < pivot);
			while(nums[--j] > pivot);
	
			if(i < j) {
				swap(nums[i], nums[j]);
			}

		}

		quick_sort(nums, left, j);
		quick_sort(nums, j + 1, right);

	}
public:
	vector<int> sortArray(vector<int>& nums) {
		quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}
};