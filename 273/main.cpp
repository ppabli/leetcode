#include <iostream>

using namespace std;

class Solution {
public:
	string helper(int num) {

		string digits[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
		string digits10[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string digits10b10[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

		string result = "";

		if (num > 99) {
			result += digits[num / 100 - 1] + " Hundred ";
		}

		num %= 100;

		if (num > 19) {
			result += digits10b10[num / 10] + " ";
			num %= 10;
		}

		if (num > 9) {

			result += digits10[num - 10] + " ";

		} else if (num > 0) {

			result += digits[num - 1] + " ";

		}

		return result;

	}

	string numberToWords(int num) {

		if (num == 0) {
			return "Zero";
		}

		// Limit to 2^31 - 1
		string bigUnits[] = { "Thousand", "Million", "Billion" };

		string result = helper(num % 1000);

		num /= 1000;

		for (int i = 0; i < bigUnits->size(); i++) {

			if (num == 0) {
				break;
			}

			if (num % 1000 > 0) {
				result = helper(num % 1000) + bigUnits[i] + " " + result;
			}

			num /= 1000;

		}

		while (result.back() == ' ') {
			result.pop_back();
		}

		return result;

	}

};