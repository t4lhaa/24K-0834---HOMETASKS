#include<iostream>
using namespace std;

int main(){
    int luggage[]={32,25,40,12,18,50,28};
    int n=6;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=luggage[i];
            int j;
            for(j=i;j>=gap && luggage[j-gap]>temp;j-=gap){
                luggage[j]=luggage[j-gap];
            }
            luggage[j]=temp;
        }
        cout<<endl<<"Intermediate steps: "<<endl;
        for(int k=0;k<n;k++){
            cout<<luggage[k]<<" ";
        }
    }
    cout<<endl<<"Fully Sorted Luggage"<<endl;
    for(int i=0;i<n;i++){
        cout<<luggage[i]<<" ";
    }
}
