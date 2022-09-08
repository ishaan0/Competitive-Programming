#include<bits/stdc++.h>
using namespace std ;


int main(){
    ifstream file_a("bruteforce_output.txt") ;
    ifstream file_b("original_output.txt") ;

    string str1 ;
    int cnt = 0 ;
    while(getline(file_a, str1)){
    	string str2 ;
    	getline(file_b, str2) ;
    	if(str1 != str2){
    		// file_a.close() ;
    		// file_b.close() ;
    		// cout<< "Wrong Answer\n" ;
            cnt++ ;
    		// return 0 ;
    	}
    }

    file_a.close() ;
	file_b.close() ;
	
    if(cnt == 0)
        cout<< "Accepted\n" ;
    else cout<< "Wrong Answer -> " << cnt << "\n" ;

    return 0 ;
}