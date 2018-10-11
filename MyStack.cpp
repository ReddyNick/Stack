
#include "MyStack.h"
#include <iostream>
#include "stdlib.h"

// for Resize()
const int ratiomore = 2;
const double ratioless = 0.25;

namespace Stlib
{
    Stack:: Stack(const size_t cap) {

            assert(cap>=0);

            sz = 0;
            capacity = mincap = cap;
            printf("hi");

            if (capacity == 0) {
                data = nullptr;
                return;
            }
            data = (data_t*)calloc(capacity,sizeof(data_t));
            assert(data!=NULL);
    }

    Stack:: Stack()
          : sz(0), data(NULL), capacity(0), mincap(0)
          {
          }

    Stack:: ~Stack(){
        sz = capacity = mincap = 0;
        free(data);
        
    }

    void Stack:: push(const data_t item){
                 assert(isfinite(item));

                 if( sz == capacity)
                     data = Resize(data, sz, capacity,mincap, more);

                 assert(data!=NULL);
                 assert(sz<capacity);
                 data[sz] = item;
                 sz++;
    }

    data_t Stack:: pop(){
                   if(Stack:: isempty()) {
                        std::cout << "\nSTACK UNDERFLOW!\n" << std::endl;
                        abort();
                   }

                   assert(data!=NULL);
                   assert(sz>0);
                   data_t item = data[--sz];

                   data = Resize(data, sz, capacity,mincap, less);
                   return item;
    }

    data_t *Resize( data_t* data, const size_t size, size_t& capacity, const size_t mincap, bool how){

            if(how == true){
                if (data == NULL){
                    capacity = 1;
                    return (data_t*)calloc(1,sizeof(data_t));
                }

                capacity = ratiomore*capacity;
                auto newdata = (data_t*) realloc(data,capacity*sizeof(data_t));
                assert(newdata!=NULL);
                return newdata;
            }

            else {
                if ((capacity / ratiomore < mincap) || (size > ratioless * capacity)) return data;

                capacity = capacity / ratiomore;
                auto newdata = (data_t *) realloc(data, capacity * sizeof(data_t));
                assert(newdata != NULL);
                return newdata;
            }
    }
}

