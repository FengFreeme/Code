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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* p = dummyNode->next;
        if (p == NULL)
            return head;
        ListNode* q = p->next;
        ListNode* pre = dummyNode;
        if (q == NULL)
            return head;
        while (1)
        {
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
            //更新下一个要交换的结点
            pre = p;
            p = p->next;
            if (p == NULL)
            {
                ListNode* res = dummyNode->next;
                delete dummyNode;
                dummyNode = NULL;
                return res;
            }
            q = p->next;
            if (q == NULL)
            {
                ListNode* res = dummyNode->next;
                delete dummyNode;
                dummyNode = NULL;
                return res;
            }
                
        }
        ListNode* res = dummyNode->next;
        delete dummyNode;
        dummyNode = NULL;
        return res;
    }
};