#include <iostream>
#include <string>
#include "../include/Petshop.h"
#include"../include/menu.h"


using namespace std;

int main()
{


	Petshop pet;
	pet.read();

	int choice = 1;
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

	std::cin >> choice;

	
	switch(choice)
	{
		case 1:
			pet.clientes.push_back(cadastro_cliente());
			pet.write();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
      pet.editar_cliente();
			pet.write();
			break;
		case 5:
      pet.editar_funcionario();
			pet.write();
			break;
		case 6:
      pet.editar_veterinario();
			pet.write();
			break;
		case 7:
			pet.listar_clientes();
			break;
		case 8:
			break;
		case 9:
			break;
		case 0:
			break;
	}
	return 0;
}
