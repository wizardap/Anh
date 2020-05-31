#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
//typedef double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define Repd(i,n) for(__typeof(n) i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(__typeof(b) i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(__typeof(a) i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define nl puts("")
#define sp printf(" ")
#define ok puts("ok")
//#include <conio.h>

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> void db(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a << " "; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> struct Triple { T x, y, z; Triple() {} Triple(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {} };
template<class T> Triple<T> euclid(T a, T b) { if (b == 0) return Triple<T>(1, 0, a); Triple<T> r = euclid(b, a % b); return Triple<T>(r.y, r.x - a / b * r.y, r.z); }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

const double PI = 2 * acos(0);
const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dr[] = {-1, +0, +1, +0};
const int dc[] = {+0, +1, +0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ld eps = ld(1e-9);
const ll mod = 100000007;
typedef pair<int, int> II;

#define maxn 515

int n, m;
string s[maxn], res[maxn];
int a[maxn][maxn][11], f[maxn][maxn][11], d[maxn][maxn][11][2];

int cal2(int x){
    if(x == 1) return 0;
    return 1 + cal2(x >> 1);
}

int B(int x){
    return 1 << x;
}

void Boi(int r, int c, int id, int mau){
    For(i, r, r + B(id) - 1) For(j, c, c + B(id) - 1)
        res[i][j] = mau + '0';
}

void paint(int r, int c, int id){
    if(id == 0){
        res[r][c] = s[r][c];
        return;
    }
    int i = d[r][c][id][0];
    int j = d[r][c][id][1];
    int t1 = -1, t2;
    Rep(k, 4) if(k != i && k!= j){
        if(t1 == -1) t1 = k;
        else t2 = k;
    }
    Boi(r + (i >> 1) * B(id - 1), c + (i & 1) * B(id - 1), id - 1, 0);
    Boi(r + (j >> 1) * B(id - 1), c + (j & 1) * B(id - 1), id - 1, 1);
    paint(r + (t1 >> 1) * B(id - 1), c + (t1 & 1) * B(id - 1), id - 1);
    paint(r + (t2 >> 1) * B(id - 1), c + (t2 & 1) * B(id - 1), id - 1);
}

void go(int r, int c, int id){
    if(id == 0) {f[r][c][id] = 0; return;}
    go(r, c, id - 1);
    go(r, c + B(id - 1), id - 1);
    go(r + B(id - 1), c, id - 1);
    go(r + B(id - 1), c + B(id - 1), id - 1);
    int &res = f[r][c][id];
    res = inf;
    Rep(i, 4) Rep(j, 4) if(i != j){
        int t, t1 = -1, t2;
        Rep(k, 4) if(k != i && k!= j){
            if(t1 == -1) t1 = k;
            else t2 = k;
        }
        t = a[r + (i >> 1) * B(id - 1)][c + (i & 1) * B(id - 1)][id - 1]
        + B(id + id - 2) - a[r + (j >> 1) * B(id - 1)][c + (j & 1) * B(id - 1)][id - 1]
        + f[r + (t1 >> 1) * B(id - 1)][c + (t1 & 1) * B(id - 1)][id - 1]
        + f[r + (t2 >> 1) * B(id - 1)][c + (t2 & 1) * B(id - 1)][id - 1];
        if(t < res){
            res = t;
            d[r][c][id][0] = i;
            d[r][c][id][1] = j;
        }
    }
   // if(r == 0 && c == 0 && id == m) cout << res << endl;
}

int main(){
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> n;
    Rep(i, n) cin >> s[i];
    Rep(i, n) Rep(j, n) a[i][j][0] = s[i][j] - '0';
    m = cal2(n);
    Rep(i, n) res[i].resize(n);
    For(i, 1, m){
        For(r, 0, n - (1 << i))
            For(c, 0, n - (1 << i)){
                a[r][c][i] = a[r][c][i - 1] + a[r + B(i - 1)][c][i - 1]
                            +a[r][c + B(i - 1)][i - 1] + a[r + B(i - 1)][c + B(i - 1)][i - 1];
            }
    }
    go(0, 0, m);
    paint(0, 0, m);
    printf("%d\n", f[0][0][m]);
    Rep(i, n) cout << res[i] << endl;
}
