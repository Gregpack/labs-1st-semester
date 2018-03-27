#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long int powint (int a, int b)
{
    long long int c=1;
    if (b==0)
    {
        return 1;
    }
    for (b; b>0; b--)
    {
        c=c*a;
    }
    return c;
}
long long int inttoten (int b1, int sizenmb, char *b)
{
    long long int elem = 0;
    long long int unit = 0;
    int sizenmb1=sizenmb-1;
    int i=0;
    for (i; i<sizenmb; i++)
    {
        if (b[i]== '.')
        {
            break;
        }
        if (b[i]- '0'<=9 && b[i]-'0'>=0)
        {
            elem = b[i] - '0';
        }
        else {
            if (b[i] - 'a' >= 0 && b[i] - 'a' <= 5) {
                elem = b[i] - 'a' + 10;
            } else {
                elem = b[i] - 'A' + 10;
            }
        }
        unit = unit + elem * powint(b1, sizenmb1);
        sizenmb1--;
    }
   return unit;
}
double fractoten (int b1, int i, int sizenmb, char *b)
{
    double elem = 0;
    double frac = 0;
    int sizenmb1=-1;
    for (i; i<sizenmb; i++)
    {
        if (b[i]== '.')
        {
            break;
        }
        if (b[i]- '0'<=9 && b[i]-'0'>=0)
        {
            elem = b[i] - '0';
        }
        else
        {
            if (b[i] - 'a' >= 0 && b[i] - 'a' <= 5)
            {
                elem = b[i] - 'a' + 10;
            }
            else
            {
                elem = b[i] - 'A' + 10;
            }
        }
            frac = frac + elem * pow(b1, sizenmb1);
            sizenmb1--;
    }
    return frac;
}
int tentoany(char *arr1, char *arr2, int b2, long long int unit, double fracture)
{
    int deg=0;
    long long int elem=1;
    long long int temp=unit/elem;
    do
    {
        elem=elem*b2;
        deg++;
        temp=unit/elem;
    } while (temp!=0);
    elem=elem/b2;
    deg--;
    int i=0;
    int degtemp=deg;
    for (deg; deg>=0; deg--)
    {
        temp = unit / elem;
        if (temp<=9 && temp>=0)
        {
            arr1[i] = (char)(temp+48);
        }
        else
        {
            arr1[i]=(char)(temp+55);
        }
        unit = unit - elem * temp;
        elem=elem/b2;
        i++;
    }
    arr1[i]='\0';
    int an1;
    for (i=0; i<12; i++)
    {
        deg=fracture*powint (10, 12);
        if (deg==0)
        {
            if (i==0)
            {
                an1=1;
            }
            break;
        }
        fracture=fracture*b2;
        if (fracture<1)
        {
            arr2[i]=char(48);
        }
        else
        {
            temp=fracture/1;
            if (temp<10)
            {
                arr2[i]=(char)(temp+48);
            }else
            {
                arr2[i]=(char)(temp+55);
            }
            fracture=fracture-temp;
        }


    }
    arr2[i]='\0';
    return an1;
}
int main(int argc, char *argv[])
{
    int i;
    long long int b1, b2;
    char arr1[100], b[20];
    char arr2[14];
    long long int pointnmb=0, sizenmb=0, unit=0, another;
    double fracture=0;
    /*for (i=0; i<100; i++)
    {
        arr1[i]=-1;
    }
    for (i=0; i<13; i++)
    {
        arr2[i]=-1;
    }*/
    if (argc > 1)
       {
         b1=atoi(argv[1]);
         b2=atoi(argv[2]);
         for (i=0; i<20; i++)
          {
           if ((argv[3][i]-'0' >=0 && argv[3][i]-'9'<=0) || (argv[3][i]-'A' >=0 && argv[3][i]-'F'<=0) || (argv[3][i]-'a' >=0 && argv[3][i]-'f'<=0) || (argv[3][i]=='.'))
               b[i]=argv[3][i];
              else
           {
               b[i] = '\0';
               break;
           }
          }
        }
    else
        {
          scanf("%lld%lld", &b1, &b2);
          scanf("%s", b);
        }
    if (b1>16 || b2>16 || b1<2 || b2<2)
    {
        printf("bad input");
        return 0;
    }
    i=-1;
    while (true)
    {
        i++;
        if (b[i] == '\0')
            break;
        if (b[i]-'0'<0 || b[i]-'f'>0)
        {
            if (b[i]-'.'!=0 )
            {
                printf("bad input");
                return 0;
            }
        }
        if (b[i]-'0'>=b1 && b[i]-'0'<=9 && b[i]-'0'>=0)
        {
            printf("bad input");
            return 0;
        }
        if (b[i]-'A'<=5 && b[i]-'A'>=0 && b[i]-'6'>b1)
        {
                printf("bad input");
                return 0;
        }
        if (b[i]-'a'<=5 && b[i]-'a'>=0 && b[i]-'V'>b1) {
            printf("bad input");
            return 0;
        }
        if (b[i] == '.')
        {
            if (b[i+1]== '\0' || i==0 || pointnmb!=0)
            {
                printf("bad input");
                return 0;
            }
            pointnmb = i;
        }
    }
    if (pointnmb==0)
    {
        pointnmb=i;
        another=pointnmb;
    }
    sizenmb=i;
    unit=inttoten (b1, pointnmb, b);
    fracture=fractoten (b1, pointnmb+1, sizenmb, b);
    printf("1)%x ", unit);
    printf("2)%f\n", fracture);
    int an1;
    an1=tentoany (arr1, arr2, b2, unit, fracture);
    i=0;
    /* while ((arr1[i]<=9 && arr1[i]>=0) || (arr1[i] - 'F' >= 0 && arr1[i] - 'F' <= 5 )|| (arr1[i] - 'a' >= 0 && arr1[i] - 'a' <= 5))
     {
         if (arr1[i]<=9 && arr1[i]>=0)
             printf("%d", arr1[i]);
         else
             printf("%c", arr1[i]);
         i++;
     }*/

    printf("%s", arr1);
    if (pointnmb!=another && an1!=1)
        printf(".");
    printf("%s", arr2);
    /*for (i=0; i<12; i++)
    {
        if (arr2[i]!=-1)
        {
            if (arr2[i]<=9 && arr2[i]>=0)
                printf ("%d", arr2[i]);
            else
                printf ("%c", arr2[i]);
        }
        else
            break;
    }
     */
    return 0;
}