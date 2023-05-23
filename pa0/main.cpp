#include<cmath>
#include<Eigen3/Eigen/Core>
#include<Eigen3/Eigen/Dense>
#include<iostream>

using namespace std;
using namespace Eigen;

int main() {
    const float PI = 3.1415926;
    float ra =  PI / 4.0;
    float tx = 1.0f;
    float ty = 2.0f;
    Vector3f v(2.0f, 1.0f, 1.0f);

    Matrix3f r, t;
    r << cos(ra), -sin(ra), 0.0, 
         sin(ra), cos(ra), 0.0f, 
         0.0f, 0.0f, 1.0f;

    t << 1.0f, 0.0f, tx,
         0.0f, 1.0f, ty, 
         0.0f, 0.0f, 1.0f;

    cout << t * r * v;





    return 0;
}