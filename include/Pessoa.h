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
	//constructors & destructors
	Funcionario();
	Funcionario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao);
	~Funcionario();

	//sets & gets
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
	//constructors & destructors
	Veterinario();
	Veterinario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao, string m_espcializacao,
    		 string m_crmv);
               
   ~Veterinario();

	//sets & gets
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
	//constructors & destructors
	Cliente();
	Cliente(string m_nome, string m_cpf, string m_endereco, string m_telefone, vector<Animal> m_animal);
	~Cliente();

	//sets & gets
	void set_animais(vector<Animal> &animais_ext);
	vector<Animal> get_animais();
};




#endif // PESSOA_H_INCLUDED
