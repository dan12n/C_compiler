int rim(int a,int b){
  if (a<=1){
    return 1;
  } else {
    return rim(a-1,b);
  }
}

int tom(int rock){
  if (rock<=1){
    return 1;
  } else {
    return rim(rock-1,rock);
  }
}

int main(){
    int x;
    x = 120;
    return rim(171+11,3) + tom(11);
}
