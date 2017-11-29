#ifndef PETSHOP_H_INCLUDED
#define PETSHOP_H_INCLUDED

#include "Animal.h"
#include "Pessoa.h"
#include <fstream>
#include <string>

class Petshop
{

public:
    std::vector<Cliente> clientes;
	std::vector<Funcionario> funcionarios;
	std::vector<Veterinario> veterionarios;
    int id;
    std::string endereco;
    std::string cnpj;

	void read(std::string file);
	void write(std::string file);

};

#endif // PETSHOP_H_INCLUDED
