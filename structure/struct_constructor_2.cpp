# include <bits/stdc++.h>
using namespace std;

struct Product{
    double price;
    char name[20];

    Product (){
        price=0;
        memset (name, 0, sizeof(name));
    }

    Product (double newPrice){
        price=newPrice;
    }

    Product (int newPrice){
        price=newPrice + 10;
    }

    Product (char newName[], double newPrice){
        price = newPrice;
        memset(name, 0, sizeof(name));
        strcpy (name, newName);
    }

}Y(3.6);

int main (){

    char a[] = "apple";
    Product X (a, 2.5);
    cout<<"Name  : "<<X.name<<endl;
    cout<<"Price : "<<X.price<<endl;

    return 0;
}