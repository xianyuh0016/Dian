#include <stdio.h>
#include <windows.h>
#include <stdlib.h>//pause

int main(){
    SetConsoleOutputCP(CP_UTF8);//输出编码格式UTF-8
    printf("模拟摆放货物，请依次输入货物种类、货物所在的通道标号、货物单价以及货物个数(货物种类用大写英文字母表示)\n");
    
    char sort;//货物种类
    int sign;//通道标号
    int price;//货物单价
    int number;//货物个数
    
    scanf(" %c %d %d %d",&sort,&sign,&price,&number);//扫描输入的内容
    printf("%d: ",sign);
    
    for(int i=0;i<number;i++){//for循环，重复输出货物名
        printf("%c",sort);
    }
    
    printf(" %d\n",price);


    while (number>0){
    printf("进行购买操作\n请输入需要购买的货物、货物所在的通道以及购买的数量\n");
    
    int num;//购买数量
    scanf(" %*c %*d %d",&num);
    
    if(num>number){//检查库存
        printf("库存不足,最多只能购买%d个\n",number);
        continue;
    }
    int total=num*price;//总额
    int x;//每次投币金额
    int sum=0;//投币总额
    printf("依次投币,需要投入%d元(金额只能为1元,2元,5元)\n",total);
    while(sum<total){
        scanf("%d",&x);
        if(x!=1 && x!=2 && x!=5){
            printf("只能输入1元,2元或5元哦\n");//使用if检查纠错，每次投币都要检查
        }else{
        sum=sum+x;
        }
    }
        printf("找零%d元\n",sum-total);
    number -= num;
    if(number == 0){
        break;
    }
    printf("是否继续购买? 输入1表示继续,输入0表示结束购买\n ");
    int choice;
    scanf("%d", &choice);
    if (choice == 0) {
        break;
    }
    }
    printf("购买完成");
    system("pause");
    return 0;
}