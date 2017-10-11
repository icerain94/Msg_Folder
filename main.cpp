#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include "Message.h"
#include "Folder.h"
using namespace std;
const int N = 100 + 10;

#define INF 0x3f3f3f3f
#define mod 1000000007


int main()
{
    Folder f[10];
    Message m("abc");
    m.save(f[0]);

    Message n("def");
    n.save(f[1]);
    for(int i=0;i<2;i++) f[i].test();

   // cout<<&(n.folders)<<" "<<&(m.folders)<<endl;
    swap(n,m);
    //cout<<&(n.folders)<<" "<<&(m.folders)<<endl;

    for(int i=0;i<2;i++) f[i].test();

   // delete m;
    return 0;
}
