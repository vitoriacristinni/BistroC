#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main()
{
 int op,mesas[10],status[10],i,nmesa,encontrou;

 for(i=0;i<10;i++)
 {
  status[i] = 0; //0 -> mesa livre, 1 -> mesa ocupada
  mesas[i] = i+1; //preenche o vetor com os números das mesas
 }
 op = 1;
 while(op!=7)
 {
  system("cls");
  printf("Bistro\n");
  printf("=============\n\n");
  printf("1- Reservar mesa\n");
  printf("2- Liberar mesa\n");
  printf("3- Alocar cliente\n");
  printf("4- Listar mesas ocupadas\n");
  printf("5- Listar mesas livres\n");
  printf("6- Listar todas as mesas\n");
  printf("7- Sair\n");
  printf("Escolha sua opcao: ");
  scanf("%d", &op);

  switch(op)
  {
   case 1:
     //realiza a reserva de uma mesa cujo numero foi informado.
     system("cls");
     printf("Informe o numero da mesa que deseja reservar: ");
     scanf("%d", &nmesa);
     if(status[nmesa-1]==1) //verifica se a mesa ja esta reservada
     {
      printf("Mesa ja reservada. Verifique outra opcao.");
      getch();
     }
     else
     {
      for(i=0;i<10;i++)
      {
       if(nmesa == mesas[i])
       {
        status[i] = 1;
        printf("Reserva realizada com sucesso!");
        getch();
       }
      }
     }
     break;
   case 2:

     system("cls");
     printf("Informe o numero da mesa que deseja liberar: ");
     scanf("%d", &nmesa);
     if(status[nmesa-1]==0) //verifica se a mesa ja esta liberada
     {
      printf("Esta mesa ja esta livre. Verifique outra opcao.");
      getch();
     }
     else
     {
      for(i=0;i<10;i++)
      {
       if(nmesa == mesas[i])
       {
        status[i] = 0;
        printf("Liberacao realizada com sucesso!");
        getch();
       }
      }
     }
     break;
   case 3:
     //Aloca o Cliente na primeira mesa livre encontrada.
     i = 0;
     encontrou = 0;
     while(i<10)
     {
       if(status[i]==0)
       {
         status[i]=1;
         printf("O cliente foi alocado na mesa: %d", mesas[i]);
         getch();
         i = 10;
         encontrou = 1;
       }
       i++;
     }
     if(encontrou==0)
     {
       printf("Nao existe mesa disponivel!");
       getch();
     }
     break;
   case 4:

     system("cls");
     printf("Mesas ocupadas\n");
     printf("==============\n\n");
     printf("Mesa  Status\n\n");
     encontrou = 0; //flag para saber se existe pelo menos uma mesa ocupada
     for(i=0;i<10;i++)
     {
      if(status[i]==1)
      {
        printf(" %d    Ocupada\n", mesas[i]);
        encontrou = 1;
      }
     }
     if(encontrou==0)
     {
      printf("Todas as mesas estao Livres");
     }
     getch();
     break;
   case 5:

     system("cls");
     printf("Mesas livres\n");
     printf("==============\n\n");
     printf("Mesa  Status\n\n");
     encontrou = 0;
     for(i=0;i<10;i++)
     {
      if(status[i]==0)
      {
        printf(" %d    Livre\n", mesas[i]);
        encontrou = 1;
      }
     }
     if(encontrou==0)
     {
      printf("Todas as mesas estao Ocupadas");
     }
     getch();
     break;
   case 6:

     system("cls");
     printf("Todas as Mesas\n");
     printf("==============\n\n");
     printf("Mesa  Status\n\n");
     encontrou = 0;
     for(i=0;i<10;i++)
     {
       if(status[i]==1) //Se a mesa esta OCUPADA
       {
         printf(" %d    Ocupada\n", mesas[i]);
       }
       else  //senão, a mesa esta LIVRE
       {
         printf(" %d    Livre\n", mesas[i]);
       }
     }
     getch();
     break;
   case 7:
     break;
   default:
     printf("Opcao invalida!");
     getch();
     break;
  }
 }
 return 0;
}
