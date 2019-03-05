
#ifndef MYSTACK_H
#define MYSTACK_H


#include "assert.h"
#include "math.h"
#include <cstddef> // for size_t

typedef int data_t;

// arguments for Resize()
const bool more = true, less = false;

namespace Stlib
{
    class Stack {
    public:

        Stack(size_t cap);
        Stack();
        ~Stack();

        void push(data_t item);
        data_t pop();
        bool isempty() {return size_== 0;}
        size_t size() const { return size_;}
        size_t capacity() const { return capacity_;}
        data_t hsum() const {return hashsum_;}
        bool is_OK();
        int Verificator();
        int NewData();
        int dump();


    private:

        size_t size_;       // number of elements
        size_t capacity_; // size of array
        size_t mincap_;   // minimal size of array, 0 by default
        data_t *data_;
        data_t hashsum_;

        int Get_hsum();
        int Resize(bool how);

    };
    /**
     * Resize changes the stack capacity with hysteresis
     *
     * [in] bool how = true -> make bigger
     * capacity *= INCREASE_RATIO
     *
     * [in] bool how = false -> make less
     * if size <= DECREASE_RATIO*capacity then
     * capacity /= INCREASE_RATIO
     * */

}
#endif
