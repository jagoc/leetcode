/*
 * @Author: jago 
 * @Date: 2020-07-20 17:44:15 
 * @Last Modified by: jago
 * @Last Modified time: 2020-07-21 14:33:39
 */

// Question 2: Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// 直接一次遍历2个链表，相加即可；注意进位

// Testcase
// 正常 [23, 52]
// 临界 [69, 38], [69, 238], [69, 938], [234, 0]


#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* pHead = NULL;
    ListNode* pNode, *pCur;
    int flag = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int val = l1->val + l2->val + flag;
        pNode = new ListNode(val % 10);
        flag = val / 10;
        if (pHead == NULL)
        {
            pHead = pNode;
            pCur = pNode;
        }
        else
        {
            pCur->next = pNode;
            pCur = pNode;
        }
        
        l1 = l1->next;
        l2 = l2->next;

    }

    ListNode* pRemain = l1;
    if (l2 != NULL)
    {
        pRemain = l2;
    }

    // 多余位数
    while (pRemain != NULL)
    {
        int val = pRemain->val + flag;
        pNode = new ListNode(val % 10);
        flag = val / 10;
        pCur->next = pNode;
        pCur = pNode;
        pRemain = pRemain->next;
    }

    // 最后进位
    if (flag != 0)
    {
        pNode = new ListNode(flag);
        pCur->next = pNode;
    }
    return pHead;
}

// 头指针、当前指针、创建节点指针
ListNode* createListNode(int arr[], int length)
{
    ListNode *headNode = NULL;
    ListNode *currNode, *pNode;
    for (int idx = 0; idx < length; ++idx)
    {
        pNode = new ListNode(arr[idx]);
        if (headNode == NULL)
        {
            headNode = pNode;
            currNode = pNode;
            continue;
        }
        currNode->next = pNode;
        currNode = pNode;
    }
    return headNode;
}

// 头指针、当前指针
ListNode* createList(int arr[], int length)
{
    ListNode* listNode = NULL;
    ListNode** curNode = &listNode;
    for (int idx = 0; idx < length; ++idx)
    {
        *curNode = new ListNode(arr[idx]);
        curNode = &((*curNode)->next);
    }
    return listNode;
}


void printListNode(ListNode* headNode)
{
    while (headNode != NULL)
    {
        std::cout << headNode->val << std::endl;
        headNode = headNode->next;
    }
    return;
}

int main()
{
    int arr1[3] = {2, 5, 7};
    int arr2[1] = {0};
    ListNode *listNode1 = createList(arr1, sizeof(arr1) / sizeof(int));
    printListNode(listNode1);

    ListNode *listNode2 = createList(arr2, sizeof(arr2) / sizeof(int));
    printListNode(listNode2);
    std::cout << std::endl;
    printListNode(addTwoNumbers(listNode1, listNode2));
}
