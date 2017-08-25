/*
 * SRM223-D1-500.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: Hossam Eissa
 *      Idea: for every permutation of the string try all possible primes
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
const double eps=1e-9;
class PrimeAnagrams{
	bool arr[N];
	vector<int>p;
public:
	bool isprime(int n){
		if(n<2)return 0;
		for(int i=2;i*i<=n;i++){
			if(n%i==0)return 0;
		}
		return 1;
	}
	vector <int> primes(string anagram){
		sort(anagram.begin(),anagram.end());
		ll ans=1e18;
		int ansa=-1,ansb=-1,ansc=-1;
		do{
			for(int i=1;i<anagram.size();i++){
				for(int j=i+1;j<anagram.size();j++){
						ll a,b,c;
						a=b=c=0;
						string s1,s2,s3;
						for(int k=0;k<anagram.size();k++){
							if(k<i)
								a=a*10+(anagram[k]-'0'),s1+=anagram[k];
							else if(k<j)
								b=b*10+(anagram[k]-'0'),s2+=anagram[k];

							else
								c=c*10+(anagram[k]-'0'),s3+=anagram[k];
						}
						if(s1[0]=='0'||s2[0]=='0'||s3[0]=='0')
							continue;
						if(isprime(a)&&isprime(b)&&isprime(c)){
								if(a*b*c<ans){
									ans=a*b*c;
									ansa=a;
									ansb=b;
									ansc=c;
								}
						}
				}
			}

		}while(next_permutation(anagram.begin(),anagram.end()));
		vector<int>v={ansa,ansb,ansc};
		sort(v.begin(),v.end());
		if(ansa==-1)return vector<int>();
		return v;
	}


};
int main(){
	PrimeAnagrams p;
	vector<int>v=p.primes("39151");
	if(v.size()!=0)
	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	else cout<<"NO Sol"<<endl;
	return 0;
}
