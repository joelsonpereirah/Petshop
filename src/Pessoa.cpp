#include "../include/Pessoa.h"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


//////////////Construtores e Destrutores--- PESSSOA/////////////////////
Pessoa::Pessoa(){
	nome = "";
	cpf = "";
	endereco = "";
	telefone = "";
}

Pessoa::Pessoa(string m_nome, string m_cpf, string m_endereco, string m_telefone){
    nome = m_nome;
    cpf = m_cpf;
    endereco = m_endereco;
    telefone = m_telefone;
}


Pessoa::~Pessoa(){

}


///////////////////////////////////GET's e SET's --- PESSSOA////////////////////////////////
string Pessoa::getNome() const{
    return nome;
}

void Pessoa::setNome(string m_nome){
    nome = m_nome;
}


string Pessoa::getCpf() const{
    return cpf;
}

void Pessoa::setCpf(string m_cpf){
    cpf = m_cpf;
}


string Pessoa::getEndereco() const{
    return endereco;
}

void Pessoa::setEndereco(string m_endereco){
    endereco = m_endereco;
}


string Pessoa::getTelefone() const{
    return telefone;
}

void Pessoa::setTelefone(string m_telefone){
    telefone = m_telefone;
}

/// Edita os dados de Pessoa a partir dos valores pedidos no fluxo de entrada
/// padrão.
void Pessoa::editar(){
	string nome, cpf, endereco, telefone;

	std::cin.ignore(INT_MAX, '\n');

	std::cout << "Editar nome (" << this->nome << "): ";
	getline(cin, nome);
	if (nome.length() > 0) {
		setNome(nome);
	}

	std::cout << "Editar endereço (" << this->endereco << "): ";
	getline(cin, endereco);
	if (endereco.length() > 0) {
		setEndereco(endereco);
	}

	std::cout << "Editar telefone (" << this->telefone << "): ";
	getline(cin, telefone);
	if (telefone.length() > 0) {
		setTelefone(telefone);
	}
}

///////////////////Construtores e Destrutores ---FUNCIONARIOS////////////////q
Funcionario::Funcionario():Pessoa(){

    funcao = "";
    admissao = "";

}
Funcionario::Funcionario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao)
: Pessoa(m_nome, m_cpf, m_endereco, m_telefone){

    funcao = m_funcao;
    admissao = m_admissao;


}

Funcionario::~Funcionario(){

}

/////////GET's e SET's------FUNCIONARIOS////////////q

string Funcionario::getFuncao() const{
    return funcao;
}

void Funcionario::setFuncao(string m_funcao){
    funcao = m_funcao;
}


string Funcionario::getAdmissao() const{
    return admissao;
}

void Funcionario::setAdmissao(string m_admissao){
    admissao = m_admissao;
}

/// Edita os dados de Funcionario a partir dos valores pedidos no fluxo de entrada
/// padrão.
void Funcionario::editar(){
	Pessoa::editar();

	string funcao, admissao;

	std::cout << "Editar função (" << this->funcao << "): ";
	getline(cin, funcao);
	if (funcao.length() > 0) {
		setFuncao(funcao);
	}

	std::cout << "Editar admissão (" << this->admissao << "): ";
	getline(cin, admissao);
	if (admissao.length() > 0) {
		setAdmissao(admissao);
	}
}

/////////////Construtores e Destrutores -- FUNCIONARIO //////

Veterinario::Veterinario(): Funcionario(){

    especializacao = "";
    crmv = "";

}

Veterinario::Veterinario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao, 
    string m_espcializacao, string m_crmv) : Funcionario(m_nome, m_cpf, m_endereco, m_telefone, m_funcao, m_admissao){
    
    especializacao = m_espcializacao;
    crmv = m_crmv;
    
}


Veterinario::~Veterinario(){

}
////////////SET's e GET's ---- VETERINARIO/////////////

string Veterinario::getEspecializacao() const{
    return especializacao;
}

void Veterinario::setEspecializacao(string m_espcializacao){
    especializacao = m_espcializacao;
}


string Veterinario::getCrmv() const{
    return crmv;
}

void Veterinario::setCrmv(string m_crmv){
    crmv = m_crmv;
}

/// Edita os dados de Veterinario a partir dos valores pedidos no fluxo de entrada
/// padrão.
void Veterinario::editar(){
	Funcionario::editar();

	string especializacao, crmv;

	std::cout << "Editar especialização (" << this->especializacao << "): ";
	getline(cin, especializacao);
	if (especializacao.length() > 0) {
		setFuncao(especializacao);
	}

	std::cout << "Editar CRMV (" << this->crmv << "): ";
	getline(cin, crmv);
	if (crmv.length() > 0) {
		setAdmissao(crmv);
	}
}

//Constructors & Destructors
Cliente::Cliente(){
    nome = "";
    cpf = "";
    endereco = "";
    telefone = "";
}

Cliente::Cliente(string m_nome, string m_cpf, string m_endereco, string m_telefone, vector<Animal> m_animal)
:Pessoa(m_nome, m_cpf, m_endereco, m_telefone){
    
    animais = m_animal;
}

Cliente::~Cliente(){

}

//Sets & Gets
void Cliente::setAnimais(vector<Animal> &animais_ext){
	animais = animais_ext;
}       
  
vector<Animal> Cliente::getAnimais() const{
    return animais;
}  

Cliente Cliente::operator= (const Cliente &obj){
    animais = obj.getAnimais();

    return *this;
}







