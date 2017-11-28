
#include "Petshop.h"
#include "Pessoa.h" 

#include <iostream>
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
