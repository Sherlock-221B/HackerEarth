/**
** Problem: https://www.hackerearth.com/december-circuits-16/algorithm/christmas-digits/
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
    string n,x;
    int k;
    cin>>n>>k>>x;
    int diff=(int)(x.length()-n.length());
    
    if(k==0) cout<<n;
    else if(k<diff){
        string answer;
        while(k--) answer.PB('9');
        answer.append(n);
        cout<<answer;
    }else{
        k=min(k,diff);
        int i=0,j=0; // indices x->i, n->j
        string answer;
        VI insert_indices;
        while(j<n.length() && k>0){
            if(x[i]==n[j]) {
                answer.PB(n[i]);
                i++,j++;
            }
            else{
                answer.PB(x[i]);
                insert_indices.PB(answer.size()-1);
                k--,i++;
            }
        }
        if(j==n.length()){
            answer.append(x.substr(i,x.length()-i));
        }else{
            while(j<n.length()){
                if(x[i]==n[j]){
                    answer.PB(n[j]);
                    i++,j++;
                }else if(x[i]>n[j]){
                    answer.append(n.substr(j,n.length()-j));
                    break;
                }else{
                    //rollback
                    LOOPR(y,insert_indices.size()-1,0){
                        if(answer[y]>'0'){
                            answer[y]--;
                            break;
                        }else{
                            answer[y]='9';
                        }
                    }
                    answer.append(n.substr(j,n.length()-j));
                    break;
                }
            }
        }
        cout<<answer;
    }

    return 0;
}
