// File that contains all the definition of functions declared in the .h file

#include <unordered_map>

#include "foodchain.h"

namespace {

std::shared_ptr<creature> make_offspring(const std::shared_ptr<creature>& parent)
{
	switch (parent->get_id_number())
	{
	case 2:
		return std::make_shared<grasshopper>(parent->get_max_health(), parent->get_speed());
	case 3:
		return std::make_shared<mouse>(parent->get_max_health(), parent->get_speed());
	case 4:
		return std::make_shared<rabbit>(parent->get_max_health(), parent->get_speed());
	case 5:
		return std::make_shared<frog>(parent->get_max_health(), parent->get_speed());
	case 6:
		return std::make_shared<bird>(parent->get_max_health(), parent->get_speed());
	case 7:
		return std::make_shared<snake>(parent->get_max_health(), parent->get_speed());
	case 8:
		return std::make_shared<fox>(parent->get_max_health(), parent->get_speed());
	case 9:
		return std::make_shared<hawk>(parent->get_max_health(), parent->get_speed());
	case 10:
		return std::make_shared<owl>(parent->get_max_health(), parent->get_speed());
	default:
		return nullptr;
	}
}

}


// Overload != operator to see if two pointers point at the same creature
bool creature::operator!=(creature& other) const
{
	if (this == &other) return false;
	else return true;
}


// Plant class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution.
*/
plant::plant()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };
	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	number_plants++;
}

int plant::number_plants{};


// Grasshopper class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
grasshopper::grasshopper()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;

	number_grasshoppers++;
}

// Parametrized constructor
grasshopper::grasshopper(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;

	number_grasshoppers++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void grasshopper::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void grasshopper::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int grasshopper::number_grasshoppers{};

// Mouse class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
mouse::mouse()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;

	number_mice++;
}

// Parametrized constructor
mouse::mouse(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;

	number_mice++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void mouse::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void mouse::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int mouse::number_mice{};

// Rabbit class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
rabbit::rabbit()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;

	number_rabbits++;
}

// Parametrized constructor
rabbit::rabbit(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;

	number_rabbits++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void rabbit::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void rabbit::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int rabbit::number_rabbits{};

// Frog class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
frog::frog()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;

	number_frogs++;
}

// Parametrized constructor
frog::frog(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;

	number_frogs++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void frog::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void frog::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int frog::number_frogs{};

// Bird class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
bird::bird()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;

	number_birds++;
}

// Parametrized constructor
bird::bird(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;

	number_birds++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void bird::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void bird::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int bird::number_birds{};

// Snake class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
snake::snake()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;
	number_snakes++;
}

// Parametrized constructor
snake::snake(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;
	number_snakes++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void snake::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void snake::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int snake::number_snakes{};

// Fox class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
fox::fox()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;
	number_foxes++;
}

// Parametrized constructor
fox::fox(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;
	number_foxes++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void fox::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void fox::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int fox::number_foxes{};

// Hawk class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health follows a gaussian distribution, taking the mean as its parent's max health (originally,
it takes the value of the specie.
*/
hawk::hawk()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;
	number_hawks++;
}

// Parametrized constructor
hawk::hawk(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;
	number_hawks++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void hawk::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the frogs to move
void hawk::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int hawk::number_hawks{};

// Owl class
/*
Cosntructor: as a default, the position of the creature is randomly generated. Additionally,
its health depends on the amount of creatures of the same specie that are in the environment.
As more creatures there are in the environment, the lower the health.
*/
owl::owl()
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(species_health);
	health = max_health;

	speed = gaussian_int(species_speed);
	if (speed < 0)
		speed = 0;
	number_owls++;
}

// Parametrized constructor
owl::owl(int parents_max_health, int parents_speed)
{
	int x_coordinate{ uniform_int(0, screen_width) };
	int y_coordinate{ uniform_int(0, screen_height) };

	position = std::make_pair(x_coordinate, y_coordinate);

	// Simulate mutations
	max_health = gaussian_int(parents_max_health);
	health = max_health;

	speed = gaussian_int(parents_speed);
	if (speed < 0)
		speed = 0;
	number_owls++;
}

