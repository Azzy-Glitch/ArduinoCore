#include <iostream>

using namespace std;

// float funcAverage(int a, int b){
//     float avg= (a+b)/2.0;
//     return avg;
// }

// float funcAverage(float a, int b){
//     float avg= (a+b)/2.0;
//     return avg;
// }

/*instead of creating different functions we use
 template function to use any type of data type
 into our function*/
template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T1, class T2>
float Average(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

/*By using template function we can get
 any type of data type as input to find avg
 instead of creating many functions for diff
 data types*/

int main()
{
    float a;
    a = Average(59.4, 2045);

    printf("\n");
    printf("The average of these numbers is %3f", a);
    printf("\n");

    int x = 17 , y = 29;
    swapp(x , y);
    cout << x << endl << y << endl;

    return 0;
}
