#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<math.h>

struct agenda
{
   int week;
   int   day;
   int   month;
   int   year;
	char event[100];
	char tag[20];
};

void listeleme_day() //13.01.2016  List all events of a specific day, and show the total number of events.
   {                                                            
   	int fm(int date, int month, int year) {                         //citation 
   int fmonth, leap;                                                //Seventh row between fortieth row is an excerpt from
                                                                    //http://www.codingunit.com/how-to-make-a-calendar-in-c
   //leap function 1 for leap & 0 for non-leap                  
   if ((year % 100 == 0) && (year % 400 != 0))
      leap = 0;
   else if (year % 4 == 0)
      leap = 1;
   else
      leap = 0;
 
   fmonth = 3 + (2 - leap) * ((month + 2) / (2 * month))
         + (5 * month + month / 9) / 2;
 
   //bring it in range of 0 to 6
   fmonth = fmonth % 7;
 
   return fmonth;
}
 
//----------------------------------------------
int day_of_week(int date, int month, int year) {
 
   int dayOfWeek;
   int YY = year % 100;
   int century = year / 100;
 
   printf("\nDate: %d/%d/%d \n", date, month, year);
 
   dayOfWeek = 1.25 * YY + fm(date, month, year) + date - 2 * (century % 4);    
 
   //remainder on division by 7
   dayOfWeek = dayOfWeek % 7;
 
   switch (dayOfWeek) {
      case 0:
         printf("weekday = Saturday");
         break;
      case 1:
         printf("weekday = Sunday");
         break;
      case 2:
         printf("weekday = Monday");
         break;
      case 3:
         printf("weekday = Tuesday");
         break;
      case 4:
         printf("weekday = Wednesday");
         break;
      case 5:
         printf("weekday = Thursday");
         break;
      case 6:
         printf("weekday = Friday");
         break;
      default:
         printf("Incorrect data");
   }
   return 0;
}
   	int date, month, year;
    
   printf("\nYou selected list all events of a specific day, and show the total number of events.\n");  //Reminder have made.
   
   printf("\nPlease enter the day: ");       //were asked to day,month and year from user.
   scanf("%d", &date);
   
   printf("\nPlease enter the month: ");
   scanf("%d", &month);
   
   printf("\nPlease enter the year: ");
   scanf("%d", &year);
 
   day_of_week(date, month, year);
 
    
    char hafta[5];
    char event[100];                   //identifications was performed.
	int date2,month2,year2,week2;
	struct agenda b[50];
	int i=0;
	
	    FILE *dosya;                                        
		if((dosya= fopen("Agenda.txt","r"))!=NULL)         //The location of the file which file to be opened was shown.It will be read.
		{
			printf("\n\n Events:\n\n");
		
	while(!feof(dosya))                                    //It demonstrates how to read and what to read.
	{
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[50].tag);    
		
		if(date==date2 && month==month2 && year==year2)          //if the same date that the user enters in the file, print the screen.
		{
			
			i++;
			if(i>0)                                               
			{
			printf("%d/%d/%d %s #%s\n",date2,month2,year2,event,b[50].tag);
		    }
		}
		
	}
	    }
	    
	if(i!=0)                                                 //if it found, print total number of events. 
	printf("\nTotal number of events: %d\n\n",i);
	
	if(i==0)                                                   //if it didnt find, print no records found.
	{
		printf("\aNo Records Found.\n\n");
	}
	
	fclose(dosya);                    //File was closed.
	
    getch();
 
   
}

