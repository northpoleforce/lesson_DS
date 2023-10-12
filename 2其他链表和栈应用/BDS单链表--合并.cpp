#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode() { next = NULL; }
    ListNode(int x, ListNode* nx) : data(x), next(nx) {}
};
// 带头结点的单链表类定义
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
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
    bool LL_check_insert(int i);
    bool LL_check(int i);
    int LL_size();
    int double_LL_merge(LinkList* La, LinkList* Lb);
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
    ListNode* p = head;
    while (x-- && p != NULL) p = p->next;
    return p;
}
int LinkList::LL_get(int x) {
    ListNode* p = head;
    while (x--) p = p->next;
    return p->data;
}
int LinkList::LL_del(int x) {
    ListNode* p = head;
    x--;
    while (x--) p = p->next;
    p->next = p->next->next;
    len--;
    return len;
}
int LinkList::LL_insert(int x, int item) {
    ListNode* p = head;
    x--;
    while (x--) p = p->next;
    ListNode* q = new ListNode(item, p->next);
    p->next = q;
    len++;
    return len;
}
bool LinkList::LL_check_insert(int x) { return len + 1 >= x && x > 0; }
bool LinkList::LL_check(int x) { return len >= x && x > 0; }
int LinkList::LL_size() { return len; }
int LL_merge(ListNode*& La, ListNode*& Lb) {
    int res;
    if (La == NULL) {
        res = Lb->data; Lb = Lb->next;
        return res;
    }
    if (Lb == NULL) {
        res = La->data; La = La->next;
        return res;
    }
    if (La->data <= Lb->data) {
        res = La->data; La = La->next;
        return res;
    }
    res = Lb->data; Lb = Lb->next;
    return res;
}
int LinkList::double_LL_merge(LinkList* La, LinkList* Lb) {
    ListNode* p, * q;
    p = La->head->next; q = Lb->head->next;
    ListNode* r = head;
    // bool first = 1;
    while (1) {
        if (p == NULL && q == NULL) break;
        r->next = new ListNode(LL_merge(p, q), NULL); r = r->next;
        // if (first) {
        //     first = 0;
        //     head->next = r;
        // }
        // else
        //     r->next
        len++;
    }
    return len;
}

int main() {
    int n, m, x;
    LinkList* la = new LinkList(), * lb = new LinkList();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        // la->LL_check_insert(i);
        la->LL_insert(i, x);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        lb->LL_insert(i, x);
    }
    LinkList lc;
    lc.double_LL_merge(la, lb);
    lc.LL_display();

    return 0;
}