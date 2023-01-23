#define rp ' '
#define ln '\n'

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char a[100100];
queue<char> q;
int main(){
    int n;
    cin>>n;
    cin>>a;
    for(int i=0; i<n; i++){
        if(a[i]=='n' && a[i+1]=='a'){
            q.push('n');
            q.push('y');
            q.push('a');
            i++;
        }
        else q.push(a[i]);
    }
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
}