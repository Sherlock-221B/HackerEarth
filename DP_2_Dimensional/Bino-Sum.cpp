/**
** Problem: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/bino-sum-1/
**/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;
#define LOOP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define LOOPE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LOOPR(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB(item) push_back(item)
#define MP(item1,item2) make_pair((item1),(item2))
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

#define MOD 1000000007L
vector<LL> fact;

void compute(){
    fact.resize(1001);
    fact[0]=1;
    LOOPE(i,1,1000){
        fact[i]=(i*fact[i-1])%MOD;
    }
}


int main(){

    compute();
    //LOOP(i,20) DEBUG(i,fact[i]);
    int T;
    cin>>T;
    while(T--){
        LL N,P,answer=0;
        cin>>N>>P;
        LOOPE(i,0,P){
            answer+=(fact[N]/(fact[i]*fact[N-i]))%MOD;
            DEBUG(N,i,answer);
            DEBUG("for lst , fact : ",(fact[N]/(fact[i]*fact[N-i]))%MOD);
        }
        cout<<answer<<endl;
    }

    return 0;
}
