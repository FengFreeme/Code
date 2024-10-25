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
    //初始化链表
    MyLinkedList() 
    {
        dummyNode = new LinkNode(0);
        size = 0;
    }

    // index从0开始
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
        //delete命令指示释放了p指针原本所指的那部分内存，
        //被delete后的指针p的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句p=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了p，会指向难以预想的内存空间
        p = nullptr;
        size--;
    }
    // 打印链表
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
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList.get(1);              // 返回 3
    myLinkedList.printLinkedList();

    return 0;
}