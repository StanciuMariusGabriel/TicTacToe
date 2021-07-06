#pragma once

class Strategy
{
public:
	virtual ~Strategy() = default;

	virtual void ComputerMove() = 0;
};