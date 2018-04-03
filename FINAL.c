#include<stdio.h>
typedef struct date
{
    int day;
    char month[10];
    int year;
}d;
typedef struct rooms
{
int room;
char name[20];
char add[40];
long int tel;
d date1;
}r;
r no,temp[4];
int roomallot[20];
void check_in();
void check_out();
void info();
void delete(int ntallot1);
void re_name();
void arrange();
void print_info(r temp1);
void room_vacant();
void get_again();
void assign_zero();
int i,j;
int c;
void main()
{
printf("                                                        =============================\n");
printf("--------------------------------------------------------WELCOME TO HOTEL TRANSYLVANIA--------------------------------------------------------\n");
printf("                                                        =============================\n");
int check;
assign_zero();
get_again();
room_vacant();
printf("Select one option:\n 1.Check IN\n 2.Check OUT\n 3.Get Info.\n");
scanf("%d",&check);
switch(check)
{
case 1: check_in();
             break;
case 2: check_out();
             break;
case 3: info();
             break;
default: printf("Option INVALID");
              main();
}
}

void check_in()
{
FILE *fp7;
fp7=fopen("hotel.txt","r+");
int allot,flag=0;
printf("Enter the room no. to be alloted\n");
scanf("%d",&allot);
for(i=0;i<20;i++)
{
if(allot==roomallot[i])
{
flag=0;
break;
}
if(allot!=roomallot[i])
{
flag=1;
}
}
if(flag==1)
{
printf("Room Vacant\n");
printf("Enter Customer Name.\n");
scanf("%s",no.name);
printf("Enter Contact No.\n");
scanf("%ld",&no.tel);
printf("Enter Address\n");
scanf("%s",no.add);
printf("Enter Day in Nos.\n");
scanf("%d",&no.date1.day);
printf("Enter Month\n");
scanf("%s",no.date1.month);
printf("Enter Year\n");
scanf("%d",&no.date1.year);
no.room=allot;
fseek(fp7,(20-c)*(sizeof(no)),0);
fwrite(&no,sizeof(no),1,fp7);
printf("ROOM ALLOTED\n THANK YOU!\n");
}
if(flag==0)
{
printf("Room Not Vacant\n Try Another Room\n");
}
fclose(fp7);
main();
}
void check_out()
{
int ntallot,flag1=0;
printf("Enter Room No.");
scanf("%d",&ntallot);
for(i=0;i<20;i++)
{
if(ntallot==roomallot[i])
{
flag1=1;
break;
}
if(ntallot!=roomallot[i])
{
flag1=0;
}
}
if(flag1==0)
{
printf("Room is Vacant \n No Info Found\n");
}
if(flag1==1)
{
delete(ntallot);
printf("Check Out Successful\n");
}
main();
}

void delete(int ntallot)
{
FILE *fp1,*fp2;
fp1=fopen("hotel.txt","r");
fp2=fopen("htemp.txt","w");
if(fp1==NULL)
{
    printf("Error Opening File\n");
    fclose(fp1);
    fclose(fp2);
}
else
{
while(feof(fp1))
{
fread(&temp[0],sizeof(no),1,fp1);
if(temp[0].room!=ntallot)
fwrite(&temp[0],sizeof(no),1,fp2);
if(temp[0].room==ntallot)
   print_info(temp[0]);
}

}
fclose(fp1);
fclose(fp2);
re_name();
}
void re_name()
{
FILE *fp3,*fp4;
fp3=fopen("hotel.txt","w");
fp4=fopen("htemp.txt","r");
while(feof(fp4))
{
fread(&temp[1],sizeof(no),1,fp4);
fwrite(&temp[1],sizeof(no),1,fp3);
}
fclose(fp4);
fclose(fp3);
}


void info()
{
FILE *fp5;
fp5=fopen("hotel.txt","r");
int infono,flag2=0;
printf("Enter Room No.");
scanf("%d",&infono);
fread(&temp[2],sizeof(no),1,fp5);
do
{
    if(infono==temp[2].room)
    {
     flag2=1;
     break;
    }
    if(infono!=temp[2].room)
    {
     flag2=0;
    }
}while(fread(&temp[2],sizeof(no),1,fp5));
if(flag2==1)
{
    print_info(temp[2]);
}
if(flag2==0)
{
printf("INFO NOT FOUND\nSelected Room is Vacant\n");
}
fclose(fp5);
main();
}



void print_info(r temp1)
{
printf("Name-%s\n",temp1.name);
printf("Address-%s\n",temp1.add);
printf("Contact No.-%ld\n",temp1.tel);
printf("Check-In Date: %d-%s-%d\n",temp1.date1.day,temp1.date1.month,temp1.date1.year);
}

void get_again()
{
    FILE *fp;
    fp=fopen("hotel.txt","r");
    if(fp==NULL)
     {
	    printf("Error Opening File");
	    exit(0);
     }
   else
     {
       while(fread(&temp[3],sizeof(no),1,fp))
        {
            roomallot[(temp[3].room)-1]=temp[3].room;
        }
    fclose(fp);
     }

}
void room_vacant()
 {
     c=0;
    printf("ROOMS VACANT:\n");
    for(i=0;i<20;i++)
    {
        if(roomallot[i]=='\0')
         {
           printf("\tRoom No.%d\n",i+1);
           c++;
         }
    }
    printf("Total no. of Rooms= 20\n");
    printf("No. of Rooms Vacant= %d\n",c);
 }

 void assign_zero()
{
    int k=0;

    for(k=0;k<20;k++)
    {
        roomallot[k]='\0';
    }

}
