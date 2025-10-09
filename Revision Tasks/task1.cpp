#include<iostream>
using namespace std;

int main(){
    int ID[]={205,102,310,450,120,90};
    int n=6;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=ID[i];
            int j;
            for(j=i;j>=gap && ID[j-gap]>temp;j-=gap){
                ID[j]=ID[j-gap];
            }
            ID[j]=temp;
        }
        cout<<endl<<"After gap: "<<endl;
        for(int k=0;k<n;k++){
            cout<<ID[k]<<" ";
        }
    }
    cout<<endl<<"Fully Sorted IDs"<<endl;
    for(int i=0;i<n;i++){
        cout<<ID[i]<<" ";
    }
}
