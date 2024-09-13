#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct
{
    int jour ;
    int mois;
    int anne ;
} date_naissance;
typedef struct
{
    int id;
    char nom[50];
    char prenom[50];
    date_naissance date ;
    char departement[3];
    float note_generale;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nmbrAjouter;


//verifie unique  id


int verifierUniqueId(int id)
{
    for(int i=0; i<nmbrAjouter; i++)
    {
        if(etudiants[i].id==id)
        {
            return 1;
        }
    }
    return 0;
}

// fonction qui return date de naissance


date_naissance returnDateDeNaissance()
{
    date_naissance date;
    do
    {
        printf("Joure de naissance : ");
        scanf("%d", &date.jour);
    }
    while(date.jour<1  || date.jour>31);

    do
    {
        printf("Mois de naissance : ");
        scanf("%d", &date.mois);
    }
    while(date.mois<1 || date.mois>12);

    do
    {
        printf("Annes de naissance : ");
        scanf("%d",&date.anne);
    }
    while(date.anne<1980 || date.anne>2016);

    return date;

}



// Fonction pour ajouter un étudiant

Etudiant  ajouterEtudiant()
{
    Etudiant etudiant ;
    int choixdepa =0;

    printf("Ajouter les information d'etudiants : \n");

    do
    {
        printf("Numero unique: ");
        scanf("%d", &etudiant.id);
    }
    while(verifierUniqueId(etudiant.id)==1);

    printf("Nom: ");
    fflush(stdin);
    gets(etudiant.nom);

    printf("Prenom: ");
    fflush(stdin);
    gets(etudiant.prenom);

    etudiant.date=returnDateDeNaissance();

    do
    {
        printf(" Departement:  \n");
        printf("\t1.smi \n");
        printf("\t2.smp \n");
        printf("\t3.ige \n");
        scanf(" %d",&choixdepa);
        switch(choixdepa)
        {
        case 1:
            strcpy(etudiant.departement,"smi");

            break;
        case 2:
            strcpy(etudiant.departement,"smp");
            break;
        case 3:
            strcpy(etudiant.departement,"ige");
            break;
        default:
            printf(" il ya seulement trois choix !! \n");
            break;
        }
    }
    while(choixdepa< 1 || choixdepa > 3);


    do
    {
        printf("La note est entre 00.00 et 20.00 \n");
        printf("Note generale : ");
        scanf("%f", &etudiant.note_generale);

    }
    while(etudiant.note_generale<0 || etudiant.note_generale>20);


    return etudiant;

}



// ajouter plusiur etudiant

void ajouterPlusieurEtudiant(int n)
{
    int i;
    for( i=0 ; i<n ; i++)




    {
        etudiants[i]=ajouterEtudiant();
    }
}



// Fonction pour modifier un étudiant

void modifierEtudiant(int id_modifier)
{


    for (int i = 0; i < nmbrAjouter; i++)
    {
        if (etudiants[i].id == id_modifier)
        {
            etudiants[i]=ajouterEtudiant();

        }


    }
}

// Fonction pour supprimer un étudiant

void supprimerEtudiant(int idSuprimer)
{
    for (int i = 0; i < nmbrAjouter; i++)
    {
        if (etudiants[i].id == idSuprimer)
        {
            for (int j = i; j < nmbrAjouter - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }
            nmbrAjouter--;
            printf("Etudiant supprime avec succes !\n");

        }

    }
}

// Fonction pour afficher les détails d'un étudiant

void afficherEtudiant(int id)
{
    for (int i = 0; i < nmbrAjouter; i++)
    {
        if (etudiants[i].id == id)
        {   printf("\n");
            printf("les details d'etudiants est :\n");
            printf("Numero unique: %d \n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %d / %d / %d \n", etudiants[i].date.jour,etudiants[i].date.mois,etudiants[i].date.anne);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].note_generale);
            printf("\n");
            return;
        }
    }
    printf("Etudiant avec nomero unique %d non trouve.\n", id);
}




// fonction return combien d'etudiant dans chaque departement

int nmbreEtudiantsDansChaqueDepart(char depart[100])
{

    int nmbrEtudiants=0 ;

    for (int i = 0; i <nmbrAjouter ; i++)
    {
        if (strcmp(etudiants[i].departement,depart)==0)
        {
            nmbrEtudiants ++;

        }
    }
    return nmbrEtudiants ;
}

//foncttion calculer la moyenne  de chaque département