void listeleme_week()       //15.01.2016  List all events of a specific week, and show the total number of events.
{
	int week, year;                      //identifications was performed.
	struct agenda b[50];
	
	printf("\nYou selected list all events of a specific week, and show the total number of events.\n");      //Reminder have made.
	
	printf("\nPlease enter the week: ");           //were asked to week and year from user.
	scanf("%d", &week);
	
	printf("\nPlease enter the year: ");
	scanf("%d", &year);
	
	 
	 
	  char hafta[5];                           //identifications was performed.
	  char event[100];
	  int date2,month2,year2,week2;
	  	int i=0;
	
	    FILE *dosya;
		dosya= fopen("Agenda.txt","r");                 //it will read.
		
		printf("\n\n Events:\n\n");
		
		while(!feof(dosya))                          //It demonstrates how to read and what to read.
	{	
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[50].tag);             
		if(week== week2 && year==year2)              //if the same date that the user enters in the file, print the screen.
		{
			i++;
			if(i>0)
			{
			printf("%d . %s %d/%d/%d #%s\n",week2,hafta,date2,month2,year2,event,b[50].tag);
		    }
		}
	}
	
	if(i!=0)                                          //if it found, print total number of events.
	printf("\nTotal number of events: %d\n\n",i);
	
	if(i==0)                                         //if it didnt find, print no records found.
	{
		printf("\aNo Records Found.\n\n");              
	}
	
	fclose(dosya);                                  //File was closed.
	
    getch();
    
    
}

void listeleme_month()   //14.01.2016  List all events of a specific month, and show the total number of events.
   {
   	int month, year;                      //identifications was performed.
    struct agenda b[50];
    
   printf("\nYou selected list all events of a specific month, and show the total number of events.\n");      //Reminder have made.
   
   printf("\nPlease enter the month: ");         //were asked to month and year from user.
   scanf("%d", &month);
   
   printf("\nPlease enter the year: ");
   scanf("%d", &year);
   
 
      char hafta[5];                          //identifications was performed.
      char event[100];
	int date2,month2,year2,week2;
	
	int i=0;
	
	    FILE *dosya;
		if((dosya= fopen("Agenda.txt","r"))!=NULL)                //it will read.
		{
			printf("\n\n Events:\n\n");
		
	while(!feof(dosya))                                    //It demonstrates how to read and what to read.
	{
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[50].tag);
		if(month==month2 && year==year2)                //if the same date that the user enters in the file, print the screen.
		{
			i++;
			if(i>0)
			{
			printf("%d/%d/%d %s #%s\n",date2,month2,year2,event,b[50].tag);
		    }
		}
		
		
	}
        }
        
    if(i!=0)                                              //if it found, print total number of events.
	printf("\nTotal number of events: %d\n\n",i);
        
	if(i==0)                                       //if it didnt find, print no records found.
	{
		printf("\aNo Records Found.\n\n");
	}
	
	fclose(dosya);                      //File was closed.
	
    getch();
 
   
}


void listeleme_year()    //14.01.2016  List all events of a specific year.
   {
   	int year;          //identifications was performed.
   	
   	printf("\nYou selected list all events of a specific year.\n");              //Reminder have made.
 
   printf("\nPlease enter the year: ");                 //were asked to year from user.
   scanf("%d", &year);
 
   
 
   
   
      char hafta[5];                          //identification was performed.
      char event[100];
      struct agenda b[50];
	int date2,month2,year2,week2;
	
	int i=0;
	
	    FILE *dosya;
		if((dosya= fopen("Agenda.txt","r"))!=NULL)            //it will read.
		{
			printf("\n\n Events:\n\n");
		
	while(!feof(dosya))                               //It demonstrates how to read and what to read.
	{
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[50].tag);
		if(year==year2)                           //if the same year that the user enters in the file, print the screen.
		{
			 i++;
			if(i>0)                                   
			{
			printf("%d/%d/%d %s #%s\n",date2,month2,year2,event,b[50].tag);
		    }
		}
		
	}
	
	if(i!=0)                                          //if it found, print total number of events.
	printf("\nTotal number of events: %d\n\n",i);
	
	if(i==0)                                       //if it didnt find, print no records found.
	{
		printf("\aNo Records Found.\n\n");
	}
    }
    
	fclose(dosya);                              //File was closed.
	
    getch();
 
   
}


