#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

void viderBuffer(void)
{
   int c = 0;
   while (c != '\n' && c != EOF)
   {
      c = getchar();
   }
}


int main(void)
{
   char reponse[3] = "";

   printf("BONJOUR ! VOULEZ-VOUS FERMER CE PROGRAMME ??? [O/N]\n");

   do
   {
      if(! (fgets(reponse, 3, stdin)) )
      {
         printf("OH ! IL Y A EU UNE ERREUR !!!\n"
               "ON FERME LE PROGRAMME !\n");
         exit(-1);
      }
      
      reponse[0] = toupper(reponse[0]);

      if(reponse[1] != '\n')
      {
         printf("IL FAUT QUE TU ME REPONDES AVEC O POUR DIRE OUI OU N POUR DIRE NON !!!\n");
         viderBuffer();
      }
      else
      {
         switch(reponse[0])
         {
            case 'O' :
               printf("OK AU REVOIR !!!\n");
               return 0;
            
            case 'N' :
               printf("OK !\n");
               sleep(5);
               printf("ET MAINTENANT ???\n");
               break;
            
            default :
            printf("IL FAUT QUE TU ME REPONDES AVEC O POUR DIRE OUI OU N POUR DIRE NON !!!");
         }
      }
   } while(1);
}
