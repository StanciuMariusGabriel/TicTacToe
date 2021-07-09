// Copyright (C) 2019-2021, General Magic B.V.
// All rights reserved.
//
// This software is confidential and proprietary information of General Magic
// ("Confidential Information"). You shall not disclose such Confidential
// Information and shall use it only in accordance with the terms of the
// license agreement you entered into with General Magic.

//#include "Platform/PlatformDll.h"

#include <gtest/gtest.h>

#include <iostream>

struct MyStruct
{
	const char* fileName;
};

class RouteFileEncoderTestSuite : public ::testing::Test, public ::testing::WithParamInterface<MyStruct>
{
	void SetUp() override
	{
		std::cout << "SetUp() called\n";
	}
	void TearDown() override
	{
		std::cout << "TearDown() called\n";
	}
};

TEST_P( RouteFileEncoderTestSuite, TestParametrized1 )
{
	std::cout << "TestParametrized1 entered\n";
	std::cout << GetParam().fileName << std::endl;
}

TEST_P( RouteFileEncoderTestSuite, TestParametrized2 )
{
	std::cout << "TestParametrized2 entered\n";
	std::cout << GetParam().fileName << std::endl;
}

INSTANTIATE_TEST_SUITE_P(
	RouteFileEncoderTest,
	RouteFileEncoderTestSuite,
	::testing::Values(
		MyStruct{ "Param 1" }
		, MyStruct{ "Param 2" }
) );
