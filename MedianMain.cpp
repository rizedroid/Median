#include "Median.h"

#define AUTO

int main()
{
    Median::Median m;

#ifndef AUTO
    // Manual test
    //add numbers
    {
        m.addNumber(10);
    }
    // print current median
    m.printMedian();
#else
    //auto test
    m.autoTest();
#endif
    return 0;
}