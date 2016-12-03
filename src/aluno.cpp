#include "aluno.h"
/**
 * Construtor Aluno com todos os argumentos
 */
Aluno::Aluno(int num, string nome, int ano, string email, string estatuto, Docente* tutor, vector< pair<string, Uc *> > cadeiras_inscrito){
	this->numero = num;  				// coloca o n�
	this->nome = nome;					// nome colocado
	this->ano = ano;
	this->email = email;
	this->estatuto = estatuto;
	this->tutor = tutor;
	this->cadeiras_inscrito = cadeiras_inscrito;
}
/**
 * default construtor
 */
Aluno::Aluno(){
}
/**
 * overload do operador ==
 */
bool Aluno::operator == (const Aluno* & p2) const
{	cout<<"1";
cout<<p2->getNome();
	return nome == p2->getNome(); }



/**
 * getAno, devolve ano
 */
int Aluno::getAno() const {
	return ano;
}
/**
 * setAno, altera o ano
 */
void Aluno::setAno(int ano) {
	this->ano = ano;
}
/**
 * devolve as cadeiras �s quais o aluno esta inscrito
 */
vector< pair<string, Uc *> > Aluno::getCadeirasInscrito() const {
	return cadeiras_inscrito;
}
/**
 * altera o vetor de cadeiras as quais o aluno esta inscrito
 */
void Aluno::setCadeirasInscrito(vector< pair<string, Uc *> > cadeirasInscrito) {
	cadeiras_inscrito = cadeirasInscrito;
}


/**
 * devolve o email do aluno
 */
const string& Aluno::getEmail() const {
	return email;
}
/**
 * altera email
 */
void Aluno::setEmail(const string& email) {
	this->email = email;
}
/**
 * devolve o estatuto do aluno
 */
const string& Aluno::getEstatuto() const {
	return estatuto;
}
/**
 * altera estatuto
 */
void Aluno::setEstatuto(const string& estatuto) {
	this->estatuto = estatuto;
}
/**
 * Devolve nome do aluno
 */
const string& Aluno::getNome() const {
	return nome;
}
/**
 * altera nome
 */
void Aluno::setNome(const string& nome) {
	this->nome = nome;
}
/**
 * devolve numero
 */
int Aluno::getNumero() const {
	return numero;
}
/**
 * altera numero
 */
void Aluno::setNumero(int numero) {
	this->numero = numero;
}
/**
 * Mostra toda a INFO do aluno
 */
void Aluno::displayAlunoInfo(){
	cout << "Nome : " << nome << endl;
	cout << "Numero de Estudante: " << numero << endl;
	cout << "Ano Curricular: " << ano << endl;
	cout << "Email: " <<email << endl;
	//cout << "Data de inscricao: " << this->data << endl;
	cout << "Estatuto: " << estatuto << endl;
	cout << "Tutor: " << (*tutor).getNome() << endl;
	cout << "Cadeiras que frequenta: " << "(" <<cadeiras_inscrito.size() << ")" << endl;

	for(unsigned int i = 0; i<this->cadeiras_inscrito.size(); i++){
		cout << "	" << cadeiras_inscrito[i].second->getSigla();
		cout << "	" << cadeiras_inscrito[i].second->getNome();
		cout << "	" << cadeiras_inscrito[i].first << endl;
		//cout << "	" << (*cadeiras_inscrito[i]).getSigla() << "	" << (*cadeiras_inscrito[i]).getNome() << endl;
	}

	cout << "==============================" << endl;

}


/**
 * mostra apenas numero e nome do aluno
 */
void Aluno::displayAluno(){
	cout << numero << "	" << nome << "	" << endl;
}
/**
 * dada uma Uc verifica se o aluno esta ou nao isncrito a essa uc
 */
