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

void printq(queue<int> q) { 
    while(!q.empty()) { 
        cout<<q.front()<<" ";
        q.pop();
    }
    PEL;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,k1,k2,temp; 
    queue<int> q1,q2,qq1,qq2;
    lld limit = 1; 
    rep(11) limit*=(i+1);
    limit = 110;
    cin>>n;
    cin>>k1; rep(k1)  { cin>>temp; q1.push(temp); qq1.push(temp);}
    cin>>k2; rep(k2)  { cin>>temp; q2.push(temp); qq2.push(temp);}
    lld times =0;
    while((!q1.empty()) && (!q2.empty()) ) {
        int v1 = q1.front(); int v2 = q2.front(); q1.pop();q2.pop();
        if(v1 > v2) q1.push(v2),q1.push(v1);
        else q2.push(v1),q2.push(v2);
        times++;
        printq(q1); printq(q2);cout<<endl;
        if(limit< times) {cout<<-1; return 0; }
    }
    cout<<times<< " "<<(q1.empty()?2:1);

    return 0;
}

