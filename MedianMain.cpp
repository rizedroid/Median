#include <iostream>
#include "Median.h"

int main()
{
    Median::Median m;
    //add numbers
    m.addNumber(1);
    m.addNumber(2);
    m.addNumber(3);
    m.addNumber(1);
    // print current median
    m.printMedian();
    return 0;
}