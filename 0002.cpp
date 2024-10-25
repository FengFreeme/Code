#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL, * tail = NULL;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;  //若l1为空则填补0
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
                head = tail = new ListNode(sum % 10);
            else
            {
                //头插法
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
    ListNode* l1 = new ListNode, * l2 = new ListNode;
    vector<int> num1 = { 2, 4, 3 };
    vector<int> num2 = { 5, 6, 4 };
    ListNode* templ1 = l1;
    templ1->next = NULL;
    templ1->val = num1[0];
    for (int i = 1; i < 3; i++)
    {
        ListNode* node = new ListNode;
        node->next = NULL;
        templ1->next = node;
        templ1 = node;
        templ1->val = num1[i];
    }
    ListNode* templ2 = l2;
    templ2->next = NULL;
    templ2->val = num2[0];
    for (int i = 1; i < 3; i++)
    {
        ListNode* node = new ListNode;
        node->next = NULL;
        templ2->next = node;
        templ2 = node;
        templ2->val = num2[i];
    }
    Solution S;
    ListNode* ans = S.addTwoNumbers(l1, l2);

    return 0;
}