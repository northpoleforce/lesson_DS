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
    ListNode(int x, ListNode* nx): data(x), next(nx) {}
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
bool LinkList::LL_check_insert(int x) { return len + 1 >= x && x >0; }
bool LinkList::LL_check(int x) { return len >= x && x > 0; }
int LinkList::LL_size() { return len; }

int main() {
    int n; cin >> n;
    int x;
    LinkList LL;
    while (n--) {
        cin >> x;
        LL.LL_insert(LL.LL_size() + 1, x);
    }
    LL.LL_display();
    int pos;
    for (int i = 0; i < 2; ++i) {
        cin >> pos >> x;
        if (LL.LL_check_insert(pos))
            LL.LL_insert(pos, x), LL.LL_display();
        else
            cout << "error\n";
    }
    for (int i = 0; i < 2; ++i) {
        cin >> pos;
        if (LL.LL_check(pos))
            LL.LL_del(pos), LL.LL_display();
        else
            cout << "error\n";
    }
    for (int i = 0; i < 2; ++i) {
        cin >> pos;
        if (LL.LL_check(pos))
            cout << LL.LL_get(pos) << "\n";
        else
            cout << "error\n";
    }

    return 0;
}