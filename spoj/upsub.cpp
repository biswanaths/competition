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

int top[N];
char seq[N][N];

void print() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<3;j++) {
            cout<<seq[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(int k,string s,char prev,int n) {
    if(k==n) {cout<<s<<endl; return ; }
    for(int i=top[k];i>=0;i--) {
        if(prev <= seq[k][i])
            dfs(k+1, s + seq[k][i] , seq[k][i],n);
    }
    return;
}

void solve() { 
    string s; 
    cin>>s;
    int z = s.size();
    //for(int i=0;i<z;i++) 
    for(int j=0;j<z;j++) seq[j][0]=0;
    fill(top,top+z,-1);
    int l=0;
    rep(z) {
        int j;
        for(j=0;top[j]!=-1 && seq[j][top[j]] <= s[i] ;j++) ;
        seq[j][++top[j]]=s[i];
        seq[j][top[j]+1]=0;
        l = max(l,j);
    }
    dfs(0,"",0,l+1);
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
    while(t--) { 
        solve();
        //print();
    }
    return 0;
}


