#ifndef __uc_h__
#define __uc_h__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class Aluno;

class Uc {
protected:
	string nome;
	string sigla;
	int semestre;
	int ano;
	float creditos;
	vector<Aluno*> alunos;

public:
	Uc(string nome,string sigla,int semestre,int ano,float creditos);
	virtual ~Uc(){};
	int getAno() const;
	void setAno(int ano);
	float getCreditos() const;
	void setCreditos(float creditos);
	const string& getNome() const;
	void setNome(const string& nome);
	int getSemestre() const;
	void setSemestre(int semestre);
	const string& getSigla() const;
	void setSigla(const string& sigla);
	vector<Aluno*> getAlunos() const;
	void setAlunos(vector<Aluno*> alunos);

	virtual void addAluno(Aluno* aluno) = 0;
	virtual void displayUC()=0;

	virtual string getFaculdade() ;
	virtual string getCurso();
	virtual string getArea() ;

	virtual int getVagas();
	virtual void setVagas(int vagas);

	virtual void display_incomplete();

};

class Optativa: public Uc {
	int vagas;
	string curso;
	string faculdade;
	string area;
public:
	Optativa(string nome,string sigla,int semestre,int ano,float cred,int vagas,string curso,string fac,string area);
	~Optativa(){};
	string getArea();
	void setArea(const string& area);
	string getCurso() ;
	void setCurso(const string& curso);
	string getFaculdade();
	void setFaculdade( string faculdade);
	int getVagas();
	void setVagas(int vagas);
	void displayUC();
	void addAluno(Aluno* aluno);
	void display_incomplete();


};

class N_Optativa: public Uc {

public:
	N_Optativa(string nome,string sigla,int semestre,int ano,float cred);
	~N_Optativa(){};
	void displayUC();
	void addAluno(Aluno* aluno);

	int getVagas();
	void setVagas(int vagas);
	string getFaculdade() ;
	string getCurso();

	 string getArea() ;


	 void display_incomplete();

};

vector<Uc*> initUCs();

#endif


