/*
 * @Author: jago 
 * @Date: 2020-07-21 15:48:22 
 * @Last Modified by: jago
 * @Last Modified time: 2020-07-21 16:08:42
 */

// Question 35: Search Insert Position. Easy
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.

// 二分法

// Testcase
// 正常：[1, 2, 3] 2; [1, 3] 2;
// 临界：[1, 2] 3; [] 3; [1, 2] 0;

#include <iostream>
#include <vector>


int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0)
    {
        return 0;
    }

    int iStart = 0, iEnd = nums.size() - 1;
    while (iStart <= iEnd)
    {
        int iMiddle = (iStart + iEnd) >> 1;
        if (nums[iMiddle] == target)
            return iMiddle;
        else if (nums[iMiddle] < target)
            iStart = iMiddle + 1;
        else 
            iEnd = iMiddle - 1;
    }

    return iStart;

}