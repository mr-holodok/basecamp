//
// Created by mukola on 24.02.20.
//

#include <math.h>
#include <stdexcept>
#include <algorithm>
#include "BucketSorter.h"

std::vector<float>* BucketSorter::get_values() const {
    std::vector<float> *v = new std::vector<float>();
    for (int i = 0; i < m_capacity; ++i)
        for (auto num : m_buckets[i])
            v->push_back(num);

        return v;
}

void BucketSorter::sort() {
    for (int i = 0; i < m_capacity; ++i)
        m_buckets[i].sort();
}

void BucketSorter::add(const float &value) {
    uint ind = get_index(value);
    m_buckets[ind].push_back(value);
}

bool BucketSorter::check(const float &value) const {
    uint ind = get_index(value);
    auto it = std::find(m_buckets[ind].begin(), m_buckets[ind].end(), value);
    return (it != m_buckets[ind].end());
}

unsigned int BucketSorter::get_index(const float &value) const {
    if (floor(value) >= m_capacity)
        throw std::invalid_argument("Value is out of the Bucket supported range!");
    return floor(value);
}

BucketSorter::~BucketSorter() {
    delete[] m_buckets;
}

unsigned int BucketSorter::get_max_collisions() const {
    uint count = 0;
    for (int i = 0; i < m_capacity; ++i)
        if (m_buckets[i].size() > count)
            count = m_buckets[i].size();
    return count;
}
