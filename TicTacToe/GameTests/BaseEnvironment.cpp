#include "BaseEnvironment.h"

#include <iostream>
using namespace std;

void BaseEnvironment::SetUp()
{
	cout << "BaseEnvironment::SetUp" << endl;
}

void BaseEnvironment::TearDown()
{
	cout << "BaseEnvironment::TearDown" << endl;
}