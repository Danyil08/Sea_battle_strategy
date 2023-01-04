// Function to determine the minimal number of misses that is needed to guaranteely destroy all the ships in the given position
short est_pos(bool (&field)[10][10][2], short (&avships)[4], vector < pair <Field, short> > (&mem)[100], short almiss = 80)
{
	if (terminator(avships))
	{
		return 0;
	}
	bool miss[10][10], dam[10][10], destr[10][10], field0[10][10][2], sense;
	short est = 80, worst, sup, free, avships0[4];
	equiv_pos(field, avships, miss, dam, destr, free);
	if (terminator(avships))
	{
		return 0;
	}
	if (last_ship(avships))
	{
		if (avships[0] == 1)
		{
			return free - 1;
		}
		pair <short, short> deck;
		if (last_dam(field, deck))
		{
			return last_dam_est(field, deck);
		}
	}
    for (int i = 0; i < mem[free-1].size(); i++)
    {
    	if (same_fields((mem[free-1])[i].first, field))
    	{
    		return (mem[free-1])[i].second;
		}
	}
	for (short i = 0; i < 10; i++)
    {
    	for (short j = 0; j < 10; j++)
    	{
    		if (!field[i][j][0] && !field[i][j][1])
    		{
    		    sense = true;
    		    if (miss[i][j] && (almiss == 1))
    		    {
    		    	sense = false;
				}
				if (sense)
				{
				    worst = 0;
        		    if (miss[i][j])
        		    {
    	    		    copy_field(field0, field);
		    		    copy_avships(avships0, avships);
    				    field0[i][j][1] = 1;
        			    sup = est_pos(field0, avships0, mem, almiss - 1) + 1;
    	    		    if (sup > worst)
    		        	{
    			        	worst = sup;
				        }
			        }
    			    if (dam[i][j])
        		    {
    	    		    copy_field(field0, field);
	    			    copy_avships(avships0, avships);
				        mark_dam(field0, make_pair(i, j));
        			    sup = est_pos(field0, avships0, mem, almiss);
        			    if (sup > worst)
    	    	    	{
    		    	    	worst = sup;
				        }
    			    }
	    		    if (destr[i][j])
    	    	    {
    		    	    copy_field(field0, field);
			    	    copy_avships(avships0, avships);
    				    set_fatal(field0, avships0, make_pair(i, j));
        			    sup = est_pos(field0, avships0, mem, almiss);
    	    		    if (sup > worst)
    		        	{
    			        	worst = sup;
				        }
			        }
			        if (worst < est)
			        {
    			    	est = worst;
    			    	if (almiss > est)
    			    	{
    			    		almiss = est;
						}
	    			}
	    		}
			}
		}
	}
	Field f = to_field(field);
	mem[free-1].push_back(make_pair(f, est));
    return est;
}