float calculeMoyenneChaqueDepart(char depart[100] )
{

    float somme=0;
    int count=0;
    for(int i=0; i<nmbrAjouter; i++)
    {
        if(strcmp(etudiants[i].departement,depart)==0)
        {
            somme +=etudiants[i].note_generale;
            count++;
        }
    }
    if(count==0)
    {
        return 0;
    }
    return somme / count;
}
//calculer le moyenne general

float calculerMoyenneGeneral()
{
    float sommeG=0;
    for(int i=0; i<nmbrAjouter ; i++)
    {

        sommeG += etudiants[i].note_generale ;

    }
    return sommeG/nmbrAjouter;
}
//Afficher le nombre total d'étudiants inscrits.

int calculerNombreEtudiantsInscri()
{
    int inscri=0;
    for(int i=0; i<nmbrAjouter ; i++)
    {

        inscri++;
    }
    return inscri;

}



// affiche nombre de chaque depart

    int afficheNombreEtudiantParDepart(char depart[100])
    {
        int nmbrEtudiants=0 ;


        for (int i = 0; i <nmbrAjouter ; i++)

        {
            if (strcmp(etudiants[i].departement,depart)==0)
            {
                nmbrEtudiants ++;
            }


        }
        return nmbrEtudiants;

    }

// Fonction pour afficher les statistiques

    void etudiantsAyantLesMeilleuresNotes()
    {
        Etudiant temps ;

        int totalReussite = 0;
        for (int i = 0; i < nmbrAjouter; i++)
        {
            for(int j=0 ; j<i; j++)
            {
                if (etudiants[j].note_generale>etudiants[i].note_generale && etudiants[i].note_generale >= 10.0)
                {
                    temps=etudiants[j];
                    etudiants[j]=etudiants[i];
                    etudiants[i]=temps;
                    totalReussite++;
                }
            }
            afficherEtudiant(etudiants[i].id);
        }


    }
//Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.

    void etudiantAyantUnM(float seuil)
    {

        for(int i=0; i<nmbrAjouter; i++)
        {

            printf("les etudiants %d",etudiants[i].id);
            if(etudiants[i].note_generale>seuil)
            {
                printf("les etudiants %d",etudiants[i].id);
                afficherEtudiant(etudiants[i].id);

            }
        }

    }



// Fonction de recherche d'un étudiant par nom

    void rechercherEtudiant(char* nom)
    {
        for (int i = 0; i < nmbrAjouter; i++)
        {
            if (strcmp(etudiants[i].nom, nom) == 0)
            {
                afficherEtudiant(etudiants[i].id);
            }
        }
    }
//Afficher la liste des étudiants inscrits dans un département spécifique

    void afficheListeEtudiantsDansChaqueDepart(char depart)
    {
        for (int i = 0; i < nmbrAjouter; i++)
        {
            if (strcmp(etudiants[i].departement,depart)==0)
            {
                afficherEtudiant(etudiants[i].id);
            }
        }
    }


// Fonction de tri des étudiants par nom
    void tri()
    {
        printf("les etudiants avant le tri : \n");
        afficheEtudeDeTri();
        Etudiant temp ;
        for(int i=0; i<nmbrAjouter; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(etudiants[j].note_generale>etudiants[i].note_generale)
                {
                    temp=etudiants[j];
                    etudiants[j]=etudiants[i];
                    etudiants[i]=temp;
                }
            }
        }
        printf("Les etudiants apres le tri : \n");
        afficheEtudeDeTri();
    }
 //Tri des étudiants selon leur statut de réussite (ceux ayant une moyenne supérieure ou égale à 10/20)

    void triStatusReussite()
    {


        printf("Etudiants reussis (moyenne >= 10) :\n");
    for (int i = 0; i < nmbrAjouter; i++) {
        if (etudiants[i].note_generale >= 10) {
            afficherEtudiant(etudiants[i].id);
        }
    }

    }

// affiche des etudiants par les condition dans autre fonction

    void afficheEtudeDeTri()
    {

        for(int i=0; i<nmbrAjouter; i++)
        {
            afficherEtudiant(etudiants[i].id);
        }


    }



// Fonction principale

