#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution 
{
public:
    ListNode* reverseList1(ListNode* head) 
    {
        ListNode* dummyNode = new ListNode();
        ListNode* p = head;
        while (p != NULL)
        {
            ListNode* q = p->next;
            p->next = dummyNode->next;
            dummyNode->next = p;
            p = p->next;
            p = q;
        }
        return dummyNode->next;
    }
    // ͷ�巨
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL)
            return head;
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = NULL;
        ListNode* p = DummyHead, * q = head;
        while (q != NULL)
        {
            ListNode* temp = q;
            q = q->next;
            temp->next = p->next;
            p->next = temp;
        }
        return DummyHead->next;
    }
};