// If the creature has not eaten in a while, its health is reduced. The amount of reduced health
// and the rate at which the creature needs to eat depend on the creature's max health and speed
void owl::starvation()
{
	if (speed != 0)
	{
		if (has_eaten.size() >= 300 / speed)
		{
			if (std::find(begin(has_eaten), end(has_eaten), true) == end(has_eaten))
				health -= max_health / 5;
			has_eaten.clear();
		}
	}
}

// Allows the owls to move
void owl::move()
{
	// Generate two random numbers between -1 and 1
	int dx{ uniform_int(0, 2) };
	int dy{ uniform_int(0, 2) };
	dx -= 1;
	dy -= 1;

	// Update the position
	position.first += dx * speed;
	position.second += dy * speed;

	// Ensure the creatures does not exit the screen (essentially, making it a torus)
	if (position.first > screen_width) position.first = 0;
	if (position.second > screen_height) position.second = 0;
	if (position.first < 0) position.first = screen_width;
	if (position.second < 0) position.second = screen_height;
}

int owl::number_owls{};

// Rectangle class

// Default constructor: as default, the rectangles cover all the screen
rectangle::rectangle()
{
	x = 0;
	y = 0;
	width = screen_width;
	height = screen_height;
}

// Parametrized constructor
rectangle::rectangle(int x_in, int y_in, int width_in, int height_in)
{
	x = x_in;
	y = y_in;
	width = width_in;
	height = height_in;
}

// Function that takes a point and returns true if it is contained in the rectangle
bool rectangle::contains_point(std::pair<int,int> point)
{

	return (point.first >= (x - width) &&
		point.first <= (x + width) &&
		point.second >= (y - height) &&
		point.second <= (y + height));
}

// Function that takes a rectangle and returns true if it overlaps with the other rectangle
bool rectangle::intersects(rectangle range)
{
	int x_2{ range.get_x() };
	int y_2{ range.get_y() };
	int width_2{ range.get_width() };
	int height_2{ range.get_height() };

	int l1_x = x - width; // X coordinate of the top left corner of the first rectangle
	int r1_x = x + width; // X coordinate of the bottom right corner of the first rectangle
	int l2_x = x_2 - width_2; // X coordinate of the top left corner of the second rectangle
	int r2_x = x_2 + width_2; // X coordinate of the bottom right corner of the second rectangle

	int l1_y = y + height; // Y coordinate of the top left corner of the first rectangle
	int r1_y = y - height; // Y coordinate of the bottom right corner of the first rectangle
	int l2_y = y_2 + height_2; // X coordinate of the top left corner of the second rectangle
	int r2_y = y_2 - height_2; // X coordinate of the bottom right corner of the first rectangle

	// Check if one is in a different x of the other
	if (l1_x >= r2_x || l2_x >= r1_x)
		return false;

	// Check if one is above the other
	if (r1_y >= l2_y || r2_y >= l1_y)
		return false;

	return true;
}


// Quadtree class

std::shared_ptr<quadtree> quadtree::child_for_point(std::pair<int, int> point)
{
	const int x = boundary.get_x();
	const int y = boundary.get_y();

	if (point.first <= x)
	{
		if (point.second <= y)
			return topleft;
		return bottomleft;
	}

	if (point.second <= y)
		return topright;
	return bottomright;
}

