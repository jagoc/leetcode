/*
 * @Author: jago 
 * @Date: 2020-07-20 15:15:30 
 * @Last Modified by: jago
 * @Last Modified time: 2020-07-21 15:49:47
 */

// Question 1: Two Sum. Easy
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// 暴力法：n^2
// 使用另一个数组下标对应原数组每个元素值，search速度为O(1)，但不支持负数元素；
// 直接使用hashmap

// Testcase
// 没有考虑到同一元素使用2次；相同元素出现2次情况
// 正常 [1, 3, 5, 7] 4; 
// 临界 [1, 3] 4; [2, 1, 3] 4; [2, 2] 4;
// 异常 [1, 3, 4] 5;

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    for (int idx = 0; idx != nums.size(); ++idx)
    {
        // 相同key，insert会失败
        // numMap.insert({nums[idx], idx});
        // 相同key，[]会覆盖
        numMap[nums[idx]] = idx;
    }

    vector<int> indices;
    for (int idx = 0; idx != nums.size(); ++idx)
    {
        int anotherNum = target - nums[idx];
        auto iter = numMap.find(anotherNum);
        if (iter != numMap.end())
        {
            if (idx == iter->second)
            {
                continue;
            }
            indices.push_back(idx);
            indices.push_back(iter->second);
            return indices;
        }
    }
    return indices;
}

int main()
{
    // Test
    vector<int> nums = {2, 2};
    vector<int> indices = twoSum(nums, 4);
    for (const auto idx : indices)
    {
        std::cout << idx << " ";
    }
}

