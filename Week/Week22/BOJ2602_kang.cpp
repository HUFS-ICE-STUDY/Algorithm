#include<iostream>
#include<string>
#define Angel 0
#define Devil 1
using namespace std;
int dp[2][21][101];
int scrollLen,bridgeLen;
char scroll[21], angelBridge[101], devilBridge[101];
void printAngel(){
    printf("====Angel side====\n");
    for(int i = 1 ; i <= scrollLen ; i++){
        for(int j = 1 ; j <= bridgeLen ; j++){
            printf("%d ",dp[Angel][i][j]);
        }
        printf("\n");
    }
}
void printDevil(){
    printf("====Devil side====\n");
    for(int i = 1 ; i <= scrollLen ; i++){
        for(int j = 1 ; j <= bridgeLen ; j++){
            printf("%d ",dp[Devil][i][j]);
        }
        printf("\n");
    }
}
int main(){
    scanf(" %s %s %s", scroll+1, angelBridge+1, devilBridge+1);
    int count = 0;
    for(int i = 1 ; i < 20 ; i++){
        if(scroll[i] != '\0')
            count++;
    }
    scrollLen = count;
    count = 0;
    for(int i = 1 ; i < 101 ; i++){
        if(angelBridge[i] != '\0')
            count++;
    }
    bridgeLen = count;
    for(int bridgeNo = 1 ; bridgeNo <= bridgeLen ; bridgeNo++){
        //Angel part
        if(scroll[1] == angelBridge[bridgeNo]){
            dp[Angel][1][bridgeNo] = 1+dp[Angel][1][bridgeNo-1];
        }else{
            dp[Angel][1][bridgeNo] = dp[Angel][1][bridgeNo-1];
        }
        //Devil part
        if(scroll[1] == devilBridge[bridgeNo]){
            dp[Devil][1][bridgeNo] = 1+dp[Devil][1][bridgeNo-1];
        }else{
            dp[Devil][1][bridgeNo] = dp[Devil][1][bridgeNo-1];
        }
    }
    for(int scrollNo = 2 ; scrollNo <= scrollLen ; scrollNo++){
        for(int bridgeNo = 1 ; bridgeNo <= bridgeLen ; bridgeNo++){
            //Angel part
            if(scroll[scrollNo] == angelBridge[bridgeNo]){
                dp[Angel][scrollNo][bridgeNo] = dp[Angel][scrollNo][bridgeNo-1] + dp[Devil][scrollNo-1][bridgeNo-1];
            }else{
                dp[Angel][scrollNo][bridgeNo] = dp[Angel][scrollNo][bridgeNo-1];
            }
            //Devil part
            if(scroll[scrollNo] == devilBridge[bridgeNo]){
                dp[Devil][scrollNo][bridgeNo] = dp[Devil][scrollNo][bridgeNo-1] + dp[Angel][scrollNo-1][bridgeNo-1];
            }else{
                dp[Devil][scrollNo][bridgeNo] = dp[Devil][scrollNo][bridgeNo-1];
            }
        }
        // printf("\ncurrent scroll character: %c\n",scroll[scrollNo]);
        // printAngel();
        // printDevil();
    }
    
    printf("%d",dp[Angel][scrollLen][bridgeLen]+dp[Devil][scrollLen][bridgeLen]);
}