void Create_Event(){
	
	FILE *fp1;                          //identifications was performed.
int size = 0;                   
   struct agenda b[50];

   fp1 = fopen("Agenda.txt","a+");            //It will add.
   
   if(fp1 == NULL)                            //If fýle is empty, print this
      printf("File could not be opened!\n");
   else
   {
       
    printf("\nPlease enter a week of  year:\n");           //else informations will be asked user.
	scanf("%d",&b[size].week);
	printf("\nPlease enter a day:\n");
	scanf("%d",&b[size].day);
	printf("Please enter a month:\n");
	scanf(" %d",&b[size].month);
	printf("Please enter a year:\n");
	scanf(" %d",&b[size].year);
	printf("Please enter a event:\n");
	scanf(" %s",&b[size].event);
	printf("Please enter a tag:\n");
	scanf(" %s",&b[size].tag);
	
	fprintf(fp1,"\n%d Hafta %d %d %d %s %s",b[size].week,b[size].day,b[size].month,b[size].year,b[size].event,b[size].tag);  //Added information is printed on the screen.
	size++; 

      
       
       fclose(fp1);

   }
	
}


void delete_event(){

FILE *dosya,*yeni; //dosya iþaretçileri tanýmlama

	int size=0;                         //identification was performed.
   	int SIZE=0;
    char tag2[50];
    struct agenda b[50];
    
   printf("\nYou selected list all events of a specific month, and show the total number of events.\n");      //Reminder have made.
   
   printf("\nPlease enter the tag: ");         //were asked to tag from user.
   scanf("%s", &tag2[SIZE]);
   
   
      char hafta[5];                          //identification was performed.
      char event[100];
	int date2,month2,year2,week2;
	int i=0;
	   
	dosya=fopen("Agenda.txt","r"); //bilgiler dosyadan okunacak.
    yeni=fopen("Agenda1.txt","w"); //yeni bilgiler bu dosyaya yazýlacak. FILE *dosya;
		
	while(!feof(dosya))                                    //It demonstrates how to read and what to read.
	{
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[size].tag);
		if(strcmp(tag2,b[size].tag)==0)                //if the same tag that the user enters in the file,it will skip this line
		{

            fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[size].tag);  // After it skip,it will start to read.

      }     

      fprintf(yeni,"\n%d %s %d %d %d %s %s",week2,hafta,date2,month2,year2,event,b[size].tag);       //Final state will be writen new file.

   }

fclose(dosya);                    //Files will be closed.
fclose(yeni);

remove("Agenda.txt");                   //File will be removed.
rename("Agenda1.txt","Agenda.txt");        //File will be renamed.

}


void search_tag()   //14.01.2016  
   {
   	int size=0;                     //identifications was performed.
   	int SIZE=0;
    char tag2[50];
    struct agenda b[50];
    
   printf("\nYou selected search for event/s  with a special tag.\n");      //Reminder have made.
   
   printf("\nPlease enter the tag: ");         //were asked tag from user.
   scanf("%s", &tag2[SIZE]);
   

      char hafta[5];                          //identifications was performed.
      char event[100];
	int date2,month2,year2,week2;
	int i=0;
	
	    FILE *dosya;                                         //The location of the file which file to be opened was shown.
		if((dosya= fopen("Agenda.txt","r"))!=NULL)
		{
		
	while(!feof(dosya))                                    //It demonstrates how to read and what to read.
	{
		fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[size].tag);
		if(strcmp(tag2,b[size].tag)==0)                //if the same tag that the user enters in the file, print the screen.
		{
			printf("\n\n\n Yapilmasi gereken:\n");
			i++;
			if(i>0)
			{
			printf("%d/%d/%d %s #%s\n",date2,month2,year2,event,b[size].tag);
		    }
		}
		
		
	}
        }
	if(i==0)                                       //if it didnt find, print no records found.
	{
		printf("\a\nNo Records Found.");
	}
	
	fclose(dosya);                      //File was closed.
	
    getch();
 
   
}

