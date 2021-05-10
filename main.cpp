/*
    This project has been created by Siddharth Singh during his Second Semester in VIT-VELLORE.
    This project in the foem of assignment was given by his OOPS-professor.
    The contents, methods and fuctions are solely created by Siddharth himself. 
*/

/*
    Created By: SIDDHARTH SINGH(20BBS0070)
    Title:      WorkStore product and bill management system which is to be operated by an employee.
*/


//Header Files
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

//Functions Declarations (OutofClass)
void user_driven_login();
void user_drivenmenu();

//Function to search and fetch the key_i value for corressponding Product-BatchID
int getKey(string batID);
//Function of batchID to hold array and various batchID updations
void batchIDArray(int i);


class product
{
    public:
        //Characteristics of products
        string batchid;
        string dateofmanu; //dd-mm-yy format
        string name;
        float rate;
        //User-defined functions
        void add_products();
        void mod_products(int srNo);
        void display_productdetails();
         
};

//Declaring object globally
product p[100];

int i;                       //product indexing
int proNum;                 //Total number of products
int j;                      //Product Counter
string batch_ID[500];       //BatchID Array
//Get current date and time
time_t now = time(0);
char* date_time = ctime(&now);

int key[100];           //Array to store key_i values
int k=0;
int z=0;               //BillCounter(Product SrNo)
int quantity[100];    //Global Array to store quantity of each product
int q;               //QuantityCounter



//Derived Class of Products to inherit the properties for Class BillGenerate
class BillGenerate : public product
{
    public:
        void generateBill();
        
        //Function to display Bill
        void displayBill(int h,int c);
};


//Function Defination(In class functions)
void product::add_products()
{
    //getline(cin, str);
    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tAppend products to the list\n";
    proNum++;
    cout<<"\t\tEnter Name of the product: ";
    cin>>p[i].name;
    cout<<"\t\tEnter BatchID of the product: ";
    cin>>p[i].batchid;
    cout<<"\t\tEnter DateofManufactoring of the product: ";
    cin>>p[i].dateofmanu;
    cout<<"\t\tEnter Rate of the product: ";
    cin>>p[i].rate;
    cout<<endl<<endl;
    j = 1; //Product Counter Initialized
    batchIDArray(i);
}



void product::mod_products(int srNo)
{
    char label;
    int choice;
    if(srNo <= proNum )
    {
        cout<<"\t\t\t***Product Description***\n";
        cout<<"\t\tName of the Product: "<<this->name<<endl;
        cout<<"\t\tBatchID of the Product: "<<this->batchid<<endl;
        cout<<"\t\tDateOfManufactoring of the Product: "<<this->dateofmanu<<endl;
        cout<<"\t\tRate of the Product: "<<this->rate<<endl;
        cout<<endl<<endl;
        xx:
        cout<<"\tWhich Product-specification do you want to modify?\n";
        cout<<"\t\t1.Product NAME\n";
        cout<<"\t\t2.Product DateOfManufactoring\n";
        cout<<"\t\t3.Product Rate\n";
        cout<<"\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                cout<<"\t\tEnter new NAME: ";
                cin>>this->name;
                break;

            case 2: 
                cout<<"\t\tEnter new DateOfManufactoring: ";
                cin>>this->dateofmanu;
                break;

            case 3: 
                cout<<"\t\tEnter new RATE: ";
                cin>>this->rate;
                break; 
        
            default: cout<<"Out of Choices!!";
                break;
        }
        cout<<"\tDo you want to Modify any other Product-Description?(Y/N) ";
        cin>>label;
        if(label == 'Y')
        {
            goto xx;             //Did'nt wanted to include this but under given circumstaces it seemed to be the best!
        }
    }
    else
    {
        cout<<"\t\tOut of Stock!"<<endl;
    }
    j = 1;                       //Product Counter Initialized (In a recursive way)
}


void product::display_productdetails()
{
    cout<<setw(15)<<j<<setw(25)<<this->name<<setw(25)<<this->batchid<<setw(25)<<this->dateofmanu<<setw(20)<<this->rate<<endl;
}


void generateBill()
{
    string batID;
    char label;
    //int key[100];        //Array to store key_i values
    //int k=0;
    q = -1;
    cout<<"\n\n";
    xx:
    q++;
    cout<<"\t\tEnter the BatchID of the product purchased: ";
    cin>>batID;
    cout<<"\t\tEnter the quantity of item: ";
    cin>>quantity[q];
    key[k] = getKey(batID);
    cout<<"\t\tDo you want to add more items?(Y/N): ";
    cin>>label;
    if(label == 'Y')
    {
        k++;
        cout<<"\n";
        goto xx;
    }
    cout<<"\n\n\n\n\n\n\n\n";   
   
}

