#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 102
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int top[N],l;
char seq[N][N];
string res;

void print() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<3;j++) {
            cout<<seq[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(int k,char prev) {
    if(k==l+1) {cout<<res<<endl; return ; }
    for(int i=top[k];i>=0;i--) {
        if(prev <= seq[k][i])
            res[k]= seq[k][i],
            dfs(k+1, seq[k][i]);
    }
    return;
}

void solve() { 
    string s; 
    cin>>s;
    int z = s.size();
    for(int j=0;j<z;j++) seq[j][0]=0;
    fill(top,top+z,-1);
    l=0;
    rep(z) {
        int j;
        for(j=0;top[j]!=-1 && seq[j][top[j]] <= s[i] ;j++) ;
        seq[j][++top[j]]=s[i];
        seq[j][top[j]+1]=0;
        l = max(l,j);
    }
    res="";
    rep(l) res+='a';
    dfs(0,0);
    PEL;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t;cin>>t;
    double total = 0.0;
    while(t--) { 
        clock_t start = clock();
        solve();
        double duration = (clock() - start ) / (double ) CLOCKS_PER_SEC;
        total += duration;
        cout<<fixed<<setprecision(9)<<duration<<endl;
        //print();
    }
    cout<<fixed<<setprecision(9)<<total<<endl;
    return 0;
} 
