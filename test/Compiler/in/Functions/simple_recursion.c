int factorial(int i) {

   if(i < 2) {
        return 1;
   } else {
        return 5 * factorial(i - 1);
    }
}

int  main() {
   int i = 6;

   return factorial(i);
}