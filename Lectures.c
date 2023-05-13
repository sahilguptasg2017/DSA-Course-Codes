//#include <stdio.h>
//#include <limits.h>
//int a=5;
/*#include <stdio.h>
//retrun type of fuctiion

int main(){
    //main fucntion
printf("Neso Acadmey");

//ending statement 

return 0;

}
#include <stdio.h>
int main(){

    int var1 =3;
    int var2=var1;
    printf("%d",var2);
    return 0;   
}
#include <stdio.h>
int main(){

int var1,var2,var3,var4;
var1=var2=var3=var4=4;
printf("%d",var1);
printf("%d",var2);
printf("%d",var3);
printf("%d",var4);

return 0;
}
#include <stdio.h>
int main(){
int var1=3;
int var2=4;
printf("%d %d",var1,var2);
return 0;
}
//use of placeholder
#include <stdio.h>
int main(){
int two=2, three=3, six=6;
int result=(two*three)/six;
printf("arithmetic expression is like:(%d+%d)/%d",two,three,six);
printf("and the result is: %d" ,result);
}
#include <stdio.h>
int main(){
    printf("%d",sizeof(int));
    return 0;
}
#include <stdio.h>
int main(){
    printf("%d",sizeof(long int));
    return 0;
}
#include <stdio.h>
#include <limits.h>
int main(){
    int var1=INT_MAX;
    int var2=INT_MIN;
    printf("range of signed integer is from: %d to %d",var2,var1);
    return 0;


}
#include <stdio.h>
#include <limits.h>
int main(){
    int var1=0;
    int var2=UINT_MAX;
    printf("range of signed integer is from: %u to %u",var1,var2);
    return 0;

}
#include <stdio.h>
#include <limits.h>
int main(){
    int var1=SHRT_MAX;
    int var2=SHRT_MIN;
    printf("range of signed integer is from: %d to %d",var2,var1);
    return 0;

}
#include <stdio.h>
#include <limits.h>
int main(){
    short unsigned int var1=0;
    short unsigned int var2=USHRT_MAX;
    printf("range of signed integer is from: %d to %d",0,var2);
    return 0;

}
int main(){
 int var =-2147483649;
printf("%d",var);


}
int main(){



    char var=-127   ;
    printf("%c",var);
    return 0;



}
  int main(){
    float var1=3.141592;
    double var2=3.14592;
    long double var3=3.14592;

    printf("%d\n",sizeof(float));
    printf("%d\n",sizeof(double));
    printf("%d\n",sizeof(long double));
    printf("%.16f\n",var1);//float takes 8
    printf("%.16lf\n",var2);//l is for double, double takes 16
    printf("%.21Lf\n",var3);//L is for long double long double takes 19 digits as same
    int var=4/9;
    printf("%d\n",var);

    float t=4/9;
    printf("%.2f\n",t);

    float r=4.0/9.0;
    printf("%.2f\n",r);


  }

int main(){

//Q1-----printf("%d",printf("%s","Hello world!"));
//return 0;
//Q2-----printf("%s\n","Hello");
//printf("%10s","Hello");
//Q3---char c=255;
//c=c+10;
//printf("%d",c);
unsigned i=1;
int j=-4;
printf("%u",i+j);

return 0;  
  
  }
int main(){
int var=65;//local variable
printf("%d",var);
return 0;
}  
int fun(){

printf("%d",var);

}

//function inside a function, variable internal to a block:
int main(){

int var=3;
{//int var=4; // if variable not present internal, it will print outside one//
printf("%d\n",var);
}
printf("%d",var);

return 0;

}


int fun();


int var=10;//global variable
int main(){

    int var=3;
    printf("%d\n",var);
    fun();// function called the global function and took the global variable//
    return 0;
}
int fun()
{
    printf("%d",var);
}
int var;
int main(){

    //auto int var;
    printf("%d",var);
    //garbage value here and global variable assigned 0 
}

extern int a;// linker finds error once commented the variable out.
extern int a;
extern int a;// multiple declarations is allowed and multiple definitions is not allowed 
int main(){
    printf("%d",a);
    return 0; 


}

extern int a=9;
int main()
{


//    extern int a;
    printf("%d",a);
    return 0;



}
int main(){
    register int var;
    return 0;


}
int increment();
//extern int count; // cannot call static int , variable is global only within that file 
int main()
{
    int value;
    value=increment();
    value=increment();
    value=increment();
   // count=count+3;
    //value=count;
    printf("%d",value);

        
    return 0;


}

int increment()
{
    int var=3;
    static int count=var;//this variable is static in nature and doesnt destroy.(must always be a constant value)
    //int count =0 ;
    count=count+1;
    return count; 
}

//constants

#define PI 3.14159// give name capital...
int main(){

    printf("%.5f",PI);
    return 0;


}
#define vfalue 89
int main(){
    printf("value is %d",value);// value not replaced

    return 0;

}
#define add(x,y) x+y
int main(){

    printf("the addition of two numbers is:%d ",add(4,3));

}

# define greater(x,y) if(x>y)\
                        printf("%d is greater than %d",x,y );\
                      else\
                      printf("%d is lesser than %d",x,y);
int main()                         
{
    greater(5,6);
    return 0;

}
#define add(x,y) x+y
int main(){
    printf("the value of 5*(4+3) is : %d",5*add(4,3));// ans is 23
    return 0;

}
int main(){
    printf("DATE: %s\n",__DATE__);
    printf("TIME: %s\n",__TIME__);

}
int main()
{
    const int var=67;// constant value assigned cant be changed
    var=57;
    printf("%d",var);
}
int main(){

    int var=052;
    printf("%o",var);// print an octal value and here we are providing an octal value so same output...
    return 0;


}
int main()
{
    int a,b;
    printf("enter the first number: ");
    scanf("%d",&a);
    printf("enter the second number: ");
    scanf("%d",&b);
    printf("%d+%d=%d",a,b,a+b);
    return 0;

}
int main()
{
    int var=0x43FF;
    printf("%X",var);//%X gives capital f capital f
    return 0;


}
static int i;
static int i=27;
static int i;
int main()
{
static int i;
printf("%d",i);
return 0;
}
//#include <stdio.h>
int main(){
    int var;
    scanf("%d",&var);
    if(var%2==0&&var!=2&&var!=0)\
    printf("YES");\
    else\
    printf("NO");
    return 0;
}
static int i=24;// gets stored in bss//
int main()
{
    int var=433;
    printf("%d",var);
    return 0;
}
static int i;
static int i=27;
//i=45;// not allowed
int main()
{
    static int i;
     i=45;
    printf("%d",i);
    return 0;

}

//operators

int main()
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a / b=%d\n",a/b);
    printf("a %% b =%d",a%b);
    return 0;     



}


int main(){

    int a=2, b=3,c=4,d=5;
    printf("a*b/c = %d\n",a*b/c);//because of integer ans is 1
    printf("a+b-c = %d\n",a+b-c);
    printf("a+b*d-c%%a =%d",a+b*d-c%a);
    return 0;
}
//#include <stdio.h>
int main()
{
    int a=5;
    int x,y;
    x=a++;
    y=++a;
    printf("%d %d",x,y);

}
int main()
{
    int a=4, b=3;
    printf("%d",a+++b);
    return 0; 

}
//Relational operators...

int main() 
{
    int a=300,b=2090;
    if (b>=a)
    {

        printf("you are in");
    }
    else
    {
        printf("you are out");

    }
}
//Logical operators in C...&&, ||
#include <stdio.h>
#include <math.h>
int main()
{
    long long int a;
    scanf("%d",&a);
    long long int var=pow(2,a);
    long long int var1=pow(10,9)+7;
    // scanf("%d",a);
    printf("%d",(var)%(var1));

}
int main()
{
    int a=5;
    if (a==5&& a!=6 && a<=56 && a>4)
    {
        printf("you are in");

    }


}
int main()
{
    int a=5;
    if (!(a==6)){
        printf("you are in");

    }


int main()
{
    int a=5,b=3;
    int incr;

    incr=(b>a)||(b++);//False///
    printf("%d\n",incr);
    printf("%d",b);
    return 0;

}

int main()
{
    char x=1,y=2;
    if (x&y)
        printf("Results of x&y is 1");
    if (x&&y)
        printf("results of x&&y is 1");


    return 0;        

}

int main()

{
    char var=32;
    printf("%d",var>>4); // ans is left operand / 2**(right operand)...... similarly for left shift..
    return 0;

}

#include <stdio.h>
int main()

{
    int n;
    int count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
            char s1[20];
            scanf("%s",&s1);
            if(*s1=='I'){

                count=count+20;

            }
            if(*s1=='T'){

                count=count+4;

            }
            if(*s1=='C'){

                count=count+6;

            }
            if(*s1=='O'){

                count=count+8;

            }
            if(*s1=='D'){

                count=count+12;

            }        

    }
    printf("%d",count);
    return 0;
}

int main()
{
    printf("%d",7^4);

}

//assignment operators...

int main()
{
    char a=7;
    a ^=5;
    printf("%d",printf("%d",a+=3));
    return 0;

}
// conditional operator..
#include <stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(t%2==0){
            printf("%d\n",(t/2)-1);
            
        }
        else{


            printf("%d\n",(t/2));

        }

    }

    return 0;
}


int main()
{   char result;
    int marks;
    if(marks>33){
        result='p';

    }
    else{

        result="f";

    }    

}

//?  : is conditional operator
int main()
{
    char result;
    int marks;
    // l value ,r value ....
    result=(marks>33)?'p':'f';
}

int main()
{
    int var=75;
    int var2=56;
    int num;
    num=sizeof(var)?(var2>23?((var==75)?'A':0):0):0;
    printf("%d",num);
    return 0;

}

int main(){
    int a=(3,4,8);// gives the right most operand..
    printf("%d",a);

}

int main()
{

    int var=(printf("%s\n","Hello"),5);
    printf("%d",var);
    return 0;

}

int main(){
int a;
a=3, 4, 5;// this is treated as (a=3),4,5
printf("%d",a);
}
int main()
{
    int a=3,4,8;//error int a int 4 int 8;;
    printf("%d",a);


}
int main(){
    int var ;
    int num ;

    num=(var=15,var+35);
    printf("%d",num);
    return 0;
}
int main()
{
    int var=(fun());// evaluated as function here ..

}
int main()
{
    int a;
    a=fun1()+fun2();
    printf("%d",a);
}
int fun1(){

    printf("Neso\n");
    return 1;

}
int fun2(){

    printf("Academy\n");
    return 1;
}
int main()
{
    int a=10,b=20,c=30,d=40;
    if(a<=b==d>c)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");

    }
    return 0;
}
int main(){
    int x,y;
    int count=0;
    int i=0;
    scanf("%d %d",&x,&y);
    int g=x;
    while(i!=1){
        if(x%10==0 || (x-y)%10==0 ){
            printf("%d",count+1);
            i=i+1;
        }
        else{
            x=g*(count+2);
            count=count+1;
                   
            
        }
    }    
    return 0;   
}
int main()
{
    int i=5;
    int var = sizeof(i++);
    printf("%d %d",i,var);// variable length array type..
    return 0;

}
int main()
{
    int a=1;
    int b=1;
    int c=++a||b++;// condition of short circuit....//
    int d= b--&&--a;

    printf("%d %d %d %d",d,c,b,a);

}
int main()
{
    int n;
    scanf("%d",&n);
    int result=0;
    int remainder;
    int q=n;
    while(q!=0){
        remainder=q%10;
        result=(result*10)+remainder;
        q=q/10;
    }
    if(result==n){
        printf("%s","it is a paliidrome");
    }
    else{
        printf("%s","it is not a palidrome");
    }
    return 0;
}
int main()
{
//    printf("%d",~9);


}
int factorial(n){
    int mult=1;
    for(int i=n;i>=1;i--){
        mult*=i;
    }     
    return mult;
}
int main(){
    int x=2;
    switch (x)// only integeral constants are allowed//..
    {
        case 1:printf("x is 1 ");
            break;
        case 2:printf("x is 2");
            break;
        case 3:printf("x is 3");
            break;
        default:printf("x is other than 1 2 3");
            break;        
    }   

}
#define y 2
#define z 23// defined can be used//
int main()
{
    int x=2;
    switch(x){
        case y:printf("x is 2");
            break;
        case z:printf("x is 23");
            break;
        default:printf("x is other than 2 and 23 ");
            break;    

    }
}
// default can be placed any where ...
#include <stdio.h>
int main(){
    int i=0;
    do{
        printf("%d",i);
        i--;
    }while(i>0);

}
#include <stdio.h>
int main()
{
    int n;
    do
    {
        //printf("enter a number\n");
        scanf("%d",&n);
    }while(n!=0);
    printf("you ar out ");
}

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0){
        if(n<0){
            break;
        }
        scanf("%d",&n);    

    }   

}

#include <stdio.h>
int main()
{
    int i,n=2;
    for(i=1;i<=20;i++){
        if (i==n){
            n+=2;
            continue;
        }
        printf("%d ",i);
    }

}

#include <stdio.h>
int main()
    {
    int i=1024;
    for(;i;i>>=1){ // PRINTED 11 TIMES TILL I =0;
        printf("Hello,World");
    }
    return 0;
}
  
#include <stdio.h>
int main()
{
    for(int i=0;i<20;i++){
        switch(i){
            case 0:i+=5;
            case 1:i+=2;
            case 5:i+=5;
            default: i+=4;
// no break in switch so all cases are added..//
        }

        printf("%d ",i);
    }

}
#include <stdio.h>
int main(){
    int i=-5;
    while(i<=5){
        if(i>=0){
            break;
        }
        else{
            i++;
            continue;
        }
        printf("Neso");
    }
}
#include <stdio.h>
int main()
{
    int i =0;
    for (printf("one\n");i<3 && printf("");i++){
        printf("Hi!\n");

    }
    return 0;
}
#include <stdio.h>
int main()
{
    int a=7;
    int b=-a;
    printf("%d",b);
    return 0;

}
#include <stdio.h>
int main()
{
    unsigned int i=500;
    while(i++!=0);
    printf("%d",i);
    return 0;
}
#include <stdio.h>
int main()
{
    int x=3;
    if(x==2); x=0;// ; ends the statement..
    if(x==3) x++;
    else x+=2;
    printf("x=%d",x);
    return 0;
}

int main ()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf("%s"," ");
        }        
        for (int k=0;k<2*i;k++){
            printf("%s","*");
        }
        printf("%s\n","*");
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int result=0;
    int remainder;
    int q=n;
    while(q!=0){
        remainder=q%10;
        result=(result*10)+remainder;
        q=q/10;
    }
    if(result==n){
        printf("%s","it is a paliidrome");
    }
    else{
        printf("%s","it is not a palidrome");
    }
    return 0;
}
//Armstrong number...
#include <stdio.h>
#include <math.h>
int main()
{
    int number1;
    int count1=0;
    int remainder;
    int result=0;
    scanf("%d",&number1);
    int number2=number1;
    int number3=number1;
    while(number1!=0){
        count1=count1+1;
        number1=number1/10;
    }
    while(number2!=0){
        remainder=number2%10;
        result+=pow(remainder,count1);
        number2=number2/10;
    }
    //printf("%d\n",count1);
    //printf("%d",result);
    if(number3==result){
    printf("Armstrong number");
    }
    else{
        printf("not armstrong");
    }
}
#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int c=a;
    int result=0;
    while(a!=0){
        int b=1;
        for(int i=1;i<=a%10;i++){
            b*=i;
        }
        result+=b;
        a=a/10;
    }
    if(result==c){
        printf("it is a strong number");

    }
    else{
        printf("it is not a strong number");
    }
}
#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d",&a);
    int count=0;
    for(int i=2;i<=ceil(sqrt(a));i++){
        if(a%i==0){
            count+=1;
        }
    }
    if(count==0&&a!=1){
        printf("the number is a prime");
    }
    else{
        printf("the number is not a prime");
    }

}

// adition for positive numbers..
#include <stdio.h>
int main()
{
    int x;
    int y;
    scanf("%d %d",&x,&y);
    if(y>=0){
    if(x>y){
        while(y!=0){
            x++;
            y--;
        }
        printf("%d",x);
    }
    else{
        while(x!=0){
            y++;
            x--;
        }
        printf("%d",y);
    }
    }
    else{
        while(y!=0){
            x--;
            y++;
        }
    printf("%d",x);
    }
}   

//half adder method..
#include <stdio.h>
int main()
{
    int sum,carry,a,b;
    scanf("%d %d",&a,&b);
    while(b!=0){
        sum=a^b;
        carry=(a&b)<<1;
        a=sum;
        b=carry;
    }      
    printf("%d",sum);
}

// fibonacci
#include <stdio.h>
int main()
{
    int a=0;
    int b=1;
    int n;
    int result=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d ",a);
        result=a+b;
        a=b;
        b=result;
    }
}

//floyds triangle
#include <stdio.h>
int main()
{
    int n;
    int a=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++ ){
        for(int j=0;j<=i;j++){
            printf("%d ",a);
            a++;
        }
        printf("\n");
    }
    
}
///binary to decimal.
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    int dec=0;
    int a=0;
    while(n!=0){
        dec=dec+(n%10)*pow(2,a);
        a+=1;
        n=n/10;
    }
    printf("%d",dec);

}
// power of a^b
#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int x=1;
    double y=1.0;
    if(b>0){
    while(b!=0){
        
        x=x*a;
        b-=1;
        
        }
    
    printf("%d", x);    
    }
    else{
        while(b!=0){

            y=y*(1.0/a);
            b++;

        }
        printf("%.10f",y);
    }


}
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%400==0){
        printf("it is a leap year ");
    }
    else if (n%100==0 ){
        printf("it is not a leap year");
    }
    else if(n%4==0){
        printf("it is  a leap year");
    }
    else{
        printf("it is not a leap year");
    }
    return 0;
}
//perfect number//
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int result=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            result+=i;
        }
    }
    if(n==result){
        printf("it is a perfect number");
    }
    else{
        printf("it is not a perfect number");
    }
}

#include <stdio.h>
int areaofrect(int lenght,int breadth)
{
    int area;
    area=lenght*breadth;
    return area;
}

int main(){
    int l,b;
    scanf("%d %d",&l,&b);
    int area=areaofrect(l,b);
    printf("%d",area);

}
#include <stdio.h>
//function  declaration..
//char fun();
char fun(){
    return 'a';
}
int main()
{
    char c=fun();
    printf("%c",c);
}
int add(int , int );

int main()
{
    int n=20, m=30,sum;
    sum=add(m,n);
    printf("%d",sum);
}

int add(int a,int b){
    return a+b; 
}
#include <stdio.h>
int fun(int x,int y){
    x=20;
    y=10;

}
//call by value..
int main(){
    int x=10, y=20;
    fun(x,y);
    printf("%d %d",x,y);
}

int fun(int *ptr1, int *ptr2){
    *ptr1=20;

    *ptr2=10;

}
int main()
{
    int x=10; int y=20;
    fun(&x,&y);
    printf("%d %d",x,y);

}
#include <stdio.h>
void f1(int a,int b){
    int c;
    c=a;a=b;b=c;
}
void f2(int *a ,int *b){

    int c;
    c=*a;*a=*b;*b=c;
}

int main()
{
    int a=4,b=5,c=6;
    f1(a,b);
    f2(&b,&c);    
    printf("%d",c-a-b);
    return 0;
}

#include <stdio.h>
int fun()
{
    static int num=16;
    return num--;

}
int main()
{
    for(fun();fun();fun())
    printf("%d ",fun());
    return 0;
}
//static function
#include <stdio.h>
int fun(int , int );
int main(){     
    int sum=fun(3,4);
    printf("%d",sum);    
    return 0;
}

static int fun(int a, int b){
    int c;
    c=a+b;
    return c;
}
//stacking
#include <stdio.h>
main(){
    fun1();
}   
fun1(){
    fun2(); 
}
fun2(){
    fun3();
}
fun3(){
    return;
}
int main(){
    int a=10;
    a=fun1(a);
    printf("%d",a);
}
int fun1(int a){
    int b=5;
    b=b+a;
    return b;

}
//scoping..
int fun1(){

    int a=10;
}
int fun1(){
    int a= 40;
}
#include <stdio.h>

int a=10,b=20;
int main()
{
    int a=5;
    {
        int c;
        c=b/a;
        printf("%d",c);

    }
}

#include <stdio.h>
int fun1(int);
int fun2(int);
int a=5;
int main()
{
    int a=10;
    a=fun1(a);
    printf("%d",a);
}
int fun1(int b){
    b=b+10;
    b=fun2(b);
    return b;
}
int fun2(int b){
    int c;
    c=a+b;
    return c;
}

#include <stdio.h>
int fun1(int);
int fun2(int);
int a=5;
int main(){
    int a=10;
    a=fun1(a); 
    printf("%d",a);

}
int fun1(int b){
    b+=10;
    b=fun2(b);
    return b;
}
int fun2(int b){
    int c;
    c=a+b;
    return c;
}
#include <stdio.h>
int a,b;
void print(){
    printf("%d %d",a,b);
}
int fun1(){
    int a,c;
    a=0;b=1;c=2;
    return c;
}
void fun2(){
    int b;
    a=3;b=4;
    print();
}
int main(){
    a=fun1();
    fun2();
}
#include <stdio.h>

int fun(int n){
    if(n==1){
        return 1;
    }
    else{
        return 1+fun(n-1);
    }
}
int main(){
    int n=3;
    printf("%d",fun(n));
    return 0;
}

#include <stdio.h>

int factorial(int n){
    if (n==1){
        return 1;
    }    
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int n=4;
    printf("%d",factorial(n));
}
// indirect recursion..
#include <stdio.h>
void odd();
void even();
int n=1;

void odd(){
    if(n<=10){
        printf("%d ",n+1);
        n++;
        even();
    }
    return;
}    
void even(){
    if(n<=10){
        printf("%d ",n-1);
        n++;
        odd();
    }
    return;
}    
int main(){
    odd();
}

// tail recursive..
#include <stdio.h>
void fun(int n){
    if(n==0){
        return;
    }
    else{
        printf("%d ",n);
    }
    return fun(n-1);
}
int main(){
    fun(3);
    return 0;
}


#include <stdio.h>
void fun(int n){
    if(n==0){
        return;
    }
    fun(n-1);
    printf("%d ",n);
}
int main()
{
    fun(3);
    return 0;
}

#include <stdio.h>

int fun(int n){
    if(n==1){
        return 0;
    }
    else{
        return 1+fun(n/2);
    }
}
int main(){
    printf("%d",fun(8));
}

#include <stdio.h>
void fun(int n){
    int i=0;
    if(n>1){
        fun(n-1);
    }
    else{
        for(i=0;i<n;i++);
            printf(" * ");
    }
}

#include <stdio.h>
int fun(int n){
    int x=1,k;
    if (n==1) return x;
    for(k=1;k<n;++k){
        x=x+fun(k)*fun(n-k);
    }
    return x;
}
int main(){
    printf("%d",fun(5));
    return 0;
}
#include <stdio.h>
void count(int n){
    static int d=1;
    printf("%d ",n);
    printf("%d ",d);
    d++;
    if(n>1){
        count(n-1);
    }
    printf("%d ",d);
}
int main(){
    count(3);
}
#include <stdio.h>
int main(){
    int i=9;
    for(;i;){
        printf("h");
        i--;
    } 
}

//array..same type
#include <stdio.h>
int main(){
    int arr[5];
}
#define N 10
int main(){
    int arr[N];
}

//using macro will reduce step while changing the value of N..
#include <stdio.h>
int main(){
    int a[15],i;
    for(i=0;i<15;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<15;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

#include <stdio.h>
int main(){
    int arr[10]={1,2,5,67,32};    
    printf("%d",arr[9]);
}

#include <stdio.h>
int main(){
    int arr[]={2,3,1,4,5};
    for(int i=0;i<5;i++){
        if arr[i]


    }
}

#include <stdio.h>
int main(){
    char str [ ];
    scanf("%s",&a);
    printf("%s",a);
    
}

#include  <stdio.h>
int main(){
    int b;
    scanf("%d",b);
    int a[]={1,2,3,4,5,6,7,8,9};
    int midpoint_index=((sizeof(a)/4)+1)/2;
    if(a[midpoint_index]>b){
    for(int i=midpoint_index;i>=0;i--){
        a[
        
    }
    }


}

#include <stdio.h>
int main(){
    int arr[10]={[0]=1,[5]=2,[6]=3};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ",arr[i]);
    }
}


#include <stdio.h>
int main(){
    int a[]={1,2,3,[2]=4,[6]=45}; 
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d ",a[i]);
    }
}

#include <stdio.h>
int main(){
    int arr[9]={34,56,54,32,67,89,90,32,21};
    for(int i=sizeof(arr)/sizeof(arr[0])-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
}

#include <stdio.h>
int main(){
    int a=6756;
    int arr[10]={0};
    while(a!=0){
        int remainder=a%10;
        arr[remainder]+=1;
        a=a/10;
    }   
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if( arr[i]>1){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}

#include <stdio.h>
int main()
{
    int arr[2][3]={{1,2,3},{4,5,6}};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
    }
}

#include <stdio.h>
int main(){
    int arr[2][2][3]={{{1,2,3},{4,5,6}},
                    {{7,8,9},{10,11,12}}
                    }; 
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                printf("%d ",arr[i][j][k]);
            }
        }
    }
}
#include <stdio.h>
int main(){
    int arr[5][5]={{8,3,9,0,10},{3,5,17,1,1},{2,8,6,23,1},{15,7,3,2,9},{6,14,2,6,0}};
    for(int i=0;i<5;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=arr[i][j];

        }
        printf("%d ",sum);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        int sum1=0;
        for(int j=0;j<5;j++){
            sum1+=arr[j][i];

        }
        printf("%d ",sum1);
    }

}
#include <stdio.h>
#define MAX 50
int main(){
    int a[MAX][MAX],b[MAX][MAX],product[MAX][MAX];
    int arows,acolumns;
    int sum=0;
    scanf("%d %d",&arows,&acolumns);
    for(int i=0;i<arows;i++){
        for(int j=0;j<acolumns;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int brows,bcolumns;
    scanf("%d %d",&brows,&bcolumns);
    for(int i=0;i<brows;i++){
        for(int j=0;j<bcolumns;j++){
            scanf("%d",&b[i][j]);
        }
    }
    if(acolumns!=brows){
        printf("Cant multi");
    }
    else{
        for(int i=0;i<arows;i++){
            for(int j=0;j<bcolumns;j++){
                for(int k=0;k<brows;k++){
                    sum+=a[i][k]*b[k][j];
                }
                product[i][j]=sum;
                sum=0;
            }
        }
    }
    for(int i=0;i<arows;i++){
        for(int j=0;j<bcolumns;j++){
            printf("%d ",product[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
int main(){
    const int arr[10]={1,2,3,4,5,6,7,8,9,10};
    arr[1]=45;
    return 0;
}

//variable lenght array..
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n,i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=0;i--){
        printf("%d",a[i]);

    }
    return 0;
}    

#include <stdio.h>
int main(){
    int x=5, *ptr=&x;
}


//value of operator..
#include <stdio.h>
int main(){

    int x=5;
    int *ptr;
    ptr=&x;
    printf("%d",*ptr);
}
#include <stdio.h>
int main(){
    int x=10;
    int *ptr=&x;
    *ptr=4;
    printf("%d",*ptr);   
}

#include <stdio.h>
int main(){
    int i=10,j=20;
    int *p,*q;
    p=&i;
    q=&j;
    *q=*p;
    printf("%d %d",*p,*q);
 }

#include <stdio.h>
int main()
{
    int i=1;
    int *p=&i;
    int q=p;
    int *q=5;
    printf("%d",*p);

}

#include <stdio.h>
int main()
{
    int a[]={23,45,6,98};
    int min=a[0],max=a[0];
    for(int i=1;i<sizeof(a)/sizeof(a[0]);i++){
        if (a[i]<min){
            min=a[i];
        }
    }
    printf("%d\n",min);
    for(int i=1;i<sizeof(a)/sizeof(a[0]);i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("%d",max);
}

#include <stdio.h>
void minMax(int arr[],int len,int *min,int *max){
    *min=*max=arr[0];
    for(int i=1;i<len;i++){
        if (arr[i]>*max){
            *max=arr[i];
        }
        if(arr[i]<*min){
            *min=arr[i];
        }
    }        
}

int main(){
    int a[]={23,4,21,98,987,45,32,10,123,986,50,3,4,5};
    int min,max;
    int len=sizeof(a)/sizeof(a[0]);
    minMax(a,len,&min,&max);
    printf("%d %d",min,max);
    return 0;
}

//bubble sort..
#include <stdio.h>
int main(){
    int arr[]={5,2,1,3,6,7};
    for(int j=0;j<sizeof(arr)/sizeof(arr[0]);j++){
        int swapped=0;
        for(int i=0;i<sizeof(arr)/sizeof(arr[0])-j-1;i++){
            int key;
            key=arr[i];
            if(arr[i+1]<key){
                arr[i]=arr[i+1];
                arr[i+1]=key;
                swapped=1;
           }
        }   
        if (swapped==0){
            break;
        }
    }
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ",arr[i]);
    }
}

#include <stdio.h>
int *findmid(int a[],int n){
    return &a[n/2];
}
int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int *mid=findmid(a,n);
    printf("%d",*mid);
    return 0;    
     
}

#include <stdio.h>
int *fun(){
    int i=10;//automatic variable..
    return &i;
}  
int main(){
    int *p=fun();
    printf("%d",*p);

}



#include <stdio.h>

int main() {
    
     int i=0;
     int j;
     j = ++i + i++;
    printf("Case-2: value of j is %d",j);
}

#include <stdio.h>
void fun(const int *p){
    *p=0;
}
int main(){
    const int i=10;
    fun(&i);
    return 0;
}

//%p is a format specifier..
#include <stdio.h>
int main(){
    int i=10;
    int *p=&i;
    printf("%p",p);
}

//undefined behaviour 
#include <stdio.h>
int main(){
    int a[]={1,2,3,4};
    int b[]={10,20,30,40};
        int *p=&a[0];
    int *q=&b[3];
    printf("%d",q-p);
}

#include <stdio.h>
int main(){
    int a[]={5,16,7,89,45,32,23,10};
    int *p=&a[2];
    printf("%d\n",*(--p));
    printf("%d",*p);
    return 0;
}
#include <stdio.h>
int main(){
    int a[]={1,2,3,4,5,6};
    int *p=&a[3];
    int *q=&a[5];
    printf("%d\n",p<=q);
    printf("%d\n",p>=q);
    q=&a[3];
    printf("%d",p==q);
}
#include <stdio.h>
int main(){
    int arr[]={1,34,55,451};
    int *p=&arr[0];
    int sum=0;
    for(p=&arr[0];p<&arr[4];p++){
        sum+=(*p);
    }
    printf("%d",sum);
}

#include <stdio.h>
int main(){
    int i=0;
    printf("%d",i);
}
#include <stdio.h>
int main(){
    int a[5];
    *a=10;
    printf("%d",a[0]);
    return 0;
}
#include <stdio.h>
int main(){
    int a[]={11,22,36,5,2};
    int sum=0,*p;

    for(p=a;p<=a+4;p++){
        sum+=(*p);
    }
    printf("%d",sum);
    return 0;
}

#include <stdio.h>
#define N 5
int main(){
    int a[N];
    int *p; 

    for(p=a;p<=a+N-1;p++){
        scanf("%d",p);
    }
    for(p=a+N-1;p>=a;p--){
        printf("%d ",*p);
    }
    return 0;           
}

#include <stdio.h>
int add(int b[],int len){
    int sum=0,i;
    for(i=0;i<len;i++){
        sum+=b[i];
    }
    return sum;

}
int main(){
    int a[]={1,2,3,4};
    int len=(sizeof(a))/(sizeof(a[0]));
    printf("%d",add(a,len));
    return 0;
}

#include <stdio.h>
int main(){
    int arr[2][2]={{1,2},{3,4}};
    int *p;
    for(p=&arr[0][0];p<=&arr[1][1];p++){
        printf("%d ",*p);
    }
}

#include <stdio.h>
int main(){     
    int a[2][2]={{1,2},{3,4}};
    //*a gives address and *a+1 gives address of first element of the first row..
    printf("%d",*(*(a+1)+1));
}
//3d array using pointers..
#include <stdio.h>
int main(){
    int a[2][2][2]={{{1,2},{3,4}},
                    {{5,6},{7,8}}
                    };
    printf("%d",*(**(a+1)+3));
}

#include <stdio.h>
int main(){
    int a[2][2][2]={{{1,2},{3,4}},
                    {{5,6},{7,8}}
                    };
    printf("%d",*(**(a)+1));
}


#include <stdio.h>
int main(){
    int a[5]={1,2,3,4,5};
    int (*p)[5]=&a;
    printf("%p",p);
    return 0;    
}
#include <stdio.h>
int main(){
    int a[5]={1,2,3,4,5};
    int (*p)[5]=&a;
    printf("%d",**p);

}
#include <stdio.h>
int main(){
    int a[][3]={1,2,3,4,5,6};
    int (*ptr)[3]=a;
    printf("%d %d ",(*ptr)[1],(*ptr)[2]);
    ++ptr;
    printf("%d %d",(*ptr)[1],(*ptr)[2]);
}
#include <stdio.h>
#include <math.h>
int fun1(int n){
    if(n==1){
        return 1;
    }
    else{
        return fun1(n-1)*n;
    }
}
int main(){
        
    printf("%d",fun1(pow(2,4)));
    return 0;

}
#include <stdio.h>
int main(){
    unsigned char i;
    for(int i=0;i<256;i++){
        printf("%c\n",i);
    }
    return 0;
}
#include <stdio.h>
int main(){ 
    int a[][3]={1,2,3,4,5,6};
    int (*ptr)[3]=a;
    printf("%d %d ",(*ptr)[1],(*ptr)[2]);
    ++ptr;
    printf("%d %d",(*ptr)[1],(*ptr)[2]);

    return 0;
}
#include <stdio.h>
void f(int *p, int *q){
    p=q;
    *p=2;
}
int i=0,j=1;
int main(){
    f(&i,&j);
    printf("%d %d",i,j);
    return 0;
}

#include <stdio.h>
int f(int *a,int n){
    if(n<=0){
        return 0;
    }
    else if(*a%2==0){
        return *a+f(a+1,n-1);
    }
    else{
        return *a-f(a+1,n-1);
    }
}
int main(){
    int a[]={12,7,13,4,11,6};
    printf("%d",f(a,6));
    getchar();
    return 0;
}

#include <stdio.h>
void toh(int n, char rodA,char rodB,char rodC){
    if (n==1){
        printf("\n Move disk 1 to rod %c to rod %c",rodA,rodC);
        return;
    }
    toh(n-1,rodA,rodB,rodC);    
    printf("\n Move disk %d from rod %c to %c",n,rodA,rodC);    
    toh(n-1,rodB,rodC,rodA);
}
int main(){
    int n;
    scanf("%d",&n);
    toh(n,'A','B','C');
}
#include <stdio.h>
int f(int x,int *py,int **ppz){
    int y,z;
    **ppz+=1;
    z=**ppz;
    *py+=2;
    y=*py;
    x += 3;
    return x + y +z;
}

void main(){
    int c,*b,**a;
    c=4,b=&c,a=&b;
    printf("%d",f(c,b,a));
}
#include <stdio.h>
void swap(int *x,int *y){
    static  int *temp;
    temp=x;
    x = y;
    y=temp;
}
void printab(){
    static int i,a=-3,b=-6;
    i=0;
    while(i<=4){
        if ((i++)%2==1) continue;
        a=a+i;
        b=b+i;
    }
    swap (&a,&b);
    printf("a=%d,b=%d\n",a,b);
}
int main(){
    printab();
    printab();
}


# include <stdio.h>
int main(){
    int i,j;
    char a[2][3]={{'a','b','c'},{'d','e','f'}};
    char b[3][2];
    char *p=*b;

}
#include <stdio.h>
int main(){
    printf("%s","kjejwjefje\
    eokdoewkdoew"); 
}


#include <stdio.h>
int main(){
    char *ptr="Hello world!";
    printf("%c",*(ptr+2));
}

#include <stdio.h>
int main(){
    
    char s[6]="Hello";
    char t[6];
    int i;
    for(i=0;s[i]!='\0';i++){
        t[i]=s[i];
    }
    t[i]='\0';
    printf("%s",t);
    return 0;

}

#include <stdio.h>
int main(){
    char *ptr="Hello world";
    printf("%6.5s",ptr);
    
}
#include <stdio.h>
int main(){
    char *s="Hello";
    puts(s);
    puts(s);
}
#include <stdio.h>
int main(){
    char a[10];
    scanf("%s",a);
    printf("%s",a);
}

#include <stdio.h>
int main(){
    char a[10];
    gets(a);
    printf("%s",a);
}

#include <stdio.h>
int main(){
    char a[10];
    scanf("%9s",a);
    printf("%s",a);
}

#include <stdio.h>

    int input(char str[],int n){
        int ch,i=0;
        while ((ch=getchar())!='\n'){
            if (i<n){
                str[i++]=ch;
            }   
        }
        str[i]='\0';
        return i;
    }
    int main(){
        char str[100];
        int n=input(str,5);
        printf("%d %s",n,str);
        return 0;
    }

#include <stdio.h>
int main(){
    int ch;
    for(ch='A';ch<='Z';ch++){
        putchar(ch);
    }
    return 0;
}    

#include <stdio.h>
#include <string.h>
int main(){
    char str1[10]="Hello";
    char str2[10];
    char str3[10];
    strcpy(str3,strcpy(str2,str1));
    printf("%s %s",str2,str3);
    return 0;
}*/
/*int main(){
    char str1[6]="Hello";
    char str2[4];
    strncpy(str2,str1,sizeof(str2));
    printf("%s",str2);
    return 0;
}
int main(){
    char str1[6]="Hello";
    char str2[6];
    strncpy(str2,str1,sizeof(str2));
    str2[sizeof(str2)-1]='\0';
    printf("%s",str2);
    return 0;
}

int main(){
    char str[100]="hello world";//calculates length of string
    printf("%d ",strlen(str));
    return 0;
}

int add(int a , int b){
    return a+b;
}
#define ops 4
float sum(float a, float b){return (a+b);}
float diff(float a, float b){return (a-b);}
float mul(float a,float b){return (a*b);}
float div(float a,float b){return (a/b);}

struct {
    char *engine;
   } car1 ,car2 ;
   
typedef struct car
{
    char engine[50];
    char fuel_type[0];
    int fuel;    
}car;

struct abc{
    int p;
    int q;
}; 

struct abc{
    int x;
    int y;
    int z;
    char *fuel;
};
int main(){
    struct abc a={.y=20,.x=10,.z=30};
      
    /*
    struct abc a1={2,3};
    struct 
    {
        /* data */
    
    
    
    //struct abc c1={};//typedef used can be used to create this..
    //car becomes new data type

    /*INTEGER var=100;
    printf("%d",var);

    
    char str1[100], str2[100];
    strcpy(str1,"welcome to ");
    strcpy(str2,"neso Academy");
    strcat(str1,str2);
    printf("%s",str1);
    return 0;
    
    char str1[5],str2[100];
    strcpy(str1,"hel");
    strcpy(str2,"lo");
    strncat(str1,str2,sizeof(str1)-sizeof(str1)-1);    
    printf("%s",str1);
    return  0;
    
    char *s1="abc";
    char *s2="abcd";
    if (strcmp(s1,s2)<0){
        printf("s1 is less than s2");
    }    
    else{
        printf("s1 is more or equal than s2");
    }
    return 0;
    
    char *fruits[12]={"2 oranges","2 Apples","3 bananas","1 pineapple"};       
    
    char *c="GATECSIT2017";
    char *p=c;
    printf("%d",(int)strlen(c+2[p]-6[p]-1));
    
    int (*ptr)[10];//pointer pointing to array of ten integers..
    return 0;
   
    int (*ptr)(int,int)=add;
    int result;
    result=(ptr)(10,20);
      printf("%d",result);
    
   //use of function pointers .. 
    float (*ptr2func[ops])(float,float)={sum,diff,mul,div};
    int choice;
    float a,b;
    scanf("%d",&choice);
    scanf("%f %f",&a,&b);
    printf("%f",ptr2func[choice-1](a,b));
    return 0;

   
  struct 
  {
    char *engine;
    char *fuel_type;
    int fuel;
    int seating;
    float somehting;
  } car1,car2 ;
    
   car1.engine="s1";
   car2.engine="s2";
   printf("%s\n",car1.engine);
   printf("%s",car2.engine);
   
  //struct tag//
  struct f1
  {
    char *e1;
    char *e2;
  };
  int manager(){
    struct f1 manager;
    {
        
    };
    
  }
 
       
   return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;

};

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));

    head->data=45;
    head->link=NULL;
    printf("%d",head->data);
    return 0;


}