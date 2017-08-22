/*
Author: Hossam Eissa
Idea:try all possible pizza and choose one if it fit all orders
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int have[N],dhave[N];
int main()
{
  //  freopen("o.txt","w",stdout);
    while(1)
    {
        int cnt=0;
        char s[105];
        while(gets(s)&&s[0]!='.')
        {
            have[cnt]=dhave[cnt]=0;
            int len=strlen(s);
            for(int i=1; i<len; i+=2)
            {
                if(s[i-1]=='-')
                {
                    dhave[cnt]|=(1<<(s[i]-'A'));
                }
                else
                {
                    have[cnt]|=(1<<(s[i]-'A'));
                }
            }
           // cout<<cnt<<" "<<have[cnt]<<" "<<dhave[cnt]<<endl;
            cnt++;
        }
        if(cnt==0)break;
        int ans=-1;
        for(int i=0;i<(1<<16);i++){
                int h=i,dh=(1<<16)-1-i;
                bool f=1;
                for(int j=0;j<cnt;j++){
                    if((have[j]&h)||(dhave[j]&dh))continue;
                    else    f=0;
                }
            if(f){
            //    cout<<i<<" "<<dh<<endl;
                ans=i;
                break;
            }
        }
        if(ans==-1)
            puts("No pizza can satisfy these requests.");
        else {
              //  cout<<ans<<endl;
                printf("Toppings: ");
                for(int i=0;i<16;i++){
                    if(ans&(1<<i))
                        printf("%c",'A'+i);
                }
                puts("");
        }
    }

}
