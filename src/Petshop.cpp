
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
void Petshop::read(string arquivo_clientes,
									 string arquivo_funcionarios,
									 string arquivo_veterinarios) {
	ifstream fp_clientes(arquivo_clientes);
	ler_clientes(fp_clientes);
	fp_clientes.close();

	ifstream fp_funcionarios(arquivo_funcionarios);
	ler_funcionarios(fp_funcionarios);
	fp_clientes.close();

	ifstream fp_veterinarios(arquivo_veterinarios);
	ler_veterinarios(fp_veterinarios);
	fp_veterinarios.close();
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

/// Faz a leitura dos dados dos funcionários, separados por '|',
/// a partir do fluxo de entrada.
/// Sendo a leitura dada pela ordem: nome, cpf, endereço, telefone, função e
//admissao.
/// @param in Fluxo de entrada
void Petshop::ler_funcionarios(istream &in) {
	string line;
	while (getline(in, line)) {
    string nome, cpf, endereco, telefone, funcao, admissao;

		stringstream ss(line);
		getline(ss, nome, '|');
		getline(ss, cpf, '|' );
		getline(ss, endereco, '|');
		getline(ss, telefone, '|');
		getline(ss, funcao, '|');
		getline(ss, admissao);

		Funcionario funcionario(nome, cpf, endereco, telefone, funcao, admissao);

		funcionarios.push_back(funcionario);
	}
}

/// Faz a leitura dos dados dos veterinários, separados por '|',
/// a partir do fluxo de entrada.
/// Sendo a leitura dada pela ordem: nome, cpf, endereço, telefone, função e
//admissao, especialização e crmv
/// @param in Fluxo de entrada
void Petshop::ler_veterinarios(istream &in) {
	string line;
	while (getline(in, line)) {
    string nome, cpf, endereco, telefone, funcao, admissao, especializacao, crmv;

		stringstream ss(line);
		getline(ss, nome, '|');
		getline(ss, cpf, '|' );
		getline(ss, endereco, '|');
		getline(ss, telefone, '|');
		getline(ss, funcao, '|');
		getline(ss, admissao, '|');
		getline(ss, especializacao, '|');
		getline(ss, crmv);

		Veterinario veterinario(nome, cpf, endereco, telefone, funcao, admissao, especializacao, crmv);

		veterinarios.push_back(veterinario);
	}
}

/// Persiste os dados da aplicação.
/// @param arquivo Nome do arquivo contendo os dados dos clientes
void Petshop::write(string arquivo_clientes,
									  string arquivo_funcionarios,
									  string arquivo_veterinarios) {
	ofstream fp_clientes(arquivo_clientes);
	salvar_clientes(fp_clientes);
	fp_clientes.close();

	ofstream fp_funcionarios(arquivo_funcionarios);
	salvar_funcionarios(fp_funcionarios);
	fp_funcionarios.close();

	ofstream fp_veterinarios(arquivo_veterinarios);
	salvar_veterinarios(fp_veterinarios);
	fp_veterinarios.close();
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
/// no fluxo de saída.
/// Sendo dada pela ordem: nome, nascimento, espécie, raça e id.
/// @param out Fluxo de saída
void Petshop::salvar_animais(ostream &out, vector<Animal> animais) {
	for (auto animal : animais) {
		out << animal.getNome() << '|' << animal.getNascimento() << '|'
				<< animal.getEspecie() << '|' << animal.getRaca() << '|'
				<< animal.getId() << std::endl;
	}
}

/// Persiste os dados dos funcionários, separados por '|',
/// no fluxo de saída.
/// Sendo dada pela ordem: nome, CPF, endereço, telefone, função, admissão.
/// @param in Fluxo de saída
void Petshop::salvar_funcionarios(ostream &out) {
	for (auto funcionario : funcionarios) {
		out << funcionario.getNome() << '|' << funcionario.getCpf() << '|'
				<< funcionario.getEndereco() << '|' << funcionario.getTelefone() << '|'
				<< funcionario.getFuncao() << '|' << funcionario.getAdmissao()
				<< std::endl;
	}
}

/// Persiste os dados dos veterinários, separados por '|',
/// no fluxo de saída.
/// Sendo dada pela ordem: nome, CPF, endereço, telefone, função, admissão,
/// especialização e CRMV.
/// @param in Fluxo de saída
void Petshop::salvar_veterinarios(ostream &out) {
	for (auto veterinario : veterinarios) {
		out << veterinario.getNome() << '|' << veterinario.getCpf() << '|'
				<< veterinario.getEndereco() << '|' << veterinario.getTelefone() << '|'
				<< veterinario.getFuncao() << '|' << veterinario.getAdmissao() << '|'
				<< veterinario.getEspecializacao() << '|' << veterinario.getCrmv()
				<< std::endl;
	}
}
