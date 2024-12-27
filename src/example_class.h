/*!
 * Copyright (c) 2024 cpp11_ptr_reprex authors. All rights reserved.
 * Licensed under the MIT License. See LICENSE file in the project root for license information.
 */
#ifndef EXAMPLE_CLASS_H_
#define EXAMPLE_CLASS_H_

#include <iostream>
#include <memory>
#include <random>

/*!
 * \brief Simple "data" object with data randomly generated at initialization.
 * ExampleClass will contain a vector of smart pointers to DataObject elements.
 */
class DataObject {
public:
    DataObject() {
        // Setup RNGs
        std::random_device rd;
        std::poisson_distribution<int> poisson_dist;
        std::normal_distribution<double> normal_dist;
        // Generate data
        a_ = normal_dist(rd);
        b_ = normal_dist(rd);
        c_ = normal_dist(rd);
        d_ = poisson_dist(rd);
        e_ = poisson_dist(rd);
        f_ = normal_dist(rd);
        g_ = normal_dist(rd);
        h_ = poisson_dist(rd);
    }
    ~DataObject() {}
private:
    double a_;
    double b_;
    double c_;
    int d_;
    int e_;
    double f_;
    double g_;
    int h_;
};

class ExampleClass {
public:
    ExampleClass(int vec_size) {
        data_ = std::vector<std::unique_ptr<DataObject>>(vec_size);
        for (int i = 0; i < vec_size; i++) {
            data_[i].reset(new DataObject());
        }
        vec_size_ = vec_size;
    }
    ~ExampleClass() {}
private:
    std::vector<std::unique_ptr<DataObject>> data_;
    int vec_size_;
};

#endif // EXAMPLE_CLASS_H_