void back_up()
{

FILE *dosya,*yeni; // defination of pointers of files

	int size=0;
   	int SIZE=0;
   	int date, month, year;
    char tag2[50];
    struct agenda b[50];
    
   	printf("\nYou selected list all events of a specific month, and show the total number of events.\n"); //Reminder have made.
   
    char hafta[5];  //identification was performed.
    char event[100];
	int date2,month2,year2,week2;
	int i=0;
	   
	dosya=fopen("Agenda.txt","r"); // Informations will be read in that file
    yeni=fopen("Agenda_backup.txt","w"); //Informations will be copied in that file.
		
	while(!feof(dosya)) //It demonstrates how to read and what to read.
	{
	fscanf(dosya,"%d %s %d %d %d %s %s",&week2,hafta,&date2,&month2,&year2,event,b[size].tag); // It reads all events in Agenda.txt
    fprintf(yeni,"%d %s %d %d %d %s %s\n",week2,hafta,date2,month2,year2,event,b[size].tag); // It writes all events that reads int Agenda.txt to Agenda_backup.txt
   	} // end while

	fclose(dosya); // file was closed
	fclose(yeni); // file was closed

}


void printMenu(int choice) {
	
	int c;
	
	printf("\n**********WELCOME YOUR PERSONAL AGENDA**********\n");
	
	LOOP1:printf("Menu:\n1-)List all events of a specific day, and show the total number of events.\n2-)List all events of a specific week, and show the total number of events.\n3-)List all events of a specific month, and show the total number of events.\n4-)List all events of a specific year.\n5-)Create a record for a new event.\n6-)Update a record of a specific event.\n7-)Delete a record of a specific event.\n8-)Search for event/s with a special tag.\n9-)Backup all events into a flat file.\n10-)Exit.\n");
	
		printf("\nPlease enter your choice from menu:");
		scanf("%d", &choice);
		
	    /* After useer's choice, prpgram will ask that 'Do you want to countinue?'
		If user wants continue, he/she must press 1. Otherwise press 2.
		We used for that goto function. LOOP1 is in fornt of menu's printf function because, if user wants continue, he/she must see menu again.	
		LOOP2 is in front of case10 because, we can exit this program like that.
		*/
		
		
		switch (choice) {
			
			case 1: 
			listeleme_day();// this choice shows all events in entered specific day
				
				printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
						
				break;
			
			case 2: 
			listeleme_week();// this choice shows all events in entered specific week
			
				printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 3: 
			listeleme_month();// this choice shows all events in entered specific month
			
				printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 4: 
			listeleme_year();// this case shows all events in entered specific year
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 5: 
			Create_Event();// this case creates new event in entered date
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 6: // this case updates events in entered event
			delete_event();
			Create_Event();
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 7: // this case deletes events in entered event
			delete_event();
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
					
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 8: 
			search_tag();  // this case searches events with entered specific tag
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
				
				break;
				
			case 9: 
			back_up();// this case backup all event file
			
			printf("Do you want to continue?(1=yes, 2=no):");
				scanf("%d", &c);
				if (c == 1) {
					goto LOOP1;
				}
					if (c == 2) {
						
						goto LOOP2;
					}
		
			break;
				
			LOOP2:case 10: // this case load all event file
			
				printf("BYE BYE\n");
				break;
				
			default:
				
				printf("Please enter a valid choice.\n");
				break;
				
			} // end switch
	
} // end funtion of printMenu



//------------------------------------------
int main() {
	
	printf("********************PERSONAL AGENDA********************\n");
	printf("You have 3 entrence right.\n");
	
	char password[6];
	int counter = 0;
	
	do {
		
		printf("\nPlease enter password:");
		scanf("%s", &password);
		
		if(strcmp(password, "123456") == 0) {
			printf("\nCorrect password\n");
			printMenu(counter);
			break;		
		} // end if
		
		else {
			printf("Wrong password.\n");
			counter++; // if your password is wrong, counter will increase 1
		} // end else
		
		if (counter == 3) {
			printf("Your entrence right is over.\n");
		} // end if
			
	} while(counter != 3); // if counter is equal to 3, your enterence right finish.
	
} // end main
