#include<bits/stdc++.h>
using namespace std;

/// Used to get factorial of larger number .
/// manually multiplying to calculate .

void multiply(int n,vector<int>& arr) ;
void bigFactorial(int n){
    vector<int> arr ;
    arr.push_back(1) ;

    for(int i=2;i<=n;i++)
        multiply(i,arr) ;

    for(int i=arr.size()-1;i>=0;i--)
        cout<< arr[i];
    cout<< endl;
}

void multiply(int n,vector<int>& arr){
    int carry = 0 ;
    for(int i=0;i<arr.size();i++){
        int temp = arr[i]*n + carry ;
        arr[i] = temp%10 ;
        carry = temp/10 ;
    }

    while(carry!=0){
        arr.push_back(carry%10) ;
        carry /= 10 ;
    }
}

int main()
{

    Boost
	return 0;
}
