// File that contains useful features for the code, defined in utilities.h

#include <random>
#include <chrono>
#include "gnuplot-iostream.h"
#include "CImg.h"
#include "utilities.h"

// Function that returns a random integer between a range. It follows a uniform distribution
	int uniform_int(int initial_range, int final_range)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(initial_range, final_range);
		return dist(rng);
	}

// Function that returns a random integer between a range, where the input is the mean
// It follows a gaussian distribution
int gaussian_int(int mean)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::normal_distribution<double> dist(mean, 3);
	return dist(rng);
}

// Function to plot the three variables and display them in a new window
void plot_variables(std::vector<std::vector<int>> population, std::vector<std::vector<int>> average_health,
	std::vector<std::vector<int>> average_speed)
{
	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");
	Gnuplot gp2("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");
	Gnuplot gp3("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");

	gp << "set title 'Creature number vs generation'\n";
	gp << "set ylabel 'Creatures'\n";
	gp << "set xlabel 'Generation'\n";

	gp << "plot '-' title 'Plants' with lines lc '#A9E190',"
		<< "'-' title 'Grasshoppers' with lines lc '#4E6151',"
		<< "'-' title 'Mice' with lines lc '#808080',"
		<< "'-' title 'Rabbits' with lines  lc '#7F4F24',"
		<< "'-' title 'Frogs' with lines lc '#297045',"
		<< "'-' title 'Birds' with lines lc '#CCCC00',"
		<< "'-' title 'Snakes' with lines lc '#1C3628',"
		<< "'-' title 'Foxes' with lines lc '#FC9E4F',"
		<< "'-' title 'Hawks' with lines lc '#66151D',"
		<< "'-' title 'Owls' with lines lc '#7987F4'\n";

	// Hardcoded, instead of using a for loop, to ensure the
	// gnuplot machine recognizes it
	gp.send(population[0]);
	gp.send(population[1]);
	gp.send(population[2]);
	gp.send(population[3]);
	gp.send(population[4]);
	gp.send(population[5]);
	gp.send(population[6]);
	gp.send(population[7]);
	gp.send(population[8]);
	gp.send(population[9]);


	gp2 << "set title 'Avergae health vs generation'\n";
	gp2 << "set ylabel 'Average max health'\n";
	gp2 << "set xlabel 'Generation'\n";
	gp2 << "plot '-' title 'Grasshoppers' with lines lc '#4E6151',"
		<< "'-' title 'Mice' with lines lc '#808080',"
		<< "'-' title 'Rabbits' with lines  lc '#7F4F24',"
		<< "'-' title 'Frogs' with lines lc '#297045',"
		<< "'-' title 'Birds' with lines lc '#CCCC00',"
		<< "'-' title 'Snakes' with lines lc '#1C3628',"
		<< "'-' title 'Foxes' with lines lc '#FC9E4F',"
		<< "'-' title 'Hawks' with lines lc '#66151D',"
		<< "'-' title 'Owls' with lines lc '#7987F4'\n";

	// Hardcoded, instead of using a for loop, to ensure the
	// gnuplot machine recognizes it
	gp2.send(average_health[0]);
	gp2.send(average_health[1]);
	gp2.send(average_health[2]);
	gp2.send(average_health[3]);
	gp2.send(average_health[4]);
	gp2.send(average_health[5]);
	gp2.send(average_health[6]);
	gp2.send(average_health[7]);
	gp2.send(average_health[8]);


	gp3 << "set title 'Average speed vs generation'\n";
	gp3 << "set xlabel 'Generation'\n";
	gp3 << "set ylabel 'Average speed'\n";
	gp3 << "plot '-' title 'Grasshoppers' with lines lc '#4E6151',"
		<< "'-' title 'Mice' with lines lc '#808080',"
		<< "'-' title 'Rabbits' with lines  lc '#7F4F24',"
		<< "'-' title 'Frogs' with lines lc '#297045',"
		<< "'-' title 'Birds' with lines lc '#CCCC00',"
		<< "'-' title 'Snakes' with lines lc '#1C3628',"
		<< "'-' title 'Foxes' with lines lc '#FC9E4F',"
		<< "'-' title 'Hawks' with lines lc '#66151D',"
		<< "'-' title 'Owls' with lines lc '#7987F4'\n";

	// Hardcoded, instead of using a for loop, to ensure the
	// gnuplot machine recognizes it
	gp3.send(average_speed[0]);
	gp3.send(average_speed[1]);
	gp3.send(average_speed[2]);
	gp3.send(average_speed[3]);
	gp3.send(average_speed[4]);
	gp3.send(average_speed[5]);
	gp3.send(average_speed[6]);
	gp3.send(average_speed[7]);
	gp3.send(average_speed[8]);

	// Ask for an input to ensure the prgram doesn't close right after plotting the variables
	int a;
	std::cin >> a;
}

// Function to put together a string with an integer, using the namspace patch
std::string make_text(std::string string, int variable)
{
	std::string string_1{ patch::to_string(variable) };
	std::string string_2{ string + string_1 };

	return string_2;
}

