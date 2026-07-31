#include <iostream>

class Sensor {
private:
    int distance_cm;
    int threshold_cm;

public:
    Sensor(int distance, int threshold) {
        distance_cm = distance;
        threshold_cm = threshold;
    }

    bool obstacleDetected() {
        return distance_cm < threshold_cm;
    }
   
};

int main() {
    Sensor front(18, 20);
    Sensor rear(25,20);

    if (front.obstacleDetected()) {
        std::cout << "Obstacle detected!" << std::endl;
    } else {
        std::cout << "Clear path." << std::endl;
    }
       if (rear.obstacleDetected()) {
        std::cout << "Obstacle detected!" << std::endl;
    } else {
        std::cout << "Clear path." << std::endl;
    }

    return 0;
}