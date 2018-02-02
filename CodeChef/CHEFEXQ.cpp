/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int>v(n),v2(n);
    int tmp=0;
    int blocksz=sqrt(n)+1;
    int blocknumber=(n+blocksz-1)/blocksz;
    vector<vector<short> > blocks(blocknumber,vector<short>(1<<20));
    vector<int>lazy(blocknumber);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        v2[i]=v[i];
        tmp^=v[i];
        v[i]=tmp;
        blocks[i/blocksz][tmp]++;
    }
    while(q--){
        int type,index,value;
        scanf("%d%d%d",&type,&index,&value);
        type--;
        index--;
        if(type){
            int ans=0;
            for(int blocknum=0;blocknum<blocknumber;blocknum++){
                int st=blocknum*blocksz;
                int en=min(st+blocksz,n)-1;
                if(index<st)
                    break;
                else if(en<=index){
                    ans+=blocks[blocknum][(value^lazy[blocknum])];
                }
                else {
                    for(int j=st;j<=index;j++){
                            if((v[j]^lazy[blocknum])==value)
                                ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }
        else{
            int currbl=index/blocksz;
            int currblen=min((currbl+1)*blocksz-1,n);

            for(int i=index;i<=currblen;i++){
                blocks[i/blocksz][v[i]]--;
                v[i]^=v2[index]^value;
                blocks[i/blocksz][v[i]]++;
            }
            for(int j=currbl+1;j<blocknumber;j++){
                lazy[j]^=(v2[index]^value);
            }
            v2[index]=value;
        }
    }

  return 0;
}
