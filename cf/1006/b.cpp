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

std::priority_queue<int, std::vector<int>, std::greater<int> > q;

vector<int> v;

int n,k,t;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>k;
    int ans = 0 ;
    rep(n) { 
        cin>>t;
        v.push_back(t);
        if(i<k) 
            q.push(t), ans+= t;
        else {
            if(q.top() < t) {
                int a = q.top();
                q.pop();
                q.push(t); 
                ans += t - a;
            }
        }
    }

    cout<<ans<<endl;

    int c =0, run = 0, tm = -1;
    vector<int> runs;
    rep(n) { 
        run++;
        if(k>0 && v[i]>= q.top()) { 
            if(k==1) cout<<n-i-1+run<<" ";
            else cout<<run<<" ";
            run = 0;
            k--;
        }
        if(!q.empty() && q.top() == v[i]) q.pop();
    }

    return 0;
}

