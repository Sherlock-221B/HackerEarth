/**
** Problem: https://www.hackerearth.com/december-circuits-16/approximate/christmas-divisors/
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

VI v;
vector<LL> sub;
unordered_set<LL> s;
int N;
void compute(int index, LL value){
    if(index==N){
        if(s.find(value)==s.end()){
            sub.PB(value);
            s.insert(value);
        }
        return;
    }
    compute(index+1, value);
    compute(index+1, value*v[index]);
}

int main(){
    v.clear();
    sub.clear();
    s.clear();
    int k,x,y;
    cin>>k;
    while(k--){
        cin>>x>>y;
        while(y--) v.PB(x);
    }
    N=v.size();
    compute(0,1);
    int S=sub.size();
    vector<bool> visited(S,false);
    vector<LL> answer;
    answer.PB(1);
    LOOP(j,1,S){
        LOOP(i,1,S-1){
            if(!visited[i] && (answer.back()%sub[i]==0 || sub[i]%answer.back()==0)){
                visited[i]=true;
                answer.PB(sub[i]);
                break;
            }
        }
    }
    if(answer.size()!=S) cout<<"No";
    else for(LL i:answer) cout<<i<<" ";
    return 0;
}
