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
    ListNode* removeNthFromEnd1(ListNode* head, int n) 
    {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        int num = 0;
        ListNode* p = dummyNode->next;
        while (p != NULL)
        {
            num++;
            p = p->next;
        }
        int index = num - n + 1;
        p = dummyNode->next;
        ListNode* pre = dummyNode;
        while (index - 1 > 0)
        {
            pre = p;
            p = p->next;
            index--;
        }
        pre->next = p->next;
        delete p;
        p = NULL;
        return dummyNode->next;
    }
    ListNode* removeNthFromEnd2(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (fast != NULL && n > 0)
        {
            fast = fast->next;
            n--;
        }
        fast = fast->next;
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* pre = slow;
        slow = slow->next;
        pre->next = slow->next;
        delete slow;
        slow = NULL;
        return dummyHead->next;
    }
    // 双指针
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 先用双指针判断要删除的结点的位置
        int dis = n;
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = head;
        ListNode* pre = DummyHead, * p = DummyHead->next, *q = DummyHead->next;
        while (q != NULL && dis > 1)
        {
            q = q->next;
            dis--;
        }
        while (q->next != NULL)
        {
            pre = pre->next;
            p = p->next;
            q = q->next;
        }
        pre->next = p->next;
        delete p;
        p = NULL;

        return DummyHead->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1);

    Solution S;
    S.removeNthFromEnd(head, 1);

    return 0;
}