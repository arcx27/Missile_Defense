// Missiles classes and functions.

class defense_missile {
    
    double x_coord, y_coord, x_speed, y_speed;
    int fuel;

    public:
        void set_values(double, double, double, double, int);

    }; // Remember, classes end with ;





// Define a distance between points function...

double distance(double w, double x, double y, double z){
    double a = w - x;
    double b = y - z;
    double dist = sqrt(pow(a, 2) + pow(b, 2));
    return dist;
    } // End distance


// Missiles incoming, but from where?
/*
int initial_position(int x, int y){
    x = rand()% 15 + 10;
    y = rand()% 15 + 10;
    return x, y;
    }
*/

// Easy Enemy Avoidance Function

double easy_avoid(double a, double b, double x, double y){

    double new_x, new_y;

    // a = enemy_x, b = enemy_y, x = you_x, y = you_y
    double dist_x = a - x;
    double dist_y = b - y;
        
    if(dist_x <= 2 && dist_y > 0){
        new_y = b - 1;      // Eventually replace 1 with x_speed and y_speed, respectively
        new_x = a;
        return new_x, new_y;
        }

    else if(dist_x < -1 && dist_y){
        new_y = b - 1;
        new_x = a - 1;
        return new_x, new_y;
        }
    
    else{
        new_x = a - 1;
        new_y = b - 1;
        return new_x, new_y;
        }

    } // End easy_avoid
















