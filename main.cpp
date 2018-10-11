
#include <iostream>
#include "assert.h"
#include "MyStack.h"
#include "stdlib.h"


int main()
{

    Stlib::Stack st1;
    Stlib::Stack st2(12);

    for(int i=0;i<20;i++){
        st2.push(i);
        //printf("capup = %d\n",st2.capa());
    }

     while(!st2.isempty()){
        printf(" %f,", st2.pop());
        //printf("capdown = %d\n",st2.capa());
    }

    //std::cout<<st2.pop(); //stack underflow

    return 0;
}
