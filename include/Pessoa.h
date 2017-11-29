#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED


#include <vector>
#include <string>
#include "Animal.h"
#include "Pessoa.h"

using namespace std;


class Pessoa
{
protected:
	string nome;
	string cpf;
	string endereco;
	string telefone;
public:
	//constructors & destructors
	Pessoa();
	Pessoa(string m_nome, string m_cpf, string m_endereco, string m_telefone);
	~Pessoa();

	//sets & gets
	void setNome(string);
	string getNome() const;


	void setCpf(string);
	string getCpf() const;


	void setEndereco(string);
	string getEndereco() const;


	void setTelefone(string);
	string getTelefone() const;

};

class Funcionario: public Pessoa
{
protected:
	string funcao;
	string admissao;

public:
	//constructors & destructors
	Funcionario();
	Funcionario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao);
	~Funcionario();

	//sets & gets
	void setFuncao(string);
	string getFuncao() const;


	void setAdmissao(string);
	string getAdmissao() const;
};




class Veterinario : public Funcionario
{
private:
	string especializacao;
	string crmv;
public:
	//constructors & destructors
	Veterinario();
	Veterinario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao, string m_espcializacao,
    		 string m_crmv);
               
   ~Veterinario();

	//sets & gets
	void setEspecializacao(string);
	string getEspecializacao() const;


	void setCrmv(string);
	string getCrmv() const;
};



class Cliente : public Pessoa
{
public:
	vector<Animal> animais;
public:
	//constructors & destructors
	Cliente();
	Cliente(string m_nome, string m_cpf, string m_endereco, string m_telefone, vector<Animal> m_animal);
	~Cliente();

	Cliente operator= ( const Cliente &other);
	//sets & gets
	void setAnimais(vector<Animal> &animais_ext);
	vector<Animal> getAnimais() const;

};




#endif // PESSOA_H_INCLUDED
