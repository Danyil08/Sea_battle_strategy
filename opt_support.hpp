// Function to check whether the given position is valid
bool check_pos(const bool (&field)[10][10][2], short avships[4]);
// Function to check is there any non-destroyed ship
bool terminator(short (&avships)[4]);
// Function to check is there damaged ship and if it is to return it (implicitly in the "deck" parametr)
bool last_dam(bool (&field)[10][10][2], pair <short, short> (&deck));
// Function to check is there exactly one non-destroyed ship
bool last_ship(short (&avships)[4]);
// Function to copy bool's array that describes field (assigns the first parameter by second parameter)
void copy_field(bool (&field0)[10][10][2], bool (&field)[10][10][2]);
// Function to copy short's array that describes non-destroyed ships (assigns the first parameter by second parameter)
void copy_avships(short (&avships0)[4], short (&avships)[4]);
// Function to "simplify" position if it is possible (find and mark ceils such that result of shoot in can be determined)
void equiv_pos(bool (&field)[10][10][2], short (&avships)[4], bool (&miss)[10][10], bool (&dam)[10][10], bool (&destr)[10][10], short &free);
// Function to determine the minimal number of misses to guaranteely destroy the last non-destroyed but damaged ship
short last_dam_est(bool (&field)[10][10][2], pair <short, short> deck);
// Structure is used to describe battlefield
struct Field
{
	bool field[10][10][2];
};
// Function to check whether the given fields are identical 
bool same_fields(Field f, bool (&field0)[10][10][2]);
// Function to turn correspondent bool array into "Field" structure
Field to_field(bool (&field)[10][10][2]);

