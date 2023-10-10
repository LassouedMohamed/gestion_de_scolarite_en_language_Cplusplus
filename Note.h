#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED
class Note{
private:
     Matiere Mat;
     Etudiant Etu;
     float note;
     string Type;
public:
    Note();
    Note(Matiere ,Etudiant ,float,string);
    Matiere getMat();
    Etudiant getEtu();
    float getNote();
    friend bool operator ==(Note const &, Note const &);
    friend ostream & operator << (ostream &,Note const &);
};

Note::Note(){
    this->note=0.0;
    this->Type="";
}

Note::Note(Matiere M , Etudiant E,float g,string v){
    this->note=g;
    this->Type=v;
    this->Mat=M;
    this->Etu=E;
}

Etudiant Note::getEtu(){
    return Etu;
}

Matiere Note::getMat(){
    return Mat;
}

float Note::getNote(){
    return note;
}
bool operator ==(Note const &n1, Note const &n2){
    if(n1.Etu==n2.Etu && n1.Mat ==n2.Mat)
        return true;
    return false;
}

ostream & operator << (ostream & os , Note const & N){
    os<<"Matiere : "<<N.Mat<<"**Etudiant :"<<N.Etu<<"note : "<<N.note<<" type : "<<N.Type<<endl;
    return os;
}


#endif // NOTE_H_INCLUDED
