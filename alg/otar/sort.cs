using System;

public class SortingProgram
{
	static int Main(String[] args)
	{
	  Console.WriteLine("Enter numbers separated by comma: ");
	  string lineofnumbers = Console.ReadLine();
	  
	  string[] tokens = lineofnumbers.Split(',');
	  Double[] array = new Double[tokens.Length];
	  
	  for(int i = 0; i < tokens.Length; i++)
	    array[i] = Double.Parse(tokens[i]);
	  
	  double[] sorted = QuickSort(array, 0, array.Length - 1);
	  
  	  string answer = "default";
	  Console.WriteLine("Default is sorting by ascending order. Sort by descending order ? (y, n, q): ");
	  answer = Console.ReadLine();
	  while(answer != "q")
	    {
	      switch(answer)
		{
		case "y": 
		  for(int i = sorted.Length - 1; i>=0; --i)
		    Console.WriteLine(sorted[i]);
		  answer = "q";
		  break;
		case "n": 
		  foreach(Double i in sorted)
		    Console.WriteLine(i);
		  answer = "q";
		  break;
		default: 
		  Console.WriteLine("Answer with (y)es, (n)o or (q)uit.");
		  answer = Console.ReadLine();
		  break;
		}
	    }
	    return 0; 
	}


	  


	public static Double[] QuickSort(Double[] a, Double left, Double right)
	{
	  Double i = left;
	  Double j = right;
	  Double randcentre = ((left + right) / 2);
	  Double x = a[Convert.ToInt32(randcentre)];
	  Double w = 0;
	  while (i <= j)
	    {
	      while (a[Convert.ToInt32(i)] < x)
		{
		  i++;
		}
	      while (x < a[Convert.ToInt32(j)])
		{
		  j--;
		}
	      if (i <= j)
		{
		  w = a[Convert.ToInt32(i)];
		  a[Convert.ToInt32(i++)] = a[Convert.ToInt32(j)];
		  a[Convert.ToInt32(j--)] = w;
		}
	    }
	  if (left < j)
	    {
	      QuickSort(a, left, j);
	    }
	  if (i < right)
	    {
	      QuickSort(a, i, right);
	    }
	  return a;
	}
	

}
