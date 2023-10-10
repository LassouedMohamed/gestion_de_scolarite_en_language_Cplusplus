#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

class Personne{
 protected:
    int id;
    string Nom;
    string Prenom;
    string Mail;

 public:
    Personne();
    Personne(int,string,string,string);
    int getId();
    void setId(int);
    void setNom(string);
    void setPrenom(string);
    void setMail(string);

    friend ostream & operator<<(ostream & , Personne const &);

} ;

Personne::Personne(){
    this->id=0;
    this->Nom="";
    this->Prenom="";
    this->Mail="";
}
Personne::Personne(int y, string p,string b,string r){
    this->id=y;
    this->Nom=p;
    this->Prenom=b;
    this->Mail=r;
}

void Personne::setId(int id){
  this->id=id;

}

int Personne::getId(){
    return id;
}

void Personne::setNom(string Nom){
    this->Nom=Nom;
}

void Personne::setPrenom(string Prenom){
    this->Prenom=Prenom;
}

void Personne::setMail(string Mail){
    this->Mail=Mail;
}

ostream & operator<<(ostream & os , Personne const & P){
   os<<P.id<<" "<<P.Nom<<" "<<P.Prenom<<" "<<P.Mail<<endl;
   return os ;
}
#endif // PERSONNE_H_INCLUDED
