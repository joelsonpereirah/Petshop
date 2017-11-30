#include "../include/menu.h"

int menu_principal(){
    int choice;
    std::cout<<"Seja Bem Vindo - PETSHOP!!"<<std::endl;

  	std::cout<<"-------MENU---------"<<std::endl;

  	std::cout<<"---CADASTROS---"<<std::endl;
  	std::cout<<"[1] Cadastrar Clientes"<<std::endl;
  	std::cout<<"[2] Cadastrar Funcionário"<<std::endl;
  	std::cout<<"[3] Cadastrar Veterinario"<<std::endl;
  
  	std::cout<<"---EDITAR---"<<std::endl;
  	std::cout<<"[4] Editar Cliente"<<std::endl;
  	std::cout<<"[5] Editar Funcionario"<<std::endl;
  	std::cout<<"[6] Editar Veterinario"<<std::endl;

  	std::cout<<"---LISTAR---"<<std::endl;
  	std::cout<<"[7] Listar Clientes"<<std::endl; 
  	std::cout<<"[8] Listar Funcionarios"<<std::endl; 
  	std::cout<<"[9] Listar Veterinario"<<std::endl; 

  	std::cout << "[0] Saída" << std::endl;

	std::cout << "Escolha: ";std::cin >> choice;

    return choice;
}


Cliente cadastro_cliente(){
    std::string nome, cpf, endereco, telefone;
    std::vector<Animal> animais;
    int qt_pet;

    std::cin.ignore(INT_MAX,'\n');
    std::cout << "Nome: "; getline(cin,nome);
    std::cout << "CPF: "; getline(cin,cpf);
    std::cout << "Endereço: "; getline(cin,endereco);
    std::cout << "Telefone: "; getline(cin,telefone);
    std::cout << "Quantidade de animais: "; std::cin >> qt_pet;
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
    std::cout << "Nome do animal: "; getline(cin,nome);
    std::cout << "Data de nascimento do animal: "; getline(cin,nascimento);
    std::cout << "Espécie: "; getline(cin,especie);
    std::cout << "Raça: "; getline(cin,raca);
    Animal animal{nome, nascimento, especie, raca};

    return animal;
}

Cliente editar_cliente(Cliente &cliente){
    
    std::cout << "---Editar cliente---" << std::endl;
  	std::cout << "[1] Editar animais" << std::endl;
    std::cout << "[2] Editar nome" << std::endl;
    std::cout << "[3] Editar cpf" << std::endl;
    std::cout << "[4] Editar endereco" << std::endl;
    std::cout << "[5] Editar telefone" << std::endl;
    std::cout << "Escolha: " << std::endl;

    int choice;
    std::cin >> choice;

    string newStr;
    int animal_position;
    std::vector<Animal> animais;
    switch(choice){
        case 1:
            //Listar animal
            //enviar para a função editar_animal a escolha feita através da listagem
            animais = cliente.getAnimais();
            listar_animais(animais);

            std::cout << "Digite o número associado ao animal que se deseja editar: ";
            std::cin >> animal_position;
            editar_animal(animais[animal_position]);

            cliente.setAnimais(animais);
            break;
        case 2:
            std::cout << "Digite o novo nome: "; std::cin >> newStr;
            cliente.setNome(newStr);
            break;
        case 3:
            std::cout << "Digite o novo cpf: "; std::cin >> newStr;
            cliente.setCpf(newStr);
            break;
        case 4:
            std::cout << "Digite o novo endereço: "; std::cin >> newStr;
            cliente.setEndereco(newStr);
            break;
        case 5:
            std::cout << "Digite o novo telefone: "; std::cin >> newStr;
            cliente.setTelefone(newStr);
            break;
    }
    return cliente;
}