// Function to split the quadtree in four sons
void quadtree::split()
{
	if (!can_split())
		return;

	int x{ boundary.get_x() };
	int y{ boundary.get_y() };
	int w{ boundary.get_width() };
	int h{ boundary.get_height() };

	// Initialize new boundary rectangles for the new quadtree
	rectangle rec_topright(x + w / 2, y - h / 2, w / 2, h / 2);
	rectangle rec_topleft(x - w / 2, y - h / 2, w / 2, h / 2);
	rectangle rec_bottomright(x + w / 2, y + h / 2, w / 2, h / 2);
	rectangle rec_bottomleft(x - w / 2, y + h / 2, w / 2, h / 2);

	// Create the quadtrees and the pointers that point to them
	std::shared_ptr<quadtree> p_tl(new quadtree(rec_topleft));
	std::shared_ptr<quadtree> p_tr(new quadtree(rec_topright));
	std::shared_ptr<quadtree> p_bl(new quadtree(rec_bottomleft));
	std::shared_ptr<quadtree> p_br(new quadtree(rec_bottomright));

	// Set the quadtrees to their pointers
	topleft = p_tl;
	topright = p_tr;
	bottomleft = p_bl;
	bottomright = p_br;

	// Update the variable has divided to true
	has_divided = true;

	std::vector<std::shared_ptr<creature>> retained_points;
	retained_points.reserve(points.size());

	for (const auto& point : points)
	{
		std::shared_ptr<quadtree> child = child_for_point(point->get_position());

		if (child != nullptr && child->boundary.contains_point(point->get_position()))
			child->insert(point);
		else
			retained_points.push_back(point);
	}

	points = retained_points;
}

// Function to insert points in the quadtree
void quadtree::insert(std::shared_ptr<creature> point)
{
	// Check that the point is inside the boundary of the quadtree, and so it can be stored
	if (!boundary.contains_point(point->get_position()))
		return;

	if (has_divided)
	{
		std::shared_ptr<quadtree> child = child_for_point(point->get_position());
		if (child != nullptr && child->boundary.contains_point(point->get_position()))
			child->insert(point);
		else
			points.push_back(point);
		return;
	}

	// Keep points in the current node if it still has room or the region can no longer split.
	if (points.size() < capacity || !can_split())
		points.push_back(point);

	// If it is full, check if it has already divided. If it has not, divide the quadtree. If it
	// already has, use recursion to insert the point to one of the sons of the quadtree.
	else
	{
		split();

		std::shared_ptr<quadtree> child = child_for_point(point->get_position());
		if (child != nullptr && child->boundary.contains_point(point->get_position()))
			child->insert(point);
		else
			points.push_back(point);

	}
}

// Function to look for points that are in the same branch of the quadtree
void quadtree::query(rectangle range, std::vector<std::shared_ptr<creature>>& found)
{
	// Check that the range is inside the boundary. If it is not, return an empty array
	if (!range.intersects(boundary))
		return;

	// If it is inside, push back the points and check if it has other quadtrees inside
	for (int i{}; i < points.size(); i++)
	{
		if (range.contains_point(points[i]->get_position()))
			found.push_back(points[i]);
	}

	if (has_divided)
	{
		topleft->query(range, found);
		topright->query(range, found);
		bottomleft->query(range, found);
		bottomright->query(range, found);
	}
}

// Function to draw the quadtree, mainly used for debugging purposes, even though it can be
// illustrative
cimg_library::CImg<unsigned char> quadtree::show(cimg_library::CImg<unsigned char> image)
{
	int x = boundary.get_x();
	int y = boundary.get_y();
	int w = boundary.get_width();
	int h = boundary.get_height();

	// Draw the boundary of the quadtree
	image = image.draw_rectangle(x - w, y + h, x + w, y - h, white, 255, 0xFFFFFFFF);

	// Draw the boundary of the quadtrees sons
	if (has_divided)
	{
		image = topleft->show(image);
		image = topright->show(image);
		image = bottomleft->show(image);
		image = bottomright->show(image);
	}
	return image;
}


// Ecosystem class

