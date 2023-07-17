#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct news_list
{
    char news[1000];
};
struct news_list nl[100];
int global_count=0;

int longest_line()
{
    int m=0,index,i,count,j;
    for(i=0;i<global_count;i++)
    {
        count=0;
        j=0;
        while(nl[i].news[j]!='\0')
        {
            count++;
            j++;
        }
        if(count>m)
        {
            m=count;
            index=i;
        }
    }
    return index;
}

void load_from_file()
{
    FILE *fp;

    fp=fopen("News_list.txt","r");

    if(fp==NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while(!feof(fp))
    {
        //fscanf(fp,"%s",nl[global_count].news);
        fgets(nl[global_count].news,1000,fp);
        printf("%s",nl[global_count].news);
        global_count++;
    }
    fclose(fp);
}

int main()
{

    int M,i;
    load_from_file();

    M=longest_line();

    printf("\n\nThe Longest Line is :\n%s\n\n",nl[M].news);

return 0;
}

