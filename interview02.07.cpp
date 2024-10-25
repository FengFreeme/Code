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
    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) 
    {
        ListNode* dummyHeadA = new ListNode();
        dummyHeadA->next = headA;
        ListNode* dummyHeadB = new ListNode();
        dummyHeadB->next = headB;
        ListNode* pA = dummyHeadA->next;
        int m = 0;
        while (pA != NULL)
        {
            m++;
            pA = pA->next;
        }
        ListNode* pB = dummyHeadB->next;
        int n = 0;
        while (pB != NULL)
        {
            n++;
            pB = pB->next;
        }
        pA = dummyHeadA->next;
        pB = dummyHeadB->next;
        if (m > n)
        {
            int ins = m - n;
            while (ins > 0)
            {
                pA = pA->next;
                ins--;
            }
        }
        else if (m < n)
        {
            int ins = n - m;
            while (ins > 0)
            {
                pB = pB->next;
                ins--;
            }
        }
        while (pA != NULL)
        {
            if (pA == pB)
                return pA;
            else
            {
                pA = pA->next;
                pB = pB->next;
            }
        }
        return NULL;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int len1 = 0, len2 = 0;
        ListNode* DummyHead1 = new ListNode(0);
        ListNode* DummyHead2 = new ListNode(0);
        DummyHead1->next = headA;
        DummyHead2->next = headB;
        ListNode* p = DummyHead1;
        while (p->next != NULL)
        {
            p = p->next;
            len1++;
        }
        p = DummyHead2;
        while (p->next != NULL)
        {
            p = p->next;
            len2++;
        }
        ListNode* p1 = DummyHead1;
        ListNode* p2 = DummyHead2;
        int dis = len1 - len2;
        if (dis >= 0)
        {
            while (dis > 0)
            {
                p1 = p1->next;
                dis--;
            }
        }
        else
        {
            dis = -dis;
            while (dis > 0)
            {
                p2 = p2->next;
                dis--;
            }
        }
        while (p1 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == NULL)
            return NULL;
        else
            return p1;
    }
};

int main()
{
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(1);
    ListNode* p = new ListNode(2);
    headB->next = p;
    p = new ListNode(3);
    headA->next = p;
    headB->next->next = p;
    Solution S;
    S.getIntersectionNode(headA, headB);

    return 0;
}