// Parametrized constructor
ecosystem::ecosystem(int num_plants, int num_grasshoppers, int num_mice, int num_rabbits,
	int num_frogs, int num_birds, int num_snakes, int num_foxes, int num_hawks, int num_owls)
{
	// Save memory to append the creatures to the vector
	creatures.reserve(num_plants + num_grasshoppers + num_mice + num_rabbits +
		num_frogs + num_birds + num_snakes + num_foxes + num_hawks + num_owls);

	for (int i{}; i < num_plants; i++)
	{
		std::shared_ptr<creature> new_plant{ new plant() };
		creatures.push_back(new_plant);
	}
	for (int i{}; i < num_grasshoppers; i++)
	{
		std::shared_ptr<creature> new_gh{ new grasshopper() };
		creatures.push_back(new_gh);
	}
	for (int i{}; i < num_mice; i++)
	{
		std::shared_ptr<creature> new_mouse{ new mouse() };
		creatures.push_back(new_mouse);
	}
	for (int i{}; i < num_rabbits; i++)
	{
		std::shared_ptr<creature> new_rabbit{ new rabbit() };
		creatures.push_back(new_rabbit);
	}
	for (int i{}; i < num_frogs; i++)
	{
		std::shared_ptr<creature> new_frog{ new frog() };
		creatures.push_back(new_frog);

	}
	for (int i{}; i < num_birds; i++)
	{
		std::shared_ptr<creature> new_bird{ new bird() };
		creatures.push_back(new_bird);
	}
	for (int i{}; i < num_snakes; i++)
	{
		std::shared_ptr<creature> new_snake{ new snake() };
		creatures.push_back(new_snake);
	}
	for (int i{}; i < num_foxes; i++)
	{
		std::shared_ptr<creature> new_fox{ new fox() };
		creatures.push_back(new_fox);
	}
	for (int i{}; i < num_hawks; i++)
	{
		std::shared_ptr<creature> new_hawk{ new hawk() };
		creatures.push_back(new_hawk);
	}
	for (int i{}; i < num_owls; i++)
	{
		std::shared_ptr<creature> new_owl{ new owl() };
		creatures.push_back(new_owl);
	}
}

// Function to display each creature
cimg_library::CImg<unsigned char> ecosystem::display(cimg_library::CImg<unsigned char> image)
{
	for (int i{}; i < creatures.size(); i++)
	{
		std::pair<int, int> position{ creatures[i]->get_position() };
		std::vector<int> color_component{creatures[i]->get_color()};

		// Transform the color into an array
		const unsigned char color[] = { color_component[0], color_component[1], color_component[2] };

		// Draw the creature
		image = image.draw_rectangle(position.first - creature_width, position.second - creature_height,
			position.first + creature_width, position.second + creature_height, color);
	}
	return image;
}

