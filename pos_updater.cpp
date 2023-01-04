#include"pos_updater.hpp"
void mark_dam(bool (&field)[10][10][2], pair <short, short> ceil)
{
    field[ceil.first][ceil.second][0] = 1;
    field[ceil.first][ceil.second][1] = 0;
    if (ceil.first>0 && ceil.second>0)
    {
        field[ceil.first-1][ceil.second-1][0] = 0;
        field[ceil.first-1][ceil.second-1][1] = 1;
    }
    if (ceil.first>0 && ceil.second<9)
    {
        field[ceil.first-1][ceil.second+1][0] = 0;
        field[ceil.first-1][ceil.second+1][1] = 1;
    }
    if (ceil.first<9 && ceil.second>0)
    {
        field[ceil.first+1][ceil.second-1][0] = 0;
        field[ceil.first+1][ceil.second-1][1] = 1;
    }
    if (ceil.first<9 && ceil.second<9)
    {
        field[ceil.first+1][ceil.second+1][1] = 0;
        field[ceil.first+1][ceil.second+1][1] = 1;
    }
}
//####################################################################################################
void mark_destr(bool (&field)[10][10][2], pair <short, short> ceil)
{	
    field[ceil.first][ceil.second][0] = 1;
    field[ceil.first][ceil.second][1] = 1;
    if (ceil.first>0 && ceil.second>0)
    {
        field[ceil.first-1][ceil.second-1][0] = 0;
        field[ceil.first-1][ceil.second-1][1] = 1;
    }
    if (ceil.first>0 && ceil.second<9)
    {
        field[ceil.first-1][ceil.second+1][0] = 0;
        field[ceil.first-1][ceil.second+1][1] = 1;
    }
    if (ceil.first<9 && ceil.second>0)
    {
        field[ceil.first+1][ceil.second-1][0] = 0;
        field[ceil.first+1][ceil.second-1][1] = 1;
    }
    if (ceil.first<9 && ceil.second<9)
    {
        field[ceil.first+1][ceil.second+1][1] = 0;
        field[ceil.first+1][ceil.second+1][1] = 1;
    }
    if (ceil.first>0)
    {
        if (field[ceil.first-1][ceil.second][0]==0)
		{
            field[ceil.first-1][ceil.second][0] = 0;
            field[ceil.first-1][ceil.second][1] = 1;
        }
    }
    if (ceil.first<9)
    {
        if (field[ceil.first+1][ceil.second][0]==0)
        {
            field[ceil.first+1][ceil.second][0] = 0;
            field[ceil.first+1][ceil.second][1] = 1;
        }
    }
    if (ceil.second>0)
    {
        if (field[ceil.first][ceil.second-1][0]==0)
        {
            field[ceil.first][ceil.second-1][0] = 0;
            field[ceil.first][ceil.second-1][1] = 1;
        }
    }
    if (ceil.second<9)
    {
        if (field[ceil.first][ceil.second+1][0]==0)
        {
            field[ceil.first][ceil.second+1][0] = 0;
            field[ceil.first][ceil.second+1][1] = 1;
        }
    }
}
//####################################################################################################
bool sup_ship(const bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length)
{
	if (direction) // vertical
	{
		if (tail.second + length <= 10) // fully in field
		{
			if (tail.first > 0) // left-side ceils
			{
				if (tail.second > 0)
				{
					if (field[tail.first-1][tail.second-1][0])
					{
						return false;
					}
				}
				for (short i = tail.second; i < tail.second + length; i++)
				{
					if (field[tail.first-1][i][0])
				    {
					    return false;
				    }
				}
				if (tail.second + length < 10)
				{
					if (field[tail.first-1][tail.second+length][0])
					{
						return false;
					}
			    }
			}
			if (tail.second > 0)
			{
				if (field[tail.first][tail.second-1][0])
				{
					return false;
				}
			}
			bool sup = true;
			for (short i = tail.second; i < tail.second + length; i++) // ship itself
			{
				if (field[tail.first][i][1])
				{
					return false;
				}
				if (sup && !field[tail.first][i][0])
				{
					sup = false;
				}
			}
			if (sup)
			{
				return false;
			}
			if (tail.second + length < 10)
			{
				if (field[tail.first][tail.second+length][0])
				{
					return false;
				}
			}
			if (tail.first < 9) // right-side ceils
			{
				if (tail.second > 0)
				{
					if (field[tail.first+1][tail.second-1][0])
					{
						return false;
					}
				}
				for (short i = tail.second; i < tail.second + length; i++)
				{
					if (field[tail.first+1][i][0])
				    {
					    return false;
				    }
				}
				if (tail.second + length < 10)
				{
					if (field[tail.first+1][tail.second+length][0])
					{
						return false;
					}
			    }
			}
		}
		else
		{
			return false;
		}
	}
	else // horizontal
	{
		if (tail.first + length <= 10) // fully in field
		{
			if (tail.second > 0) // up-side ceils
			{
				if (tail.first > 0)
				{
					if (field[tail.first-1][tail.second-1][0])
					{
						return false;
					}
				}
				for (short i = tail.first; i < tail.first + length; i++)
				{
					if (field[i][tail.second-1][0])
				    {
					    return false;
				    }
				}
				if (tail.first + length < 10)
				{
					if (field[tail.first+length][tail.second-1][0])
					{
						return false;
					}
			    }
			}
			if (tail.first > 0)
			{
				if (field[tail.first-1][tail.second][0])
				{
					return false;
				}
			}
			bool sup = true;
			for (short i = tail.first; i < tail.first + length; i++) // ship itself
			{
				if (field[i][tail.second][1])
				{
					return false;
				}
				if (sup && !field[i][tail.second][0])
				{
					sup = false;
				}
			}
			if (sup)
			{
				return false;
			}
			if (tail.first + length < 9)
			{
				if (field[tail.first+length][tail.second][0])
				{
					return false;
				}
			}
			if (tail.second < 9) // down-side ceils
			{
				if (tail.first > 0)
				{
					if (field[tail.first-1][tail.second+1][0])
					{
						return false;
					}
				}
				for (short i = tail.first; i < tail.first + length; i++)
				{
					if (field[i][tail.second+1][0])
				    {
					    return false;
				    }
				}
				if (tail.first + length< 9)
				{
					if (field[tail.first+length][tail.second+1][0])
					{
						return false;
					}
			    }
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
//####################################################################################################
void set_ship(bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length)
{
	if (direction) // vertical
	{
		if (tail.first > 0) // left-side ceils
		{
			if (tail.second > 0)
			{
				field[tail.first-1][tail.second-1][1] = 1;
			}
			for (short i = tail.second; i < tail.second + length; i++)
			{
				field[tail.first-1][i][1] = 1;
			}
			if (tail.second + length < 10)
			{
				field[tail.first-1][tail.second+length][1] = 1;
		    }
		}
		if (tail.second > 0)
		{
			field[tail.first][tail.second-1][1] = 1;
		}
		for (short i = tail.second; i < tail.second + length; i++) // ship itself
		{
			field[tail.first][i][0] = 1;
			field[tail.first][i][1] = 1;
		}
		if (tail.second + length < 10)
		{
			field[tail.first][tail.second+length][1] = 1;
		}
		if (tail.first < 9) // right-side ceils
		{
			if (tail.second > 0)
			{
				field[tail.first+1][tail.second-1][1] = 1;
			}
			for (short i = tail.second; i < tail.second + length; i++)
			{
				field[tail.first+1][i][1] = 1;
			}
			if (tail.second + length < 10)
			{
				field[tail.first+1][tail.second+length][1] = 1;
		    }
		}
	}
	else // horizontal
	{
		if (tail.second > 0) // up-side ceils
		{
			if (tail.first > 0)
			{
				field[tail.first-1][tail.second-1][1] = 1;
			}
			for (short i = tail.first; i < tail.first + length; i++)
			{
				field[i][tail.second-1][1] = 1;
			}
			if (tail.first + length < 9)
			{
				field[tail.first+length][tail.second-1][1] = 1;
		    }
		}
		if (tail.first > 0)
		{
			field[tail.first-1][tail.second][1] = 1;
		}
		for (short i = tail.first; i < tail.first + length; i++) // ship itself
		{
			field[i][tail.second][0] = 1;
			field[i][tail.second][1] = 1;
		}
		if (tail.first + length < 10)
		{
			field[tail.first+length][tail.second][1] = 1;
		}
		if (tail.second < 9) // down-side ceils
		{
			if (tail.first > 0)
			{
				field[tail.first-1][tail.second+1][1] = 1;
			}
			for (short i = tail.first; i < tail.first + length; i++)
			{
				field[i][tail.second+1][1] = 1;
			}
			if (tail.first + length < 10)
			{
				field[tail.first+length][tail.second+1][1] = 1;
		    }
		}
	}
}
//####################################################################################################
bool sup_fatal(const bool (&field)[10][10][2], pair <short, short> tail, bool direction, short length)
{
	short check = 0;
	if (direction)
	{
		for (short i = tail.second; i < tail.second + length; i++)
		{
			if (!field[tail.first][i][0])
			{
				check++;
			}
		}
	}
	else
	{
		for (short i = tail.first; i < tail.first + length; i++)
		{
			if (!field[i][tail.second][0])
			{
				check++;
			}
		}		
	}
	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//####################################################################################################
bool find_fatal(const bool (&field)[10][10][2], short avships[4], pair <short, short> target)
{
	if (avships[0]!=0 && sup_ship(field, target, 0, 1))
	{
		return true;
	}
	for (short i = 1; i < 4; i++)
	{
		if (avships[i]!=0)
		{
			if (target.first - i > 0)
			{
				for (short j = target.first - i; j <= target.first; j++)
				{
					if (sup_ship(field, make_pair(j, target.second), 0, i+1))
					{
						if (sup_fatal(field, make_pair(j, target.second), 0, i+1))
						{
							return true;
						}
					}
				}
			}
			else
			{
				for (short j = 0; j <= target.first; j++)
				{
					if (sup_ship(field, make_pair(j, target.second), 0, i+1))
					{
						if (sup_fatal(field, make_pair(j, target.second), 0, i+1))
						{
							return true;
						}
					}
				}
			}
		    if (target.second - i > 0)
			{
				for (short j = target.second - i; j <= target.second; j++)
				{
					if (sup_ship(field, make_pair(target.first, j), 1, i+1))
					{
						if (sup_fatal(field, make_pair(target.first, j), 1, i+1))
						{
							return true;
						}
					}
				}
			}
			else
			{
				for (short j = 0; j <= target.second; j++)
				{
					if (sup_ship(field, make_pair(target.first, j), 1, i+1))
					{
						if (sup_fatal(field, make_pair(target.first, j), 1, i+1))
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
//####################################################################################################
void set_fatal(bool (&field)[10][10][2], short (&avships)[4], pair <short, short> target)
{
	bool sense = true;
	if (avships[0]!=0 && sup_ship(field, target, 0, 1))
	{
		set_ship(field, target, 0, 1);
		avships[0]--;
		sense = false;
	}
	for (short i = 1; i < 4; i++)
	{
		if (!sense)
		{
			break;
		}
		if (avships[i]!=0)
		{
			if (target.first - i > 0)
			{
				for (short j = target.first - i; j <= target.first; j++)
				{
					if (sup_ship(field, make_pair(j, target.second), 0, i+1))
					{
						if (sup_fatal(field, make_pair(j, target.second), 0, i+1))
						{
							set_ship(field, make_pair(j, target.second), 0, i+1);
							avships[i]--;
							sense = false;
							break;
						}
					}
				}
			}
			else
			{
				for (short j = 0; j <= target.first; j++)
				{
					if (sup_ship(field, make_pair(j, target.second), 0, i+1))
					{
						if (sup_fatal(field, make_pair(j, target.second), 0, i+1))
						{
							set_ship(field, make_pair(j, target.second), 0, i+1);
							avships[i]--;
							sense = false;
							break;
						}
					}
				}
			}
		    if (target.second - i > 0)
			{
				for (short j = target.second - i; j <= target.second; j++)
				{
					if (sup_ship(field, make_pair(target.first, j), 1, i+1))
					{
						if (sup_fatal(field, make_pair(target.first, j), 1, i+1))
						{
							set_ship(field, make_pair(target.first, j), 1, i+1);
							avships[i]--;
							sense = false;
							break;
						}
					}
				}
			}
			else
			{
				for (short j = 0; j <= target.second; j++)
				{
					if (sup_ship(field, make_pair(target.first, j), 1, i+1))
					{
						if (sup_fatal(field, make_pair(target.first, j), 1, i+1))
						{
							set_ship(field, make_pair(target.first, j), 1, i+1);
							avships[i]--;
							sense = false;
							break;
						}
					}
				}
			}
		}
	}	
}

