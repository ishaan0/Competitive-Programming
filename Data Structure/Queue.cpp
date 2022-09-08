#include<bits/stdc++.h>
using namespace std;

#define Max_size 10

/**** Queue Body ****/
class Queue{
    int data[Max_size+1],head,tail;
public:
    Queue(){head = tail = 0;}
    void enqueue(int item);
    int dequeue();
    bool Empty();

};

/**** Empty ****/
bool Queue:: Empty(){
    if(head == tail)
        return true;
    return false;
}

/**** enqueue ****/
void Queue:: enqueue(int item){
    if((tail+1) % (Max_size+1) == head){
        cout<< "Queue is Full ...." << endl;
        return ;
    }
    data[tail] = item;
    tail = ((tail+1) % (Max_size+1));
}

/**** dequeue ****/
int Queue:: dequeue(){
    if(Empty()){
        cout<< "Queue is Empty" << endl;
        return -1;
    }

    int item = data[head];
    head = ((head+1) % (Max_size+1)) ;
    return item;
}


int main(){



    return 0;
}