Animal editar_animal(Animal &animal){
    std::cout << "---Editar animal---" << std::endl;
  	std::cout << "[1] Editar nome" << std::endl;
    std::cout << "[2] Editar nascimento" << std::endl;
    std::cout << "[3] Editar espécie" << std::endl;
    std::cout << "[4] Editar raça" << std::endl;
    std::cout << "Escolha: " << std::endl;

    int choice;
    std::cin >> choice;

    string newStr;
    switch(choice){
        case 1:
            std::cout << "Digite o novo nome: "; std::cin >> newStr;
            animal.setNome(newStr);
            break;
        case 3:
            std::cout << "Digite a nova data de nascimento: "; std::cin >> newStr;
            animal.setNascimento(newStr);
            break;
        case 4:
            std::cout << "Digite a nova espécie: "; std::cin >> newStr;
            animal.setEspecie(newStr);
            break;
        case 5:
            std::cout << "Digite a nova raça: "; std::cin >> newStr;
            animal.setRaca(newStr);
            break;
    }
    return animal;
}

void listar_clientes(std::vector<Cliente> &clienteData){
    std::vector<Animal> animais;
    for(uint i = 0; i < clienteData.size(); i++)
    {
        std::cout << "[" << i+1 << "] " << clienteData[i].getNome() << ": " << std::endl;
        std::cout << "  Cpf: " << clienteData[i].getCpf() << std::endl;
        std::cout << "  Endereco: " << clienteData[i].getEndereco() << std::endl;
        std::cout << "  Telefone: " << clienteData[i].getTelefone() << std::endl;
        std::cout << "  Animais: " << std::endl;
        animais = clienteData[i].getAnimais();
        for(uint j = 0; j < animais.size(); j++){
            std::cout << "    ["<< j+1 << "]" <<animais[j].getNome() << ": " << std::endl;
            std::cout << "      Nascimento: " << animais[j].getNome() << std::endl;
            std::cout << "      Espécie: " << animais[j].getNome() << std::endl;
            std::cout << "      Raça: " << animais[j].getNome() << std::endl;
        }
        std::cout << std::endl;
    }   
}
void listar_animais(std::vector<Animal> &animalData){
    for(uint i = 0; i < animalData.size(); i++)
    {
        std::cout << "[" << i+1 << "]" << animalData[i].getNome() << ": " << std::endl;
        std::cout << "  Nascimento: " << animalData[i].getNome() << std::endl;
        std::cout << "  Espécie: " << animalData[i].getNome() << std::endl;
        std::cout << "  Raça: " << animalData[i].getNome() << std::endl;
        std::cout << std::endl;
    } 
}


void listar_funcionarios(std::vector<Funcionario> &funcionarioData){
    for(uint i = 0; i < funcionarioData.size(); i++)
    {
        std::cout << "[" << i+1 << "] " << funcionarioData[i].getNome() << ": " << std::endl;
        std::cout << "  Cpf: " << funcionarioData[i].getCpf() << std::endl;
        std::cout << "  Endereco: " << funcionarioData[i].getEndereco() << std::endl;
        std::cout << "  Telefone: " << funcionarioData[i].getTelefone() << std::endl;
        std::cout << "  Funcao: " << funcionarioData[i].getTelefone() << std::endl;
        std::cout << "  Admissao: " << funcionarioData[i].getTelefone() << std::endl;
        std::cout << std::endl;
    }
}
void listar_veterinario(std::vector<Veterinario> &veterinarioData){
    for(uint i = 0; i < veterinarioData.size(); i++)
    {
        std::cout << "[" << i+1 << "] " << veterinarioData[i].getNome() << ": " << std::endl;
        std::cout << "  Cpf: " << veterinarioData[i].getCpf() << std::endl;
        std::cout << "  Endereco: " << veterinarioData[i].getEndereco() << std::endl;
        std::cout << "  Telefone: " << veterinarioData[i].getTelefone() << std::endl;
        std::cout << "  Funcao: " << veterinarioData[i].getTelefone() << std::endl;
        std::cout << "  Admissao: " << veterinarioData[i].getTelefone() << std::endl;
        std::cout << "  Especialização: " << veterinarioData[i].getEspecializacao() << std::endl;
        std::cout << "  Crmv: " << veterinarioData[i].getCrmv() << std::endl;
        std::cout << std::endl;
    }
}
//