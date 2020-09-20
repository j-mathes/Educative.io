#include <iostream>
using namespace std;


class Student{
  private:
    string name;
    float mark1;
    float mark2;
  public:
         Student() {
           name = "null";
         }
         Student(string na, float ma1,float ma2){ 
           name = na;
           mark1 = ma1;
           mark2 = ma2;
         }
         int GetMarks(int marknumber){
           if (marknumber == 1)
            return mark1;
           else
            return mark2;
         }
         float calc_average(){
           return (mark1 + mark2) / 2;
         }
};
