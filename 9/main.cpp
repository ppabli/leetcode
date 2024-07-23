class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0) {
			return false;
		}

		long y = 0;
		long z = x;

		while (x) {
			y = y * 10 + x % 10;
			x /= 10;
		}

		return y == z;

	}
};