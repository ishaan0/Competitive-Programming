#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

int main(){
	unordered_map< int, int, custom_hash > m1 ;
	unordered_map< pair<int,int>,int,custom_hash > m2 ;

	m1.reserve(1024) ;
    m1.max_load_factor(0.25) ;

    m2.reserve(1024) ;
    m2.max_load_factor(0.25) ;

	m1[2] = 5 ;
	m1[3] = 6 ;

	m2[make_pair(2,3)] = 11 ;
	m2[make_pair(5,8)] = 33 ;

	gp_hash_table< int,int, custom_hash > g1 ;
	gp_hash_table< pair<int,int>,int, custom_hash >  g2 ;

	g1[2] = 5 ;
	g1[3] = 6 ;

	g2[make_pair(2,3)] = 11 ;
	g2[make_pair(5,8)] = 33 ;

	cout<< m1.size() << " " << m2.size() << "\n" ;
	cout<< g1.size() << " " << g2.size() << "\n" ;


	return 0 ;
}