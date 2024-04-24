// PHYS 30762 Final Assignement C++ 
// Student ID: 10457059
// April 2022

/* 
---------------------------------------------------------------------------------------------------------
The code asks the user for an initial distribution of creatures and simulates the evolution of the
 ecosystem. Then, it plots the evolution on the number of creatures, average health and average speed
 of each specie.
 --------------------------------------------------------------------------------------------------------
 */

#include "foodchain.h"

int main()
{
	 std::vector<std::vector<std::vector<int>>> variables{ event_loop() };
	plot_variables(variables[0], variables[1], variables[2]);
	
	return 0;
}