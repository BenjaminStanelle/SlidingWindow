/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 Input: nums = [1], k = 1
Output: [1]*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
	//inputs
	int K = 3;	//window size
	int nums[] = { 1, 3, -1, -3, 5, 3, 6, 7 };

	int nums_size = sizeof(nums) / sizeof(nums[0]);
	int L = 0, R = 0, i, j;
	deque<int> dq;
	vector<int> result;
	result.reserve(nums_size - K + 1);

	//go through input array
	while (R < nums_size) {
		//while deque not empty and dq.front <
		while ((dq.size() != 0) && nums[dq.front()] < nums[R]) {
			dq.pop_front();
		}
		dq.push_back(R);

		if (L > dq.front()) {
			dq.pop_front();
		}

		if (R + 1 >= K) {
			result.emplace_back(nums[dq.front()]);
			L++;
		}

		R++;
	}
	

	for (i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}
