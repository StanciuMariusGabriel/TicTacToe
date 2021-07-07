#include "gtest/gtest.h"


int main(int argc, char** argv)
{
	// http://google.github.io/googletest/primer.html

	::testing::InitGoogleTest(&argc, argv);

	int res = RUN_ALL_TESTS();

	return res;
}