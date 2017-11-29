#include "../include/Animal.h"
#include <iostream>
using namespace std;


//Constructors & Destructors
Animal::Animal(){
    nome = {};
	id = {};
	nascimento = {};
	especie = {};
	raca = {};
}

Animal::Animal(string m_nome, int m_id, string m_nascimento, string m_especie, string m_raca){
	nome = m_nome;
	id = m_id;
	nascimento = m_nascimento;
	especie = m_especie;
	raca = m_raca;

}

Animal::~Animal(){

}


//Sets & Gets
void Animal::setNome(string m_nome){
	nome = m_nome;
}
string Animal::getNome(){
	return nome;
}


void Animal::setId(int m_id){
	id = m_id;
}

int Animal::getId(){
	return id;
}


void Animal::setNascimento(string m_nascimento){
	nascimento = m_nascimento;
}

string Animal::getNascimento(){
	return nascimento;
}


void Animal::setEspecie(string m_especie){
	especie = m_especie;
}

string Animal::getEspecie(){
	return especie;
}

void Animal::setRaca(string m_raca){
	raca = m_raca;
}


string Animal::getRaca(){
	return raca;
}



