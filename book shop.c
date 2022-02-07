#include<stdio.h>
#include<conio.h>

char date[20];
char uname[20];
char bname[20];
char mno[15];
long int cost;
int n,i;

//function for writing entry of book file

void write()
{
    FILE *fp;
    char dat[20];
    char unam[20];
    char bnam[20];
    char mn[15];
    long int cos;

    printf("\nEnter Date              ::");
    scanf("%s",&dat);
    printf("Enter Name of Customer  ::");
    scanf("%s",&unam);
    printf("Enter MObile Number     ::");
    scanf("%s",&mn);
    printf("Enter of Book Name      ::");
    scanf("%s",&bnam);
    printf("Enter Cost of Book      ::");
    scanf("%ld",&cos);

    fp=fopen("Record File.txt","a");
    fprintf(fp,"\n%s %s %s %s %ld\n",dat,unam,mn,bnam,cos);
    printf("\n       Record written successfully!!!");
    fclose(fp);
}

//function to search record by date

void display(char da[])
{
    FILE *fp;
    int res;

    fp=fopen("Record File.txt","r");

    while(fscanf(fp,"%s %s %s %s %ld\n",date,uname,mno,bname,&cost)!=EOF)
    {
        res=strcmp(date,da);
        if(res==0)
    {
    printf("\n   Customer name = %s",uname);
    printf("\n   Mobile No     = %s",mno);
    printf("\n   Book Name     = %s",bname);
    printf("\n   Book Cost     = %ld",cost);
    }
    }
    //close of while loop
    fclose(fp);
}
//close of display function

void main()
{
    char ch;
    char lm[20];
    //textcolor(10);
    //textbackground(4);
    do
    {
        //clrscr();

        printf("\n\n*****Welcome To The Our BookShop*****\n");
        printf("\nPress<1> to Create Entry For Book");
        printf("\nPress<2> to Sch On Specific Date");
        printf("\nPress<0> to exit");

        printf("\n\nEnter Choice ::");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:write();
            break;

            case 2:printf("\nEnter Date ::");
                scanf("%s",&lm);
                display(lm);
                break;

            case 3:exit(0);

            default:printf("\nInvalid Selection");
        }
        getch();
    }
    //close of do loop
    while(ch!=0);
}
//close of main
