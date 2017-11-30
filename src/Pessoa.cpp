#include "../include/Pessoa.h"
#include <iostream>
#include <algorithm>
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

Funcionario Funcionario::operator= ( const Funcionario &other){
    funcao = other.getFuncao();
	admissao = other.getAdmissao();
    nome = other.getNome();
	cpf = other.getCpf();
	endereco = other.getEndereco();
	telefone = other.getTelefone();

    return *this;
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

Veterinario Veterinario::operator= ( const Veterinario &other){
    especializacao = other.getEspecializacao();
    crmv = other.getCrmv();
    funcao = other.getFuncao();
	admissao = other.getAdmissao();
    nome = other.getNome();
	cpf = other.getCpf();
	endereco = other.getEndereco();
	telefone = other.getTelefone();

    return *this;
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
    nome = obj.getNome();
	cpf = obj.getCpf();
	endereco = obj.getEndereco();
	telefone = obj.getTelefone();
    return *this;
}







