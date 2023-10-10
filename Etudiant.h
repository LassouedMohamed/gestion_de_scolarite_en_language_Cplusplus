#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
class Etudiant: public Personne{

private:
    int Num_insc;
public:
    Etudiant();
    Etudiant(int,int,string,string,string);
    Etudiant saisie();
    friend ostream & operator <<(ostream & , Etudiant const &);
    int getNumIns();
    string getNomEtu();
    string getPrenomEtu();
    friend bool operator ==(Etudiant const & , Etudiant const &);
};

Etudiant::Etudiant():Personne(){
    this->Num_insc=0;
}

Etudiant::Etudiant(int s,int y, string p,string b,string r):Personne(y, p, b, r){
    this->Num_insc=s;
}

int Etudiant::getNumIns(){
    return Num_insc;
}

string Etudiant::getNomEtu(){
    return Nom;
}

string Etudiant::getPrenomEtu(){
    return Prenom;
}

Etudiant Etudiant::saisie(){
    int id, num_insc;
    string Nom, Prenom,Mail;
    cout<<"entrer id : ";
    cin>>id;
    cout<<"entrer num inscription : ";
    cin>>num_insc;
    cout<<"entrer Nom : ";
    cin>>Nom;
    cout<<"entrer Prenom : ";
    cin>>Prenom;
    cout<<"entrer Mail : ";
    cin>>Mail;
    Etudiant e(id, num_insc,Nom, Prenom,Mail);
    return e;
}
bool operator ==(Etudiant const &e1 , Etudiant const &e2){
    if( (e1.id==e2.id) && (e1.Nom.compare(e2.Nom)==0) && (e1.Mail.compare(e2.Mail)==0) && (e1.Prenom.compare(e2.Prenom)==0)&& (e1.Num_insc == e2.Num_insc) )
        return true;
    return false;
}


ostream & operator <<(ostream & os, Etudiant const & E){
    os<<" | "<<E.Num_insc<<" | "<<E.Nom<<" | "<<E.Prenom;
    return os ;
}


#endif // ETUDIANT_H_INCLUDED
