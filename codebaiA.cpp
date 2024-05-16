#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int d=0,D=0;
    for ( int i;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z') D++;
        if(s[i]>='a'&&s[i]<='z') d++;
    }
    if (D>d){
        for(int i=0;i<s.length();i++)
        if(s[i]>='a'&&s[i]<='z') s[i]=s[i]-'a'+'A';
    }
    else for (int i=0;i<s.length();i++)
    if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
cout<<s;
        
    }