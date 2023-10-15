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
    // for(i = 0; i < L; i ++)
    //     cout << next[i] << ' ';
    // cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete []next;
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
    
    for (int i = len-1; i > 0; --i)
        next[i] = next[i-1];
    next[0] = -1;
}
int myString::KMPFind(string p, int pos, int next[]) {
    int len = p.length();
    for (int i = pos, j = 0; i < size; ++i) {
        while (j > 0 && mainstr[i] != p[j]) {
            j = next[j];
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
    cout << mainstr << "\n";
}
int main() {
    int t; cin >> t;
    string a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        myString str_main;
        str_main.SetVal(a);
        str_main.output();
        int pos = str_main.KMPFindSubstr(b, 0);
        // cout << a.substr(0, pos+1) << "\n";
        if (pos != -1)
            str_main.SetVal(a.substr(0, pos)+c+a.substr(pos+b.length(),a.length()-(pos+b.length())));
        str_main.output();
        // cout << str_main.KMPFindSubstr(b, 0)+1 << "\n";
    }
    return 0;
}