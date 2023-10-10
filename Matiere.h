#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED
class Matiere{
private:
    string IdMat;
    string NomMat;
    float coef;
    Enseignant Ens;
public:
    Matiere ();
    Matiere (string,string,float,Enseignant);
    string getid();
    string getnom();
    Enseignant getEns();
    void   setnom(string);
    void   setcoef(float);
    void   setid(string);
    friend ostream & operator <<(ostream &, Matiere const &);
    Matiere saisie();
    float getcoef();
    friend bool operator ==(Matiere const & , Matiere const &);

};

Matiere::Matiere(){
    this->IdMat="";
    this->NomMat="";
    this->coef=0.0;
}

Matiere::Matiere(string d,string x,float c,Enseignant e){
    this->IdMat=d;
    this->NomMat=x;
    this->coef=c;
    this->Ens=e;
}

Matiere Matiere::saisie(){
    string idMatiere;
    string nomMatiere;
    float coeff;
    int cnss;
    int id;
    string nom;
    string prenom;
    string mail;


    cout<<"id matiere"<<endl;
    cin>>idMatiere;
    cout<<"nom Matiere"<<endl;
    cin>>nomMatiere;
    cout<<"coeff"<<endl;
    cin>>coeff;
    cout<<"cnss"<<endl;
    cin>>cnss;
    cout<<"id"<<endl;
    cin>>id;
    cout<<"nom"<<endl;
    cin>>nom;
    cout<<"prenom"<<endl;
    cin>>prenom;
    Enseignant E(cnss,id,nom,prenom,mail);
    Matiere c(idMatiere,nomMatiere,coeff,E);
    return c;
}

string Matiere::getid(){
    return(IdMat);
}

string Matiere::getnom(){
    return(NomMat);
}

float Matiere::getcoef(){
    return(coef);
}

Enseignant Matiere::getEns(){
    return(Ens);
}

void Matiere::setnom(string N){
    NomMat=N;
}

void Matiere::setcoef(float c){
    coef=c;
}

void Matiere::setid(string id){
    IdMat=id;
}
bool operator ==(Matiere const & m1, Matiere const & m2){
    if( (m1.IdMat.compare(m2.IdMat)==0) && (m1.NomMat.compare(m2.NomMat)==0) && (m1.coef ==m2.coef )&& (m1.Ens == m2.Ens) )
        return true;
    return false;
}
ostream & operator <<(ostream & os , Matiere const & M){
    os<<"IdMat : "<<M.IdMat<<" coef : "<<M.coef<<" NomMat : "<<M.NomMat<<endl<<"  Enseignant : "<<M.Ens<<endl;
    return os ;
}



#endif // MATIERE_H_INCLUDED
