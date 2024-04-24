// File that contains all the definition of functions declared in the .h file

#include "foodchain.h"


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

// Function to split the quadtree in four sons
void quadtree::split()
{
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
}

// Function to insert points in the quadtree
void quadtree::insert(std::shared_ptr<creature> point)
{
	// Check that the point is inside the boundary of the quadtree, and so it can be stored
	if (!boundary.contains_point(point->get_position()))
		return;

	// Check the quadtree is not full and store the point if it is not
	if (points.size() < capacity)
		points.push_back(point);

	// If it is full, check if it has already divided. If it has not, divide the quadtree. If it
	// already has, use recursion to insert the point to one of the sons of the quadtree.
	else
	{
		if (has_divided == false)
		{
			split();
		}
		topleft->insert(point);
		topright->insert(point);
		bottomleft->insert(point);
		bottomright->insert(point);

	}
}

// Function to look for points that are in the same branch of the quadtree
std::vector<std::shared_ptr<creature>> quadtree::query(rectangle range,
	std::vector<std::shared_ptr<creature>> found)
{
	// Check that the range is inside the boundary. If it is not, return an empty array
	if (!range.intersects(boundary))
	{
		std::vector<std::shared_ptr<creature>> cr;
		return cr;
	}

	// If it is inside, push back the points and check if it has other quadtrees inside
	else
	{
		for (int i{}; i < points.size(); i++)
		{
			if (range.contains_point(points[i]->get_position()))
				found.push_back(points[i]);
		}
		if (has_divided)
		{
			std::vector<std::shared_ptr<creature>> a{ topleft->query(range, found) };
			std::vector<std::shared_ptr<creature>> b{ topright->query(range, found) };
			std::vector<std::shared_ptr<creature>> c{ bottomleft->query(range, found) };
			std::vector<std::shared_ptr<creature>> d{ bottomright->query(range, found) };

			// Concatanate the points of the sons of the quadtree
			found.insert(found.begin(), a.begin(), a.end());
			found.insert(found.begin(), b.begin(), b.end());
			found.insert(found.begin(), c.begin(), c.end());
			found.insert(found.begin(), d.begin(), d.end());
		}
	}
	return found;
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
std::vector<std::shared_ptr<creature>> ecosystem::reproduce(quadtree qdtree)
{
	// Initialize vector for the new generation creatures and reserve memory for it
	std::vector<std::shared_ptr<creature>> new_creatures;
	new_creatures.reserve(creatures.size());

	// Create an empty vector to use to query
	std::vector<std::shared_ptr<creature>> vector;
	std::vector< bool> existing_creatures;

	for (int i{}; i < creatures.size(); i++)
	{
		existing_creatures.push_back(true);
	}

	// Check if any creature needs to die or reproduce. It will look for points in the same
	// quadtree and then check if those points intersect
	for (int i{}; i < creatures.size(); i++)
	{
		std::pair<int,int> position{ creatures[i]->get_position() };
		int creature_id{ creatures[i]->get_id_number() };
		std::vector<int> eats{ creatures[i]->get_eats() };

		rectangle range(position.first, position.second, creature_width, creature_height);
		std::vector<std::shared_ptr<creature>> subgroup_creatures{ qdtree.query(range, vector) };

		bool should_die{ false };
		bool new_grasshopper{ false };
		bool new_mouse{ false };
		bool new_rabbit{ false };
		bool new_frog{ false };
		bool new_bird{ false };
		bool new_snake{ false };
		bool new_fox{ false };
		bool new_hawk{ false };
		bool new_owl{ false };
		bool has_eaten{ false };

		// If there are creatures found, check if they intersect 
		if (!subgroup_creatures.empty())
		{
			for (int j{}; j < subgroup_creatures.size(); j++)
			{
				int x{ subgroup_creatures[j]->get_position().first };
				int y{ subgroup_creatures[j]->get_position().second };
				int creature_id_2{ subgroup_creatures[j]->get_id_number() };

				std::vector<int> eats_2{ subgroup_creatures[j]->get_eats() };

				rectangle creature_range(x, y, creature_width, creature_height);

				rectangle creature_range_2(position.first, position.second, 
					creature_width, creature_height);

				// Check if they intersect, making sure we are not cheking a creature with itself
				if (creature_range.intersects(creature_range_2) && creatures[i] != subgroup_creatures[j]
					&& existing_creatures[i])
				{
					// Check if they are the same type of creature
					if (creature_id == creature_id_2)
					{
						if (creature_id == 2)
							new_grasshopper = true;
						if (creature_id == 3)
							new_mouse = true;
						if (creature_id == 4)
							new_rabbit = true;
						if (creature_id == 5)
							new_frog = true;
						if (creature_id == 6)
							new_bird = true;
						if (creature_id == 7)
							new_snake = true;
						if (creature_id == 8)
							new_fox = true;
						if (creature_id == 9)
							new_hawk = true;
						if (creature_id == 10)
							new_owl = true;
						should_die = true;
						std::replace(existing_creatures.begin() + i, existing_creatures.begin() + i,
							true, false);
					}
					else
					{
						// Check if the creature[i] eats the other creature
						if (std::find(eats.begin(), eats.end(), creature_id_2) != eats.end())
						{
							if (creatures[i]->get_speed() > subgroup_creatures[j]->get_speed())
							{
								has_eaten = true;
								creatures[i]->set_health(creatures[i]->get_max_health());
								if (creature_id == 2)
									new_grasshopper = true;
								if (creature_id == 3)
									new_mouse = true;
								if (creature_id == 4)
									new_rabbit = true;
								if (creature_id == 5)
									new_frog = true;
								if (creature_id == 6)
									new_bird = true;
								if (creature_id == 7)
									new_snake = true;
								if (creature_id == 8)
									new_fox = true;
								if (creature_id == 9)
									new_hawk = true;
								if (creature_id == 10)
									new_owl = true;
							}
						}
						// Check if the creature[j] is eaten by the other creature
						if (std::find(eats_2.begin(), eats_2.end(), creature_id) != eats_2.end())
						{
							if (creatures[i]->get_speed() < subgroup_creatures[j]->get_speed())
							{
								should_die = true;
								std::replace(existing_creatures.begin() + i, existing_creatures.begin() + i,
									true, false);
							}
						}
					}

				}
				if (j == (subgroup_creatures.size() - 1))
				{
					// Create the new creatures and don't push back the ones that
					// didn't make it
					creatures[i]->has_eaten_push_data(has_eaten);
					if (!should_die)
						new_creatures.push_back(creatures[i]);
					if (new_grasshopper)
					{
						std::shared_ptr<creature> new_gh(new grasshopper(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_gh);
					}
					if (new_mouse)
					{
						std::shared_ptr<creature> new_mouse(new mouse(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_mouse);
					}
					if (new_rabbit)
					{
						std::shared_ptr<creature> new_rb(new rabbit(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_rb);
					}
					if (new_frog)
					{
						std::shared_ptr<creature> new_frog(new frog(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_frog);
					}
					if (new_bird)
					{
						std::shared_ptr<creature> new_bird(new bird(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_bird);
					}
					if (new_snake)
					{
						std::shared_ptr<creature> new_snake(new snake(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_snake);
					}
					if (new_fox)
					{
						std::shared_ptr<creature> new_fox(new fox(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_fox);
					}
					if (new_hawk)
					{
						std::shared_ptr<creature> new_hawk(new hawk(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_hawk);
					}
					if (new_owl)
					{
						std::shared_ptr<creature> new_owl(new owl(creatures[i]->get_max_health(),
							creatures[i]->get_speed()));
						new_creatures.push_back(new_owl);
					}
				}
			}
		}
		else
		{
			new_creatures.push_back(creatures[i]);
		}
	}
	return new_creatures;
}

// Function to create quadtree from an environment. Each creature's position is a data point
// that is inserted in the quadtree
quadtree ecosystem::create_tree()
{
	rectangle boundary(0, 0, screen_width, screen_height);
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
			//int probability{ uniform_int(1,2) };
			int probability{ 2 };

			if (probability == 2)
			{
				std::shared_ptr<creature> new_plants(new plant());
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