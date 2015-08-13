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

int l[N];
bool asg[N];
bool ava[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    for(int i=1;i<=n;i++) { 
        cin>>l[i];
        if(l[i]>n) continue;
        if(ava[l[i]]==false) {
            ava[l[i]]=true;
            asg[i] = true;
        }
    }
    /*
    for(int i=1;i<=n;i++)  
        cout<<asg[i]<<" "; PEL;

    for(int i=1;i<=n;i++)  
        cout<<ava[i]<<" "; PEL;
    */
    int ai=1;
    for(int i=1;i<=n;i++) { 
        if(asg[i]==false) {
            while(ava[ai]==true) ai++;
            l[i]=ai;
            ava[ai]=true;ai++;
            asg[i]=true;
        }
    }

    for(int i=1;i<=n;i++) 
        cout<<l[i]<<" ";
    
    return 0;
}

