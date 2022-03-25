#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int gcm, lcm;
int sum=INT_MAX;
int main(){
    scanf(" %d %d",&gcm,&lcm);
    /*
    A와 B가 있을때,
    GCM (이하 G) 을 이용하여 A와 B를 표현할 수 있다.
    A = Ga, B = Gb의 경우
    LCM (이하 L) 은 아래와 같이 표현할 수 있다.
    L = Gab
    여기서, L/G를 할 경우 남는것은 ab이며, 가능한 ab의 조합쌍을 통해 기존의 A와 B를 유추할 수 있다.
    여기서 G의 조건일 만족하기 위해서는 a와 b는 서로소여야 한다.
    G의 값이 고정된 경우 a와 b가 서로소가 아니라면 G의 값이 변하기 때문이다.(a b가 서로소가 아니라면 a와 b는 다시 G'a', G'b'으로 표현될 수 있기 때문이다.
    그렇다면 A = GG'a'인데, A와 B의 최대공약수는 GG'가 되므로, 최대공약수는 G가 아니게되기 때문이다.)
    
    */
    int gA=gcm,gB=lcm;
    int num = lcm/gcm;
    for(int i = 1 ; i < sqrt(num) ; i++){
        if(num%i == 0){
            int a = i,b = num/i;
            // printf("%d %d\n",a,b);
            int ta = a,tb = b;
            int tmp;
            // printf("ta: %d",ta);
            while(true){
                if(tb%ta == 0)
                    break;
                tmp = ta;
                ta = tb%ta;
                tb = tmp;
                // printf("->%d",ta);
            }
            if(ta != 1){
                // printf("\nnot seoroso\n");
                // printf("gcm: %d\n",ta);
                continue;
            }
                
            // printf("%d %d\n",a,b);
            a*=gcm;b*=gcm;
            if(sum > a+b){
                sum=a+b;
                gA=a;gB=b;
            }
        }
    }
    printf("%d %d",gA,gB);
}