
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

using namespace std;

using std::cout; using std::cerr;
using std::endl; using std::string;

//funçoes

int menu(){
  int resposta;
  //system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows

  //inclusão, exclusão, buscas e relatório;
  cout << "\n\n\n\t\t\t ______________[Menu]_______________ "<<endl;
        cout << "\t\t\t|                                   |"<<endl;
        cout << "\t\t\t|  Exibir Lista de veículos ---- 1  |"<<endl;
        cout << "\t\t\t|  Incluir veículo ------------- 2  |"<<endl;
        cout << "\t\t\t|  Remover veículo COLETIVAMENTE 3  |"<<endl;
        cout << "\t\t\t|  Remover veículo ESPECÍFICO -- 4  |"<<endl;
        cout << "\t\t\t|  BUSCA EM PILHA -------------- 5  |"<<endl;
        cout << "\t\t\t|  BUSCA EM FILA --------------- 6  |"<<endl;
        cout << "\t\t\t|  Mostrar Relatório ----------- 7  |"<<endl;
        cout << "\t\t\t|  Sair ------------------------ 0  |"<<endl;
        cout << "\t\t\t|___________________________________|\n\n"<<endl;

  cout << "\nEscolha uma opção"<<endl;
  
  cin >> resposta;
  if(resposta<0||resposta>7){
    return menu();
  }
  else
  {
    return resposta; 
  }
}

//Estruturas


struct Carro{  
  string modelo;  
  string marca;  
  string tipo;
  string ano;
  string km;
  string potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  string portas;
  string placa;

  bool comparacaoTotal(Carro* c){
    return  (c->placa == placa);
  }
  bool comparacaoParcial(Carro* c){
    return  (c->modelo == modelo ||
    c->marca == marca ||
    c->tipo == tipo ||
    c->ano == ano ||
    c->km == km ||
    c->potencia == potencia ||
    c->combustivel == combustivel ||
    c->cambio == cambio ||
    c->direcao == direcao ||
    c->cor == cor ||
    c->portas == portas ||
    c->placa == placa);
  }
};

struct No {
    Carro *carro;
    struct No *proxNo;
};

class Lista{
  No* cabeca; // primeiro elemento
	No* cauda; // último elemento
  int tamanho = 0;

  Lista()
  {
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;
  }

  void inserir(Carro c)
	{
		No* novo_no; 
    novo_no = new No();
    novo_no->carro = &c;

		if(cabeca==NULL)
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->proxNo = cabeca;
			cabeca = novo_no;
		}
    tamanho++;
    
    //Ordenar
    No* no;
    No* auxNo;
    no = cabeca;
    
    while(no!=NULL && no->proxNo != NULL){
      if(no->carro->placa > no->proxNo->carro->placa){
        auxNo->carro = no->proxNo->carro;
        no->proxNo->carro = no->carro;
        no->carro = auxNo->carro;
      }
      no = no->proxNo;
    }
	}
};

// as q tem q colocar  /*



*/
