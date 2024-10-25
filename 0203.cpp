#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution 
{
public:
    // 自己的版本
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head == NULL)
            return NULL;
        ListNode* p = head;
        while (p != NULL)
        {
            if (p->val == val)
                p = p->next;
            else
                break;
        }
        head = p;
        if (p == NULL)
            return head;
        ListNode* pre = p;
        p = p->next;
        while (p != NULL)
        {
            if (p->val == val)
            {
                pre->next = p->next;
                p = p->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
    // 书上法一 没有头指针
    ListNode* removeElements(ListNode* head, int val)
    {
        // 删除头结点
        while (head != NULL && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        //删除其他结点
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        return head;
    }
    // 头指针
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummyHead = new ListNode(0);  //虚拟头指针
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};