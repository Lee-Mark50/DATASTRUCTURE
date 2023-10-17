//xiangdaonaxiedaona
#include<iostream>
using namespace std;


//思路是：在已知序列的基本长度，首位情况下，去考虑按位先找到最大max的位置和真值；将该位与末尾进行调换位置，这就确保一位定下来，之后只需要递归sort首位到末尾-1即可
//    出现问题是如何进行循环更迭——从冒泡的思路来看，选用双for循环，前后遍历来达到目的是比较适合的一种方法

/*
for(int i=low;i<high+1;i++){//这样for问题是，会达到一个分组比较的效果,源极大浪费,时间复杂度O(n·n)

    for(int j = high;j>i;j--){
        //-》——————《-
        if(a[i]>a[j]){
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    return a[];
}
*/

void sort(int a[] , int low, int high){
    int max=0;
    for(int i=low;i<high+1;i++){
        //easy alo 使用冒泡的思路来写
        if( a[i] > max){
            max = a[i];//大了直接更新
        }
        else continue;
    }
    a[high] = max;
    printf("%d\n",a[high]);
    
    
    if(low < high-1){
        sort(a,low,high-1);
    }
}
void mopao(int a[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int l = 0; l < length - 1 - i; l++) {
            if (a[l] > a[l + 1]) {
                temp = a[l];
                a[l] = a[l + 1];
                a[l + 1] = temp;
            }
        }
    }
}


// int zhebanSort(int lowa, int highb,int key){
//     //diguileixing
//     //顺序表有序
//     int low = 1;
//     int high = ST.length;
//     int mid;
//     for(int i=low;i<high;i++){
//         mid = (low+high)/2;
//         if(L.elem[mid] == key)
//             return mid;
//         else if(L.elem[mid] > key)
//             zhebanSort(low,mid);
//         else zhebanSort(mid,high);
//     }
//     return -1;
// }

int main(){
    int a[5] = {7,5,3,1,8};
    sort(a,0,4);

}