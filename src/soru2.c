#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000


int main(int argc,char** argv)
{
    
    FILE * dosyaoku;

    char tampon[BUFFER_SIZE];

    int kelimesay = 0;

    dosyaoku= fopen(argv[2], "r");
    
    if(dosyaoku == NULL)
    {
        printf("DOSYA HATASI!!!!.\n");
       
        exit(1);
    }

    printf("Dosya açıldı. \n");

    int i=0;
    
    int satir=0;    
    
    while(fgets(tampon, BUFFER_SIZE, dosyaoku) != NULL) 
    {
        
        kelimesay = strlen(tampon);
        if(strcmp(argv[1],"-r")==0){
        satir++;
        if(strstr(tampon,"strcpy(")!=NULL)
        {
            printf("%d. satir: strcpy kullanilmiş yerine strlcpy kullanmalisiniz\n",satir);
        } 
        
        else if((strstr(tampon,"getpw(")!=NULL) && (strstr(tampon,"getpwuid")==NULL))
        {
            printf("%d. satir: getpw kullanilmis yerine getpw kullanmalisiniz. \n",satir);
        }
        
        else if(strstr(tampon,"strcat(")!=NULL)
        {
            printf("%d. satir: strcat kullanilmis yerine strlcat kullanmalisiniz. \n",satir);
        }
         else if(strstr(tampon,"sprintf(")!=NULL)
        {
            printf("%d. satir: sprintf kullanilmis yerine snprintf kullanmalisiniz. \n",satir);
        }else if(strstr(tampon,"strcpy(")!=NULL)
        {
            printf("%d. satir: strcpy kullanilmis yerine strlcpy kullanmalisiniz. \n",satir);
        }

         else if(strstr(tampon,"gets(")!=NULL  && strstr(tampon,"fgets") == NULL)
        {
            printf("%d. satir:  gets kullanilmis yerine fgets kullanmalisiniz. \n",satir);
        }
        
        }
        if(strcmp(argv[1],"-s")==0){
        satir=0;
        satir++;
        if(strstr(tampon,"strcpy (")!=NULL && strstr(tampon,"strcpy(")!=NULL)
        {
            printf("%d. satir:  kullanilmiş\n",satir);
        }
        else if(strstr(tampon,"strcpy (")!=NULL && strstr(tampon,"strcpy(")!=NULL)
        {
            printf("%d. satir: kullanilmis.  \n",satir);
        }
        else if(strstr(tampon,"strcat (")!=NULL && strstr(tampon,"strcat(")!=NULL)
        {
            printf("%d. satir:  kullanilmis\n",satir);
        }
         else if(strstr(tampon,"sprintf (")!=NULL && strstr(tampon,"sprintf(")!=NULL)
        {
            printf("%d. satir: kullanilmis  \n",satir);
        }

         else if(strstr(tampon,"fgets") == NULL && strstr(tampon,"gets(")!=NULL && strstr(tampon,"gets (")!=NULL)
        {
            printf("%d. satir: kullanilmis  \n",satir);
        }

         else if(strstr(tampon,"getpw(")!=NULL && (strstr(tampon,"getpwuid")==NULL) && strstr(tampon,"getpw (")!=NULL) 
        {
            printf("%d. satir:  kullanilmis  \n",satir);
        }
        
        }
      
    } 


    
    fclose(dosyaoku);


    return 0;
}