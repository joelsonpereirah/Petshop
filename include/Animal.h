#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
using namespace std;


class Animal
{

public:
	string nome;
	int id;
	string nascimento;
	string especie;
	string raca;

public:
	Animal();
	Animal(string m_nome, int m_id, string m_nascimento, string m_especie, string m_raca);
	~Animal();

	void setNome(string);
	string getNome();

	void setId(int);
	int getId();

	void setNascimento(string);
	string getNascimento();


	void setEspecie(string);
	string getEspecie();


	void setRaca(string);
	string getRaca();

};

#endif // ANIMAL_H_INCLUDED
