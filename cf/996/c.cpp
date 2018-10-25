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

int n,k;
int p[4][52];
int t[2][52];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>k;
    for(int i=0;i<4;i++) { 
        for(int j=0;j<n;j++) { 
            cin>>p[i][j];
        }
    }

    for(int i=0;i<2*k;i++) {
        for(int l=0;l<k;l++) { 
            if(p[1][l] && p[0][l]==p[1][l]) {
                cout<<p[0][l]<<" "<<1<<" "<<l+1<<endl;
                p[1][l] = 0;
            }
            if(p[2][l] && p[3][l]==p[2][l]) {
                cout<<p[3][l]<<" "<<4<<" "<<l+1<<endl;
                p[2][l] = 0;
            }
        }
        int tr = p[1][k-1];
        int t, pr= p[2][0];
        for(int l=0;l<k;l++) { 
            t = pr;
            pr = p[1][l];
            p[1][l] = t;
            //if(p[1][l]) 
                cout<<p[1][l]<<" "<<2<<" "<<l+1<<endl;
        }
        for(int l=k-1;l>=0;l--) { 
            t = pr;
            pr = p[2][l];
            p[2][l] = pr;
            //if(p[2][l]) 
                cout<<p[2][l]<<" "<<3<<" "<<l+1<<endl;
                ;
        }
        cout<<"done round"<<endl;
    }


    return 0;
}

