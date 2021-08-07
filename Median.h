#pragma once
#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>

namespace Median {
    class Median {
    public:
        Median() : median(0) {}

        void addNumber(double num) {
            calcMedian(num);
        }
        double printMedian() const {
            std::cout << "Median is: "<< this->median << std::endl;
            return this->median;
        }

        void autoTest() {
            autoTestMedian();
        }
    private:
        double median;
        std::multiset<double> data;
        std::multiset<double>::iterator left, right;

        void clearLastMedian() {
            if (!this->data.empty()) {
                this->data.clear();
            }
        }

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

        void autoTestMedian() {
            std::string s;
            double num;
            int lineCounter = 0;
            std::ifstream myFile;
            // open file and run tests
            myFile.open("test.txt");
            if (!myFile) {
                std::cout << "File not created!";
            }
            else {
                //Read every line and parse
                while (std::getline(myFile, s)) {
                    std::istringstream lineIn(s);
                    std::cout << "readed nunmbers: " << s << std::endl;
                    while (lineIn >> num) {
                        if (lineCounter % 2 == 0) {
                            addNumber(num);
                        }
                        else {
                            if (num == printMedian()) {
                                std::cout << "true" << std::endl;
                                clearLastMedian();
                            }
                            else {
                                std::cout << "false" << " correct answer is " << num << std::endl;
                                clearLastMedian();
                            }
                        }
                    }
                    lineCounter++;
                }
                myFile.close();
            }
        }
    };
} // namespase Median