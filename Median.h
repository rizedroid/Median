#pragma once
#include <set>
#include <vector>
namespace Median {
    class Median {
    public:
        Median() : median(0) {}

        void addNumber(double num) {
            calcMedian(num);
        }
        void printMedian() const {
            std::cout << this->median << std::endl;
        }
    private:
        double median;
        std::multiset<double> data;
        std::multiset<double>::iterator left, right;

        void calcMedian(double num){
            // insert number
            data.insert(num);
            // check if is one element and init iterators
            if (data.size() == 1) {
                left = data.begin();
                right = data.begin();
                median = *left;
            } else {
                // is even or odd
                if (data.size() % 2 == 0) {
                    if (num >= *right)
                        right++;
                    else
                        left--;
                } else {
                    if (num >= *right)
                        left++;
                    else if (num <= *left)
                        right--;
                    else {
                        left++;
                        right--;
                    }
                }
            }
            this->median = (double)(*left + *right) / 2;
        }
    };
} // namespase Median