/**
** Problem: https://www.hackerearth.com/december-circuits-16/approximate/christmas-gifts/
**/
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

int unvisited;
#define RED false
#define WHITE true

void DFS(int vertex, vector<bool> &visited, vector<bool> &color,vector<list<int> > &graph ,bool current_color){
    if(current_color==WHITE){
        ITERATE(it,graph[vertex]){
            if(visited[*it] && color[*it]==WHITE){
                return;
            }
        }
    }
    visited[vertex]=true;
    color[vertex]=current_color;
    unvisited--;
    ITERATE(it,graph[vertex]) if(!visited[*it]) DFS(*it,visited,color,graph,!current_color);
}

int main(){

    
    int N,M,u,v;
    cin>>N>>M;
    unvisited=N;
    vector<list<int> > graph(M+1);
    LOOP(i,1,M){
        cin>>u>>v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<bool> visited(N+1,false),color(N+1);
    DFS(1,visited,color,graph,RED);
    if(unvisited>0) cout<<"No";
    else LOOP(i,1,N) if(color[i]==true) cout<<"1 "; else cout<<"0 "; 
    return 0;
}
