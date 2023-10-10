#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"
#include "Matiere.h"
#include "GroupeModule.h"
#include "Groupe.h"
#include "NOTE.h"


void afficherGroupe(vector<Groupe> listeGroupe){
    for (int i=0;i<listeGroupe.size(); i++){
        cout<<"\t - position "<<i<<" "<<listeGroupe[i]<<" "<<endl;
    }
}

void afficherNotes(vector<Note> listeNote){
    for (int i=0;i<listeNote.size(); i++){
        cout<<"\t - position "<<i<<" "<<listeNote[i]<<" "<<endl;
    }
}

void ajouterGroupe (vector<Groupe> listeGroupe,Groupe  grp){
        listeGroupe.push_back(grp);
}

supprimerGroupe(vector<Groupe> listeGroupe){
    afficherGroupe(listeGroupe);
    int p;
    do {
        cout<<"entrer position a supprimer sinon -1 pour exit";
        cin>>p;
    }while(p<-1 || p>=listeGroupe.size());
    if (p>=0 && p<listeGroupe.size()) {
        vector <Groupe>::iterator deb=listeGroupe.begin();
        listeGroupe.erase(deb+p);

    }
}

supprimerNote(vector<Note> listeNote){
    afficherNotes(listeNote);
    int p;
    do {
        cout<<"entrer position a supprimer sinon -1 pour exit";
        cin>>p;
    }while(p<-1 || p>=listeNote.size());
    if (p>=0 && p<listeNote.size()) {
        vector <Note>::iterator deb=listeNote.begin();
        listeNote.erase(deb+p);

    }
}

void ajouterNote(vector<Note> listeNote,Note  note){
        listeNote.push_back(note);
}



void afficherResultat(double rt){
    if(rt>10){
        cout<<" | Admis";
    }else{
        cout<<" | Ajourne";
    }
}

void afficherMention(double rt){
    if(rt < 10 )
        cout<<" |            |"<<endl;
    else if(rt>=10 && rt < 12 )
        cout<<" | Passable   |"<<endl;
    else if(rt>=12 && rt<14)
        cout<<" | Assez Bien |"<<endl;
    else if(rt>=14 && rt<16)
        cout<<" | Bien       |"<<endl;
    else if(rt>=16 && rt<18)
        cout<<" | Tres Bien  |"<<endl;
    else if(rt>=18 && rt<20)
        cout<<" | Excellent  |"<<endl;
}

double MoyenneParMatiere(vector<Note> notes, Etudiant e, Matiere m){
    double sommeNotes=0.0;
    int nb=0;
    for(int i=0;i<notes.size();i++){
        if( (notes[i].getEtu()==e ) && (notes[i].getMat()==m) ){
            sommeNotes += notes[i].getNote();
            nb++;
        }
    }
    if(nb==0){
        return 0;
    }
    return sommeNotes/nb;
}

double MoyenneParGroupeModule(vector<Note> notes, Etudiant e, GroupeModule grpM){
    vector<Matiere> listeMatieres = grpM.getListeMat();
    double moyenne =0;
    double nb=0;
    for(int i=0;i<listeMatieres.size();i++){
        moyenne +=(MoyenneParMatiere(notes,e,listeMatieres[i]))*listeMatieres[i].getcoef();
        nb+=listeMatieres[i].getcoef();
    }
    if(nb==0){
        return 0;
    }
    return moyenne/nb;
}

void MoyenneGenerale(vector<Note> notes, Groupe grp, Etudiant e){
    vector<GroupeModule> ListeGroupeModule = grp.getListeModules();
    double MoyenneGroupeModule=0;
    double nb=0;
    for(int j=0;j<ListeGroupeModule.size();j++){
        MoyenneGroupeModule += (MoyenneParGroupeModule(notes,e,ListeGroupeModule[j]))*ListeGroupeModule[j].getCoefGM();
        nb +=ListeGroupeModule[j].getCoefGM();
    }
    cout<<" | "<< MoyenneGroupeModule/nb;
    afficherResultat(MoyenneGroupeModule/nb);
    afficherMention(MoyenneGroupeModule/nb);
    cout<<" | "<<endl;
}

