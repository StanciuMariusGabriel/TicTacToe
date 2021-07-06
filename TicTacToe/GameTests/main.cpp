#include "gtest/gtest.h"
#include "BaseEnvironment.h"

::testing::Environment* env;

int main(int argc, char** argv)
{
	// http://google.github.io/googletest/primer.html

	::testing::InitGoogleTest(&argc, argv);

	env = new BaseEnvironment();
	::testing::AddGlobalTestEnvironment(env);

	int res = RUN_ALL_TESTS();

	return res;
}