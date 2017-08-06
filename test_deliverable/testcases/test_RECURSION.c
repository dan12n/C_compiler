int factorial(int i) {

   if(i < 5) {
        return 1;
   } else {
        return factorial(i - 1) + 1;
    }
}