// Function to draw the legend in the system
cimg_library::CImg<unsigned char> draw_legend(cimg_library::CImg<unsigned char> image, int generation,
	double time)
{
	// Draw the legend
	image.draw_rectangle(0, 0, 250, 350, black, 1);
	image.draw_rectangle(200, 75, 225, 100, color_plant);
	image.draw_rectangle(200, 100, 225, 125, color_grasshopper);
	image.draw_rectangle(200, 125, 225, 150, color_mouse);
	image.draw_rectangle(200, 150, 225, 175, color_rabbit);
	image.draw_rectangle(200, 175, 225, 200, color_frog);
	image.draw_rectangle(200, 200, 225, 225, color_bird);
	image.draw_rectangle(200, 225, 225, 250, color_snake);
	image.draw_rectangle(200, 250, 225, 275, color_fox);
	image.draw_rectangle(200, 275, 225, 300, color_hawk);
	image.draw_rectangle(200, 300, 225, 325, color_owl);
	image.draw_line(0, 350, 250, 350, white);
	image.draw_line(250, 0, 250, 350, white);

	std::string string{ make_text("Generation: ", generation) };
	std::string string_1{ make_text("Time:", time) + " ms" };

	const char* text_1{ string.c_str() };
	const char* text_2{ string_1.c_str() };

	image.draw_text(0, 0, text_1, white, black, 1, 25);
	image.draw_text(0, 25, text_2, white, black, 1, 25);

	return image;
}

// Function to draw the button in the system
cimg_library::CImg<unsigned char> draw_button(cimg_library::CImg<unsigned char> image)
{
	std::string string2{ "E kill 1/2 of the population" };

	const char* text{ string2.c_str() };

	image.draw_rectangle(screen_width - 310, 0, screen_width, 50, black);
	image.draw_line(screen_width - 310, 0, screen_width - 310, 50, white);
	image.draw_line(screen_width - 310, 50, screen_width, 50, white);
	image.draw_text(screen_width - 290, 12, text, white, black, 1, 25);

	return image;
}

// Function that triggers when there are no creatures left
cimg_library::CImg<unsigned char> game_over(cimg_library::CImg<unsigned char> image)
{
	std::string string2{ "Press ESC or close this window to plot the results of the simulation" };

	const char* text{ string2.c_str() };

	image.draw_text(100, screen_height / 2, text, white, black, 1, 40);
	return image;
}

// Function that displays the ecosystem and takes care of the event loop
std::vector<std::vector<std::vector<int>>> event_loop()
{
	// Ask the user for inputs
	int i{};
	std::vector<int> inputs{ check_input(i) };

	// Initialize the ecosystem with the amount of creatures desired
	ecosystem eco(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5],
		inputs[6], inputs[7], inputs[8], inputs[9]);

	// Initialize vectors that will track variables to latter be plotted
	int generation{};
	std::vector<std::vector<int>> population{ {},{},{},{},{},{},{},{},{},{} };
	std::vector<std::vector<int>> average_health{ {},{},{},{},{},{},{},{},{} };
	std::vector<std::vector<int>> average_speed{ {},{},{},{},{},{},{},{},{} };
	

	// Create the background and window for the display
	cimg_library::CImg<unsigned char> image(screen_width, screen_height, 1, 3, 0);
	cimg_library::CImgDisplay display(screen_width, screen_height, "Evolution");


	// Event loop
	while (!display.is_closed() && !display.is_keyESC())
	{
		if (display.is_resized())
			display.resize().display(image);

		auto start = std::chrono::high_resolution_clock::now();

		// Display the ecosystem
		image = eco.display(image);

		// Update the ecosystem
		eco.evolve();

		// Stop the chronometer to print the time it has taken for the computer to compute
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

		// Draw the legend, the generation and the amount of time taken to process each gen
		image = draw_legend(image, generation, duration.count() / 1000);

		// Draw the amount of creatures in the system
		image = eco.draw_text(image);

		// Draw the button
		image = draw_button(image);

		// Check if button is pressed
		if (display.is_keyE())
			eco.kill_half();

		// Push back the data that will later be plotted
		for (int i{}; i < 10; i++)
		{
			population[i].push_back(eco.num_creature(i + 1));
			std::vector<int> av_health_speed{ eco.average_health_speed(i + 1) };
			if (i > 0)
			{
				average_health[i - 1].push_back(av_health_speed[0]);
				average_speed[i - 1].push_back(av_health_speed[1]);
			}
			av_health_speed.clear();
		}

		// Display the image and erase it
		display.display(image);
		image.fill(0);

		generation += 1;

		if (eco.number_creatures() == 0)
		{
			image = game_over(image);
		}
	}

	// Store the data that will be plotted and return them
	std::vector<std::vector<std::vector<int>>> variables;
	variables.push_back(population);
	variables.push_back(average_health);
	variables.push_back(average_speed);

	return variables;
}