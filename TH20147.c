#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//to path sto pc moy
#define PA "D:\\1HMU\\Domhmenos Programmatismos\\Ergasies\\4 2019\\DataMeteoE4.txt"
#define LL 80

typedef struct{
char date[11];
char hour[9];
long int ak;
char volt[5];
char thermk[5];
char apsyn[5];
char olpi[5];
char dp[5];
char thermp[5];
}line;

void er1(line** z,int i);
void er2(line* x);

void apsn(float *aps){
	const float met=10.0*10-6;
	float met1= *aps/met;
	printf("%f\n",met1);
	met1 += *aps;
	printf("%f\n",met1);
}

void ol(float *aps){
	const float met=8.0*10-6;
	float met1= *aps/met;
	printf("%f\n",met1);
	met1 += *aps;
	printf("%f\n",met1);
}

void dpe(float *aps){
	const float met=9.0*10-6;
	float met1= *aps/met;
	printf("%f\n",met1);
	met1 += *aps;
	printf("%f\n",met1);
}

void er3(line* x){
	float pin[3];
	pin[0]= atof(x->apsyn);
	pin[1]= atof(x->olpi);
	pin[2]= atof(x->dp);
	apsn(&pin[0]);
	ol(&pin[1]);
	dpe(&pin[2]);

}

void main(){
	   setlocale(LC_NUMERIC, "C");
	//ena string gia to diavasma 1as grammhs
	char buffer[LL];
	//deikths se deiktes domhs line
	//xrhsh ws pinakas
	line **read;
  //anoigma arxeiou
  FILE *f = fopen(PA,"r");
  //desmeush mnhmhs gia 1 line
  read = (line **)malloc( sizeof(line *) );
  //diathrhsh mege8ous pinaka
	size_t size = sizeof(read);
	//mhkos pinka,poses 8eseis
  int i=0;
	//voh8itikh metavlhth
	line help;
  while (!feof(f)) {
		//diavasma 1as grammhs
		fgets(buffer, LL, f);
		//"metafrash" grammhs se domh
  	sscanf(buffer ,"%s %s %li %s %s %s %s %s %s",help.date,help.hour,&help.ak,help.volt,help.thermk,help.apsyn,help.olpi,help.dp,help.thermp);
    //aukshsh mege8ous pinaka
		printf("Erwthma 2o\n");
		er2(&help);
		er3(&help);
		size = size + sizeof(help);
		read = (line**) realloc (read,size );
		//desmeush xwrou gia 1 8esh
		read[i] = (line *)malloc( sizeof(help) );
		//ana8esh timhs
  	*read[i] = help;
  	i++;
  }
 int j ;
 for(j = 0; j<=i-1; j++){
	 printf("%s\n",read[j]->hour);
 }

 fclose(f);

 er1(read,i);

}

void er1(line** z,int i){
	printf("Erwthma 1\n");
for (int j=0; j<=i-1; j++){
	if (atof(z[j]->thermk)>26.5 && atof(z[j]->thermk)<32.5){
     printf("%s %s %lf\n", z[j]->date, z[j]->hour,atof(z[j]->thermk));
	}
}
}

 void er2(line* x){
   float pin1[3]= {10.0*10-6 ,8.0*10-6 ,9.0*10-6 };

	 float pin[4];
   pin[0]= atof(x->apsyn);
	 pin[1]= atof(x->olpi);
	 pin[2]= atof(x->dp);

	 for( int i=0;i<=2;i++){
		 //ston pin3 apothikeyw to G
		 pin[3] = pin[i]/pin1[i];
		 printf("%f \n",pin[3]);
		 pin[3]+=pin[i];
		 printf("%f\n",pin[3]);
	 }
 }
