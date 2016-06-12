#pragma once
#include "Real.h"


Real::Real()
{
}

Real::Real(float v)
{
	tokenTag = Tag::REAL;
	value = v;
}

Real::~Real()
{
}

std::string Real::toString()
{
	return "REAL-> value: " + std::to_string(value) + "  token: " + std::to_string(tokenTag);
}