// Function to make intersecting creatures reproduce or kill each other. It uses the quadtree
// method to iterate for all the creatures
std::vector<std::shared_ptr<creature>> ecosystem::reproduce(quadtree& qdtree)
{
	// Initialize vector for the new generation creatures and reserve memory for it
	std::vector<std::shared_ptr<creature>> new_creatures;
	new_creatures.reserve(creatures.size() * 2);

	std::unordered_map<creature*, std::size_t> creature_indices;
	creature_indices.reserve(creatures.size());

	for (std::size_t i{}; i < creatures.size(); ++i)
		creature_indices.emplace(creatures[i].get(), i);

	std::vector<bool> existing_creatures(creatures.size(), true);
	std::vector<bool> should_reproduce(creatures.size(), false);
	std::vector<bool> has_eaten(creatures.size(), false);

	// Check if any creature needs to die or reproduce. It will look for points in the same
	// quadtree and then check if those points intersect
	for (std::size_t i{}; i < creatures.size(); ++i)
	{
		if (!existing_creatures[i])
			continue;

		std::pair<int,int> position{ creatures[i]->get_position() };
		int creature_id{ creatures[i]->get_id_number() };
		std::vector<int> eats{ creatures[i]->get_eats() };

		rectangle range(position.first, position.second, creature_width * 2, creature_height * 2);
		std::vector<std::shared_ptr<creature>> subgroup_creatures;
		qdtree.query(range, subgroup_creatures);
		rectangle creature_range(position.first, position.second, creature_width, creature_height);

		// If there are creatures found, check if they intersect 
		if (!subgroup_creatures.empty())
		{
			for (const auto& other_creature : subgroup_creatures)
			{
				const auto index_it = creature_indices.find(other_creature.get());
				if (index_it == creature_indices.end())
					continue;

				const std::size_t other_index = index_it->second;
				if (other_index == i || !existing_creatures[i] || !existing_creatures[other_index])
					continue;

				int x{ other_creature->get_position().first };
				int y{ other_creature->get_position().second };
				int creature_id_2{ other_creature->get_id_number() };
				std::vector<int> eats_2{ other_creature->get_eats() };

				rectangle other_creature_range(x, y, creature_width, creature_height);

				if (!creature_range.intersects(other_creature_range))
					continue;

				// Check if they are the same type of creature
				if (creature_id == creature_id_2)
				{
					should_reproduce[i] = true;
					should_reproduce[other_index] = true;
					existing_creatures[i] = false;
					existing_creatures[other_index] = false;
					break;
				}

				// Check if the creature[i] eats the other creature
				if (std::find(eats.begin(), eats.end(), creature_id_2) != eats.end())
				{
					if (creatures[i]->get_speed() > other_creature->get_speed())
					{
						has_eaten[i] = true;
						creatures[i]->set_health(creatures[i]->get_max_health());
						should_reproduce[i] = true;
						existing_creatures[other_index] = false;
						continue;
					}
				}

				// Check if the creature[i] is eaten by the other creature
				if (std::find(eats_2.begin(), eats_2.end(), creature_id) != eats_2.end())
				{
					if (creatures[i]->get_speed() < other_creature->get_speed())
					{
						has_eaten[other_index] = true;
						creatures[other_index]->set_health(creatures[other_index]->get_max_health());
						should_reproduce[other_index] = true;
						existing_creatures[i] = false;
						break;
					}
				}
			}
		}
	}

	for (std::size_t i{}; i < creatures.size(); ++i)
	{
		creatures[i]->has_eaten_push_data(has_eaten[i]);
		if (existing_creatures[i])
			new_creatures.push_back(creatures[i]);

		if (should_reproduce[i])
		{
			std::shared_ptr<creature> new_creature = make_offspring(creatures[i]);
			if (new_creature != nullptr)
				new_creatures.push_back(new_creature);
		}
	}
	return new_creatures;
}

// Function to create quadtree from an environment. Each creature's position is a data point
// that is inserted in the quadtree
quadtree ecosystem::create_tree()
{
	rectangle boundary(screen_width / 2, screen_height / 2,
		screen_width / 2 + 1, screen_height / 2 + 1);
	quadtree qdtree(boundary);

	for (int i{}; i < creatures.size(); i++)
	{
		qdtree.insert(creatures[i]);
	}

	return qdtree;
}

// Function to create plants. When a creature dies, there is a probability of 1/2 that a plant spawns
void ecosystem::plant_generation()
{
	if (deaths == 0)
		return;
	else
	{
		for (int i{}; i < deaths; i++)
		{
			int probability{ uniform_int(1,2) };

			if (probability == 2)
			{
				std::shared_ptr<creature> new_plants(std::make_shared<plant>());
				creatures.push_back(new_plants);
			}

		}
	}
	deaths = 0;
}

// Counts the number of each creature
int ecosystem::num_creature(int id)
{
	int number{};

	for (int i{}; i < creatures.size(); i++)
	{
		if (creatures[i]->get_id_number() == id)
			number += 1;
	}

	return number;
}

