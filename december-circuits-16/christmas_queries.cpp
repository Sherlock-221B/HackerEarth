/**
** Problem: https://www.hackerearth.com/december-circuits-16/algorithm/christmas-queries/
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

int main(){

    int N;
    cin>>N;
    string S[N+1];
    LOOP(i,1,N) cin>>S[i];
    int M;
    cin>>M;
    string P[M+1];
    LOOP(i,1,M) cin>>P[i];
    int Q,query, id, pos;
    char c;
    cin>>Q;
    while(Q--){
        cin>>query;
        switch(query){
            case 1: cin>>id>>pos>>c;  P[id][pos-1]=c;   break;
            case 2: cin>>id>>c; P[id].PB(c);     break;
            case 3: cin>>id;
                int answer=0;
                LOOP(i,1,N){
                    if(S[i].find(P[id])!=string::npos) answer++;
                }
                cout<<answer<<endl;
            break;
        }
    }
    
    return 0;
}
