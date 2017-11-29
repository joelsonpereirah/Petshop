
#include "Petshop.h"
#include "Pessoa.h" 

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Petshop::Petshop(){
	
}

Petshop::~Petshop(){
}


void Petshop::cadastrar_clientes(Cliente m_cliente){
	clientes.push_back(m_cliente);
}

void Petshop::mostrar_clientes(){
	 for(unsigned int i = 0 ; i < clientes.size(); i++){
	 	cout<<"Nome:"<<clientes[i].getNome()<<endl;
	 	cout<<"Telefone:"<<clientes[i].getTelefone()<<endl;	 	
	 	
	 }
}

void Petshop::cadastrar_funcionarios(Funcionario m_funcionario){

	funcionarios.push_back(m_funcionario);
}

void Petshop::mostrar_funcionarios(){
	 for(unsigned int i = 0 ; i < funcionarios.size(); i++){
	 	cout<<funcionarios[i].getNome();
	 }
}

/// Lê os dados do sistema armazenados durante a persistência.
/// @param arquivo Nome do arquivo contendo os dados dos clientes
void Petshop::ler_dados(string arquivo) {
	ifstream fp(arquivo);
	ler_clientes(fp);
	fp.close();
}

/// Faz a leitura dos dados dos clientes, separados por '|',
/// a partir do fluxo de entrada.
/// Sendo a leitura dada pela ordem: nome, CPF, endereço e telefone.
/// @param in Fluxo de entrada
void Petshop::ler_clientes(istream &in) {
	string line;
	while (getline(in, line)) {
		string nome, cpf, endereco, telefone;

		stringstream ss(line);
		getline(ss, nome, '|');
		getline(ss, cpf, '|' );
		getline(ss, endereco, '|');
		getline(ss, telefone);

		ifstream fp(cpf);
		vector<Animal> animais = ler_animais(fp);
		fp.close();

		Cliente cliente(nome, cpf, endereco, telefone, animais);

		clientes.push_back(cliente);
	}
}

/// Faz a leitura dos dados dos animais, separados por '|',
/// a partir do fluxo de entrada.
/// Sendo a leitura dada pela ordem: nome, nascimento, espécie, raça e id.
/// @param in Fluxo de entrada
vector<Animal> Petshop::ler_animais(istream &in) {
	vector<Animal> animais;
	string line;

	while (getline(in, line)) {
		string nome, nascimento, especie, raca;
		string s_id;

		stringstream ss(line);
		getline(ss, nome, '|');
		getline(ss, nascimento, '|');
		getline(ss, especie, '|');
		getline(ss, raca, '|');
		getline(ss, s_id);

		int id = std::stoi(s_id);

		Animal animal(nome, id, nascimento, especie, raca);
		animais.push_back(animal);
	}

	return animais;
}

/// Persiste os dados da aplicação.
/// @param arquivo Nome do arquivo contendo os dados dos clientes
void Petshop::salvar_dados(string arquivo) {
	ofstream fp(arquivo);
	salvar_clientes(fp);
	fp.close();
}

/// Persiste os dados dos clientes, separados por '|',
/// no fluxo de saída.
/// Sendo dada pela ordem: nome, CPF, endereço e telefone.
/// @param in Fluxo de saída
void Petshop::salvar_clientes(ostream &out) {
	for (auto cliente : clientes) {
		out << cliente.getNome() << '|' << cliente.getCpf() << '|'
				<< cliente.getEndereco() << '|' << cliente.getTelefone() << std::endl;

		ofstream fp(cliente.getCpf());
		salvar_animais(fp, cliente.getAnimais());
		fp.close();
	}
}

/// Persiste os dados dos animais, separados por '|',
/// no fluxo de fluxo.
/// Sendo dada pela ordem: nome, nascimento, espécie, raça e id.
/// @param out Fluxo de saída
void Petshop::salvar_animais(ostream &out, vector<Animal> animais) {
	for (auto animal : animais) {
		out << animal.getNome() << '|' << animal.getNascimento() << '|'
        << animal.getEspecie() << '|' << animal.getRaca() << '|'
        << animal.getId() << std::endl;
	}
}
