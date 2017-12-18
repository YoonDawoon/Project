#include<stdio.h>
#include<termio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct Table
{
    int pch, ppo, pom, pbe, pso, ppeo, total, total2, so, be, num;
}table;
typedef struct Date
{
    int day;
    int income;
    struct Table ta;
}date;
table t[SIZE];
date d[SIZE];
void check(int, int);
void people(int);
void order(int, int);
void list(int);
void pay(int);
void tanum(void);
void _list(int);
void sales(int);
int total(int);
int Memo();

const char chi[10] = "Chicken";
const char por[10] = "Pork";
const char oml[10] = "Omlet";
const char bee[10] = "Beer";
const char soj[10] = "Soju";
const int price[5] = { 20000, 13000, 18000, 4000, 3500 };
int sonum=0, benum=0;

int main(void)
{

     int select;
     int i=0;
     printf("=====POS=====\n\n");
     do
     {
         printf("DATE: ");
         scanf("%d", &d[i].day);
         if(d[i].day == 0)
             break;
     do
     {
         printf("1. People \n2. Order\n3. Order List\n4. Calculate\n5. Day's sales\n6. Quit \n");
         printf("Select : ");
         scanf("%d", &select);
         system("clear");
         check(select, i);
         if(select == 6)
             Memo(d[i].day);
     }
     while (select != 6);
     i++;
     }while(1);
 }

 void tanum(void)
 {
     if(t[1].num!=0)
         printf("table No.1(full) \n");
     if(t[2].num!=0)
         printf("table No.2(full) \n");
     if(t[3].num!=0)
         printf("table No.3(full) \n");
     if(t[4].num!=0)
         printf("table No.4(full) \n");
     if(t[5].num!=0)
         printf("table No.5(full) \n");
 }
 void check(int _select, int _i)
 {
     int ts;
     switch (_select)
     {
     case 1:
         tanum();         
			do
         {
             printf("Select the table : ");
             scanf("%d", &ts);
             if (ts >5 || ts<1)
                 printf("Our Bar have 1~5 Table!!!\n");
         } while (ts > 5 || ts < 1);
         t[ts].num++;
         people(ts);
         break;
     case 2:
         tanum();
         do
         {
             printf("Select the table : ");
             scanf("%d", &ts);
             if (ts >5 || ts<1)
                 printf("Our Bar have 1~5 Table!!!\n");
         } while (ts > 5 || ts < 1);
         order(ts,_i);
         break;
     case 3:
         tanum();
         do
         {
             printf("Select the table : ");
             scanf("%d", &ts);
             if (ts >5 || ts<1)
                 printf("Our Bar have 1~5 Table!!!\n");
         } while (ts > 5 || ts < 1);
         list(ts);
         break;
     case 4:
         tanum();
         do
         {
             printf("Select the table : ");
             scanf("%d", &ts);
             if (ts >5 || ts<1)
                 printf("Our Bar have 1~5 Table!!!\n");
         } while (ts > 5 || ts < 1);
         pay(ts);
         break;
     case 5:
         sales(_i);
         break;
     case 6:
         break;
     default:
         printf("There are not exist");
         break;
     }
 }
 void people(int i)
 {
     int k;
     system("clear");
     do
     {
         printf("How Many People Are You Come Together?: ");
         scanf("%d", &t[i].ppeo);
         system("clear");
         if (t[i].ppeo <= 0)
             printf("Under 0 People Can't Come \n");
     } while (t[i].ppeo <= 0);
 }
 void order(int i, int a)
 {
     int select;
     int order = 0;
     system("clear");
     do
     {
         printf("=====Order====\n");
         printf("(If you want cancle, input '-')\n\n");
         printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. Quit\n\n", chi, por, oml, bee, soj);
         printf("Select : ");
         scanf("%d", &select);
         switch (select)
         {
         case 1:
             order += price[0];
             t[i].pch++;
             break;
         case -1:
             if(t[i].pch>0){
             order -= price[0];
             t[i].pch--;}
             break;
         case 2:
             order += price[1];
             t[i].ppo++;
             break;
         case -2:
             if(t[i].ppo>0){
             order -= price[1];
             t[i].ppo--;}
             break;
         case 3:
             order += price[2];
             t[i].pom++;
             break;
         case -3:
             if(t[i].pom>0){
             order -= price[2];
             t[i].pom--;}
             break;
         case 4:
             order += price[3];
             t[i].pbe++;
             d[a].ta.be++;
             break;
         case -4:
             if(t[i].pbe>0){
             order -= price[3];
             t[i].pbe--;
             d[a].ta.be--;}
             break;
         case 5:
             order += price[4];
             t[i].pso++;
             d[a].ta.so++;
             break;
         case -5:
             if(t[i].pso>0){
             order -= price[4];
             t[i].pso--;
             d[a].ta.so--;}
             break;
         case 6:
             break;
         default:
             printf("Error \n");
         }
         system("clear");
         _list(i);
     }
     while (select != 6);
     system("clear");
 }
 void list(int i)
 {
     int j;
     do
     {
         printf("=====Order List=====\n\n");
         _list(i);
         printf("Quit>>0 : ");
         scanf("%d", &j);
     }while (j != 0);
     system("clear");
 }
 void pay(int i)
 {
     int j, k;
     int getm;
     int result=total(i);
     int n = result%t[i].ppeo;
     int nn = result/t[i].ppeo;
     do
     {
         printf("====Calculate====\n");
         _list(i);
         printf("\n1. Pay\n");
         printf("2. Cancle \n\n");
         printf("Select : ");
         scanf("%d", &j);
         if (j == 1)
         {
             if(n != 0){
             printf("You Cannot Use Dutchpay\n");
             k = 1;}
             if(n == 0){
                 printf("1 Per Person Pay: %d\n",nn);
             printf("If you want to dutch pay Press 1, If you don't want Press Any Number : ");}
             scanf("%d", &k);
             switch (k)
             {
             case 1:
                 do
                 {
                     printf("Received Money: ");
                     scanf("%d", &getm);
                     result -= getm*t[i].ppeo;
                     if (result < 0)
                     {
                         printf("Remain : %d\n", (-1)*result);
                         printf("Change return:");
                         scanf("%d", &getm);
                         result = result - getm;
                     }
                 } while (result != 0);
                t[i].total2 = t[i].total;
                 system("clear");
                 break;
             default:
                 do
                 {
                     printf("Received Money: ");
                     scanf("%d", &getm);
                     result -= getm;
                     if (result >= 0)
                         printf("Balance : %d\n", result);
                     if (result < 0)
                     {
                         printf("Change: %d\n", (-1)*result);
                         printf("Change return:");
                         scanf("%d", &getm);
                         result = result + getm;
                     }
                 } while (result != 0);
                 t[i].total2 = t[i].total;
                 system("clear");
                 break;
             }
             t[i].num=0;
             if (t[i].pch != 0)
                 t[i].pch=0;
             if (t[i].ppo != 0)
                 t[i].ppo=0;
             if (t[i].pom != 0)
                 t[i].pom=0;
             if (t[i].pbe != 0)
                 t[i].pbe=0;
             if (t[i].pso != 0)
                 t[i].pso=0;
         }
             if (j==2)
                 break;
     }while (j != 2 && result != 0);
 }
 void _list(int i)
 {
     if (t[i].pch != 0)
         printf("%s(%d) : %dwon\n", chi, t[i].pch, t[i].pch*price[0]);
     if (t[i].ppo != 0)
         printf("%s(%d) : %dwon\n", por, t[i].ppo, t[i].ppo*price[1]);
     if (t[i].pom != 0)
         printf("%s(%d) : %dwon\n", oml, t[i].pom, t[i].pom*price[2]);
     if (t[i].pbe != 0)
         printf("%s(%d) : %dwon\n", bee, t[i].pbe, t[i].pbe*price[3]);
     if (t[i].pso != 0)
         printf("%s(%d) : %dwon\n", soj, t[i].pso, t[i].pso*price[4]);
     printf("Total : %dwon\n", total(i));
 }
 void sales(int a)
 {
     int i, j;
     for (i = 1; i < 6; i++)
     {
         d[a].income += t[i].total2;
     }
     printf("Day's sales:%d \n", d[a].income);
     for (i = 1; i < 6; i++)
     {
         t[i].total2=0;
     }
     printf("The number of beer: %d \n", d[a].ta.be);
     printf("The number of soju: %d \n", d[a].ta.so);
     printf("1. Delete, 2. Quit:");
     scanf("%d", &j);
     switch (j)
     {
     case 1:
         a = 0;
         break;
     case 2:
         break;
     default:
         break;
     }
     system("clear");
 }
 int total(int i)
 {
     t[i].total = ((price[0] * t[i].pch) + (price[1] * t[i].ppo) + (price[2] * t[i].pom) + (price[3] * t[i].pbe) + (price[4] * t[i].pso));
     return t[i].total;
 }
 int Memo()
 {
     FILE *fp;
     int i=0;

     fp = fopen("a.txt", "a+");
     if(fp == NULL)
     {
         printf("Cannot Make File.\n");
         return 1;
     }
     else
     {
         do{
         printf("==============\n");
         printf("DATE: %d\n", d[i].day);
         printf("Today: %d\n", d[i].income);
         printf("The number of beer: %d\n", d[i].ta.be);
         printf("The number of soju: %d\n", d[i].ta.so);
         i++;
         }while(d[i].day != 0);
     }

     fclose(fp);

     return 0;
 }
