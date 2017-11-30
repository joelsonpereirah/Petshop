#include "../include/menu.h"

Cliente cadastro_cliente(){
    std::string nome, cpf, endereco, telefone;
    std::vector<Animal> animais;
    int qt_pet;
    std::cin.ignore(INT_MAX,'\n');
    std::cout << "Nome: "; getline(cin,nome);
    std::cout << "CPF: "; getline(cin,cpf);
    std::cout << "Endereço: "; getline(cin,endereco);
    std::cout << "Telefone: "; getline(cin,telefone);
    std::cout << "Quantos animais o cliente possui?"; std::cin >> qt_pet;
    std::cin.ignore(INT_MAX,'\n');
    for(int i=0; i<qt_pet; i++)
    {
        Animal aux = cadastro_animal();
        animais.push_back(aux);
    }
    Cliente cliente{nome, cpf, endereco, telefone, animais};
    return cliente;
}

Animal cadastro_animal(){
    std::string nome, nascimento, especie, raca;
    std::cout << "Nome: "; getline(cin,nome);
    std::cout << "Nascimento: "; getline(cin,nascimento);
    std::cout << "Espécie: "; getline(cin,especie);
    std::cout << "Raça: "; getline(cin,raca);
    Animal animal{nome, nascimento, especie, raca};

    return animal;
}