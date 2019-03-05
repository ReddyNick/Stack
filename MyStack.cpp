#include "MyStack.h"
#include <iostream>
#include "stdlib.h"

// for Resize()
const int INCREASE_RATIO = 2;
const double DECREASE_RATIO = 0.25;
const data_t CANARY = 696;


namespace Stlib
{
    Stack::Stack(const size_t cap)
         : size_(0)
         , capacity_(cap)
         , mincap_(cap)
         , data_(new data_t[cap + 2])
         , hashsum_(0)
    {
            data_[0] = data_[1] = CANARY;
            is_OK();
    }

    Stack::Stack()
         : size_(0)
         , data_(new data_t[2])
         , capacity_(0)
         , mincap_(0)
         , hashsum_(0)
    {
        data_[0] = data_[1] = CANARY;
        is_OK();
    }

    Stack::~Stack()
    {
        size_ = capacity_ = mincap_ = -7;
        hashsum_ = NAN;
        delete[] data_;
    }

    void Stack::push(const data_t item)
    {
        is_OK();
        if (size_ == capacity_)
            Resize(more);

        data_[++size_] = item;
        data_[size_ + 1] = CANARY;

        hashsum_ = Get_hsum();
        is_OK();
    }

    data_t Stack::pop()
    {
        printf("1st");
        is_OK();
        if(Stack:: isempty())
        {
            std::cout << "\nSTACK UNDERFLOW!\n" << std::endl;
            abort();
        }

        data_t item = data_[size_--];
        data_[size_ + 1] = CANARY;

        Resize(less);

        printf("2nd");
        hashsum_ = Get_hsum();
        is_OK();

        return item;
    }
    bool Stack::is_OK()
    {
        switch(Verificator())
        {
            case 0:
                return true;
            case 1:
                printf("ERROR! data_  = nullptr.\n");
                dump();
                abort();
            case 2:
                printf("ERROR! size or capacity is invalid.\n");
                dump();
                abort();
            case 3:
                printf("ERROR! hashsum  = %d is invalid. should be = %d\n", hashsum_, Get_hsum());
                dump();
                abort();
            case 4:
                printf("ERROR! CANARY is invalid.\n");
                dump();
                abort();
            default:
                printf("ERROR! Stack is invalid.\n");
                dump();
                abort();
        }
    }

    int Stack::Verificator()
    {
        int erno = 0;

        if (data_ == nullptr)
            erno = 1;
        else
        if (size_ > capacity_ || size_< 0 || capacity_ < 0)
            erno = 2;
        else
        if (hashsum_ != Get_hsum())
            erno = 3;
        else
        if (data_[0] != CANARY || CANARY != data_[size_ + 1])
            erno = 4;

        return erno;
    }
    int Stack::Resize(bool how)
    {
        if (how == true)
        {
            if (capacity_ == 0)
                {
                    capacity_ = 1;
                    NewData();
                }

            capacity_ = INCREASE_RATIO * capacity_;
            NewData();
            return 0;
        }
        else
        {
            if ((capacity_ / INCREASE_RATIO < mincap_) || (size_ > DECREASE_RATIO * capacity_))
                return 0;

            capacity_ = capacity_ / INCREASE_RATIO;

            NewData();
            return 0;
        }
    }

    int Stack::NewData()
    {
        data_t* newdata = new data_t[capacity_ + 2];
        for (int i = 0; i < size_; i++)
            newdata[i + 1] = data_[i + 1];

        newdata[0] = newdata[size_ + 1] = CANARY;

        data_t* ptr = data_;
        data_ = newdata;

        delete[]ptr;
    }

    int Stack::dump()
    {
        printf("size = %d, capacity = %d, hashsum = %d"
               "\n------------------------------------\n", (int)size_, (int)capacity_, (int)hashsum_);

        for(int i = 0; i < capacity_ + 2; i++)
        {
            if (i == 0 || i == size_ + 1)
                printf("[%d] -> %d <- CANARY\n", i, data_[i]);
            else
            if (i > size_ + 1)
                printf("[%d] -> empty (%d)\n", i, data_[i]);
            else
                printf("[%d] -> %d\n", i, data_[i]);
        }

        return 0;
    }

    int Stack::Get_hsum()
    {
        int res = 0, coef = 1;
        for (int i = 0; i <= size_ + 1; i++)
        {
            res += data_[i] * coef;
            coef = -coef;
        }

        return res;
    }
}

