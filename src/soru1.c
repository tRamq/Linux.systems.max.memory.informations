#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "fields.h"


int main(){

IS  dosya;
 
	int c=getpid();
	char l[25];
	sprintf(l,"%d",c);
	char h[25];
	strcpy(h,"/proc/");
	strcat(h,l);
	strcat(h,"/smaps");

	char* s;
	s= (char *) malloc(200);

	char z[30];
	strcpy(z,"cat /proc/");
	strcat(z,l);
	strcat(z,"/smaps");
	

	dosya=new_inputstruct(h);
	
	 int size=0;
	char boyut[20];
	int x=999999;
	int f=3333333;
	int y=999998;
	int a =0;

	while(get_line(dosya) >= 0)
    {
	
	for(int i=0;i<dosya->NF;i++)
	{

	
		if(strstr(dosya->fields[i],"[stack]")!=NULL)
		{
			printf("\nStack Baslangic..:");
			x=dosya->line;
			for(int j=0;j<12;j++)
			printf("%c",dosya->text1[j]);
		}
		
		else if(dosya->line==x+1 && strstr(dosya->text1,"Size") != NULL)
		{
			x=9999999;
			size=0;
			int carp=1;
			
			for(int j=strlen(dosya->text1)-1;j>=0;j--)
			{
				if(dosya->text1[j] >='0' && dosya->text1[j] <= '9')
				{
					size +=(dosya->text1[j]-48)*carp;
					carp *=10;
				}
			}

			printf("  Boyutu..:  %d byte\n",size*1024);
			
		}

		else if(strstr(dosya->fields[i],"[heap]")!=NULL)
		{
			printf("\nHeap Baslangic..:");
			y=dosya->line;
			for(int j=0;j<12;j++)
			printf("%c",dosya->text1[j]);
		}
		
		else if(dosya->line==y+1 && strstr(dosya->text1,"Size") != NULL)
		{
			y=19991212;
			size=0;
			int carp=1;
			for(int j=strlen(dosya->text1)-1;j>=0;j--)
			{
				if(dosya->text1[j] >='0' && dosya->text1[j] <= '9')
				{
					size +=(dosya->text1[j]-48)*carp;
					carp *=10;
				}
			}

			printf("   Boyutu..:  %d byte \n",size*1024);
			
		}
		/*else if(strstr(dosya->fields[i],"/soru1") && strstr(dosya->fields[i],"8 kB"))
		{
			a++;
		}*/
			//&& strstr(dosya->fields[i],"4 kB")
		else if(strstr(dosya->fields[i],"/soru1")!= NULL )
		{
			a++;
			if(a==2){
				f=dosya->line;
				printf("\nData Baslangic..:");
			for(int j=0;j<12;j++)
			printf("%c",dosya->text1[j]);
		}

		}		
		else if(dosya->line==f+1 && strstr(dosya->text1,"Size") != NULL)
		{
			f=4555;
			size=0;
			int carp=1;
			for(int j=strlen(dosya->text1)-1;j>=0;j--)
			{
				if(dosya->text1[j] >='0' && dosya->text1[j] <= '9')
				{
					size +=(dosya->text1[j]-48)*carp;
					carp *=10;
				}
			}

			printf("   Boyutu..:  %d byte \n",size*1024);
		}


	}

	}
free(s);

 jettison_inputstruct(dosya);
exit(0);

}







