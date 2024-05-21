#include<iostream>
#include<fstream>
using namespace std;

class temp{

       string itemID, itemName;
       int itemQuantity, itemPrice;
       fstream file, file1;
       int totalAmount, quantity, itemRate;
       string search;
       char _choice;
    public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);
}obj;


int main() {
    char choice;

    cout<<"Press 1 ---> Start Shopping"<<endl;
    cout<<"Press 0 ---> Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 'A':
            obj.addProduct();          //For admin
        break;
        case '1':                 //For customer
            obj.viewProduct();
            obj.buyProduct();
        break;
        case '0':
            system("exit");
        break;
        default:
             cout<<"Invalid Selection..!";
             break;
    }
    
    return 0;
}

//Add product definition
void temp :: addProduct(){
      cout<<"Enter Product ID :: ";
      cin>>itemID;
      cout<<"Enter Product Name :: ";
      cin>>itemName;
      cout<<"Enter Product Quantity :: ";
      cin>>itemQuantity;
      cout<<"Enter Product Price :: ";
      cin>>itemPrice;

      file.open("data.txt",ios :: out | ios :: app);
      file<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
      file.close();
}

void temp :: viewProduct(){
    file.open("data.txt",ios :: in);
         file>>itemID>>itemName>>itemQuantity>>itemPrice;

         while(!file.eof()){        //Loop is working(taking data from the variables) until the data isempty from the files
            
             cout<<"---------------------------"<<endl;
             cout<<"Product Id\t\tProduct Name\t\tQuantity\t\tProduct Price"<<endl;
             cout<<itemID<<"\t\t\t"<<itemName<<"\t\t\t"<<itemQuantity<<"\t\t\t"<<itemPrice<<endl;
             cout<<"---------------------------"<<endl;

         file>>itemID>>itemName>>itemQuantity>>itemPrice;
         }
    file.close();  //After ending of the while loop file will be closed
}
//Admin side completed

//Customer side started


void temp :: buyProduct(){
    _choice = 'y';

    while(_choice== 'y'){



    
    file.open("data.txt",ios :: in);
    file1.open("temp.txt",ios :: out | ios :: app);
    file>>itemID>>itemName>>itemQuantity>>itemPrice;

    cout<<"Enter Product ID :: ";
    cin>>search;
    cout<<"Enter Quantity :: ";
    cin>>quantity;

    while(!file.eof())
    {
        if(itemID == search){
            itemQuantity = itemQuantity - quantity;
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;


            itemRate = quantity * itemPrice;
            totalAmount = totalAmount + itemRate;
            cout<<"------Payment Bill-------"<<endl;
            cout<<"Total Purchase Amount :: "<<totalAmount<<endl;
            cout<<"---------------------------"<<endl;


        }else{
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
        }
        file>>itemID>>itemName>>itemQuantity>>itemPrice;
    }
    file.close(); 
    file1.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
    
    cout<<"\n Continue Shopping ! (Y / N) ";
    cin>>_choice;
    }
}