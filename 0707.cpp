#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList 
{
public:
    struct LinkNode
    {
        int val;
        LinkNode* next;
        LinkNode(int val) :val(val), next(NULL) {}
    };
    //��ʼ������
    MyLinkedList() 
    {
        dummyNode = new LinkNode(0);
        size = 0;
    }

    // index��0��ʼ
    int get(int index) 
    {
        if (index >= size || index < 0)
            return -1;
        int i = 0;
        LinkNode* p = dummyNode->next;

        while (p != NULL)
        {
            if (i == index)
                return p->val;
            p = p->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) 
    {
        LinkNode* p = new LinkNode(val);
        p->next = dummyNode->next;
        dummyNode->next = p;
        size++;
    }

    void addAtTail(int val) 
    {
        LinkNode* p = dummyNode;
        while (p->next != NULL)
        {
            p = p->next;
        }
        LinkNode* q = new LinkNode(val);
        p->next = q;
        q->next = NULL;
        size++;
    }

    void addAtIndex(int index, int val) 
    {
        if (index > size)
            return;
        if (index < 0)
            index = 0;
        LinkNode* pre = dummyNode;
        LinkNode* p = dummyNode->next;
        while (index > 0)
        {
            pre = p;
            p = p->next;
            index--;
        }
        LinkNode* q = new LinkNode(val);
        q->next = pre->next;
        pre->next = q;
        size++;
    }

    void deleteAtIndex(int index) 
    {
        if (index < 0 || index >= size)
            return;
        LinkNode* pre = dummyNode;
        LinkNode* p = dummyNode->next;
        while (index > 0)
        {
            pre = p;
            p = p->next;
            index--;
        }
        pre->next = p->next;
        delete p;
        //delete����ָʾ�ͷ���pָ��ԭ����ָ���ǲ����ڴ棬
        //��delete���ָ��p��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
        //������ټ���һ��p=nullptr,tmp���Ϊ��ָ��Ұָ��
        //���֮��ĳ���С��ʹ����p����ָ������Ԥ����ڴ�ռ�
        p = nullptr;
        size--;
    }
    // ��ӡ����
    void printLinkedList() 
    {
        LinkNode* p = dummyNode;
        while (p->next != NULL) {
            cout << p->next->val << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    LinkNode* dummyNode;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // �����Ϊ 1->2->3
    myLinkedList.get(1);              // ���� 2
    myLinkedList.deleteAtIndex(1);    // ���ڣ������Ϊ 1->3
    myLinkedList.get(1);              // ���� 3
    myLinkedList.printLinkedList();

    return 0;
}