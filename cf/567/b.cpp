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

set<string> visitors;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n; 
    vector<string> ss,ms;
    rep(n) { 
        string s,m; cin>>s>>m;
        if(s=="-") { 
            bool found = false;
            for(int j=ms.size()-1;j>=0;j--) { 
                if(ms[j]==m) {
                    found = true;break;
                }
            }
            if(!found) 
                ss.insert(ss.begin(),"+"), ms.insert(ms.begin(),m);
        }
        ss.push_back(s), ms.push_back(m);
    }

    int cur=0,mm=-1;

    rep(ss.size()) 
        cur+=(ss[i]=="+"), cur-=(ss[i]=="-"), mm=max(mm,cur);

    cout<<mm;

    return 0;
}

