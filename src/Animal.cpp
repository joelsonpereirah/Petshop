#include "../include/Animal.h"
#include <iostream>
using namespace std;


//Constructors & Destructors
Animal::Animal(){
    nome = {};
	nascimento = {};
	especie = {};
	raca = {};
}

Animal::Animal(string m_nome, string m_nascimento, string m_especie, string m_raca){
	nome = m_nome;
	nascimento = m_nascimento;
	especie = m_especie;
	raca = m_raca;

}


Animal::~Animal(){

}

Animal Animal::operator= ( const Animal &other){
	nome = other.getNome();
	nascimento = other.getNascimento();
	especie = other.getEspecie();
	raca = other.getRaca();

	return *this;
}
//Sets & Gets
void Animal::setNome(string m_nome){
	nome = m_nome;
}
string Animal::getNome() const{
	return nome;
}


void Animal::setNascimento(string m_nascimento){
	nascimento = m_nascimento;
}

string Animal::getNascimento() const{
	return nascimento;
}


void Animal::setEspecie(string m_especie){
	especie = m_especie;
}

string Animal::getEspecie() const{
	return especie;
}

void Animal::setRaca(string m_raca){
	raca = m_raca;
}


string Animal::getRaca() const{
	return raca;
}



