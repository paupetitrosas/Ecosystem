// Entry point for the ecosystem simulation.
//
// The program collects an initial population, runs the simulation,
// and then plots population, health, and speed trends.

#include "foodchain.h"

int main()
{
	 std::vector<std::vector<std::vector<int>>> variables{ event_loop() };
	plot_variables(variables[0], variables[1], variables[2]);
	
	return 0;
}