//A function to return key_i value to fetch the corresponding data of product details
int getKey(string batID)
{
    int key_i;
    for(key_i=0;key_i<proNum;key_i++)
    {
        if(batID == batch_ID[key_i])
        {
            return key_i;
        }
    }
    return -1;
}


void displayBill(int h,int c) 
{
    cout<<setw(29)<<c<<setw(27)<<p[h].name<<setw(25)<<p[h].batchid<<setw(30)<<p[h].dateofmanu<<setw(20)<<quantity[c-1]<<setw(17)<<p[h].rate<<setw(20)<<quantity[c-1]*p[h].rate<<setw(10)<<endl;   


}


void batchIDArray(int i)
{
    //string batch_ID[500];
    //initially we have 10 products, so 10 batchID's
    batch_ID[0] = "BC11256";
    batch_ID[1] = "AD12506";
    batch_ID[2] = "AF10325";
    batch_ID[3] = "YK63785";
    batch_ID[4] = "HJ16254";
    batch_ID[5] = "YZ61895";
    batch_ID[6] = "BY5621I";
    batch_ID[7] = "LOL121U";
    batch_ID[8] = "AIO123N";
    batch_ID[9] = "SIO445M";
    batch_ID[i] = p[i].batchid;
}



void user_driven_login()
{   //Login Screen
    string employee_id;
    int password;
    int pass_counter = 0; //To restrict user to enter correct password within 3 trials.
    cout<<"\n\n";
    cout<<"\t\t\t\tUSER LOGIN"<<endl<<endl;
    do
    {
        cout<<"\t\tPlease enter your Employee ID: ";
        cin>>employee_id;
        if(employee_id == "A1Q123OZ")
        {          
            do
            {
                cout<<"\t\tPlase enter the password: ";
                cin>>password;
                if (password == 123456)
                {
                    cout<<"\t\tConnecting.."; Sleep(500); cout<<"."; cout<<"."; cout<<".!";
                    Sleep(1000);
                    system("cls");
                }
                else
                {
                    cout<<"\t\tInvaild Password.Please try again.\n";
                    cout<<"\t\tNumber of trials left: "<< 2 - pass_counter<<endl;
                    pass_counter++;
                    if(pass_counter == 3)
                    {
                        cout<<"\n\t\tUser-Login Restricted. Please contact technical staff.\n\n";
                        Sleep(5000);
                        exit(0);
                    }
                }
            }while(password != 123456 && pass_counter < 3);                        
        }
        else
        cout<<"\t\tNo such Employee exist. Please try again.\n\n";
    }while(employee_id!="A1Q123OZ");
}



