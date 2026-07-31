#include <iostream>

class Motor {
private:
    int velocity_km;
    bool on_off; // TODO: dois atributos privados — um int para velocidade (0-100), um bool para "ligado"

public:
    Motor (float velocity, bool state){
    velocity_km=velocity;
    on_off=state;
    }// TODO: construtor que recebe velocidade e estado ligado, e guarda nos atributos
    bool isRunning(){
        return on_off;
    }
    // TODO: um metodo bool isRunning() que devolve se o motor esta ligado
    void printStatus(){
        std::cout<<"Velocidade: "<<velocity_km<<" e o estado é:"<<on_off<<std::endl;

    }
    // TODO: um metodo void printStatus() que imprime a velocidade e o estado (usa cout)
};

int main() {
    Motor left_motor(50, 1);// TODO: cria um objeto Motor chamado left_motor, velocidade 50, ligado = true
    left_motor.printStatus();// TODO: chama printStatus() nesse motor

    return 0;
}