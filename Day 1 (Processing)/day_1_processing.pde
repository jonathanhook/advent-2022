import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

void setup()
{
  part2();
}

void part1()
{
  String[] lines = loadStrings("input.txt");
  
  int max = 0;
  int subTotal = 0;
  
  for(int i = 0; i < lines.length; i++)
  {
    if(!lines[i].equals(""))
    {
      subTotal += Integer.parseInt(lines[i]);
    }
    else
    {
      if(subTotal > max)
      {
         max = subTotal; 
      }
      
      subTotal = 0;
    }
  }
  
  print(max);
}

void part2()
{
  String[] lines = loadStrings("input.txt");
  
  List<Integer> topThree = new ArrayList<>();
  int subTotal = 0;

  for(int i = 0; i < lines.length; i++)
  {
    if(!lines[i].equals(""))
    {
      subTotal += Integer.parseInt(lines[i]);
    }
    else
    {
      topThree.add(subTotal);
      subTotal = 0;
    }
  }
  
  Collections.sort(topThree);
  int finalSum = 0;
   
  for(int i = 1; i <= 3; i++)
  {
    finalSum += topThree.get(topThree.size() - i); 
  }
   
  print(finalSum);
}
