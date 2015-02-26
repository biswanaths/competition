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


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

int m; int n ; 

vector<pair<int,int> > al[50003];
bool visited[50003];
int mc[50003];
set<int> visting;
int wdfs(int ,int);
int dfs(int cv,int seen) {
    int cm = -1;
    if(visited[cv]) 
        return mc[cv];
    if(cv!=n) visited[cv] = true;
    if(cv==n)
        return seen;
    for(int i=0;i<al[cv].size();i++) { 
        int pm = wdfs(al[cv][i].first,max(seen,al[cv][i].second));
        if( pm != -1) {
            if( cm == -1) cm = pm;
            else cm = cm < pm ? cm : pm ;
        }
    }
    mc[cv] = cm;
    return cm; 
}

int wdfs(int cv,int seen) { 
    cout<<"call "<<cv<<" "<<seen<<endl;
    int x = dfs(cv,seen);
    cout<<"return "<<x<<endl;
    return x;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("D:\MyCodkke\Data\test.out", "w",stdout);
#endif
    mc[1]=-1;
    cin>>n>>m;
    int a,b,k;
    for(int i=0;i<m;i++) { 
        cin>>a>>b>>k;
        pair<int,int> ec(b,k);
        al[a].push_back(ec);
        pair<int,int> ed(a,k);
        al[b].push_back(ed);
    }

    int cost = wdfs(1,-1);
    if(cost==-1) 
        cout<<"NO PATH EXISTS";
    else 
        cout<<cost;
	return 0;
}
