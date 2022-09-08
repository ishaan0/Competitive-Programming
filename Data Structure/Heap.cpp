#include<bits/stdc++.h>
using namespace std;


/**** Heap body ****/
vector < int > H;

/**** Get Left child index ****/
int left(int i){
    return 2*i ;
}

/**** Get Right child index ****/
int right(int i){
    return 2*i+1 ;
}

/**** Get Parent index ****/
int parent(int i){
    return i/2 ;
}

/**** Is it a Max Heap ****/
bool is_max_heap(const vector<int>& H){
    int i,p;

    for(i=H.size()-1;i>1;i--){
        p = parent(i);
        if(H[p] < H[i])
            return false;
    }

    return true;
}

/**** Is it a Min Heap ****/
bool is_min_heap(){
    int i,p;

    for(i=H.size()-1;i>1;i--){
        p = parent(i);
        if(H[p] > H[i])
            return false;
    }

    return true;
}

void adjust(int i){
    if(H[i] > H[parent(i)]){
        swap(H[i],H[parent(i)]);
        adjust(parent(i));
    }

}


/**** insert ****/
void insert_data(int data){
    H.push_back(data);

    if(H.size() == 1)
        return ;

    adjust(H.size()-1) ;
}



int main(){


    return 0;
}
