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

int g[26][26];
int r[26];
string a,b;
int z;

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    cin>>a>>b;
    z=a.size();
    int hd =0;
    rep(z) {
        if(a[i]!=b[i]) {
            hd++;
            if( g[a[i]-'a'][b[i]-'a']==0) {
                g[a[i]-'a'][b[i]-'a']=i+1;
                r[a[i]-'a']=i+1;
            }
        }
    }

    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            //cout<<g[i][j]<<" ";
            if(g[i][j] && g[j][i]) {
                cout<<hd-2<<endl;
                cout<<g[i][j]<<" "<<g[j][i]<<endl;return 0;
            }
        }
        //cout<<endl;
    }

    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if(g[i][j]&&r[j]) {
                cout<<hd-1<<endl;
                cout<<g[i][j]<<" "<<r[j]<<endl;return 0;
            }
        }
    }

    cout<<hd<<endl;
    cout<<-1<<" "<<-1<<endl;

    return 0;
}

