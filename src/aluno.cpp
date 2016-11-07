#include "aluno.h"



#include <stdio.h>
#include <stdlib.h>

Aluno::Aluno(int num, string nome, int ano, string data, string email, string estatuto){



	this->numero = num;  // coloca o n�
	this->nome = nome;                               // nome colocado
	this->ano = ano;
	this->data = data;
	this->email = email;
	this->estatuto = estatuto;

}



int Aluno::getAno() const {
	return ano;
}

void Aluno::setAno(int ano) {
	this->ano = ano;
}

const vector<Uc*>& Aluno::getCadeirasInscrito() const {
	return cadeiras_inscrito;
}

void Aluno::setCadeirasInscrito(const vector<Uc*>& cadeirasInscrito) {
	cadeiras_inscrito = cadeirasInscrito;
}

const string& Aluno::getData() const {
	return data;
}

void Aluno::setData(const string& data) {
	this->data = data;
}

const string& Aluno::getEmail() const {
	return email;
}

void Aluno::setEmail(const string& email) {
	this->email = email;
}

const string& Aluno::getEstatuto() const {
	return estatuto;
}

void Aluno::setEstatuto(const string& estatuto) {
	this->estatuto = estatuto;
}

const string& Aluno::getNome() const {
	return nome;
}

void Aluno::setNome(const string& nome) {
	this->nome = nome;
}

int Aluno::getNumero() const {
	return numero;
}

void Aluno::setNumero(int numero) {
	this->numero = numero;
}


vector<Aluno>GetAllAlunos(){
	ifstream in;
	string filename;
	vector<Aluno>alunos;

	//cout << "nome do ficheiro ? ";			//ficheiro de alunos
	//cin >> filename;
	filename = "aa.txt";

	in.open(filename.c_str(),ifstream::in);
/**
	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		//in.open("aa.txt");
	}
*/
	string line;
	//getline(in, line);
	while (getline(in, line)){

		//cout << line << endl;

		string str1 = line.substr(0, line.find(";") - 1); // numero
		int id = atoi(str1.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		cout << id << endl;

		string str2 = line.substr(0, line.find(";") - 1);  // nome

		line = line.substr(line.find(";") + 2, string::npos);

		cout << str2 << endl;


		string str3 = line.substr(0, line.find(";") - 1);
		int year = atoi(str3.c_str());//ano  int

		line = line.substr(line.find(";") + 2, string::npos);

		string str4 = line.substr(0, line.find(";") - 1);          //data

		cout << year << endl << str4 << endl;

		//////////////////////////////////////////

		line = line.substr(line.find(";") + 2, string::npos);

		string str5 = line.substr(0, line.find(";") - 1); // email

		line = line.substr(line.find(";") + 2, string::npos);

		string str6 = line.substr(0, line.find(";") - 1); // estatuto

		cout << str5 << endl << str6 << endl;

		line = line.substr(line.find(";") + 2, string::npos);
		vector<string> v1;
		//	cout << line << endl;


		// TUTOR  

		while (line.find(",") != string::npos){

			string uc = line.substr(0, line.find(","));



			v1.push_back(uc);

			//cout << uc << endl;

			line = line.substr(line.find(",") + 2);
			//cout << line << endl;
		}

		v1.push_back(line);
		//Aluno novo_aluno(////////////);
		//alunos.push_back(novo_aluno);

	
		for (int i = 0; i < v1.size(); i++){
			cout << v1[i] << endl;
		}
		/*
		if (!in.eof()){
		//	Aluno novo_aluno();
		//	alunos.push_back(novo_aluno);
		}*/
	}
	in.close();

	return alunos;

}



	
