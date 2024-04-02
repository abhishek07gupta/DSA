#include<string>
#include<iostream>

using namespace std;

#define mod 1000000007
class Solution {
public:
    long long result(int x , int y ){
        if(y == 0){
            return 1;
        }

        long long ans = result(x,y/2);
        ans*=ans;
        ans%=mod;

        if(y%2!=0){
            ans*=x;
            ans%=mod;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;

        return (result(5,even)*result(4,odd))%mod;
    }
};


int main(){
    long long number ;
    cout<<"enter number"<<endl;
    cin>>number;
    Solution makecount;
    int count = makecount.countGoodNumbers(number);
    cout<<count;
}