// Makes the system evolve by moving, aging and reproducing or killing each creature
void ecosystem::evolve()
{

	for (int i{}; i < creatures.size(); i++)
	{
		// Move the creatures
		creatures[i]->move();

		// Make creatures age
		creatures[i]->age();

		// Takes hunger into account
		creatures[i]->starvation();
	}

	int number_of_creatures = creatures.size();

	auto remove_it = std::remove_if(creatures.begin(), creatures.end(),
		[](std::shared_ptr<creature> cr) {return cr->get_health() <= 0; });

	creatures.erase(remove_it, creatures.end());
	deaths = number_of_creatures - creatures.size();

	// Create a vector to store all the new creatures (including the old ones that will not die)
	// and safe enough memory space to later fill the vector
	std::vector<std::shared_ptr<creature>> new_creatures;

	// Create the quadtree from the ecosystem
	quadtree qdtree = create_tree();

	// Reproduce or kill the creatures
	new_creatures = reproduce(qdtree);

	// Delete the creatures and set the equal to the new creatures
	creatures.clear();
	creatures = new_creatures;

	// Generate new plants
	plant_generation();

}

void ecosystem::kill_half()
{
	std::vector < std::shared_ptr<creature>> new_creatures;
	for (int i{}; i < creatures.size(); i++)
	{
		int probability{ uniform_int(1,2) };
		if (probability == 2)
			new_creatures.push_back(creatures[i]);
	}
	creatures.clear();
	creatures = new_creatures;
}

// Draws the amount of total creatures, and each type in the background
cimg_library::CImg<unsigned char> ecosystem::draw_text(cimg_library::CImg<unsigned char> image)
{
	const char* text;
	std::string string;
	// Amount of creatures
	string = make_text("Creatures: ", creatures.size());
	text = string.c_str();
	image.draw_text(0, 50, text, white, black, 1, 25);

	// Amount of plants
	string = make_text("Plants: ", num_creature(1));
	text = string.c_str();
	image.draw_text(0, 75, text, white, black, 1, 25);

	// Amount of grasshoppers
	string = make_text("Grasshoppers: ", num_creature(2));
	text = string.c_str();
	image.draw_text(0, 100, text, white, black, 1, 25);

	// Amount of mice
	string = make_text("Mice: ", num_creature(3));
	text = string.c_str();
	image.draw_text(0, 125, text, white, black, 1, 25);

	// Amount of rabbits
	string = make_text("Rabbits: ", num_creature(4));
	text = string.c_str();
	image.draw_text(0, 150, text, white, black, 1, 25);

	// Amount of frogs
	string = make_text("Frogs: ", num_creature(5));
	text = string.c_str();
	image.draw_text(0, 175, text, white, black, 1, 25);

	// Amount of birds
	string = make_text("Birds: ", num_creature(6));
	text = string.c_str();
	image.draw_text(0, 200, text, white, black, 1, 25);

	// Amount of snakes
	string = make_text("Snakes: ", num_creature(7));
	text = string.c_str();
	image.draw_text(0, 225, text, white, black, 1, 25);

	// Amount of foxes
	string = make_text("Foxes: ", num_creature(8));
	text = string.c_str();
	image.draw_text(0, 250, text, white, black, 1, 25);

	// Amount of hawks
	string = make_text("Hawks: ", num_creature(9));
	text = string.c_str();
	image.draw_text(0, 275, text, white, black, 1, 25);

	// Amount of owls
	string = make_text("Owls: ", num_creature(10));
	text = string.c_str();
	image.draw_text(0, 300, text, white, black, 1, 25);

	return image;
}

// Calculate the average health and speed of a type of creature
std::vector<int> ecosystem::average_health_speed(int id)
{
	std::vector<int> health{};
	std::vector<int> speed{};

	std::vector<int> averages{};

	for (int i{}; i < creatures.size(); i++)
	{
		if (creatures[i]->get_id_number() == id)
		{
			health.push_back(creatures[i]->get_max_health());
			speed.push_back(creatures[i]->get_speed());
		}
	}

	if (!health.empty())
		averages.push_back(std::accumulate(health.begin(),
			health.end(), 0) / health.size());
	else averages.push_back(0);

	if (!speed.empty())
		averages.push_back(std::accumulate(speed.begin(),
			speed.end(), 0) / speed.size());
	else averages.push_back(0);

	return averages;
}
