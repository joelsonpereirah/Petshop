#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
using namespace std;


class Animal
{

public:
	string nome;
	string nascimento;
	string especie;
	string raca;

public:
	Animal();
	Animal(string m_nome, string m_nascimento, string m_especie, string m_raca);
	~Animal();

	Animal operator= ( const Animal &other);

	void setNome(string);
	string getNome() const;

	void setNascimento(string);
	string getNascimento() const;


	void setEspecie(string);
	string getEspecie() const;


	void setRaca(string);
	string getRaca() const;

};

#endif // ANIMAL_H_INCLUDED
