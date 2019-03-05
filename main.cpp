
#include <iostream>
#include "assert.h"
#include "MyStack.h"
#include "stdlib.h"


int main()
{

    Stlib::Stack st1;
    Stlib::Stack st2(12);

    for(int i=0;i<24;i++)
    {
        st1.push(i);
        printf("size = %d, capacity = %d\n-------------------\n", (int)st1.size(), (int)st1.capacity());
    }

    st1.dump();
    printf("pop pop pop\n");

    for(int i=0;i<24;i++)
    {
        st1.pop();
        printf("size = %d, capacity = %d, hsum = %d"
               "\n--------------------\n", (int)st1.size(), (int)st1.capacity(), st1.hsum());
    }


//    for(int i=0;i<21;i++)
//    {
//        st2.push(i);
//        printf("[%d] = %d\n", i, st2.data_[i]);
//    }
//
//     while(!st2.isempty()){
//        printf(" %f,", st2.pop());
//        //printf("capdown = %d\n",st2.capa());
//    }

    //std::cout<<st2.pop(); //stack underflow

    return 0;
}
