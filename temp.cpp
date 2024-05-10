#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string ADD(string a, string b) {
    a= "0"+a;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.size() != b.size()) {
        if (a.size() < b.size()) a.push_back('0'); 
        else b.push_back('0');
    }
    
    string res;

    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        int dv = temp % 10;
        carry = temp / 10;
        res.push_back(dv +'0');  
    }

    if (carry != 0) res.push_back(carry + '0'); 
    
    reverse(res.begin(), res.end()); 
    return res;
}

bool isSmaller(string a, string b) {
    if (a.size() < b.size()) return true;
    if (b.size() < a.size()) return false;
    for(int i=0;i<a.size(); i++) {
        if (a[i] == b[i]) continue;
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
        return a<b;
        /*if (a.size() < b.size()) return true;
          if (b.size() < a.size()) return flase;
          return a<=b; */
    }
}

string SUB(string a, string b) {
    bool sign =false;
    if(isSmaller(a,b)) {
        swap (a,b);
        sign = true;
        }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    //change date
    while(a.size() != b.size()){
        if(a.size() < b.size()) a.push_back('0');
        else b.push_back('0');
    }
    int carry =0;
    for(int i=0; i<a.size(); i++){
        int temp =(a[i]-'0') - (b[i] - '0' + carry);
        if (temp < 0 ){
            temp += 10;
            carry = 1;
        } 
        else carry = 0; 
        res.push_back(temp + '0');
        }
        //remove 0
        while(result.back() == '0' && result.size() > 1))res.pop_back();
    if(sign) res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
    }
    string n(string a, int b){
        reverse(a.begin(), b.end())
        string res;
        int carry = 0;
        for(int i=0; i<a.size(); i++){
            int temp = (a[i]='0')<b + carry;
            int dv = temp % 10;
            carry =temp /10;
            res.push_back(dv+'0');
        }
        if(carry !=0) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }

    string MU(string a, string b){
        reverse(a.begin(),b.end());
        reverse(b.begin(),a.end());
        string res="0";
        string bonus = "";
        for(int i=0; i < b.size(); i++){
            string temp = MU(a,b[i]='0') + bonus;
            res = ADD(res,temp);
            while (res[res.size()-1] == '0' && res.size() > 1) {
                res.pop_back();
            }
            bonus += "0";

        }
        
        return res;
    }

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    cout << ADD(a, b)<<endl; 

    return 0;
}