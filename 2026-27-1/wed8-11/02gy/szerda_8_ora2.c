#include <stdio.h>

int main_1(){
    int x = 5;
    int y = 4;
    float z = (float)(x+y)/2;
    // int osztás 0 felé kerekít
    // 7 / 4 -> 1
    printf("x=%d y=%d z=%f\n", x, y,z);
    // % az osztási maradék
    // < > != ==
    // NE 1 < x < 10
    // és && vagy ||
    if (/*feltétel*/ x % 2 == 0) {
        //törzs
        printf("x paros\n");
    } else {
        printf("x paratlan\n");
    }
    //beolvasás
    scanf("%d", &x);
    return 0;
}

int main_2(){
    int a,b,c;
    printf("Add meg az 1. oldalt:");
    scanf("%d",&a);
    printf("2. oldal:");
    scanf("%d",&b);
    printf("3. oldal:");
    scanf("%d",&c);
    if (a < b + c && b < a + c && c < b + a){
        printf("haromszog\n");
        if (a * a + b * b == c * c || b*b+c*c==a*a ||
              a*a+c*c == b*b  ){
           printf("derekszogu\n");
        }
    }else{
        printf("nem haromszog\n");
    }
    return 0;
}

int main_3(){
    int x = 0;
    int db = 0;
    printf("Add meg a paratlan szamot:");
    /*while (x % 2 == 0){
       scanf("%d", &x);
       db++; //++db; db+=1;
    }*/
    for (db = 0; x % 2 == 0; db++) {
       scanf("%d", &x);
    }
    printf("%d tenyleg paratlan\n%d. probalkozasra siker", x, db);
}

int main(){
    /*float a = 0.14, b=0.15, c=0.29, d;
    if (a+b==c){
        printf("==\n");
    }else{
        printf("!=\n");
    }
    printf("%.10f %.10f",a+b,c);
*//*
    int N,ossz=0,be;
    printf("Hány számot átlagoljunk?");
    scanf("%d",&N);
    for (int i=0; i<N; i++){
        printf("Add meg a %d. számot:",i + 1);
        scanf("%d",&be);
        ossz+=be;
    }
    printf("Az átlag: %f\n", (float)ossz/N);
*/
    int x=7;
    int y=sizeof(x);
    x= 2147483647;
    printf("%d\n",y);
    x+=1;
// float -> double
// int -> long -> long long
    double d=3.14;
    signed long long int ll=77;
    printf("d = %lf\n", d);
    printf("ll= %lld",ll);
    printf("x=%d\n",x);
    int j=1;
    for (int i=1; i<8*sizeof(j); i++){
        j*=2;
        printf("j=%d\n",j-1);
    }
    char c='5';
    int cx=c;
    printf("cx=%d\n",cx);
}