bool Aluno::estaInscrito(Uc* uc){
	for(unsigned int i = 0; i < cadeiras_inscrito.size(); i++){
		if(uc->getSigla().compare(cadeiras_inscrito[i].second->getSigla()) == 0){
			return true;
		}
	}
	return false;
}

/**
 * output do aluno guardar num ficheiro
 */
void Aluno::save(ofstream* output){
	(*output) << this->numero << " ; " << this->nome << " ; " << this->ano << " ; " << this->email << " ; " << this->estatuto
	 	 	  << " ; " << this->tutor->getCodigo() << " ; ";

	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		(*output) << this->cadeiras_inscrito[i].first;
		if(i != this->cadeiras_inscrito.size()-1){
			(*output) << ", ";
		}
	}

	(*output) << " ; ";

	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		(*output) << this->cadeiras_inscrito[i].second->getSigla();
		if(i != this->cadeiras_inscrito.size()-1){
			(*output) << ", ";
		}
	}
}


//__________________________________________________________________

/**
 * Inicializa vetor de alunos ( funcao que l� info do ficheiro inicial)
 */
vector<Aluno*> initAlunos(vector <Docente*> docentes, vector<Uc*> ucs){
	ifstream in;
	string filename;
	vector<Aluno*> alunos;

	filename = "aa.txt";

	in.open(filename.c_str(),ifstream::in);

	//TODO por excepcao de nao conseguir abrir o ficheiro

	string line;

	int id;
	string name;
	int year;
	string data;
	string email;
	Docente* tutor;

	while (getline(in, line)){

		string IDstr = line.substr(0, line.find(";") - 1); 				// numero
		id = atoi(IDstr.c_str());

		line = line.substr(line.find(";") + 2, string::npos);
		name = line.substr(0, line.find(";") - 1); 						// nome

		line = line.substr(line.find(";") + 2, string::npos);
		string YEARstr = line.substr(0, line.find(";") - 1);			// ano
		year = atoi(YEARstr.c_str());


		line = line.substr(line.find(";") + 2, string::npos);
		email = line.substr(0, line.find(";") - 1); 					// email

		line = line.substr(line.find(";") + 2, string::npos);
		string estatuto = line.substr(0, line.find(";") - 1); 			// estatuto

		line = line.substr(line.find(";") + 2, string::npos);
		int tutorID;
		string tutorIDstr = line.substr(0, line.find(";") - 1); 		// tutor
		tutorID = atoi(YEARstr.c_str());
		for(unsigned int i = 0; i<docentes.size(); i++){
			if((*docentes[i]).getCodigo() == tutorID){
				tutor = docentes[i];
			}
		}

		line = line.substr(line.find(";") + 2, string::npos);
		string data;
		vector<string> dataUCs;											// datas de inscricao
		data = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			dataUCs.push_back(data);
			line = line.substr(line.find(",") + 2, string::npos);
			data = line.substr(0, line.find(","));
		}

		data = line.substr(0, line.find(";") - 1);
		dataUCs.push_back(data);

		line = line.substr(line.find(";") + 2);
		string uc;
		vector<Uc*> ucsAluno;
		while (line.find(",") != string::npos){							// cadeiras
			uc = line.substr(0, line.find(","));
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(uc.compare((*ucs[i]).getSigla()) == 0){
					ucsAluno.push_back(ucs[i]);
				}
			}
			line = line.substr(line.find(",") + 2);
		}

		if(uc.compare(line) != 0)
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(line.compare((*ucs[i]).getSigla()) == 0){
					ucsAluno.push_back(ucs[i]);
				}
			}

	//	printf("++add++\n");
		vector< pair<string, Uc *> > cadeiras;
		for(unsigned int i = 0; i<ucsAluno.size(); i++){
			cadeiras.push_back({dataUCs[i],ucsAluno[i]});
		}


		Aluno* aluno = new Aluno(id, name, year, email, estatuto, tutor, cadeiras);
		alunos.push_back(aluno);
	}
	in.close();

	return alunos;



}

	
