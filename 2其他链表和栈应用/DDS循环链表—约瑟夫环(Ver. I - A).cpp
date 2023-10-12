#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
    int data;
    ListNode* next, * prev;
    ListNode() { next = NULL; prev = NULL; }
    ListNode(int x, ListNode* pr, ListNode* nx) : data(x), prev(pr), next(nx) {}
};
class LinkList
{
public:
    ListNode* head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();
    ListNode* LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
    int LL_get(int i);              // 获取第i个元素的数据
    int LL_insert(int i, int item); // 把数值item插入第i个位置
    int LL_del(ListNode* p);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
    bool LL_check_insert(int i);
    bool LL_check(int i);
    int LL_size();
    int double_LL_merge(LinkList* La, LinkList* Lb);
    ListNode* LL_find(int i);
    ListNode* LL_search(ListNode* p, int i);
};

LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()
{
    ListNode* p, * q;
    p = head;
    while (p != NULL)
    {
        q = p;
        if (p->prev != NULL) p->prev->next = NULL;
        if (p->next != NULL) p->next->prev = NULL;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}
void LinkList::LL_display()
{
    ListNode* p;
    p = head->next;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

ListNode* LinkList::LL_index(int x) {
    if (x == 0) return NULL;
    ListNode* p = head;
    while (x-- && p->next != NULL) {
        p = p->next;
        if (p == head) p = p->next;
    }
    return p;
}
ListNode* LinkList::LL_find(int x) {
    ListNode* p = head->next;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->next;
    }
    return p;
}
ListNode* LinkList::LL_search(ListNode* p, int x) {
    if (p == head) p = p->next;
    while (--x) {
        //  cout << "|" << p->data << "|" << p->next->data << "|\n";
        p = p->next;
        if (p == head) p = p->next;
    }
    if (p == head) p = p->next;
    return p;
}
int LinkList::LL_get(int x) {
    ListNode* p = head;
    while (x--) p = p->next;
    return p->data;
}
int LinkList::LL_del(ListNode* p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    len--;
    return len;
}
int LinkList::LL_insert(int x, int item) {
    ListNode* p = head;
    for (int i = 1; i < x; ++i) p = p->next;
    ListNode* r = p->next;
    if (x == len + 1) r = head;
    ListNode* q = new ListNode(item, p, r);
    p->next = q;
    if (q->next != NULL) q->next->prev = q;
    len++;
    return len;
}
bool LinkList::LL_check_insert(int x) { return len + 1 >= x && x > 0; }
bool LinkList::LL_check(int x) { return len >= x && x > 0; }
int LinkList::LL_size() { return len; }

int main() {
    int t, n, k, s; cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        LinkList ll;
        //cout << "<<<<<<<<\n";
        for (int i = 1; i <= n; ++i) ll.LL_insert(i, i);
        //cout << "===============\n";
        //cout << ll.LL_index(n)->next->data << "???\n";
        ListNode* p = ll.LL_index(s);
        for (int i = 1; i < n; ++i) {
            p = ll.LL_search(p, k);
            //if (i == 1)
                cout << p->data << " ";
            //else
              //  cout << " " << p->data;
            // cout << "=1=="; ll.LL_display();
            ListNode* t = p->next;
            ll.LL_del(p);
            p = t;
            // cout << "=2==";  ll.LL_display();
            // cout << p << " " << p->data << "\n";
        }
        p = ll.LL_search(p, 1);
        cout << p->data << " \n";
        //cout << "!!!!\n";
    }

    return 0;
}