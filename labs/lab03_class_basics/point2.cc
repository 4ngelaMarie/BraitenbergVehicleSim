#include <cmath>
#include <iostream>

#include "point2.h"

Point2::Point2( float x, float y) {
  position_[0] = x;
  position_[1] = y;
}

float Point2::DistanceBetween( Point2 cluster){
	//pythagrean thm
	float distance = sqrt(pow((position_[0] - cluster.position_[0]), 2.0) 
	+ pow((position_[1] - cluster.position_[1]), 2.0));
	
	return distance; 
}

void Point2::Print() {
  std::cout
  << "[" << position_[0] << ", " << position_[1] << "]"<< std::endl;
}

int Point2::Quadrant() {
	if (position_[0] == 0 && position_[1] == 0)
	{	
		return 0; } //origin
	else if (position_[0] >= 0)
	{
		if (position_[0] == 0) //borders
		{
			if (position_[1] > 0)
			{ 
				return 2; } 
			else
			{ 
				return 4;}
		}
		else if (position_[1] >= 0)
		{
			return 1; } //border and common case
		else 
		{ 
			return 4; }
	}
	else
	{
		if (position_[1] == 0) //border
		{	
			return 3; }
		else if (position_[1] > 0)
		{
			return 2; }
		else
		{
			return 3; }
	}
}
