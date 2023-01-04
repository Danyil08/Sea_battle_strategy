#include"opt_support.hpp"
bool check_pos(const bool (&field)[10][10][2], short avships[4])
{
	bool checker = true;
	short length;
	for (short i = 3; i >=0; i--)
	{
		if (avships[i]!=0)
		{
			checker = false;
			length = i + 1;
			break;
		}
	}
	if (checker)
	{
		for (short i = 0; i < 10; i++)
		{
			for (short j = 0; j < 10; j++)
			{
				if (field[i][j][0] && !field[i][j][1])
				{
					return false;
				}
			}
		}
		return true;
	}
	bool field0[10][10][2];
	short avships0[4];
	for (short x = 0; x < 10; x++)
	{
		for (short y = 0; y < 10; y++)
		{
			if (field[x][y][0] && !field[x][y][1])
			{
			    for (short i = 3; i > 0; i--)
			    {
				    if (avships[i]!=0)
				    {
					    if (x - i > 0)
						{
						    for (short j = x - i; j <= x; j++)
						    {
						        if (sup_ship(field, make_pair(j, y), 0, i+1))
						        {
						        	for (short a = 0; a < 10; a++)
						        	{
						        		for (short b = 0; b < 10; b++)
						        		{
						        			field0[a][b][0] = field[a][b][0];
						        			field0[a][b][1] = field[a][b][1];
										}
									}
									for (short a = 0; a < 4; a++)
									{
										avships0[a] = avships[a];
									}
				                    set_ship(field0, make_pair(j, y), 0, i+1);
				                    avships0[i]--;
									if (check_pos(field0, avships0))
									{
										return true;
									}
					            }
				            }    
			            }
            			else
			            {
            				for (short j = 0; j <= x; j++)
			            	{
            					if (sup_ship(field, make_pair(j, y), 0, i+1))
			            		{
						            for (short a = 0; a < 10; a++)
						        	{
						        		for (short b = 0; b < 10; b++)
						        		{
						        			field0[a][b][0] = field[a][b][0];
						        			field0[a][b][1] = field[a][b][1];
										}
									}
									for (short a = 0; a < 4; a++)
									{
										avships0[a] = avships[a];
									}
				                    set_ship(field0, make_pair(j, y), 0, i+1);
				                    avships0[i]--;
									if (check_pos(field0, avships0))
									{
										return true;
									}
					            }
				            }
			            }
		                if (y - i > 0)
		            	{
			            	for (short j = y - i; j <= y; j++)
				            {
					            if (sup_ship(field, make_pair(x, j), 1, i+1))
					            {
						            for (short a = 0; a < 10; a++)
						        	{
						        		for (short b = 0; b < 10; b++)
						        		{
						        			field0[a][b][0] = field[a][b][0];
						        			field0[a][b][1] = field[a][b][1];
										}
									}
									for (short a = 0; a < 4; a++)
									{
										avships0[a] = avships[a];
									}
				                    set_ship(field0, make_pair(x, j), 1, i+1);
				                    avships0[i]--;
									if (check_pos(field0, avships0))
									{
										return true;
									}
					            }
				            }
			            }
			            else
			            {
				            for (short j = 0; j <= y; j++)
				            {
					            if (sup_ship(field, make_pair(x, j), 1, i+1))
	            				{
	    		            	    for (short a = 0; a < 10; a++)
						        	{
						        		for (short b = 0; b < 10; b++)
						        		{
						        			field0[a][b][0] = field[a][b][0];
						        			field0[a][b][1] = field[a][b][1];
										}
									}
									for (short a = 0; a < 4; a++)
									{
										avships0[a] = avships[a];
									}
				                    set_ship(field0, make_pair(x, j), 1, i+1);
				                    avships0[i]--;
									if (check_pos(field0, avships0))
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
		}
	}
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if (sup_ship(field, make_pair(i, j), 0, length))
			{
				for (short a = 0; a < 10; a++)
				{
		       		for (short b = 0; b < 10; b++)
	        		{
			  			field0[a][b][0] = field[a][b][0];
		       			field0[a][b][1] = field[a][b][1];
					}
				}
				for (short a = 0; a < 4; a++)
				{
					avships0[a] = avships[a];
				}
				set_ship(field0, make_pair(i, j), 0, length);
				avships0[length-1]--;
				if (check_pos(field0, avships0))
				{
					return true;
				}
			}
			if (sup_ship(field, make_pair(i, j), 1, length))
			{
				for (short a = 0; a < 10; a++)
				{
		       		for (short b = 0; b < 10; b++)
	        		{
			  			field0[a][b][0] = field[a][b][0];
		       			field0[a][b][1] = field[a][b][1];
					}
				}
				for (short a = 0; a < 4; a++)
				{
					avships0[a] = avships[a];
				}
				set_ship(field0, make_pair(i, j), 1, length);
				avships0[length-1]--;
				if (check_pos(field0, avships0))
				{
					return true;
				}
			}
		}
	}
	return false;
}	
//####################################################################################################
bool terminator(short (&avships)[4])
{
	for (short i = 0; i < 4; i++)
	{
		if (avships[i]!=0)
		{
			return false;
		}
	}
	return true;
}
//####################################################################################################
bool last_dam(bool (&field)[10][10][2], pair <short, short> (&deck))
{
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if (field[i][j][0] && !field[i][j][1])
			{
				deck = make_pair(i, j);
				return true;
			}
		}
	}
	return false;
}
//####################################################################################################
bool last_ship(short (&avships)[4])
{
	short count = 0;
	for (short i = 0; i < 4; i++)
	{
		count = count + avships[i];
	}
	if (count == 1)
	{
		return true;
	}
	return false;
}
//####################################################################################################
void copy_field(bool (&field0)[10][10][2], bool (&field)[10][10][2])
{
	for (short a = 0; a < 10; a++)
	{
	    for (short b = 0; b < 10; b++)
	    {
		    field0[a][b][0] = field[a][b][0];
		    field0[a][b][1] = field[a][b][1];
        }
	}
}
//####################################################################################################
void copy_avships(short (&avships0)[4], short (&avships)[4])
{
	for (short a = 0; a < 4; a++)
	{
		avships0[a] = avships[a];
	}
}
//####################################################################################################
void equiv_pos(bool (&field)[10][10][2], short (&avships)[4], bool (&miss)[10][10], bool (&dam)[10][10], bool (&destr)[10][10], short &free)
{
	bool field0[10][10][2];
	short avships0[4];
	free = 0;
	bool breaker = 0;
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if (!field[i][j][0] && !field[i][j][1])
			{
				free++;
				copy_field(field0, field);
				field0[i][j][1] = 1;
				miss[i][j] = check_pos(field0, avships);
				field0[i][j][1] = 0;
				mark_dam(field0, make_pair(i, j));
				dam[i][j] = check_pos(field0, avships);
				copy_field(field0, field);
				if (find_fatal(field0, avships, make_pair(i, j)))
				{
					copy_avships(avships0, avships);
					set_fatal(field0, avships0, make_pair(i, j));
					if (check_pos(field0, avships0))
					{
						destr[i][j] = true;
					}
					else
					{
						destr[i][j] = false;
					}
				}
				else
				{
					destr[i][j] = false;
				}
				if (miss[i][j] && (!dam[i][j] && !destr[i][j]))
				{
				    field[i][j][1] = 1;
				    equiv_pos(field, avships, miss, dam, destr, free);
				    breaker = 1;
				    break;
				}
				if (!miss[i][j] && (dam[i][j] && !destr[i][j]))
				{
				    mark_dam(field, make_pair(i, j));
				    equiv_pos(field, avships, miss, dam, destr, free);
				    breaker = 1;
				    break;
				}
				if (!miss[i][j] && (!dam[i][j] && destr[i][j]))
				{
				    set_fatal(field, avships, make_pair(i, j));
				    if (!terminator(avships))
				    {
				    	equiv_pos(field, avships, miss, dam, destr, free);
				    	breaker = 1;
				        break;
					}
				}
			}
		}
		if (breaker)
		{
			break;
		}
	}
}
//####################################################################################################
short last_dam_est(bool (&field)[10][10][2], pair <short, short> deck)
{
	short q_est = -1;
	if (deck.first > 0)
	{
		if (!field[deck.first-1][deck.second][1])
		{
			q_est++;
		}
	}
	if (deck.first < 9)
	{
		if (!field[deck.first+1][deck.second][1])
		{
			q_est++;
		}
	}
	if (deck.second > 0)
	{
		if (!field[deck.first][deck.second-1][1])
		{
			q_est++;
		}
	}
	if (deck.second < 9)
	{
		if (!field[deck.first][deck.second+1][1])
		{
			q_est++;
		}
	}
	return q_est;
}
//#include "greed_shooter.cpp"
//####################################################################################################
bool same_fields(Field f, bool (&field0)[10][10][2])
{
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if ((f.field[i][j][0]!=field0[i][j][0])||(f.field[i][j][1]!=field0[i][j][1]))
			{
				return false;
			}
		}
	}
	return true;
}
//####################################################################################################
Field to_field(bool (&field)[10][10][2])
{
	Field f;
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			f.field[i][j][0] = field[i][j][0];
			f.field[i][j][1] = field[i][j][1];
		}
	} 
	return f;
}