int main()
    {

        int  idModifier;
        int idSuprimer;
        int idAffiche;
        float seuil;
        int choix;
        char nom[50];
        char departRecherche[100];
        char departMoyenne [100];
        char departInscri[100];







        do
        {                        printf("\n");
            printf("\t\t\t\t\t--- <<  MENU PRINCIPAL  >> ---\n");
            printf("\n ");
            printf("1. Ajouter un etudiant\n");
            printf("2. Modifier un etudiant\n");
            printf("3. Supprimer un etudiant\n");
            printf("4. Afficher les details d'un etudiant\n");
            printf("Afficher les statistiques:\n");

            printf("5.\tCalculer la moyenne generale\n");
            printf("6.\tAfficher la moyenne generale de chaque departement\n");
            printf("7.\tAfficher le nombre total d'etudiants inscrits \n");
            printf("8.\tAfficher les etudiante ayant les meilleures note\n");
            printf("9.\tAfficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
            printf("Rechercher un etudiant par:\n");
            printf("10.\tAfficher nombre d'etudiants dans chaque departement\n");
            printf("11.\tRechercher un etudiant par son nom\n");
            printf("Trier un etudiant par:\n");
            printf("12.\tAfficher liste des etudiants inscrits dans un departement specifique\n");
            printf("13.\tAfficher le triage des etudiants par moyenne generale, du plus eleve au plus faible ou inversement\n");
            printf("14.\tAfficher triage des etudiants selon leur statut de reussite (ceux ayant une moyenne superieure)\n");
            printf("15.\tQuittez\n");
            printf("Choix: ");
            scanf("%d",&choix);


            switch (choix)
            {
            case 1:
                printf("combien d'etuiants que vous ajouter :");
                scanf("%d",&nmbrAjouter);
                if(nmbrAjouter<MAX_ETUDIANTS)
                {


                    ajouterPlusieurEtudiant(nmbrAjouter);
                }
                break;
            case 2:
                do
                {
                    printf("Entrez le numero unique de l'etudiant a modifier: ");
                    scanf("%d", &idModifier);
                }
                while(verifierUniqueId(idModifier)==0);
                printf("Enter les nouveaux information de %d : \n",idModifier);
                modifierEtudiant(idModifier);
                break;
            case 3:
                printf("\n");
                printf("Entrez le numero unique de l'etudiant a supprimer: ");
                scanf("%d", &idSuprimer);
                supprimerEtudiant(idSuprimer);
                break;
            case 4:
                printf("\n");
                do
                {
                    printf("Entrez le numero unique de l'etudiant a afficher: ");
                    scanf("%d", &idAffiche);
                }
                while(verifierUniqueId(idAffiche)==0);
                printf("les detailes d'etudiants est :\n");
                afficherEtudiant(idAffiche);
                break;
            case 5:
                printf("La moyenne general est : %.2f",calculerMoyenneGeneral());
                break;
            case 6:
                printf("Entre un depart :");
                scanf("%s",departMoyenne);
                printf("Le moyenne de departements %s est :%.2f\n",departMoyenne,calculeMoyenneChaqueDepart(departMoyenne));
                break;
            case 7:
                printf("\n");
                printf("Total d'etudiants inscri est : %d",calculerNombreEtudiantsInscri());
                break;
            case 8:
                printf("\n");
                printf("Les etudiante ayant les meilleures note est : \n");
                etudiantsAyantLesMeilleuresNotes();
                break;


            case 9:
                printf("\n");
                printf("Entre le seuil :");
                scanf("%f",&seuil);
                printf("\n");
                printf("les etudiants ayant une moyenne generale superieure à un certain seuil : ");
                etudiantAyantUnM(seuil);
                break;
            case 10:
                printf("\n");
                printf("Entrer le departement que vous voullez voir nombre d'ainscription :" );
                scanf("%s",departInscri);
                printf("\n");
                printf("Le nombre d'etudiants dans chaque departement: %d \n",afficheNombreEtudiantParDepart(departInscri));
                break;
            case 11:
                printf("\n");
                printf("Entrez le nom de l'etudiant a rechercher: ");
                scanf("%s", nom);
                rechercherEtudiant(nom);
                break;
            case 12:
                printf("\n");
                printf("Entrez le departemete a rechercher: ");
                scanf("%s", departRecherche);
                printf("\n");
                printf("liste des etudiants inscrits dans un departement specifique :\n");
                afficheListeEtudiantsDansChaqueDepart(departRecherche);

                break;
            case 13:
                printf("\n");
                printf("le tri par note :\n");
                tri();
                break;
            case 14:
                printf("\n");
                triStatusReussite();
                break;
            case 15:
                printf("\n");
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix non valide.\n");
            }
        }

        while (choix != 16 );
        return 0;
        }
