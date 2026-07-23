#include <iostream>
#include <iomanip>

struct Sensor  {
    int distance_cm;
    int threshold_cm;
};

int main(){
    Sensor s;
    s.distance_cm = 15;
    s.threshold_cm = 20;
    bool obstacle = false;
    if(s.distance_cm < s.threshold_cm){
        obstacle=true;
    }
    
    if(obstacle){
    std::cout<<"Detected an obstacle"<<std::endl;
    }else{
        std::cout<<"Free path"<<std::endl;
    }
return 0;

   
}