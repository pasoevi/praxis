	public static int partitionnner(int[] array, int left, int right)
	{
	  int w = array[randcentre];
	  array[randcentre] = array[right];
	  array[right] = w;
	  int j = left;
	  for(int i = 0; i< right; ++i)
	    {
	      if(aray[i] <= array[right])
		{
		  int w = array[j];
		  array[j] = array[i];
		  array[i] = w;
		  ++j;
		}
	    }
	  int w = array[right];
	  array[right] = array[j];
	  array[j] = w;
	  
	  return j;
	}

	public static int triRapide(int[] array, int first, int last)
	{
	  if (first < last)
	    {
	      int randcentre = partition(array, first, last);
	      triRapide(array, first, randcentre -1);
	      triRapide(array, randcentre + 1, last);
	    }
	}

	public static int partition(int[] array, int start, int end)
	{
	  
	  