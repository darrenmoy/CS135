/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9 Pointers 

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Coord3D{          //declare class type that represents coordinates in 3D
public:
    double x;
    double y;
    double z;

};

double length(Coord3D *p){      //fnc length, receives coordinates of point P passed as pointer 
    double len;                 //computes the distance from origin to P 
    len = (sqrt((pow(p->x,2))+(pow(p->y,2))+(pow(p->z,2))));
    return len;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){  //2 coordinates
    if (length(p1) > length(p2)){       //if p1 distance > p2 distance 
        return p1;
    }
    else{
        return p2;
    }
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *newcoord = new Coord3D;
    *newcoord = {x, y, z};
    return newcoord;
}

void deleteCoord3D(Coord3D *p){
    delete p;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){ 
    ppos->x = ppos->x + pvel->x * dt;   //
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}
//updates the obj's position ppos with new coordinates, an object moving at constant
//velocity, vel, after elapsted time, dt

int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}