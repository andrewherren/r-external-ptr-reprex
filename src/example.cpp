#include <cpp11.hpp>
#include "example_class.h"
#include <memory>

[[cpp11::register]]
cpp11::external_pointer<ExampleClass> create_example_class_cpp(int vec_size) {
    // Create smart pointer to newly allocated object
    std::unique_ptr<ExampleClass> example_ptr_ = std::make_unique<ExampleClass>(vec_size);

    // Release management of the pointer to R session
    return cpp11::external_pointer<ExampleClass>(example_ptr_.release());
}

[[cpp11::register]]
void delete_example_class_cpp(cpp11::external_pointer<ExampleClass> example_ptr) {
    ExampleClass* released_ptr = example_ptr.release();
    delete released_ptr;
}
