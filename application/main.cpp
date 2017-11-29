#include <iostream>
#include <string>
#include "Animal.h"
#include "Pessoa.h"
#include "Petshop.h"



using namespace std;

void menu1(){
	std::cout<<"PSeja Bem Vindo - PETSHOP!!"<<std::endl;

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
}

int main()
{
	int op=1;

	Petshop petshop;

	petshop.read();

	Animal animal1("nome1", 1, "nascimento1", "especie1", "raca1");
	Animal animal2("nome2", 2, "nascimento2", "especie2", "raca2");
	Animal animal3("nome3", 3, "nascimento3", "especie3", "raca3");

	vector<Animal> animais;

	animais.push_back(animal1);
	animais.push_back(animal2);
	animais.push_back(animal3);

	Cliente cliente("nome2", "12345678", "endereco2", "12345677", animais);
	petshop.clientes.push_back(cliente);

	while(op)
	{
		menu1();
		cin>>op;
		system("clear");
	}

	petshop.write();

return 0;

}
