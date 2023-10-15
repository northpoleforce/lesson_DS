#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
    void output();
    int get_size() { return size; }
};
myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    int v = -1;
    v = KMPFind(p, pos, next);
    delete []next;
    // cout << "v:" << v << "\n";
    return v;
}
void myString::GetNext(string p, int next[]) {
    int len = p.length();
    next[0] = 0;
    for (int i = 1, j = 0; i < len; ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = next[j-1];
        }
        if (p[i] == p[j])
            j++;
        next[i] = j;
    }
}
int myString::KMPFind(string p, int pos, int next[]) {
    int len = p.length();
    for (int i = pos, j = 0; i < size; ++i) {
        while (j > 0 && mainstr[i] != p[j]) {
            j = next[j-1];
        }
        if (mainstr[i] == p[j]) {
            j++;
        }
        if (j == len)
            return i-len+1;
    }
    return -1;
}
void myString::output() {
    int *next = new int[size];
    GetNext(mainstr, next);
    int x = size-next[size-1];
    if (x == size)
        cout << size << "\n";
    else
        cout << (size%x == 0 ? 0:x-size%x) << "\n";
}
int main() {
    int t; cin >> t;
    string a;
    while (t--) {
        cin >> a;
        
        myString str_main;
        str_main.SetVal(a);
        str_main.KMPFindSubstr(a, 0);
        str_main.output();
    }
    return 0;
}