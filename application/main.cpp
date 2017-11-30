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
	pet.read();
	uint editar_posicao;
	while(choice){
		choice = menu_principal();
		switch(choice)
		{
			//Cadastrar Cliente
			case 1:
				pet.clientes.push_back(cadastro_cliente());
				break;

			//Cadastrar Funcionário
			case 2:
				pet.funcionarios.push_back(cadastro_funcionario());
				break;

			//Cadastrar Veterinário
			case 3:
				pet.veterinarios.push_back(cadastro_veterinario());
				break;

			//Editar Cliente
			case 4:
				listar_clientes(pet.clientes);

				std::cout << "Digite o número associado ao cliente que se deseja editar: ";
				std::cin >> editar_posicao;
				if( editar_posicao < 1 || editar_posicao > pet.clientes.size())
				{
					std::cout << "Posição inválida" << std::endl;
					break;
				}
				editar_cliente(pet.clientes[editar_posicao-1]);
				break;

			//Editar Funcionário
			case 5:
				listar_funcionarios(pet.funcionarios);

				std::cout << "Digite o número associado ao veterinário que se deseja editar: ";
				std::cin >> editar_posicao;
				if( editar_posicao < 1 || editar_posicao > pet.funcionarios.size())
				{
					std::cout << "Posição inválida" << std::endl;
					break;
				}

				editar_veterinario(pet.veterinarios[editar_posicao-1]);
				
				break;

			//Editar Veterinário
			case 6:
				listar_veterinarios(pet.veterinarios);

				std::cout << "Digite o número associado ao veterinário que se deseja editar: ";
				std::cin >> editar_posicao;
				if( editar_posicao < 1 || editar_posicao > pet.veterinarios.size())
				{
					std::cout << "Posição inválida" << std::endl;
					break;
				}

				editar_veterinario(pet.veterinarios[editar_posicao-1]);
				break;

			//Listar Clientes
			case 7:
				listar_clientes(pet.clientes);
				break;
			//Listar Funcionário
			case 8:
				listar_funcionarios(pet.funcionarios);
				break;
			//Listar Veterinário
			case 9:
				listar_veterinarios(pet.veterinarios);
				break;
			default:
				
				choice = 0;
				break;
		}
		string wait_for_input;
		if(choice!=0){
			std::cout << "Digite algo e pressione enter para voltar ao menu principal" << std::endl;
			getline(cin, wait_for_input);
		}
		
	}
	

	

	pet.write();
	return 0;
}
