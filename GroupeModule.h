#ifndef GROUPEMODULE_H_INCLUDED
#define GROUPEMODULE_H_INCLUDED

class GroupeModule{

private:
    string IdGM;
    string NomGM;
    float coefGM;
    vector <Matiere> ListeMat;

public:
    GroupeModule();
    GroupeModule(string,string,float,vector<Matiere>);
    bool verif(string);
    void ajouterMatiere(Matiere);
    void afficherlisteMatiere();
    void supprimerMatiere();
    void ModifierMatiere(int);
    string getNomGM();
    void setNomGM(string);
    vector <Matiere> getListeMat();
    string getId();
    float getCoefGM();
    friend ostream & operator <<(ostream &, GroupeModule const &);
};

GroupeModule::GroupeModule(){
    this->IdGM="";
    this->NomGM="";
    this->coefGM=0.0;
}

GroupeModule::GroupeModule(string n,string h,float f,vector<Matiere>M){
    this->IdGM=n;
    this->NomGM=h;
    this->coefGM=f;
    this->ListeMat=M;
}

string GroupeModule::getId(){
    return IdGM;
}

float GroupeModule::getCoefGM(){
    return coefGM;
}

string GroupeModule::getNomGM(){
    return NomGM;
}

void GroupeModule::setNomGM(string n){
    NomGM=n;
}

bool GroupeModule::verif (string k){
    for(int i=0;i<ListeMat.size();i++){
        if (ListeMat[i].getid().compare(k)==0)
            return true;
    }
        return false;
}

void GroupeModule::ajouterMatiere(Matiere mat){
    if (verif(mat.getid())!=true){
        ListeMat.push_back(mat);
        this->coefGM+=mat.getcoef();
        cout<< "matiere ajoutee";
    }
    else
        cout<<"id existe"<<endl;
}

void GroupeModule::afficherlisteMatiere(){
    cout<<"-"<<NomGM<<endl;
    for (int i=0;i<ListeMat.size(); i++){
        cout<<"\t - position "<<i<<" "<<ListeMat[i].getnom()<<" "<<endl;
    }
}

void GroupeModule::supprimerMatiere(){
    this->afficherlisteMatiere();
    int p;
    do {
        cout<<"entrer position a supprimer sinon -1 pour exit";
        cin>>p;
    }while(p<-1 || p>=ListeMat.size());
    if (p>=0 && p<ListeMat.size()) {
        vector <Matiere>::iterator deb=ListeMat.begin();
        this->coefGM-=ListeMat[p].getcoef();
        ListeMat.erase(deb+p);

    }
}

vector <Matiere> GroupeModule::getListeMat(){
    return this->ListeMat;
}
// n position
void GroupeModule::ModifierMatiere(int N){
    int choix;
    string nomMat,NomEns,prenomEns,mailEns;
    float coeffMat;
    if (N>=0 && N<ListeMat.size()){
        cout<< ListeMat[N];
        cout<<"changer nom matiere  : 1"<<endl;
        cout<<"changer coeff : 2"<<endl;
        cout<<"changer nom Ens : 3"<<endl;
        cout<<"changer prenom Ens : 4"<<endl;
        cout<<"changer mail Ens : 5"<<endl;
        cin>>choix;
        switch (choix){
        case 1:
            //choix == 1
            cout<<"entrer nom : "<<endl;
            cin>>nomMat;
            ListeMat[N].setnom(nomMat);
            break;
        case 2:
            cout<<"entrer coeff : "<<endl;
            cin>>coeffMat;
            this->coefGM-=ListeMat[N].getcoef();
            ListeMat[N].setcoef(coeffMat);
            this->coefGM+=coeffMat;
            break;
        case 3:
            cout<<"entrer nom Enseignant : "<<endl;
            cin>>NomEns;
            ListeMat[N].getEns().setNom(NomEns);
            break;
        case 4:
            cout<<"entrer prenom Enseignant : "<<endl;
            cin>>prenomEns;
            ListeMat[N].getEns().setPrenom(prenomEns);
            break;
        case 5:
            cout<<"entrer mail Enseignant : "<<endl;
            cin>>mailEns;
            ListeMat[N].getEns().setMail(mailEns);
            break;
        default:
            cout<<"numero invalide"<<endl;
            break;
        }
    }
}



ostream & operator << ( ostream & os , GroupeModule const & G ){
    os<<"IdGM "<<G.IdGM<<" NomGM : "<<G.NomGM<<" coefGM : "<<G.coefGM<<endl;
    for ( int i=0;i<G.ListeMat.size(); i++){
        os<<"Matiere num "<<(i+1)<< endl;
        os<<" -"<<G.ListeMat[i];
    }
    return os ;
}

#endif // GROUPEMODULE_H_INCLUDED
