#include <iostream>

namespace Front {
    int threshold_cm = 20;
}

namespace Rear {
    int threshold_cm = 15;
}

int main() {
    int front_distance = 18;
    int rear_distance = 25;

    if (front_distance < Front::threshold_cm) {
        std::cout << "Front: obstacle" << std::endl;
    } else {
        std::cout << "Front: clear" << std::endl;
    }

    if (rear_distance < Rear::threshold_cm) {
        std::cout << "Rear: obstacle" << std::endl;
    } else {
        std::cout << "Rear: clear" << std::endl;
    }

    return 0;
}