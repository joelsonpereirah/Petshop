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

/// Função que pede os dados do funcionário a partir da entrada padrão e retorna
/// um objeto Funcionario contendo esses dados.
Funcionario cadastro_funcionario(){
  std::string nome, cpf, endereco, telefone, funcao, admissao;

    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Nome: "; getline(cin, nome);
    std::cout << "CPF: "; getline(cin, cpf);
    std::cout << "Endereço: "; getline(cin, endereco);
    std::cout << "Telefone: "; getline(cin, telefone);
    std::cout << "Função: "; getline(cin, funcao);
    std::cout << "Admissão: "; getline(cin, admissao);

    Funcionario funcionario(nome, cpf, endereco, telefone, funcao, admissao);
    return funcionario;
}

/// Função que pede os dados do veterinário a partir da entrada padrão e retorna
/// um objeto Veterinário contendo esses dados.
Veterinario cadastro_veterinario(){
  std::string nome, cpf, endereco, telefone, funcao, admissao, especializacao, crmv;

    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Nome: "; getline(cin, nome);
    std::cout << "CPF: "; getline(cin, cpf);
    std::cout << "Endereço: "; getline(cin, endereco);
    std::cout << "Telefone: "; getline(cin, telefone);
    std::cout << "Função: "; getline(cin, funcao);
    std::cout << "Admissão: "; getline(cin, admissao);
    std::cout << "Especialização: "; getline(cin, especializacao);
    std::cout << "crmv: "; getline(cin, crmv);

    Veterinario veterinario(nome, cpf, endereco, telefone, funcao, admissao, especializacao, crmv);
    return veterinario;
}
