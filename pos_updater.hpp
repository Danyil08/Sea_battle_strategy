// Function to mark shoot in given ceil as "damage"
void mark_dam(bool (&field)[10][10][2], pair <short, short> ceil);
// Function to mark shoot in given ceil as "destruction"
void mark_destr(bool (&field)[10][10][2], pair <short, short> ceil);
/* Function to check whether the ship with the given orientation and length (number of decks) can be
  located so that it's tail is in the given ceil assuming this is the only ship added on the given field */
bool sup_ship(const bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length);
/* Function to set the ship with the given orientation and length (number of decks) 
  so that it's tail is in the given ceil in the given field */
void set_ship(bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length);
/* Function to check whether the ship such that it's tail is in the given ceil with the given 
  orientation and length (number of decks) can be destroyed by one shoot on the given field (position) */
bool sup_fatal(const bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length);
/* Function to check whether some ship with the given orientation and length (number of decks)
  can be destroyed by shoot in the given ceil on the given field (position) */
bool find_fatal(const bool (&field)[10][10][2], short avships[4], pair <short, short> target);
// Function to mark the destruction of ship by shoot in the given ceil
void set_fatal(bool (&field)[10][10][2], short (&avships)[4], pair <short, short> target);
