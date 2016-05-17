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

int data[2][100];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int prev = 0, next= 1;
    int n; cin>>n;
    rep(n) cin>>data[prev][i];
    int steps=0;
    while(1) { 
        data[next][0] = data[prev][0];
        data[next][n-1] = data[prev][n-1];
        for(int i=1;i<n-1;i++) { 
            data[next][i] = (data[prev][i]+data[prev][i-1]+data[prev][i+1]<2)?0:1;
        }
        int nochange = true;
        rep(n) {
            nochange = nochange && (data[prev][i]==data[next][i]);
        }
        if(nochange) break;
        rep(n) cout<<data[prev][i]<<" "; PEL;
        steps++;

        prev=(prev+1)%2, next=(next+1)%2;
    }

    rep(n) cout<<data[prev][i]<<" "; PEL;
    cout<<steps<<endl;

    return 0;
}

