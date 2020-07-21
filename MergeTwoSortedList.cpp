/*
 * @Author: jago 
 * @Date: 2020-07-21 15:08:28 
 * @Last Modified by: jago
 * @Last Modified time: 2020-07-21 15:52:15
 */

// Question 21: Merge Two Sorted Lists. Easy
// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

// 双指针遍历法
// 递归法

// Testcase
// 正常：135, 246
// 临界：123, 123; 123, 1;

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双指针
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }

    ListNode *pHead = nullptr;
    ListNode *pCur = pHead;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            if (pHead == nullptr)
            {
                pHead = l1;
            }
            else 
            {
                pCur->next = l1;
            }
            pCur = l1;
            l1 = l1->next;
        }
        else
        {
            if (pHead == nullptr)
            {
                pHead = l2;
            }
            else
            {
                pCur->next = l2;
            }
            pCur = l2;
            l2 = l2->next;
        }
    }

    if (l1 != nullptr)
    {
        pCur->next = l1;
    }

    if (l2 != nullptr)
    {
        pCur->next = l2;
    }
    return pHead;
}


// 递归法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }

    ListNode* pHead;
    if (l1->val <= l2->val)
    {
        pHead = l1;
        l1 = l1->next;
    }
    else
    {
        pHead = l2;
        l2 = l2->next;
    }
    pHead->next = mergeTwoLists(l1, l2);
    return pHead;
}