// File that contains useful features for the code, defined in utilities.h

#include <random>
#include <chrono>
#include <array>
#include <filesystem>
#include "gnuplot-iostream.h"
#include "CImg.h"
#include "utilities.h"

namespace {

std::mt19937& random_generator()
{
	static std::mt19937 generator(std::random_device{}());
	return generator;
}

const std::array<std::string, 10> species_names{
	"Plants", "Grasshoppers", "Mice", "Rabbits", "Frogs",
	"Birds", "Snakes", "Foxes", "Hawks", "Owls"
};

const std::array<std::string, 10> species_colors{
	"#A9E190", "#4E6151", "#808080", "#7F4F24", "#297045",
	"#CCCC00", "#1C3628", "#FC9E4F", "#66151D", "#7987F4"
};

void configure_plot(Gnuplot& gp, const std::string& output_path, const std::string& title,
	const std::string& y_label, std::size_t series_count, std::size_t species_offset)
{
	gp << "set terminal pngcairo enhanced size 1600,900 font 'DejaVu Sans,12'\n";
	gp << "set output '" << output_path << "'\n";
	gp << "set title '" << title << "' tc rgb '#1F2937' font ',18'\n";
	gp << "set xlabel 'Generation' tc rgb '#374151'\n";
	gp << "set ylabel '" << y_label << "' tc rgb '#374151'\n";
	gp << "set key outside right top box opaque width 2 textcolor rgb '#374151'\n";
	gp << "set border lw 1.4 lc rgb '#9CA3AF'\n";
	gp << "set tics textcolor rgb '#4B5563'\n";
	gp << "set grid xtics ytics lc rgb '#D8D2C6' lw 1\n";
	gp << "set lmargin 10\n";
	gp << "set rmargin 26\n";
	gp << "set tmargin 3\n";
	gp << "set bmargin 5\n";
	gp << "set yrange [0:*]\n";
	gp << "set object 1 rectangle from screen 0,0 to screen 1,1 "
		<< "fillcolor rgb '#FBF8F1' fillstyle solid 1.0 noborder behind\n";
	gp << "set object 2 rectangle from graph 0,0 to graph 1,1 "
		<< "fillcolor rgb '#F5EFE4' fillstyle solid 1.0 noborder behind\n";

	for (std::size_t i{}; i < series_count; ++i)
	{
		gp << "set style line " << (i + 1)
			<< " lc rgb '" << species_colors[i + species_offset]
			<< "' lw 2.8\n";
	}
}

template <std::size_t N>
void plot_series(Gnuplot& gp, const std::array<std::string, N>& labels,
	const std::vector<std::vector<int>>& values, std::size_t species_offset = 0)
{
	gp << "plot ";

	for (std::size_t i{}; i < values.size(); ++i)
	{
		gp << "'-' with lines ls " << (i + 1) << " title '" << labels[i + species_offset] << "'";
		if (i + 1 != values.size())
			gp << ", ";
	}
	gp << "\n";

	for (const auto& dataset : values)
		gp.send(dataset);

	gp << "unset output\n";
}

}

// Function that returns a random integer between a range. It follows a uniform distribution
int uniform_int(int initial_range, int final_range)
{
	std::uniform_int_distribution<int> dist(initial_range, final_range);
	return dist(random_generator());
}

// Function that returns a random integer between a range, where the input is the mean
// It follows a gaussian distribution
int gaussian_int(int mean)
{
	std::normal_distribution<double> dist(mean, 3);
	return static_cast<int>(dist(random_generator()));
}

// Function to plot the three variables and display them in a new window
void plot_variables(std::vector<std::vector<int>> population, std::vector<std::vector<int>> average_health,
	std::vector<std::vector<int>> average_speed)
{
	std::filesystem::create_directories("plots");

	const std::string population_plot{ "plots/population_vs_generation.png" };
	const std::string health_plot{ "plots/average_health_vs_generation.png" };
	const std::string speed_plot{ "plots/average_speed_vs_generation.png" };

	Gnuplot gp;
	Gnuplot gp2;
	Gnuplot gp3;

	configure_plot(gp, population_plot, "Population by Species", "Creatures", population.size(), 0);
	plot_series(gp, species_names, population);

	configure_plot(gp2, health_plot, "Average Maximum Health by Species", "Average Max Health",
		average_health.size(), 1);
	plot_series(gp2, species_names, average_health, 1);

	configure_plot(gp3, speed_plot, "Average Speed by Species", "Average Speed",
		average_speed.size(), 1);
	plot_series(gp3, species_names, average_speed, 1);

	std::cout << "Saved plots to:" << std::endl;
	std::cout << "  " << population_plot << std::endl;
	std::cout << "  " << health_plot << std::endl;
	std::cout << "  " << speed_plot << std::endl;
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
	std::vector<int> inputs{ check_input() };

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
