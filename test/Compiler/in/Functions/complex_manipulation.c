int tao(int id){
  if (id == 2){
    return id+1;
  } else {
    return 0;
  }
}
int main(){
  int x = 0;
  int y = 0;
  for (x = 120; x>=1; x--){
    y += tao(x);
  }
  return y;
}
