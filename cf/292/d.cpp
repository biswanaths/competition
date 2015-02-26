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

char a[2002][2002];  
int n,m;

bool degreeOne(int i,int j) { 
    int d = 0 ;
    if(a[i][j]=='.') {
        if(i>0 && a[i-1][j]=='.') d++;
        if(i<n-1 && a[i+1][j]=='.') d++;
        if(j>0 && a[i][j-1]=='.') d++;
        if(j<m-1 && a[i][j+1]=='.') d++;
    }
    return d==1;
}
PII fillOne(int i,int j) { 
    PII p(i,j);
    if(i>0 && a[i-1][j]=='.') a[i][j]='v',a[i-1][j]='^', p.first = i-1;
    else if(i<n-1 && a[i+1][j]=='.') a[i][j]='^',a[i+1][j]='v', p.first = i+1;
    else if(j>0 && a[i][j-1]=='.') a[i][j]='>',a[i][j-1]='<',p.second =j-1;
    else if(j<m-1 && a[i][j+1]=='.') a[i][j]='<',a[i][j+1]='>',p.second = j+1;
    return p;
}


void print() { 
    for(int i=0;i<n;i++) { 
        for(int j=0;j<m;j++) { 
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m;int change;
    for(int i=0;i<n;i++) {
        string s; cin>>a[i];
    }

    queue< PII > q;

    repij(n,m)  
        if(degreeOne(i,j))
            q.push( PII(i,j));

    while(!q.empty()) {
        PII p = q.front(); q.pop();
        PII newp = fillOne(p.first,p.second);
        if(degreeOne(newp.first-1,newp.second)) q.push(PII(newp.first-1,newp.second));
        if(degreeOne(newp.first+1,newp.second)) q.push(PII(newp.first+1,newp.second));
        if(degreeOne(newp.first,newp.second-1)) q.push(PII(newp.first,newp.second-1));
        if(degreeOne(newp.first,newp.second+1)) q.push(PII(newp.first,newp.second+1));

        if(degreeOne(p.first-1,p.second)) q.push(PII(p.first-1,p.second));
        if(degreeOne(p.first+1,p.second)) q.push(PII(p.first+1,p.second));
        if(degreeOne(p.first,p.second-1)) q.push(PII(p.first,p.second-1));
        if(degreeOne(p.first,p.second+1)) q.push(PII(p.first,p.second+1));
    }

    repij(n,m) 
        if(a[i][j]=='.') 
            return (cout<<"Not unique"),0;
        

    print();

    return 0;
}

