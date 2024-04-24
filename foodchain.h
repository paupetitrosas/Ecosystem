// File that contains all the declarations of classes for the code

#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <memory>
#include <limits>
#include "CImg.h" 
#include "utilities.h"

// Class declarations

// Creature class: base class from which all types of creatures will be derived. All the entities
// in the ecosystem are of this form.
class creature
{
	bool operator!=(creature& other) const;
public:
	virtual ~creature() {};

	virtual std::pair<int, int> get_position() = 0;
	virtual std::vector<int> get_color() = 0;
	virtual int get_speed() = 0;
	virtual int get_id_number() = 0;
	virtual int get_health() = 0;
	virtual int get_max_health() = 0;
	virtual std::vector<int> get_eats() = 0;
	virtual int get_number_creature() = 0;

	virtual void set_health(int new_health) = 0;
	virtual void has_eaten_push_data(bool data) = 0;

	virtual void starvation() = 0;
	virtual void move() = 0;
	virtual void age() = 0;
};


// Plant class: derived class of creature, the plants do not move nor reproduce, 
// but when any creature dies there is a 50% chance a new plant appears.
class plant : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 169,225,144 };

	// Each species has a characteristic longevity and speed
	int species_health{ 20000 };
	int speed{ 0 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Unique number to identify each subspecie of creature
	int id_number{ 1 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 0 };

	static int number_plants;

public:
	plant();
	~plant() { number_plants--; color.clear(); has_eaten.clear(); eats.clear(); }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return 0; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_plants; }

	void set_health(int new_health) { health = new_health; }

	void starvation() {}
	void has_eaten_push_data(bool data) {}
	void move() {}
	void age() { health -= 1; }
};

// Grasshopper class: derived class of creature, grasshoppers eat plants and are eaten by birds
// and frogs
class grasshopper : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 78,97,81 };

	// Each species has a characteristic longevity and speed
	int species_health{ 100 };
	int species_speed{ 3 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 2 };

	// Vector with the id number of the species this creature can eat 
	std::vector<int> eats = { 1 };

	static int number_grasshoppers;
public:
	grasshopper();
	grasshopper(int parents_max_health, int parents_speed);
	~grasshopper() { color.clear(); has_eaten.clear(); eats.clear(); number_grasshoppers--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_grasshoppers; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Mouse class: derived class of creatures, mice eat plants and are eaten by foxes, hawks and owls
class mouse : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 237,227,233 };

	// Each species has a characteristic longevity and speed
	int species_health{ 110 };
	int species_speed{ 5 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 3 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 1 };

	static int number_mice;

public:
	mouse();
	mouse(int parents_max_health, int parents_speed);
	~mouse() { color.clear(); has_eaten.clear(); eats.clear(); number_mice--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_mice; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Rabbit class: derived class of creatures, rabbit eat plants and are eaten by hawks and foxes
class rabbit : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 127,79,36 };

	// Each species has a characteristic longevity and speed
	int species_health{ 130 };
	int species_speed{ 6 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 4 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats{ 1 };

	static int number_rabbits;

public:
	rabbit();
	rabbit(int parents_max_health, int parents_speed);
	~rabbit() { color.clear(); has_eaten.clear(); eats.clear(); number_rabbits--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_rabbits; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Frog class: derived class of creature, frogs eat grasshoppers and are eaten by snakes and owls
class frog : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 41,112,69 };

	// Each species has a characteristic longevity and speed
	int species_health{ 140 };
	int species_speed{ 4 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 5 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 2 };

	static int number_frogs;

public:
	frog();
	frog(int parents_max_health, int parents_speed);
	~frog() { color.clear(); has_eaten.clear(); eats.clear(); number_frogs--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_frogs; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Bird class: derived class of creature, birds eat grasshoppers and are eaten by snakes
class bird : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 255,253,152 };

	// Each species has a characteristic longevity and speed
	int species_health{ 120 };
	int species_speed{ 8 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 6 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 2 };

	static int number_birds;

public:
	bird();
	bird(int parents_max_health, int parents_speed);
	~bird() { color.clear(); has_eaten.clear(); eats.clear(); number_birds--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_birds; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Snake class: derived class of creature, snakes eat birds and frogs
class snake : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 28,54,40 };

	// Each species has a characteristic longevity and speed
	int species_health{ 130 };
	int species_speed{ 7 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 7 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 5,6 };

	static int number_snakes;

public:
	snake();
	snake(int parents_max_health, int parents_speed);
	~snake() { color.clear(); has_eaten.clear(); eats.clear(); number_snakes--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_snakes; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Fox class: derived class of creature, foxes eat mice and rabbits
class fox : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 252,158,79 };

	// Each species has a characteristic longevity and speed
	int species_health{ 130 };
	int species_speed{ 11 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 8 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 3,4 };

	static int number_foxes;

public:
	fox();
	fox(int parents_max_health, int parents_speed);
	~fox() { color.clear(); has_eaten.clear(); eats.clear(); number_foxes--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_foxes; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Hawk class: derived class of creature, hawks eat rabbits and mice
class hawk : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 102,21,29 };

	// Each species has a characteristic longevity and speed
	int species_health{ 140 };
	int species_speed{ 9 };

	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 9 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 3,4,7 };

	static int number_hawks;

