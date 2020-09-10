void passReference(int * a, int * b) 
{
    *a = pow(*a, *b);
    *b = *a % *b;
} 
