#include <stdio.h>
#include <string.h>
struct eng
{
  int roll;
  char name[20];
  char div;
  char add[50];
};
void accept(struct eng k[20],int n)
{
  printf("Enter details as Roll,Name,Div,Address\n");
   for(int i=0;i<n;i++)
   {
     scanf("%d %s %c %s",&k[i].roll,k[i].name,&k[i].div,k[i].add);
   }
}
void writetofile(struct eng k[20],int n)
{
  FILE *fp;
  fp=fopen("eng.txt","a");
  
  for(int i=0;i<n;i++)
  {
  if(fp==NULL)
  printf("error");
  else
  {
    fprintf(fp,"%d %s %c %s\n",k[i].roll,k[i].name,k[i].div,k[i].add);
  }
  }fclose(fp);
}
void display(int n)
{
  struct eng s[20];
    FILE *fp;
    
    fp=fopen("eng.txt","r");
    if(fp==NULL)
       printf("\nError");
    else{
      
      
       for(int i=0;i<n;i++)
            {  
      fscanf(fp,"%d %s %c %s",&s[i].roll,s[i].name,&s[i].div,s[i].add);
 printf("\nDetails of student %d are \n roll no:%d\n name:%s\n division: %c \n address:%s\n",i+1,s[i].roll,s[i].name,s[i].div,s[i].add);
            }
    fclose(fp);
}
}
void delete_data()
{
    FILE *dataread = fopen("eng.txt", "r");
    int count = 0;
    char c = getc(dataread);
    struct eng s[20];
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = getc(dataread);
    }
    rewind(dataread);
    int id;
    printf("Enter the Roll No. which is to be deleted : ");
    scanf("%d", &id);
    int i = 0;
    for (; i < count; i++)
    {
        fscanf(dataread,"%d %s %c %s",&s[i].roll,s[i].name,&s[i].div,s[i].add);
    }
    FILE *del = fopen("eng.txt", "w");
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == id)
            continue;
        fprintf(del,"%d %s %c %s\n",s[i].roll,s[i].name,s[i].div,s[i].add);
        fputc('\n', del);
    }
    fclose(dataread);
    fclose(del);
}
void sandd(int r,int n){
  FILE *fp;
  int flag;
  struct eng t[20];
   fp=fopen("eng.txt","r");
           if(fp==NULL)
       printf("\nError");
    else{
       for(int i=0;i<n;i++)
            {  
      fscanf(fp,"%d %s %c %s",&t[i].roll,t[i].name,&t[i].div,t[i].add);
      if(t[i].roll==r){
        flag=1;
        printf("\nDetails of student are \n roll no:%d\n name:%s\n division: %c \n address:%s",t[i].roll,t[i].name,t[i].div,t[i].add);
        break;
        printf("record deleted successfully");
      }
    }
    if(flag !=1){
      printf("given roll no does not exists\n");
    } 
    }
}
int main(void) {
  struct eng k[20];
  int n,ch;
  int rn;

  printf("\nEnter the no. of engineering students");
  scanf("%d",&n);
  
  while(ch!=6){
    t:
      printf("\nEnter the No. to choose respective operation \n1.Accept the details\n2.Write in file\n3.read and display data from file\n4.delete a record\n5.search and display\n6.exit\n");
      scanf("%d",&ch);
      switch(ch){
        case 1:
          accept(k,n);
          break;
        case 2:
          writetofile(k,n);
          break;
        case 3:
          display(n);
        break;
        case 4:
            delete_data();
        break;
        case 5:
        
        printf("\nenter the roll no you want to search for\n");
        scanf("%d",&rn);
        sandd(rn,n);
        break;
        

  
      }
  }
  return 0;
}