public:
	hawk();
	hawk(int parents_max_health, int parents_speed);
	~hawk() { color.clear(); has_eaten.clear(); eats.clear(); number_hawks--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_hawks; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};

// Owl class: derived class of creature, owls eat frogs.
class owl : public creature
{
protected:
	std::pair<int, int> position;
	std::vector<int> color = { 121,135,244 };

	// Each species has a characteristic longevity and speed
	int species_health{ 120 };
	int species_speed{ 10 };


	// The actual health of each creature and its maximum
	int health{};
	int max_health{};

	// The actual speed of the creature
	int speed{};

	// Vector to track if the cretaure has eaten
	std::vector<bool> has_eaten{};

	// Number to identify each type of cretaure
	int id_number{ 10 };

	// Vector with the id number of the species this creature can eat
	std::vector<int> eats = { 3,5 };

	static int number_owls;

public:
	owl();
	owl(int parent_max_health, int parents_speed);
	~owl() { color.clear(); has_eaten.clear(); eats.clear(); number_owls--; }

	std::pair<int, int> get_position() { return position; }
	std::vector<int> get_color() { return color; }
	int get_speed() { return speed; }
	int get_id_number() { return id_number; }
	int get_health() { return health; }
	int get_max_health() { return max_health; }
	std::vector<int> get_eats() { return eats; }
	int get_number_creature() { return number_owls; }

	void set_health(int new_health) { health = new_health; }
	void has_eaten_push_data(bool data) { has_eaten.push_back(data); }

	void starvation();
	void move();
	void age() { health -= 1; }
};


// Rectangle class. The rectangles are created from their middle point, (x,y), and their width
// and height are the distance from the middle point to the edges.
class rectangle
{
protected:
	int x;
	int y;
	int width;
	int height;
public:
	rectangle();
	rectangle(int x_in, int y_in, int width_in, int height_in);
	~rectangle() {};

	int get_width() { return width; }
	int get_height() { return height; }
	int get_x() { return x; }
	int get_y() { return y; }

	bool contains_point(std::pair<int,int> point);
	bool intersects(rectangle range);
};

// Quadtree class. Quadtrees are used to make the search for posible intersections of creatures
// much more efficently.
class quadtree
{
protected:
	// Tells if the quadtree has divided
	bool has_divided{ false };

	// Maximum amount of points the quadtree can store 
	int capacity{ 2 };

	// The boundary of the quadtree is a rectangle. 
	//It represents the amount of screen the quadtree covers
	rectangle boundary;

	// Stored points
	std::vector<std::shared_ptr<creature>> points;

	// Each quadtree can subdivide in four other quadtrees
	std::shared_ptr<quadtree> topleft;
	std::shared_ptr<quadtree> topright;
	std::shared_ptr<quadtree> bottomleft;
	std::shared_ptr<quadtree> bottomright;
public:
	quadtree() {}
	quadtree(rectangle rec) { boundary = rec; }
	~quadtree() { points.clear(); }

	void split();
	void insert(std::shared_ptr<creature> point);

	std::vector<std::shared_ptr<creature>> query(rectangle range,
		std::vector<std::shared_ptr<creature>> found);

	cimg_library::CImg<unsigned char> show(cimg_library::CImg<unsigned char> image);
};


// Ecosystem class. This class stores all the creatures of the system and makes them interact
class ecosystem
{
	
private:
	int deaths{};
	std::vector<std::shared_ptr<creature>> creatures;
public:
	ecosystem() {};
	ecosystem(int num_plants, int num_grasshoppers, int num_mice, int num_rabbits,
		int num_frogs, int num_birds, int num_snakes, int num_foxes, int hawks, int num_owls);
	~ecosystem() { creatures.clear(); }

	int number_creatures() { return creatures.size(); }

	cimg_library::CImg<unsigned char> display(cimg_library::CImg<unsigned char> image);
	cimg_library::CImg<unsigned char> draw_text(cimg_library::CImg<unsigned char> image);

	std::vector<std::shared_ptr<creature>> reproduce(quadtree qdtree);
	int num_creature(int id);

	quadtree create_tree();

	void plant_generation();
	void evolve();
	void kill_half();

	std::vector<int> average_health_speed(int id);
};