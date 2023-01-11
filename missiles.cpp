// Lets Play Missiles!
// missiles.cpp

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "missiles.h"
using std::cout;
using std::cin;
using std::endl;


// Game settings...
// ***After getting this working, make missiles into classes, then use those classes for a Tron variant!***

double enemy_x = srand() % 15 + 10; 
double enemy_y = srand() % 15 + 10; // Initial x and y coordinates of missle; eventually, start this from y=0 (ground).
double you_x = 0, you_y = 0;  // Initial x and y of counter missile. 
double enemy_speed_x = 1, enemy_speed_y = 1;
double you_speed_x = 1.5, you_speed_y = 1.5; // Counter missiles better be quicker!
int you_fuel = 100;

double blast_radius = 0.5;
double move_x, move_y;
double diff = distance(enemy_x, you_y, enemy_x, you_y);


int main() {

    // While not intercepted...
    while (diff > blast_radius) {

        cout<<"\n\n...Chasing...\n"<<endl;

        // Chase!  (This could totally be a function...)
        
        cout<<"Enemy x and y coordinates: " << enemy_x << ", " << enemy_y <<'\n';
        cout<<"Your x and y coordinates: " << you_x << ", " << you_y <<"\n"; 
        cout<<"Distance to enemy missile: "<< diff <<"\n";       
        cout<<"What will the new coordinates be?  Maximum speeds currently are:\n";
        cout<< you_speed_x << " on the x-axis, " << you_speed_y << " on the y-axis.\n";
        cout<<"Move x:\n";
        cin>>move_x;
        cout<<"Move y:\n";
        cin>>move_y;
        if(abs(move_x) > you_speed_x || abs(move_y) > you_speed_y){
            cout<<"Can't move that fast sir, re-enter!\n"<<endl;
            cout<<"\nMove x:\n";
            cin>>move_x;
            cout<<"\nMove y:\n";
            cin>>move_y;
        } // End if
        
        // Update missile coordinates and fuel...
        you_x += move_x;
        you_y += move_y;
        you_fuel -= abs(move_x) + abs(move_y);

        // Update enemy missle location.
        enemy_x -= 1;
        enemy_y -= 1;

        diff = distance(enemy_x, you_x, enemy_y, you_y); 

        cout<<"\nEnemy coordinates: " << enemy_x << ", " << enemy_y <<"\n";
    
        cout<<"Distance is now: " << diff <<".\n";
        cout<<"Fuel level: " << you_fuel <<"\n";


        // Success?
        if(diff < blast_radius){
            cout<<"\nWithin blast radius, detonating.\n";
        } // End if

        // Defeat?
        if(enemy_x == 0 && enemy_y == 0){
            cout<<"\nDefense failed, your depot is wrecked, son.\n\n";
            return 0;
        } // End if


    } // End while

    cout<<"Defense successful!\n\n";
    return 0;

} // End main






























