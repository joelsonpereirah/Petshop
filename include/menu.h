#include<iostream>
#include<string>
#include<vector>
#include"Animal.h"
#include"Pessoa.h"
#include<limits.h>

int menu_principal();

Cliente cadastro_cliente();
Animal cadastro_animal();
Funcionario cadastro_funcionario();
Veterinario cadastro_veterinario();

Cliente editar_cliente(Cliente &cliente);
Animal editar_animal(Animal &animal);
Funcionario editar_funcionario(Funcionario &funcionario);
Veterinario editar_veterinario(Veterinario &veterinario);

void listar_clientes(std::vector<Cliente> &clienteData);
void listar_animais(std::vector<Animal> &animalData);
void listar_funcionarios(std::vector<Funcionario> &funcionarioData);
void listar_veterinario(std::vector<Veterinario> &veterinarioData);