int count_to_ten ( int count )
{
       if (count < 10)   
       {
           count_to_ten(count + 1);
       }
       return count;
}

int main()
{
  return count_to_ten (0) + count_to_ten (1) + count_to_ten (2);

}