int main()
{
  int x = 17;
  {
    int x = 11;
    {
      int x = 12;
    }
  }
  return x;
}
