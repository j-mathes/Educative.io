template<class T>
void sort(T a[], int size)
{
  for(int i = 0; i < size; i++)
  {
    int smallest = index_of_smallest(a, i, size);
    if(smallest != i)
      swap_values(a[i], a[smallest]);
  }
}

//Testing code. You don't need to make any changes here
string test(int a[], double b[]) {
 
    string str="";
    sort(a,5);
    sort(b,5);
    
    for (int i=0; i<5; i++){
      str += to_string(a[i]) + " ";
   }
  
    for (int i=0; i<5; i++){
      str += to_string(b[i]) + " ";
    }
  
  return str;
    
}
