#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

typedef struct node    //Structure for storing the Prime Numbers.
    {
     int num;
     struct node *next;
    }s;

void insert(s **,s **,int);
void display(s *);
void line(char *);
void prime(int, int);
void sqprime(int);
s *r=NULL;
s *f=NULL;
int n1, n2, cn=0, cc=0;

void main()    //Main Function: File is read and all the other functions are called.
{
   FILE *fp;
   char p[100], str[80], ch;
   int i=0, n, fl=1;
   printf("Enter path of file: ");
   F:
       gets(p);
       fp=fopen(p,"r+");
       if(fp==NULL)
        {
          printf("\nFile not found.");
          printf("\n\nERROR:Wrong path entered.\n\nHELP:\nSyntax- DRIVE:\\Directory\\Filename.extention");
          printf("\nPlease enter correct path: ");
          goto F;
        }
   else
      {
          while(!feof(fp))
            {
              ch=fgetc(fp);
              if(ch!=' ' && ch!='.' && ch!=',' && ch!=';' && ch!=':' && ch!='?' && ch!='"' && ch!='/' && ch!='\\' && ch!='-' && ch!='\n' && ch!='(' && ch!=')')
             {
              str[i]=ch;
              i++;
             }
            else
             {
              str[i]='\0';
              n=atoi(str);
              break;
             }
            }
          fclose(fp);
          printf("\nOutput:\n\n");
          fp=fopen(p,"r+");
          while(!feof(fp))
            {
             fscanf(fp,"%s",str);
             if(fl>1 && fl<=(n+1))
             {
              line(str);
              if(cn==2 && n1!=0 && n2!= 0)
               {
                prime(n1,n2);
                display(f);
                cc=0;
                cn=0;
                r=NULL;
                f=NULL;
               }
              else
               {
                printf("NIL");
                cn=0;
               }
              printf("\n");
             }
             fl++;
            }
          fclose(fp);
      }
   getch();
}

void line(char *str)    //Function for separating the numbers.
{
 char tmp[20];
 int i, j=0;
 for(i=0;str[i]!='\0';i++)
    {
     if(str[i]!=' ' && str[i]!='.' && str[i]!=',' && str[i]!=';' && str[i]!=':' && str[i]!='?' && str[i]!='"' && str[i]!='/' && str[i]!='\\' && str[i]!='-' && str[i]!='(' && str[i]!=')' && str[i]!='\n')
      {
       tmp[j]=str[i];
       j++;
      }
     else
      {
       tmp[j]='\0';
       n1=atoi(tmp);
       j=0;
       cn++;
      }
    }
 tmp[j]='\0';
 n2=atoi(tmp);
 cn++;
}

void prime(int x, int y)     //Function for checking prime number for sum of individual digits.
{
 int i, j, sum, r, tmp, flag;
 if(x<y)
 {
  for(i=x;i<=y;i++)
   {
    tmp=i;
    sum=0;
    if(i!=1)
     {
      while(tmp!=0)
       {
        r=tmp%10;
        sum=sum+r;
        tmp=tmp/10;
       }
      flag=0;
      if(sum!=1)
       {
        for(j=2;j<=sum/2;++j)
          {
           if(sum%j==0)
            {
             flag=1;
             break;
            }
          }
        if(flag==0)
          {
           sqprime(i);
          }
       }
     }
   }
 }
 else
 {
  for(i=y;i<=x;i++)
   {
    tmp=i;
    sum=0;
    if(i!=1)
     {
      while(tmp!=0)
       {
        r=tmp%10;
        sum=sum+r;
        tmp=tmp/10;
       }
      flag=0;
      if(sum!=1)
       {
        for(j=2;j<=sum/2;++j)
          {
           if(sum%j==0)
            {
             flag=1;
             break;
            }
          }
        if(flag==0)
          {
           sqprime(i);
          }
       }
     }
   }
 }
}

void sqprime(int i)       //Function for checking prime number for sum of square of individual digits.
{
 int j, sum, t, tmp, flag=0;
 tmp=i;
 sum=0;
 while(tmp!=0)
  {
   t=tmp%10;
   sum=sum+(t*t);
   tmp=tmp/10;
  }
 for(j=2;j<=sum/2;++j)
  {
   if(sum%j==0)
    {
     flag=1;
     break;
    }
  }
 if(flag==0)
  {
   insert(&f,&r,i);
  }
}

void insert(s **f, s **r, int n)   //Function for inserting the output numbers.
{
 s *q=NULL;
 q=((s*)malloc(sizeof(s)));
 q->num=n;
 q->next=NULL;
 if((*r)==NULL)
  {
   *r=q;
   *f=q;
  }
 else
  {
   (*r)->next=q;
   (*r)=q;
   (*r)->next=NULL;
  }
 cc++;
}

void display(s *f)    //Function for displaying the output.
{
 if(f==NULL)
   {
    printf("NIL");
   }
 else
   {
    while(f!=NULL)
        {
         printf("%d",f->num);
         f=f->next;
         cc--;
         if(cc!=0)
          {
           printf(",");
          }
        }
   }
}
