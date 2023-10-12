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
    /*if (i > size || i <= 0)
    {
        cout << "error\n";
        return -1;
    }
    cout << list[i - 1] << "\n";
    return 1;*/
    return list[i - 1];
}
void SeqList::list_display()
{
    cout << list_size() << " ";
    /*cout << list[0];*/
    for (int i = 0; i < size; ++i)
        cout << list[i] << " ";
    cout << "\n";
}

void print(int x)
{
    if (x < 0)
        cout << "(" << x << ")";
    else
        cout << x;
}
void display(SeqList& cc, SeqList& ii)
{
    if (ii.list_get(1) == 0)
        print(cc.list_get(1));
    else
    {
        print(cc.list_get(1));
        cout << "x^";
        print(ii.list_get(1));
    }
    for (int i = 2; i <= cc.list_size(); ++i)
    {
        cout << " + ";
        if (ii.list_get(i) == 0)
            print(cc.list_get(i));
        else
        {
            print(cc.list_get(i));
            cout << "x^";
            print(ii.list_get(i));
        }
    }
    cout << "\n";
}

SeqList c_c, c_i;
void _insert(int ii, int cc)
{
    for (int i = 1; i <= c_i.list_size(); ++i)
        if (c_i.list_get(i) == ii)
        {
            int x = c_c.list_get(i);
            c_c.list_del(i);
            c_c.list_insert(i, x + cc);
            return;
        }
    c_i.list_insert(c_i.list_size() + 1, ii);
    c_c.list_insert(c_c.list_size() + 1, cc);
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        SeqList a_c, a_i;
        int n, m, a, b;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            if (a == 0) continue;
            a_c.list_insert(a_c.list_size() + 1, a);
            a_i.list_insert(a_i.list_size() + 1, b);
        }
        display(a_c, a_i);
        SeqList b_c, b_i;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            if (a == 0) continue;
            b_c.list_insert(b_c.list_size() + 1, a);
            b_i.list_insert(b_i.list_size() + 1, b);
        }
        display(b_c, b_i);


        for (int i = 1, j = 1; i <= a_i.list_size() || j <= b_i.list_size(); )
        {
            if (i <= a_i.list_size() && a_i.list_get(i) <= b_i.list_get(j))
            {
                _insert(a_i.list_get(i), a_c.list_get(i));
                i++;
            }
            else
            {
                _insert(b_i.list_get(j), b_c.list_get(j));
                j++;
            }
            /*display(c_c, c_i);*/
        }
        for (int i = 1; i <= c_i.list_size();)
            if (c_c.list_get(i) == 0) {
                c_c.list_del(i);
                c_i.list_del(i);
            }
            else
                i++;
        display(c_c, c_i);
        /*for (int i = 1; i <= c_i.list_size(); ++i)*/
        while (c_i.list_size() > 0)
        {
            c_c.list_del(1);
            c_i.list_del(1);
        }
    }

    return 0;
}