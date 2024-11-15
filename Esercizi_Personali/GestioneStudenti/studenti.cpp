#include <iostream>



class Student {
public:
    Student(std::string nome) {
        this -> nome = nome;
    } 

    void printNome() {
        std::cout << nome << std::endl;
    }
private:
    std::string nome;
};

int main() {
    Student studente1("Alessio");

    studente1.printNome();

}