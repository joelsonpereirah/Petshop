#include "Pessoa.h"
#include "Animal.h"
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
string Pessoa::getNome(){
    return nome;
}

void Pessoa::setNome(string m_nome){
    nome = m_nome;
}


string Pessoa::getCpf(){
    return cpf;
}

void Pessoa::setCpf(string m_cpf){
    cpf = m_cpf;
}


string Pessoa::getEndereco(){
    return endereco;
}

void Pessoa::setEndereco(string m_endereco){
    endereco = m_endereco;
}


string Pessoa::getTelefone(){
    return telefone;
}

void Pessoa::setTelefone(string m_telefone){
    telefone = m_telefone;
}


///////////////////Construtores e Destrutores ---FUNCIONARIOS////////////////q
Funcionario::Funcionario():Pessoa(){
    
    nome = "";
    cpf = "";
    endereco = "";
    telefone = "";

    funcao = "";
    admissao = "";

}
Funcionario::Funcionario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao)
:Pessoa(m_nome, m_cpf, m_endereco, m_telefone){
    
   
    nome= m_nome;
    cpf = m_cpf;
    endereco = m_endereco;
    telefone = m_telefone;

    funcao = m_funcao;
    admissao = m_admissao;


}

Funcionario::~Funcionario(){

}

/////////GET's e SET's------FUNCIONARIOS////////////q

string Funcionario::getFuncao(){
    return funcao;
}

void Funcionario::setFuncao(string m_funcao){
    funcao = m_funcao;
}


string Funcionario::getAdmissao(){
    return admissao;
}

void Funcionario::setAdmissao(string m_admissao){
    admissao = m_admissao;
}



/////////////Construtores e Destrutores -- FUNCIONARIO //////

Veterinario::Veterinario(): Funcionario(){
    nome = "";
    cpf = "";
    endereco = "";
    telefone = "";

    funcao = "";
    admissao = "";

    especializacao = "";
    crmv = "";

}

Veterinario::Veterinario(string m_nome, string m_cpf, string m_endereco, string m_telefone, string m_funcao, string m_admissao, 
    string m_espcializacao, string m_crmv):Funcionario(m_nome, m_cpf, m_endereco, m_telefone, m_funcao, m_admissao){ 
    Pessoa(m_nome, m_cpf, m_endereco, m_telefone);
    
    
    nome = m_nome;
    cpf = m_cpf;
    endereco = m_endereco;
    telefone = m_telefone;

    funcao = m_funcao;
    admissao = m_admissao;

    
    especializacao = m_espcializacao;
    crmv = m_crmv;
    
}


Veterinario::~Veterinario(){

}
////////////SET's e GET's ---- VETERINARIO/////////////

string Veterinario::getEspecializacao(){
    return especializacao;
}

void Veterinario::setEspecializacao(string m_espcializacao){
    especializacao = m_espcializacao;
}



string Veterinario::getCrmv(){
    return crmv;
}

void Veterinario::setCrmv(string m_crmv){
    crmv = m_crmv;
}




Cliente::Cliente(){
    nome = "";
    cpf = "";
    endereco = "";
    telefone = "";
//  animais.push_back();

}

Cliente::Cliente(string m_nome, string m_cpf, string m_endereco, string m_telefone, Animal m_animal)
:Pessoa(m_nome, m_cpf, m_endereco, m_telefone){
    
    animais.push_back(m_animal);
}


int Cliente::addAnimal(Animal m_animal){
    
 //cout<<"Animal do parametro:"<<m_animal.getNome()<<endl;

    for(unsigned int i = 0 ; i < animais.size(); i++){
       
        //cout<<"Animal do vetor: "<<animais[i].getNome()<<endl;
        
        if (animais[i] == m_animal)
        {
            cout<<"O cliente ja possui esse animal cadastrado! "<<endl<<"Animal não adicionado!"<<endl;

            return 0;

        }      
        
    }

    animais.push_back(m_animal);
    cout<<"Animal cadastrado com Sucesso!"<<endl;
    

    return 1;
}

//void Clente::listarAnimal(Cliente m_cliente){
  //  for()   
//}
        
  
Cliente::~Cliente(){

}