void afficherPV(Groupe grp, vector<Note> notes){
    vector<Etudiant> ListeEtudiant = grp.getListeEtudiants();
    vector<GroupeModule> ListeGroupeModule = grp.getListeModules();
    cout<<"\t\t    |";
    for(int nomGm=0;nomGm<ListeGroupeModule.size();nomGm++){
        cout<<ListeGroupeModule[nomGm].getNomGM()<<"\t\t | ";
    }
    cout<<endl;
    cout<<"\t\t    |";
    for(int coefgm=0;coefgm<ListeGroupeModule.size();coefgm++){
        cout<<ListeGroupeModule[coefgm].getCoefGM()<<"\t\t\t | ";
    }
    cout<<endl;
    cout<<"\t\t    |";
    for(int nomMat=0;nomMat<ListeGroupeModule.size();nomMat++){
        vector<Matiere> ListeMatieres = ListeGroupeModule[nomMat].getListeMat();
        for(int b=0;b<ListeMatieres.size();b++){
            cout<<ListeMatieres[b].getnom()<<" | ";
        }
        cout<<"\t";
    }
    cout<<endl;
    cout<<"Liste des etudiants |";
    for(int nomMat=0;nomMat<ListeGroupeModule.size();nomMat++){
        vector<Matiere> ListeMatieres = ListeGroupeModule[nomMat].getListeMat();
        for(int b=0;b<ListeMatieres.size();b++){
            cout<<ListeMatieres[b].getcoef()<<"   | ";
        }
    }
    cout<<endl;
    for(int i =0; i<ListeEtudiant.size();i++){
        cout<<ListeEtudiant[i];
        for(int j=0;j<ListeGroupeModule.size();j++){
            vector<Matiere> ListeMatieres = ListeGroupeModule[j].getListeMat();
            for(int n=0;n<ListeMatieres.size();n++){
                cout<<" | "<<MoyenneParMatiere(notes, ListeEtudiant[i], ListeMatieres[n]);
            }
            cout<<" | "<<MoyenneParGroupeModule(notes,ListeEtudiant[i],ListeGroupeModule[j]);
        }
        MoyenneGenerale(notes,grp,ListeEtudiant[i]);
    }
}

int main(){
    Enseignant ens1(100,1,"ens1","aaaa","e1@gmail.com");
    Enseignant ens2(200,2,"ens2","ddd","e2@gmail.com");
    Enseignant ens3(300,3,"ens3","gggg","e3@gmail.com");
    Enseignant ens4(400,4,"ens4","ssss","e4@gmail.com");
    Enseignant ens5(500,5,"ens5","llll","e5@gmail.com");

    Etudiant et1(100,18,"et1","llll","et1@gmail.com");
    Etudiant et2(200,19,"et2","ggg","et2@gmail.com");
    Etudiant et3(300,20,"et3","hhhh","et3@gmail.com");
    Etudiant et4(400,21,"et4","dddd","et4@gmail.com");
    Etudiant et5(500,22,"et5","zzzz","et5@gmail.com");
    vector<Etudiant> listeEtudiant1={et1,et2,et3};
    vector<Etudiant> listeEtudiant2={et4,et5};


    Matiere m1("1","math",3,ens1);
    Matiere m2("2","algo",4,ens1);
    Matiere m3("3","c++",4,ens2);
    Matiere m4("4","c",2,ens4);
    Matiere m5("5","web",2,ens3);
    Matiere m6("6","algebre",1.5,ens5);
    vector<Matiere> listeMat1={m2,m3};
    vector<Matiere> listeMat2={m4,m5};
    vector<Matiere> listeMat3={m1,m6};

    GroupeModule gpm1("1","prog",8,listeMat1);
    GroupeModule gpm2("1","dev",4,listeMat2);
    GroupeModule gpm3("1","math",5,listeMat3);
    vector<GroupeModule> listeGroupeModule1={gpm1,gpm3};
    vector<GroupeModule> listeGroupeModule2={gpm2};

    Groupe gp1("1","Première","ING","INF",1,listeGroupeModule1,listeEtudiant1);
    Groupe gp2("2","Première","Master","INDUS",1,listeGroupeModule2,listeEtudiant2);

    vector<Groupe> listeGroupe={gp1,gp2};

    Note n1(m1,et1,15,"DS");
    Note n2(m1,et1,15,"EXAM");
    Note n3(m1,et1,15,"TP");

    Note n4(m6,et1,15,"EXAM");
    Note n5(m2,et1,18,"EXAM");
    Note n6(m3,et1,17,"EXAM");


    Note n7(m1,et2,14,"DS");
    Note n8(m1,et2,13,"EXAM");
    Note n9(m1,et2,17,"TP");

    Note n10(m6,et2,15,"EXAM");
    Note n11(m2,et2,7,"EXAM");
    Note n12(m3,et2,8,"EXAM");

    vector<Note> listeNote = {n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12};


    afficherPV(gp1, listeNote);

    return 0;
}
