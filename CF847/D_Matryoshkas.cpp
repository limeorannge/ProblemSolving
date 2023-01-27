/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: 
*/
#define rp ' '
#define ln '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
void dbg(){puts("okay");}
int n, Q;
int a[200100];
stack<int> st;
map<int, int> mp;
int main(){
    fastio;
    cin >> Q;
    while(Q--){
        mp.clear();
        while(!st.empty()) st.pop();
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        int bf = 0;
        int ans = 0;
        st.push(0);
        for(auto i : mp){
            if(i.first != bf + 1 && bf != 0){
                ans += st.top();
                while(!st.empty()) st.pop();
                st.push(0);
                st.push(i.second);
            }
            else{
                if(i.second == st.top());
                else if(i.second > st.top()){
                    st.push(i.second);
                }
                else{
                    ans += st.top() - i.second;
                    while(st.top() > i.second){
                        st.pop();
                    }
                    st.push(i.second);
                }
            }
            bf = i.first;
        }
        ans += st.top();
        cout << ans << ln;
    }
}