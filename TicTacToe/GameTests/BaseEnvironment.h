#pragma once

#include <gtest/gtest.h>

class BaseEnvironment : public ::testing::Environment
{
	void SetUp();
	void TearDown();
};