#include <stdio.h>

int main_2(){
/*
    int x=7,y=9,q=3;
    printf("%d=x %d=y\n",x,y);
    double z= (double)(x+y)/q;
    printf("atlag: %lf\n",z);
    double a=0.1, b=0.2, c=0.3;
    if (a+b==c) {
       printf("==\n");
    }else{
       printf("!=\n");
    }
    // && : és || : vagy
    scanf("%d",&x);
    printf("%.20lf %.20lf",c, a+b);*/
    int a,b,c;
    printf("add meg a 3 oldalt:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if (a + b > c && b + c > a && a+c > b){
        printf("haromszog\n");
        if (a*a + b*b == c*c || b*b+c*c == a*a 
              || a*a+c*c==b*b) {
            printf("Ez derék\n");
        }
    }else{
        printf("nem haromszog\n");
    }
    return 0;
}

int main_3(){
    int x=0, db;
    //scanf("%d",&x);
    /*if (x % 2 == 0){//% osztási maradék
       printf("\"paros\"\n");
    }else{
       printf("paratlan\n");
    }*/
    db=0;
    while (x % 2 ==0){
       db+=1;
       printf("Add meg %d edjére",db);
       scanf("%d",&x);
    }
    printf("Az %d tényleg páratlan\n", x);
    printf("Az %d. próbálkozásra sikerült\n",db);
    for (int i=1; i<= 10; i++) {
        printf("%d\n",i);
    }
    return 0;
}
int main_4(){
    printf("Hány számot átlagoljunk?");
    int N, be;
    double ossz = 0;
    scanf("%d",&N);
    for (int i=0; i<N; i++){
        scanf("%d",&be);
        ossz+=be;
    }
    printf("A számok átlaga: %lf",ossz/N);
}
int main(){
/*
    int x;
    x=sizeof(x);
    printf("%d\n",x);
    x=2147483647;
    printf("%d\n",x);
    x+=1;
    printf("%d\n",x);
    int i=0,y=1;
    while (i<8*sizeof(int)-1){
        y=2*y;
        i++;
    }
    printf("%d\n",y-1);*/
    int x;
    scanf("%d",&x);
    int ossz=0;
    while (x>0) {
         ossz+=x % 10;
         x/=10;
    }
    printf("%d\n", ossz);
}
