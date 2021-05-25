#include<fstream>
#include <gtest/gtest.h>
// Demonstrate some basic assertions.
TEST(dequeue_stl, test_case_01) {
    std::ifstream outp("../test_cases/test_case_01.output");
    std::stringstream output;
    output << outp.rdbuf();
    std::ifstream ref("../test_cases/test_case_01.ref");
    std::stringstream output_ref;
    output_ref << ref.rdbuf();
    EXPECT_EQ(0, output.str()!=output_ref.str());
    outp.close();
    ref.close();
}