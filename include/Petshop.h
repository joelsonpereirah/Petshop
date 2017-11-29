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
	std::vector<Veterinario> veterinarios;
    int id;
    std::string endereco;
    std::string cnpj;

	void read(string arquivo_clientes = "clientes",
						string arquivo_funcionarios = "funcionarios",
						string arquivo_veterinarios = "veterinarios");
	void write(string arquivo_clientes = "clientes",
						string arquivo_funcionarios = "funcionarios",
						string arquivo_veterinarios = "veterinarios");

    void ler_clientes(istream &);
	vector<Animal> ler_animais(istream &);
    void ler_funcionarios(istream &);
	void ler_veterinarios(istream &);

	void salvar_clientes(ostream &);
	void salvar_animais(ostream &, vector<Animal>);
    void salvar_funcionarios(ostream &);
	void salvar_veterinarios(ostream &);


};

#endif // PETSHOP_H_INCLUDED
