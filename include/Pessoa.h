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
	Pessoa();
	Pessoa(string m_nome, string m_cpf, string m_endereco, string m_telefone);
	~Pessoa();

	void setNome(string);
	string getNome();


	void setCpf(string);
	string getCpf();


	void setEndereco(string);
	string getEndereco();


	void setTelefone(string);
	string getTelefone();
};

class Funcionario: public Pessoa
{
protected:
	string funcao;
	string admissao;

public:
	Funcionario();
	Funcionario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao);
	~Funcionario();

	void setFuncao(string);
	string getFuncao();


	void setAdmissao(string);
	string getAdmissao();
};




class Veterinario : public Funcionario
{
private:
	string especializacao;
	string crmv;
public:
	//Veterinario();
	Veterinario();
	Veterinario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao, string m_espcializacao,
    		 string m_crmv);
               
   ~Veterinario();

	void setEspecializacao(string);
	string getEspecializacao();


	void setCrmv(string);
	string getCrmv();
};



class Cliente : public Pessoa
{
public:
	vector<Animal> animais;
public:
	 Cliente();
	 Cliente(string m_nome, string m_cpf, string m_endereco, string m_telefone, Animal m_animal);
	 ~Cliente();

	int addAnimal (Animal);
	void listarAnimal(Cliente);
	//void removeAnimal(Animal);
	//vector<Animal> getAnimais();

};




#endif // PESSOA_H_INCLUDED
