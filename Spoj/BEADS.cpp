/*
Author: Hossam Eissa
Idea: Idea: modified Sufix array empty string is the last word
*/
#include <bits/stdc++.h>
using namespace std;
#define FO freopen("o.txt","w",stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
char str[N];
int suf[N];
int rnk[N];
int tmprnk[N];
struct cmp
{
    int h;
    bool operator ()(int i,int j)const
    {
        return rnk[i]<rnk[j]||(rnk[i]==rnk[j]&&rnk[i+h]<rnk[j+h]);
    }

};
void buildSA()
{
    int len=0;
    do
    {
        suf[len]=len;
        rnk[len]=str[len];
        if(!str[len])
            rnk[len]=1e5;
    }
    while(str[len++]);
    //cout<<len<<endl;
    for(int h=1;; h<<=1)
    {
        cmp c= {h};
        sort(suf,suf+len,c);
        for(int i=1; i<len; i++)
        {
            tmprnk[i]=tmprnk[i-1]+c(suf[i-1],suf[i]);
        }

        for(int i=0; i<len; i++)
        {
            rnk[suf[i]]=tmprnk[i];
            //   cout<<rnk[suf[i]]<<endl;
        }
        if(tmprnk[len-1]==len-1)
            break;
    }

}
int main()
{
   // FO;

    int t;
    scanf("%d",&t);
   // cout<<t<<endl;
   // getchar();
    while(t--)
    {
        memset(rnk,0,sizeof rnk);
        memset(tmprnk,0,sizeof rnk);
        memset(suf,0,sizeof rnk);
        memset(str,0,sizeof str);
        //cout<<t<<endl;
        scanf(" %s",str);
        int len1=strlen(str);
        //  str[len]=(char)'z'+1;
        set<char>st;
        for(int i=0; i<len1; i++)
        {
            st.insert(str[i]);
            str[len1+i]=str[i];
        }
      /*  if(st.size()==1)
        {
            printf("1\n");
            continue;

        }*/
       // str[len*2]=0;

        buildSA();
        int len=strlen(str);

        for(int i=0; i<=len; i++)
        {
                int ans=suf[i]+1;
            if(ans<=len1)
            {
             //   if(ans>=len/2)ans=1;
				printf("%d\n",ans);
				//if(ans<=len1)
            //    printf(" %s\n",str+suf[i]);
               break;
           }
        }
    }


}
