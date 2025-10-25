#include<iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num,m,x_num=0,y_num=0;
        cin>>num>>m;
        for(int j=0;j<num;++j){
            int tmp;
            cin>>tmp;
            if(tmp>0)
                x_num++;
            else if(tmp<0)
                y_num++;
        }

        if(x_num==m)
             cout<<0<<endl;
        else if(m-x_num<0 && (y_num>=1 || num-x_num-y_num!=0))
            cout<<x_num-m<<endl;
        else if(m-x_num>0){
            if(y_num-1>=m-x_num)
                cout<< m-x_num <<endl;
            else    
                cout<< -1 <<endl;
        }
        else
            cout<< -1<<endl;
    }
    return 0;
}