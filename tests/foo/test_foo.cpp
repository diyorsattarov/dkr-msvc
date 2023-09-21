#include <gtest/gtest.h>
#include <foo/foo.h>

TEST(TestTest, TestTest) {
    ASSERT_EQ(1,1);
}

class FooTest : public ::testing::Test {
protected:
    Foo foo;

    void SetUp() override {
        foo = Foo(1);
    }
};

TEST_F(FooTest, TestFoo) {
	ASSERT_EQ(foo.getValue(), 1);
    foo.setValue(2);
    ASSERT_EQ(foo.getValue(), 2);
}