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
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
    bool LL_check_insert(int i);
    bool LL_check(int i);
    int LL_size();
    int double_LL_merge(LinkList* La, LinkList* Lb);
    ListNode* LL_find(int i);
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
    if (x == 0) return NULL;
    ListNode* p = head;
    while (x-- && p->next != NULL) p = p->next;
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
int LinkList::LL_get(int x) {
    ListNode* p = head;
    while (x--) p = p->next;
    return p->data;
}
int LinkList::LL_del(int x) {
    ListNode* p = head;
    x--;
    while (x--) p = p->next;
    p->next->next->prev = p;
    p->next = p->next->next;
    len--;
    return len;
}
int LinkList::LL_insert(int x, int item) {
    ListNode* p = head;
    x--;
    while (x--) p = p->next;
    ListNode* t = NULL;
    if (len > 0) t = p;
    ListNode* q = new ListNode(item, t, p->next);
    p->next = q;
    if (p->next->next != NULL) p->next->next->prev = q;
    len++;
    return len;
}
bool LinkList::LL_check_insert(int x) { return len + 1 >= x && x > 0; }
bool LinkList::LL_check(int x) { return len >= x && x > 0; }
int LinkList::LL_size() { return len; }
// int LL_merge(ListNode* &La, ListNode* &Lb) {
//     int res;
//     if (La == NULL) {
//         res = Lb->data; Lb = Lb->next;
//         return res;
//     }
//     if (Lb == NULL) {
//         res = La->data; La = La->next;
//         return res;
//     }
//     if (La->data <= Lb->data) {
//         res = La->data; La = La->next;
//         return res;
//     }
//     res = Lb->data; Lb = Lb->next;
//     return res;
// }
// int LinkList::double_LL_merge(LinkList *La, LinkList *Lb) {
//     ListNode *p, *q;
//     p = La->head->next; q = Lb->head->next;
//     ListNode *r = head;
//     while (1) {
//         if (p == NULL && q == NULL) break;
//         r->next = new ListNode(LL_merge(p, q), NULL); r = r->next;
//         len++;
//     }
//     return len;
// }

int main() {
    int n, m, x; cin >> n >> m;
    LinkList ll;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ll.LL_insert(i, x);
    }
    ListNode* p;
    while (m--) {
        cin >> x;
        p = ll.LL_find(x);
        if (p != NULL && p->prev != NULL && p->next != NULL) cout << p->prev->data << " " << p->next->data;
        if (p != NULL && p->prev == NULL && p->next != NULL) cout << p->next->data;
        if (p != NULL && p->prev != NULL && p->next == NULL) cout << p->prev->data;
        cout << "\n";
    }

    return 0;
}