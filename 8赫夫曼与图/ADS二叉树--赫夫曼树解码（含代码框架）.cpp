#include<iostream>
#include<string>
#include<cstring>

#define ok 1
#define error -1

using namespace std;

const int MaxW = 9999999;  // 假设结点权值不超过9999999
// 定义huffman树结点类
class HuffNode
{
public:
    char val;
    int weight;     // 权值
    int parent;     // 父结点下标
    int leftchild;  // 左孩子下标
    int rightchild; // 右孩子下标
};
// 定义赫夫曼树类
class HuffMan
{
private:
    void MakeTree();    // 建树，私有函数，被公有函数调用
    void SelectMin(int pos, int *s1, int*s2);  // 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中
public:
    int len;    // 结点数量
    int lnum;   // 叶子数量
    HuffNode *huffTree; // 赫夫曼树，用数组表示
    string *huffCode;   // 每个字符对应的赫夫曼编码
    void MakeTree(int n, int wt[], char str[]); // 公有函数，被主函数main调用
    void Coding();  // 公有函数，被主函数main调用
    int Decode(const string codestr, char txtstr[]); //输入编码串codestr，输出解码串txtstr
    void Destroy();
};
// 构建huffman树
void HuffMan::MakeTree(int n, int wt[], char str[])
{
    // 参数是叶子结点数量和叶子权值
    // 公有函数，对外接口
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1];    // 位置从 1 开始计算
    // huffCode实质是个二维字符数组，第 i 行表示第 i 个字符对应的编码
    // 赫夫曼树huffTree初始化
    for(i = 1; i <= n; i ++) {
        huffTree[i].weight = wt[i - 1]; // 第0号不用，从1开始编号
        huffTree[i].val = str[i-1];
    }
    for(i = 1; i <= len; i ++)
    {
        if(i > n) huffTree[i].weight = 0;  // 前n个结点是叶子，已经设置
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // 调用私有函数建树
}
void HuffMan::SelectMin(int pos, int *s1, int *s2)
{
    // 找出最小的两个权值的下标
    // 函数采用地址传递的方法，找出两个下标保存在 s1 和 s2 中
    int w1, w2, i;
    w1 = w2 = MaxW;  // 初始化w1和w2为最大值，在比较中会被实际的权值替换
    *s1 = *s2 = 0;
    for(i = 1; i <= pos; i ++)
    {
        // 比较过程如下：
        if (huffTree[i].weight < w1 && huffTree[i].parent == 0) {
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        } else if (huffTree[i].weight < w2 && huffTree[i].parent == 0) {
            w2 = huffTree[i].weight;
            *s2 = i;
        }
        // 如果第 i 个结点的权值小于 w1，且第 i 个结点是未选择的结点，提示：如果第 i 结点未选择，它父亲为 0
        // 把第 w1 和 s1 保存到 w2 和 s2，即原来的第一最小值变成第二最小值
        // 把第 i 结点的权值和下标保存到 w1 和 s1，作为第一最小值
        // 否则，如果第 i 结点的权值小于 w2，且第 i 结点是未选择的结点
        // 把第 i 结点的权值和下标保存到 w2 和 s2，作为第二最小值
    }
}
void HuffMan::MakeTree()
{
    // 私有函数，被公有函数调用
    int i, s1, s2;
    for(i = lnum + 1; i <= len; i ++)
    {
        SelectMin(i - 1, &s1, &s2);  // 找出两个最小权值的下标放入 s1 和 s2 中
        // 将找出的两棵权值最小的子树合并为一棵子树，过程包括
        huffTree[s1].parent = huffTree[s2].parent = i;
        // 结点 s1 和结点 s2 的父亲设为 i
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        // 结点 i 的左右孩子分别设为 s1 和 s2
        huffTree[i].weight = huffTree[s1].weight+huffTree[s2].weight;
        // 结点 i 的权值等于 s1 和 s2 的权值和
    }
}
// 销毁赫夫曼树
void HuffMan::Destroy()
{
    len  = 0;
    lnum = 0;
    delete []huffTree;
    delete []huffCode;
}
// 赫夫曼编码
void HuffMan::Coding()
{
    char *cd;
    int i, c, f, start;
    // 求 n 个结点的赫夫曼编码
    cd = new char[lnum];    // 分配求编码的工作空间
    cd[lnum - 1] = '\0';    // 编码结束符
    for(i = 1; i <= lnum; ++ i)
    {
        // 逐个字符求赫夫曼编码
        start = lnum - 1;   // 编码结束符位置
        c = i; f = huffTree[i].parent;
        while (f != 0) {
            if (huffTree[f].leftchild == c)
                cd[--start] = '0';
            if (huffTree[f].rightchild == c)
                cd[--start] = '1';
            c = f;
            f = huffTree[f].parent;
        }
        // 参考课本P147算法6.12 HuffmanCoding代码
        huffCode[i].assign(&cd[start]); // 把cd中从start到末尾的编码复制到huffCode中
    }
    delete []cd;    // 释放工作空间
}
int HuffMan::Decode(const string codestr, char txtstr[])
{
    // 编码串是codestr，解码结果放在 txtstr 中
    // 编码 0 表示往左孩子移动，编码 1 表示往右孩子移动
    int i, k, c;
    char ch;
    c = len; // c表示结点数组下标
    // 根结点是结点数组的最后一个结点，所以 c 一开始指向根节点
    k = 0;  // txtstr的指针
    for(i = 0; i < codestr.length(); i ++)
    {
        // 解码流程如下：
        // 取编码串的第 i 个字符放入变量ch
        ch = codestr[i];
        // 如果 ch 是字符 0 ，表示往左孩子移动，则 c 跳转到左孩子
        // 如果 ch 是字符 1 ，表示往右孩子移动，则 c 跳转到右孩子
        // 如果 ch 非 0 非 1 ，表示编码串有错误，返回 error 表示解码失败
        if (ch == '0')
            c = huffTree[c].leftchild;
        else if (ch == '1')
            c = huffTree[c].rightchild;
        else
            return error;
        // 如果 c 指向的结点是叶子
        if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0) {
            txtstr[k] = huffTree[c].val;
            k++;
            c = len;
        } else
            ch = '\0';
            // 解码串 txtstr 的第 k 位置保存结点 c 内的字符
            // k ++
            // c 跳回根节点
        // 否则
            // ch = '\0';   // 设置 ch 值是用于检查不完整编码的报错
    }
    if(ch == '\0') return error;
    else txtstr[k] = '\0';  // 解码成功，加入字符串结束符
    return ok;
}
// 主函数
int main()
{
    int t, n, i, j;
    int wt[800];
    char str[800];
    HuffMan myHuff;
    cin >> t;
    for(i = 0; i < t; i ++)
    {
        cin >> n;
        for (j = 0; j < n; ++j) cin >> wt[j];
        for (j = 0; j < n; ++j) cin >> str[j];
        myHuff.MakeTree(n, wt, str);
        myHuff.Coding();
        int k; cin >> k;
        string code;
        while (k--) {
            cin >> code;
            char *ans = new char[800];
            if (myHuff.Decode(code, ans) == -1)
                cout << "error\n";
            else
                cout << ans << "\n";
        }
        myHuff.Destroy();
    }
    return 0;
}