void user_drivenmenu()
{
    int choice;
    char label;
    int sum=0;
    cout<<"\n\n";
    cout<<"\t\t\tHello! Alex.\n\t    Warm greeting from the GOOD-MART\n";
    do
    {
        cout<<"\t\t***************************"<<endl;
        cout<<"\t\t           MENU            "<<endl;
        cout<<"\t\t***************************"<<endl;        
        cout<<"\t\t1.Add Products\n";
        cout<<"\t\t2.Modify Products\n";
        cout<<"\t\t3.Generate Bill for Customer\n";
        cout<<"\t\t4.Display all Products\n";
        cout<<"\t\t5.Exit\n";
        cout<<"\t    Please Choose from the above options: ";
        cin>>choice;

        switch(choice)
        {
            case 1: //i++; //Product's list gets auto incremented
                    p[i].add_products();
                    cout<<"\t\tAdding...!";
                    Sleep(2000);
                    i++;
                    system("cls");
                    break;


            case 2: 
                    int srNo;
                    system("cls");
                    cout<<endl<<endl;
                    cout<<"\t\tEnter the SR.NO of the product to be Modified: ";
                    cin>>srNo;
                    p[srNo-1].mod_products(srNo);
                    cout<<"\n\tDo you want to return to the Main-menu?(Y/N) ";
                    cin>>label;
                    if(label == 'Y')
                    {
                        cout<<"\n\n";
                        system("cls");
                        break;
                    }                        
                    else
                        exit(0);
                    cout<<"\n\n\n\n";
                    break;


            case 3: system("cls");
                    generateBill();
                    cout<<"\n\n\n";
                    system("cls");
                    cout<<setw(280)<<"Welcome to the Good-Mart"<<endl<<endl; 
                    cout<<"\t\tDate and Time of Billing:\n\t\t"<<date_time<<endl<<endl;
                    cout<<setw(15)<<"\t\tSR.NO"<<"\t\t    Product Name"<<setw(25)<<"BatchID"<<setw(30)<<"   DateOfManufacturing"<<setw(20)<<"Quantity"<<setw(20)<<"Rate(in INR)"<<setw(20)<<"Price(in INR)"<<setw(10)<<endl;
                    for(int l=0;l<=k;l++)
                    {
                        z++;
                        displayBill(key[l],z);
                    }
                    
                    for(int l=0;l<=k;l++)
                    {
                        sum = sum + quantity[l]*p[key[l]].rate;                        
                    }
                    cout<<"\n\n\t\tTotal Price: "<<sum<<endl;
                    cout<<"\t\tTotal Number of items Purchased: "<<k+1;
                    cout<<endl<<endl;
                    cout<<setw(275)<<"Visit Us Soon!";
                    cout<<"\n\t\t------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
                    cout<<"\n\tDo you want to return to the Main-menu?(Y/N) ";
                    cin>>label;
                    if(label == 'Y')
                    {
                        cout<<"\n\n";
                        system("cls");
                        break;
                    }                        
                    else
                        exit(0);
                    cout<<"\n\n\n\n";                                                                                                                                               
                    break;

                    
            case 4: 
                    system("cls");
                    cout<<"The products available in the store are:\n";
                    cout<<setw(15)<<"SR.NO"<<"\t\t    Product Name"<<setw(25)<<"BatchID"<<setw(30)<<"DateOfManufacturing"<<setw(20)<<"Rate(in INR)"<<setw(10)<<endl;
                    for(i=0;i<proNum;i++)
                    {
                        p[i].display_productdetails();
                        j++;
                    }                    
                    cout<<"\nDo you want to return to the Main-menu?(Y/N) ";
                    cin>>label;
                    if(label == 'Y')
                    {
                        cout<<"\n\n";
                        system("cls");
                        break;
                    }                        
                    else
                        exit(0);
                    cout<<"\n\n\n\n";
                    break;


            case 5: exit(0);
                    break;
            default: cout<<"Out of choices.";
        }

    }while(choice!=0);

}




int main()
{  

    cout<<"\n\n\n\t\tCREATED BY: SIDDHARTH SINGH(20BBS0070)\n\n\n";
    Sleep(5000);

    //Initially we have 10 products
    p[0].batchid = "BC11256";
    p[0].dateofmanu = "08-01-2021";
    p[0].name = "Parle-G";
    p[0].rate = 25;
    p[1].batchid = "AD12506";
    p[1].dateofmanu = "16-01-2021";
    p[1].name = "Sun-Flakes";
    p[1].rate = 58;
    p[2].batchid = "AF10325";
    p[2].dateofmanu = "25-01-2021";
    p[2].name = "Lays-Blue(PartyPack)";
    p[2].rate = 40;
    p[3].batchid = "YK63785";
    p[3].dateofmanu = "12-02-2021";
    p[3].name = "Denim T-shirt(M)";
    p[3].rate = 500;
    p[4].batchid = "HJ16254";
    p[4].dateofmanu = "19-02-2021";
    p[4].name = "WaterBottle(500ml)";
    p[4].rate = 125;
    p[5].name = "H&S Shampoo(250ml)";
    p[5].batchid = "YZ61895";
    p[5].dateofmanu = "25-02-2021";
    p[5].rate = 150;
    p[6].name = "Sunflower Oil(1L)";
    p[6].batchid = "BY5621I";
    p[6].dateofmanu = "30-02-2021";
    p[6].rate = 150;
    p[7].name = "Basmati Rice(5Kg)";
    p[7].batchid = "LOL121U";
    p[7].dateofmanu = "28-02-2021";
    p[7].rate = 550;
    p[8].name = "Dettol HandWash(Soap)";
    p[8].batchid = "AIO123N";
    p[8].dateofmanu = "15-12-2020";
    p[8].rate = 50;
    p[9].name = "Cashew Nuts(500gm)";
    p[9].batchid = "SIO445M";
    p[9].dateofmanu = "30-03-2021";
    p[9].rate = 400;
    //To initilize the batchID array 
    batchIDArray(NULL);

    proNum = 10; //Initially we have total 10 products
    i = 10; //Initially we have total 10 products
    j = 1; 
    //Calling the function for user login.
    user_driven_login();

    //Calling the function for employee driven menu.
    user_drivenmenu();
}


