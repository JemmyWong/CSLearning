/* Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.

Relatives:
303. Range Sum Query Immutable
307. Range Sum Query Mutable
304. Range Sum Query 2D Immutable */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/* Solution
 *
 * The sum of all the elements starting from position 0 to position i is stored in
 * sums[i]. This way we can reconstruct the sum from position i to position j by
 * subtracting sums[i - 1] from sums[j], leaving us with the sum of the desired elements.
 *
 * Note: we can add a dummy sum at then beginning to simplify the code */
class NumArray {
public:
    NumArray(vector<int>& nums) : sums(nums.size()+1, 0) {
        for (int i = 0; i < nums.size(); ++i) {
            sums[i+1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }

private:
    vector<long long> sums;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);