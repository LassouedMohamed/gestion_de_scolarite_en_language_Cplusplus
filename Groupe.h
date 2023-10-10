#ifndef GROUPE_H_INCLUDED
#define GROUPE_H_INCLUDED
 class Groupe{
 private:
     string IdGRP;
     string Niveau;
     string Diplome;
     string Specialite ;
     int Num_G;
     vector <GroupeModule> ListeModules;
     vector <Etudiant> ListeEtudiants;
 public:
     Groupe();
     Groupe(string,string,string,string,int,vector<GroupeModule>,vector <Etudiant>);
     vector <GroupeModule> getListeModules();
     vector <Etudiant> getListeEtudiants();

     bool verifGroupeModule(string);
     void AfficherGroupeModule();
     void AjouterGroupeModule(GroupeModule);
     void SupprimerGroupeModule(int);
     void ModifierGroupeModule(int);

     bool verifEtudiant(int);
     void AfficherEtudiant();
     void AjouterEtudiant(Etudiant);
     void SupprimerEtudiant(int);
     void ModifierEtudiant();


     friend ostream & operator <<(ostream &, Groupe const &);
 };

Groupe::Groupe(){
    this->IdGRP="";
    this->Niveau="";
    this->Diplome="";
    this->Specialite="";
    this->Num_G=0;
}

Groupe::Groupe(string k, string l, string p,string z,int q, vector <GroupeModule> G,vector<Etudiant> E){
    this->IdGRP=k;
    this->Niveau=l;
    this->Diplome=p;
    this->Specialite=z;
    this->Num_G=q;
    this->ListeModules=G;
    this->ListeEtudiants=E;
}

vector <GroupeModule> Groupe::getListeModules(){
    return (this->ListeModules);
}

vector <Etudiant> Groupe::getListeEtudiants(){
    return (this->ListeEtudiants);
}


bool Groupe::verifEtudiant(int k){
    for(int i=0;i<ListeEtudiants.size();i++){
        if (ListeEtudiants[i].getId()==k)
            return true;
    }
    return false;
}

void Groupe::AfficherEtudiant(){
     for (int i=0;i<ListeEtudiants.size(); i++){
        cout<<"position : "<<i<<" "<<ListeEtudiants[i];
    }
}

void Groupe::ModifierGroupeModule(int N){
    int choix,position;
    string nomGM;
    if(N>=0 && N<ListeModules.size()){

        cout<<ListeModules[N]<<endl;
        cout<<"changer nom de groupe module : 1"<<endl;
        cout<<"ajouter Matiere : 2"<<endl;
        cout<<"supprimer Matiere : 3"<<endl;
        cout<<"modifier Matiere : 4"<<endl;

        cin>>choix;

        switch(choix){
        case 1:{
            cout<<"entrer nom : "<<endl;
            cin>>nomGM;
            ListeModules[N].setNomGM(nomGM);
        }
            break;
        case 2:{
            Matiere newMat;
            newMat = newMat.saisie();
            ListeModules[N].ajouterMatiere(newMat);
        }
            break;
        case 3:{
            ListeModules[N].afficherlisteMatiere();
            cin>> position;
            ListeModules[N].supprimerMatiere();
        }
            break;
        case 4:{
            ListeModules[N].afficherlisteMatiere();
            cin>> position;
            ListeModules[N].ModifierMatiere(position);
        }
            break;
        default:
            cout<<"numero invalide"<<endl;
            break;
        }

    }

}

void Groupe::AjouterEtudiant(Etudiant E){
    if (verifEtudiant(E.getId())!=true){
        ListeEtudiants.push_back(E);
        cout<< "Etudiant ajoutee";
    }
    else
        cout<<"id existe"<<endl;
}

void Groupe::SupprimerEtudiant(int p){
    if (p>=0 && p<ListeEtudiants.size()) {
        vector <Etudiant>::iterator deb=ListeEtudiants.begin();
        ListeEtudiants.erase(deb+p);
    }
}

void Groupe::ModifierEtudiant(){
    int choix;
    cout<<"ajouter Etuidant : 1"<<endl;
    cout<<"supprimer Etuidant : 2"<<endl;
    cout<<"modifier nom Etuidant : 3"<<endl;
    cout<<"modifier prenom Etuidant : 4"<<endl;
    cout<<"modifier mail Etuidant : 5"<<endl;
    cin>>choix;
    switch(choix){
        case 1:{
            Etudiant newEtu;
            newEtu = newEtu.saisie();
            this->AjouterEtudiant(newEtu);
        }
        break;
        case 2:{
            int position;
            this->AfficherEtudiant();
            do{
            cin>>position;
            }while(position<0 || position>=ListeEtudiants.size());
            this->SupprimerEtudiant(position);
        }
        break;
        case 3:{
            int position;
            this->AfficherEtudiant();
            do{
                cin>>position;
            }while(position<0 || position>=ListeEtudiants.size());
            cout<<ListeEtudiants[position].getNomEtu()<<endl;
            string nom;
            cout<< "entrer nom"<<endl;
            cin>>nom;
            ListeEtudiants[position].setNom(nom);
        }
        break;
        case 4:{
            int position;
            this->AfficherEtudiant();
            do{
                cin>>position;
            }while(position<0 || position>=ListeEtudiants.size());
            cout<<ListeEtudiants[position].getPrenomEtu()<<endl;
            string prenom;
            cout<< "entrer prenom"<<endl;
            cin>>prenom;
            ListeEtudiants[position].setPrenom(prenom);
        }
        break;
        case 5:{
            int position;
            this->AfficherEtudiant();
            do{
                cin>>position;
            }while(position<0 || position>=ListeEtudiants.size());
            string mail;
            cout<< "entrer mail"<<endl;
            cin>>mail;
            ListeEtudiants[position].setMail(mail);
        }
        break;
        default:
           cout<<"numero invalide"<<endl;
        break;
    }
}


bool Groupe::verifGroupeModule(string k){
    for(int i=0;i<ListeModules.size();i++){
        if (ListeModules[i].getId().compare(k)==0)
            return true;
    }
    return false;
}

void Groupe::AfficherGroupeModule(){
     for (int i=0;i<ListeModules.size(); i++){
        cout<<"position : "<<i<<endl<<" "<<ListeModules[i];
    }
}

void Groupe::AjouterGroupeModule(GroupeModule grpM){
    if (verifGroupeModule(grpM.getId())!=true){
        ListeModules.push_back(grpM);
        cout<< "Groupe Module ajoutee";
    }
    else
        cout<<"id existe"<<endl;
}

void Groupe::SupprimerGroupeModule(int p){
    if (p>=0 && p<ListeModules.size()) {
        vector<GroupeModule>::iterator deb=ListeModules.begin();
        ListeModules.erase(deb+p);
    }
}

ostream & operator <<(ostream & os, Groupe const & G){
    os<<G.Diplome<<" "<<G.IdGRP<<" "<<G.Niveau<<" "<<G.Specialite<<" "<<G.Num_G<<endl;
    for (int i=0;i<G.ListeEtudiants.size();i++){
        os<<G.ListeEtudiants[i]<<endl;
    }
    for ( int j=0;j<G.ListeModules.size();j++){
        os<<G.ListeModules[j]<<endl;
    }
        return os;
}

#endif // GROUPE_H_INCLUDED
