int rust(int y){
  return y*13;
}


int hola(int x, int y){
    int i;

    for (i = 0; i < 10; i++) {
      x += rust(y) + i;
    }
    
    return 2*x;
}

int main(){
    int x;
    x = 120;
    int y;

    for (x = 0; x<123; x++){
      x+= hola(x,11);
      y = hola(-21,-31);
      while (x < 12){
        ++x;
        break;
      }
    }
    return x+y;
}
