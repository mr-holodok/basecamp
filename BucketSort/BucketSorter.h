//
// Created by mukola on 24.02.20.
//

#ifndef BUCKETSORT_BUCKETSORTER_H
#define BUCKETSORT_BUCKETSORTER_H

#include <list>
#include <vector>

class BucketSorter {
public:
    explicit BucketSorter(unsigned int capacity) : m_capacity{capacity}, m_buckets{ new std::list<float>[capacity] } {};
    ~BucketSorter();
    void add(const float &value);
    void sort();
    std::vector<float>* get_values() const;
    bool check(const float &value) const;
    unsigned int get_max_collisions() const;
private:
    std::list<float> *m_buckets;// = new std::list<float>[100];
    unsigned int m_capacity;

    unsigned int get_index(const float &value) const;
};


#endif //BUCKETSORT_BUCKETSORTER_H
