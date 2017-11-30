#include <iostream>
#include <string>
#include "../include/Petshop.h"
#include"../include/menu.h"

using namespace std;

int main()
{
	int choice = 1;
	Petshop pet;
	//Fazer a leitura dos arquivos

	uint editar_cliente_posicao;
	while(choice){
		choice = menu_principal();
		system("clear");
		switch(choice)
		{
			//Cadastrar Cliente
			case 1:
				pet.clientes.push_back(cadastro_cliente());
				pet.write();
				break;

			//Cadastrar Funcionário
			case 2:
				break;

			//Cadastrar Veterinário
			case 3:
				break;

			//Editar Cliente
			case 4:
				listar_clientes(pet.clientes);

				std::cout << "Digite o número associado ao cliente que se deseja editar: ";
				std::cin >> editar_cliente_posicao;
				if( editar_cliente_posicao < 1 || editar_cliente_posicao > pet.clientes.size())
				{
					std::cout << "Posição inválida" << std::endl;
					break;
				}
				editar_cliente(pet.clientes[editar_cliente_posicao-1]);
				break;

			//Editar Funcionário
			case 5:
				break;

			//Editar Veterinário
			case 6:
				break;

			//Listar Clientes
			case 7:
				listar_clientes(pet.clientes);
				break;
			//Listar Funcionário
			case 8:
				break;
			//Listar Veterinário
			case 9:
				break;
			default:
				choice = 0;
				break;
		}
		std::cin.ignore(INT_MAX,'\n');
		string wait_for_input;
		std::cout << "Digite algo e pressione enter para voltar ao menu principal" << std::endl;
		getline(cin, wait_for_input);
	}
	

	

	
	return 0;
}
