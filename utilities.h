// File that contains the definition of all global variables and
// all functions used in the code
#pragma once

#include "foodchain.h"

// Global variables
const unsigned int screen_width{ 1365 };
const unsigned int screen_height{ 700 };
const int creature_width{ 4 };
const int creature_height{ 4 };

const unsigned char white[] = { 255,255,255 };
const unsigned char black[] = { 0,0,0 };
const unsigned char color_plant[] = { 169,225,144 };
const unsigned char color_grasshopper[] = { 78,97,81 };
const unsigned char color_mouse[] = { 237,227,233 };
const unsigned char color_rabbit[] = { 127,79,36 };
const unsigned char color_frog[] = { 41,112,69 };
const unsigned char color_bird[] = { 255,253,152 };
const unsigned char color_snake[] = { 28,54,40 };
const unsigned char color_fox[] = { 252,158,79 };
const unsigned char color_hawk[] = { 102,21,29 };
const unsigned char color_owl[] = { 121,135,244 };


// Use a namespace to patch the function to_string from standard library
namespace patch
{
	template < typename T > std::string to_string(const T& integer)
	{
		std::ostringstream ostring;
		ostring << integer;
		return ostring.str();
	}
}

// Template to check for valid inputs
template <typename T>
std::vector<int> check_input(T model_input)
{
	T input;
	std::vector<int> vector;
	std::vector<std::string> creatures{ "Plants: ","Grasshoppers: ","Mice: ","Rabbits: ",
		"Frogs: ","Birds: ", "Snakes: ","Foxes: ","Hawks: ", "Owls: " };

	std::cout << "Please, enter the number of" << std::endl;

	for (int i{}; i < 10; i++)
	{
		for (;;)
		{
			std::cout << creatures[i];
			std::cin >> input;

			if (std::cin.fail())
			{
				// Prompts that there was an error with the input and then loops again
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				std::cout << "Invalid input, please try again" << std::endl;
			}
			// if valid input then for loop breaks
			else
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				vector.push_back(input);
				break;
			}
		}
	}
	return vector;
}


// Useful functions, expanded in utilities.cpp
int uniform_int(int initial_range, int final_range);
int gaussian_int(int mean);
void plot_variables(std::vector<std::vector<int>> population, std::vector<std::vector<int>> avergae_health,
	std::vector<std::vector<int>> average_speed);

std::string make_text(std::string string, int variable);

cimg_library::CImg<unsigned char> draw_legend(cimg_library::CImg<unsigned char> image, int generation,
	double time);
cimg_library::CImg<unsigned char> draw_button(cimg_library::CImg<unsigned char> image);

cimg_library::CImg<unsigned char> game_over(cimg_library::CImg<unsigned char> image);

std::vector<std::vector<std::vector<int>>> event_loop();