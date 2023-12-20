// 参考：https://blog.csdn.net/qq_56999918/article/details/122759059

#include<stdio.h>
const int maxn = 1e5 + 10;

inline int max(int a, int b) { return a > b ? a:b; }
inline int abs(int x) { return x > 0 ? x:-x; }

struct Node
{
    int key;        // 关键值
    int data;       // 携带的数据
	int size;
    int left;       // 左子树地址（数组下标）
    int right;      // 右子树地址（数组下标）
    int height;     // 当前结点为根的子树高度
    void Init(){data = key = left = right = height = size = -1;}
    void Init(int k_, int d_=0){Init(); key = k_; data = d_;}
    Node(){Init();}
    Node(int k_, int d_=0){Init(k_, d_);}
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline void HeightDiff(int now)
{
    // 计算 tr[now] 结点的平衡因子
	tr[now].data = 
		(tr[now].left == -1 ? 0:tr[tr[now].left].height)
		-(tr[now].right == -1 ? 0:tr[tr[now].right].height);
}
inline void UpdateAll(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
    tr[now].height = max(
		(tr[now].left == -1 ? 0:tr[tr[now].left].height),
		(tr[now].right == -1 ? 0:tr[tr[now].right].height)
	)+1;
	tr[now].size =
		(tr[now].left == -1 ? 0:tr[tr[now].left].size)
		+ (tr[now].right == -1 ? 0:tr[tr[now].right].size)
		+ 1;
	HeightDiff(now);
}
int LL(int an)
{
	int rightNode = tr[an].right;
	tr[an].right = tr[rightNode].left;
	tr[rightNode].left = an;
	UpdateAll(an);
	UpdateAll(rightNode);
	return rightNode;
}
int RR(int an)
{
	int leftNode = tr[an].left;
	tr[an].left = tr[leftNode].right;
	tr[leftNode].right = an;
	UpdateAll(an);
	UpdateAll(leftNode);
	return leftNode;
}
int LR(int an)
{
	tr[an].left = LL(tr[an].left);
	return RR(an);
}
int RL(int an)
{
	tr[an].right = RR(tr[an].right);
	return LL(an);
}
inline void maintain(int &now) {
	if (abs(tr[now].data) <= 1) return;
	if (tr[now].data > 1) {
		int leftLeftHeight = (tr[now].left != -1 && tr[tr[now].left].left != -1 && tr[tr[tr[now].left].left].height != -1)
			? tr[tr[tr[now].left].left].height : 0;
		int leftRightHeight = (tr[now].left != -1 && tr[tr[now].left].right != -1 && tr[tr[tr[now].left].right].height != -1)
			? tr[tr[tr[now].left].right].height : 0;
		if (leftLeftHeight >= leftRightHeight)
			now = RR(now);
		else
			now = LR(now);
	} else {
		int rightLeftHeight = (tr[now].right != -1 && tr[tr[now].right].left != -1 && tr[tr[tr[now].right].left].height != -1)
			? tr[tr[tr[now].right].left].height : 0;
		int rightRightHeight = (tr[now].right != -1 && tr[tr[now].right].right != -1 && tr[tr[tr[now].right].right].height != -1)
			? tr[tr[tr[now].right].right].height : 0;
		if (rightRightHeight >= rightLeftHeight)
			now = LL(now);
		else
			now = RL(now);
	}
}
void Insert(int &now, int key, int data=0)
{
    if(now == -1)
    {
        // 传入指针为空，新建结点保存数据
        now = ++ tp;
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else if (key < tr[now].key)
		Insert(tr[now].left, key, data);
	else
		Insert(tr[now].right, key, data);
	UpdateAll(now);
	maintain(now);
}
int findKth (int now, int k) {
	if (now == -1) return -1;
	int lSize = (tr[now].left == -1) ? 0:tr[tr[now].left].size;
	if (k <= lSize) return findKth(tr[now].left, k);
	if (k == lSize+1) return tr[now].key;
	if (k > lSize) return findKth(tr[now].right, k-lSize-1);
}
int findBigger(int now) {
	if (now == -1) return -1;
	int res = findBigger(tr[now].left);
	if (res == -1) res = now;
	return res;
}
int Delete(int &now, int key)
{
    if(key < tr[now].key) tr[now].left = Delete(tr[now].left, key);
    else if(key > tr[now].key) tr[now].right = Delete(tr[now].right, key);
    else
    {
        // 删除当前结点
		int biggerPos = findBigger(tr[now].right);
		if (biggerPos == -1) {
			if (tr[now].left == -1) now = -1;
			else now = tr[now].left;
		}
		else {
			int _key = tr[biggerPos].key;
			tr[now].right = Delete(tr[now].right, tr[biggerPos].key);
			tr[now].key = _key;
		}
    }
    // 处理树平衡
	UpdateAll(now);
	maintain(now);
	return now;
}

int main()
{
    int n, op, key, data;
    while(scanf("%d", &n) != EOF)
    {
        root = tp = -1;
        while(n --)  // 初始化根结点和“内存指针”
        {
            scanf("%d", &op);
            if(op == 1)
            {
				scanf("%d", &key);
				Insert(root, key);
            }
            else if(op == 2)
            {
				scanf("%d", &data);
				int ans = findKth(root, data);
				printf("%d\n", ans);
				if (ans != -1) Delete(root, ans);
            }
		}
    }
    return 0;
}