#include <gtest/gtest.h>
#include <sstream>
#include <bar/bar.h>

class BarTest : public ::testing::Test {
protected:
    Bar bar;

    void SetUp() override {
        bar = Bar(1);
    }

    std::string captureStdout() {
        testing::internal::CaptureStdout();
        bar.doSomething();
        std::string output = testing::internal::GetCapturedStdout();
        return output;
    }
};

TEST_F(BarTest, TestBar) {
	ASSERT_EQ(bar.getValue(), 1);
	bar.setValue(2);
	ASSERT_EQ(bar.getValue(), 2);

    std::string output = captureStdout();

    std::string expectedOutput = "Bar is doing something!\n";
    EXPECT_EQ(output, expectedOutput);
}