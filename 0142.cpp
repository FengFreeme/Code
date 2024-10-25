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
    ListNode* detectCycle1(ListNode* head) 
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode* slow = head, * fast = head;
        // 求相遇位置
        while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        // 此时slow和fast相遇点
        if (slow != fast)
            return NULL;
        slow = head;
        // 求环形入口
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = head;
        ListNode* slow = DummyHead, * fast = DummyHead;
        if (slow->next != NULL)
            slow = slow->next;
        else
            return NULL;
        if (fast->next->next != NULL)
            fast = fast->next->next;
        else
            return NULL;
        // 相对于slow来说，fast是一个节点一个节点的靠近slow的
        // 所以fast一定可以和slow重合
        while (slow != fast && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow != NULL && slow != fast)
            return NULL;
        slow = DummyHead;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* p = new ListNode(2);
    head->next = p;
    ListNode* q = p;
    p = new ListNode(0);
    head->next->next = p;
    p = new ListNode(-4);
    head->next->next->next = p;
    p->next = q;
    Solution S;
    S.detectCycle(head);

    return 0;
}