library(cpp11example)

# Create an initial Example class
my_example <- createExample(100)

# Check whether C++ destructors are run when class is overwritten
my_example <- createExample(100)

# Check whether C++ destructors are run when class is removed
rm(my_example)

# Check whether C++ destructors are run after gc()
# gc()
