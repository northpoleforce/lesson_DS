#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 顺序表类定义
class SeqList
{
private:
    int* list;      // 元素数组
    int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度
public:
    SeqList();                          // 构造函数
    ~SeqList();                         // 析构函数
    int list_size();                    // 获取顺序表实际长度
    int list_insert(int i, int item);   // 插入一个元素，参数是插入的数值和位置
    int list_del(int i);                // 删除一个元素，参数是删除的位置
    int list_get(int i);                // 获取一个元素，参数是获取的位置
    void list_display();                // 输出整个顺序表
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::~SeqList()
{
    delete[]list;
}

int SeqList::list_size() { return size; }
int SeqList::list_insert(int i, int item)
{
    /*if (size >= maxsize || i > size+1 || i <= 0)
    {
        cout << "error\n";
        return 0;
    }*/
    for (int j = size; j >= i; --j)
        list[j] = list[j - 1];
    size++;
    list[i - 1] = item;
    return 1;
}
int SeqList::list_del(int i)
{
    /*if (i > size || i <= 0)
    {
        cout << "error\n";
        return 0;
    }*/
    for (int j = i - 1; j < size; ++j)
        list[j] = list[j + 1];
    size--;
    return 1;
}
int SeqList::list_get(int i) 
{
    if (i > size || i <= 0)
    {
        cout << "error\n";
        return -1;
    }
    cout << list[i - 1] << "\n";
    return 1;
}
void SeqList::list_display()
{
    cout << list_size() << " ";
    for (int i = 0; i < size; ++i)
        cout << list[i] << " ";
    cout << "\n";
}

int main()
{
    int n; cin >> n;
    int a, b;
    SeqList sl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        sl.list_insert(sl.list_size()+1, a);
    }
    sl.list_display();

    cin >> a >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> b;
        sl.list_insert(a + i, b);
    }
    sl.list_display();
    cin >> a >> n;
    for (int i = 0; i < n; ++i)
        sl.list_del(a);
    sl.list_display();
    return 0;
}