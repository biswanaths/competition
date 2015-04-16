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
#define N 200002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define M 202

int word[M];
int connect[M][M];

// find the transistive clouser 
// use floyd warshal 
void connect_all(int m) { 
    for(int k=1;k<=m;k++) {
        for(int i=i;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                connect[i][j] = connect[i][j] || 
                    (connect[i][k] && connect[k][j]);
            }
        }
    }
}


void read(int m,int k,int n ) {
    int a,b;
    repij(m+1,m+1) connect[i][j]=0;
    rep(k) {
        cin>>a>>b; 
        connect[a][b]=connect[b][a]=1;
    }
}

int solve(int m,int k,int n ) {
    int wi;
    rep(n) {
        cin>>wi;
        for(int j=1;j<=m;j++) {
            if(wi==j) {
            }
            else if(connect[wi][j]==1) {
                word[j]++;
            }
        }
    }
    return 0;
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) { 
        int m,k,n; cin>>m>>k>>n;
        read(m,k,n);
        connect_all(m);
        cout<<solve(m,k,n)<<endl;
    }

    return 0;
}

