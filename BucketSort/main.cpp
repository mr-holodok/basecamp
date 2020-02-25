#include <iostream>
#include <sstream>
#include "BucketSorter.h"

int main() {
    std::cout
            << "Please enter floating point numbers to sort them with bucket sort. Mark end of input with  < 0> (space and zero)"
            << std::endl;
    std::string input;
    getline(std::cin, input);

    std::stringstream input_stream(input);

    BucketSorter bucketSorter = BucketSorter(101);

    float num = -1;

    // assume that the input is correct and contains only nums [ floats have point x.x ] and spaces
    input_stream >> num;
    while (num) { // num != 0
        bucketSorter.add(num);
        input_stream >> num;
    }

    std::cout << "Sorted elements: " << std::endl;
    bucketSorter.sort();
    std::vector<float> *vec = bucketSorter.get_values();
    for (auto elem : *vec)
        std::cout << elem << " ";
    delete vec;
    std::cout << std::endl;
    std::cout << "Max collision count is: " << bucketSorter.get_max_collisions() << std::endl;
    return 0;
}
