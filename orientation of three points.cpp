#include <iostream>
using namespace std;
 
struct Point
{
    int x, y;
};
int orientation(Point q1, Point q2, Point q3)
{
    
    int val = (q2.y - q1.y) * (q3.x - q2.x) - (q2.x - q1.x) * (q3.y - q2.y);
 
    if (val == 0) return 0; 
 
    return (val > 0)? 1: 2; 
}
 

int main()
{
    Point q1 = {0, 0}, q2 = {4, 4}, q3 = {1, 2};
    int o = orientation(q1, q2, q3);
    if (o==0)         cout << "Linear";
    else if (o == 1)  cout << "Clockwise";
    else              cout << "CounterClockwise";
    return 0;
}
