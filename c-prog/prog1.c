#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define	 immagine_in_lettura            "../image/babbuinocolori.txt"           /* immagine in lettura in forma matriciale */
#define	 immagine_in_scrittura_ppm	"../image/img1.ppm"       /* immagine in scrittura  in forma pgm */
#define  immagine_in_scrittura          "../image/img1.txt"           /* immagine in scrittura in forma matriciale */



#define  N 	        256	/*     numero di colonne dell'immagine      */
#define  M 	        256	/*     numero di righe dell'immagine        */


double immagine_originale_rossa[M][N],immagine_originale_verde[M][N],immagine_originale_blu[M][N], immagine_degradata_rossa[M][N],immagine_degradata_verde[M][N],immagine_degradata_blu[M][N];


void leggi() // legge il file dell'immagine originale e lo mette nella matrice immagine_originale
{
  FILE *fp;    // puntare ad un file
  int i,j;     // indici per scorrere l'immagine
  int temp, temp2;    // variabile temporanea per trasformare un intero in un double
	
  fp=fopen(immagine_in_lettura,"r"); // apertura del file in lettura
  for (i=0;i<M;i++)
    for (j=0;j<N;j++)
      {
	temp2=fscanf(fp,"%d",&temp);        // lettura della componente rossa
	immagine_originale_rossa[i][j]=temp;   // conversione da intero in double
        temp2=fscanf(fp,"%d",&temp);        // lettura della componente verde
	immagine_originale_verde[i][j]=temp;   // conversione da intero in double
        temp2=fscanf(fp,"%d",&temp);        // lettura della componente blu
	immagine_originale_blu[i][j]=temp;   // conversione da intero in double
      }
  fclose(fp); // chiusura del file
}


void scrivippm() // scrive la matrice immagine_degradata su un file formato pgm
{
  FILE *fp;    // puntare ad un file
  int i,j;     // indici per scorrere l'immagine
  int temp;    // variabile temporanea per trasformare un double in un intero
	
  fp=fopen(immagine_in_scrittura_ppm,"w"); // apertura di un file in scrittura
  fprintf(fp,"P3 \n %d %d \n 255 \n",N,M); // scrive l'intestazione del file pgm
  for (i=0;i<M;i++)
    {
      for (j=0;j<N;j++)
	{
	  temp=immagine_degradata_rossa[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
	  temp=immagine_degradata_verde[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
          temp=immagine_degradata_blu[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
	}
      fprintf(fp,"\n");
    }
  fclose(fp);   // chiusura del file 
}


void scrivi() // scrive la matrice immagine_degradata su un file
{
  FILE *fp;    // puntare ad un file
  int i,j;     // indici per scorrere l'immagine
  int temp;    // variabile temporanea per trasformare un double in un intero
  fp=fopen(immagine_in_scrittura,"w"); // apertura di un file in scrittura
  for (i=0;i<M;i++)
    {
      for (j=0;j<N;j++)
	{
	  temp=immagine_degradata_rossa[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
	  temp=immagine_degradata_verde[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
          temp=immagine_degradata_blu[i][j]; // conversione da double in intero
	  if (temp<0)                    // controllo dei limiti superiori e inferiori sulla scala di grigio
	    temp=0;
	  if (temp>255)
	    temp=255;
	  if (temp>9)                     // scrittura su un file con incolonnamento
	    {
	      if (temp>99)
		fprintf(fp," %d",temp);   // scrittura di uno spazio e tre cifre significative
	      else
		fprintf(fp,"  %d",temp);  // scrittura di due spazi e due  cifre significative
	    }
	  else
	    fprintf(fp,"   %d",temp);     // scrittura di tre spazi e una  cifra significativa
	}
      fprintf(fp,"\n");
    }
  fclose(fp);   // chiusura del file 
}




/*  Programma Principale  */
main()
{
  int j,i,m;
  leggi();                  // lettura dai dati dal file
    
    //ricopio originale
    for(i = 0; i < M; i++){
      for (j = 0; j < N; j++){
	immagine_degradata_rossa[i][j] = immagine_originale_rossa[i][j];
	immagine_degradata_verde[i][j] = immagine_originale_verde[i][j];
	immagine_degradata_blu[i][j] = immagine_originale_blu[i][j];
      }
    }
    
    //disegno occhiali
    for(i = 0; i < M; i++){
      for (j = 0; j < N; j++){
	if((j - 85) * (j - 85) + (i - 35) * (i - 35) < 900 &&
	   (j - 85) * (j - 85) + (i - 35) * (i - 35) > 700)
	{
	  immagine_degradata_rossa[i][j] = 255;
	  immagine_degradata_verde[i][j] = 255;
	  immagine_degradata_blu[i][j] = 255;
	}
	else if((j - 165) * (j - 165) + (i - 35) * (i - 35) < 900 &&
	   (j - 165) * (j - 165) + (i - 35) * (i - 35) > 700)
	{
	  immagine_degradata_rossa[i][j] = 255;
	  immagine_degradata_verde[i][j] = 255;
	  immagine_degradata_blu[i][j] = 255;
	}
      }
    }
    
    //coloro lenti
    for(i = 0; i < M; i++){
      for (j = 0; j < N; j++){
	if((j - 85) * (j - 85) + (i - 35) * (i - 35) <= 700){
	  immagine_degradata_verde[i][j] = 0;
	}
	else if((j - 165) * (j - 165) + (i - 35) * (i - 35) <= 700){
	  immagine_degradata_blu[i][j] = 0;
	}
      }
    }
  
  scrivippm();                   // scrittura dell'immagine in formato pgm
  scrivi();                      // scrittura dell'immagine in formato matriciale

}


