#ifndef ENSEIGNANT_H_INCLUDED
#define ENSEIGNANT_H_INCLUDED
class Enseignant : public Personne{
private:
    int CNSS;
public:
    Enseignant ();
    Enseignant (int,int,string,string,string);
    void setcnss(int );
    friend ostream & operator<<(ostream & , Enseignant const &);
    friend bool operator ==(Enseignant const & , Enseignant const &);
};

Enseignant::Enseignant():Personne(){
   this->CNSS=0;
}

Enseignant::Enseignant(int k,int y, string p,string b,string r):Personne(y,p, b,r){
    this->CNSS=k;
}

void Enseignant::setcnss(int k){
    CNSS=k;
}

bool operator ==(Enseignant const &e1 , Enseignant const &e2){
    if(e1.id==e2.id && (e1.Nom.compare(e2.Nom)==0) && (e1.Mail.compare(e2.Mail)==0) && (e1.Prenom.compare(e2.Prenom)==0) && e1.CNSS == e2.CNSS)
        return true;
    return false;
}

ostream & operator << (ostream & os , Enseignant const & E){
    os<<"id : "<<E.id<<" Nom : "<<E.Nom<<" Prenom : "<<E.Prenom<<" Mail : "<<E.Mail<<" CNSS : "<<E.CNSS<<endl;
    return os;
}



#endif // ENSEIGNANT_H_INCLUDED
