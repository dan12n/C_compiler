int thirst(int x) {
  return x*2;
}

int rim(int a,int b){
  if (a<2){
    return 1;
  } else {
    return thirst(a/=10);
  }
}

int tom(int rock){
  if (rock<2){
    return 1;
  } else {
    return rim(rock-1,453);
  }
}

int main(){
    int x;
    x = 120;
    return rim(x,3) + tom(x) - thirst(x*2);
}
