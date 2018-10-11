
#ifndef MYSTACK_H
#define MYSTACK_H


#include "assert.h"
#include "math.h"
#include <cstddef> // for size_t

typedef double data_t;

// arguments for Resize()
const bool more = true, less = false;

namespace Stlib
{
    class Stack {
    public:

        size_t size() const { return sz; }

        Stack(size_t cap);
        Stack();
        ~Stack();

        void push(data_t item);
        data_t pop();
        bool isempty() {return sz==0;}

    private:
        data_t *data;
        size_t sz;       // number of elements
        size_t capacity; // size of array
        size_t mincap;   // minimal size of array, 0 by default

    };
    /**
     * Resize changes the stack capacity with hysteresis
     *
     * [in] bool how = true -> make bigger
     * capacity *= ratiomore
     *
     * [in] bool how = false -> make less
     * if size <= ratioless*capacity than
     * capacity /= ratiomore
     * */

    data_t* Resize(data_t* data, const size_t size, size_t &capacity, const size_t mincap, bool how);

}
#endif
