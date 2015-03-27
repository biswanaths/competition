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
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

char f[2001][2001];
bool v[2001][2001];

int m,n;
int t,b,l,r;

void visit(int i,int j) {
    v[i][j]=true;
    if(i<t) t=i;
    if(i>b) b=i;
    if(j<l) l=j;
    if(j>r) r=j;
    if(i>0   && f[i-1][j]=='.' && !v[i-1][j]) visit(i-1,j);
    if(i<m-1 && f[i+1][j]=='.' && !v[i+1][j]) visit(i+1,j);
    if(j>0   && f[i][j-1]=='.' && !v[i][j-1]) visit(i,j-1);
    if(j<n-1 && f[i][j+1]=='.' && !v[i][j+1]) visit(i,j+1);
}


int main() 
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>f[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(f[i][j]=='.' && !v[i][j]) {
                t=m+1,b=-1,l=n+1,r=-1;
                visit(i,j);
                for(int p=t;p<=b;p++) {
                    for(int q=l;q<=r;q++) {
                        if(f[p][q]=='*') f[p][q]='.';
                        v[p][q]=true;
                    }
                }
            }
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            v[i][j]=false;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(f[i][j]=='.' && !v[i][j]) {
                t=m+1,b=-1,l=n+1,r=-1;
                visit(i,j);
                for(int p=t;p<=b;p++) {
                    for(int q=l;q<=r;q++) {
                        if(f[p][q]=='*') f[p][q]='.';
                        v[p][q]=true;
                    }
                }
            }
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<f[i][j];
        }
        cout<<endl;
    }
    return 0;
}

