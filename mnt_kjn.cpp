#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<iostream>
#include<fstream>


using namespace std;

vector <int> money;

bool genProbabability(double n){
    if((double)rand()/RAND_MAX < n){
        return true ;
    }
    return false;
}

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        printf("%d,",v[i]);
    }
}

// 買ったとき
int win_kajino(){
    int get_money = 2*(money.front() + money.back());
    if(money.size()==1){
        money.pop_back();
        return get_money;
    }
    money.erase(money.begin());
    money.pop_back();
    /*
    printf("win,{");
    print(money);
    printf("}\n");
    //*/
    return get_money;
}

// 負けたとき
int lose_kajino(){
    int get_money = (-1)*(money.front() + money.back());
    if(money.size()!=1) money.push_back(money.front() + money.back());
    else money.push_back(money.front());
    /*
    printf("lose,{");
    print(money);
    printf("}\n");
    //*/
    return get_money;
}

// カジノゲーム
int kajino(int j){
    srand((unsigned)time(NULL)*(j+1));
    double prb = 0.5;
    int sum = 0;
    while(money.empty() == false){
        if(genProbabability(prb)) sum += win_kajino();
        else sum += lose_kajino();    
    }
    return sum;
}

int main(void){
    int epoc = 10000;
    vector<int> result(epoc);

    ofstream ofs("result.csv");
    for(int i=0;i<epoc;i++){
        money = {1,2,3};
        result[i] = kajino(i);
    ofs << i << "," << result[i]<<endl;
        //printf("epoc%d = %d\n",i,kajino(i));
    }
    return 0;
} 

モンテカルロ法によるカジノの勝利シミュレーション
以下の記事を参考にcppで実装
https://qiita.com/kagawa_shinjiiiii/items/ff49a8c7ccc682845a2a