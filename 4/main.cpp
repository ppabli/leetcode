#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		vector<int> nums;

		nums.insert(nums.end(), nums1.begin(), nums1.end());
		nums.insert(nums.end(), nums2.begin(), nums2.end());

		sort(nums.begin(), nums.end());

		int n = nums.size();

		if (n % 2 == 0) {

			int mid = n / 2;
			return (nums[mid - 1] + nums[mid]) / 2.0;

		} else {

			return nums[n / 2];

		}

	}
};