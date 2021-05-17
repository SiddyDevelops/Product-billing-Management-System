# Product-billing-Management-System
A small project, written in C++ language which involves the management of products in a department store and  generate bill for a customer.

This whole program is written in C++ language with various concepts of OOPS ranging from this pointer to the concepts of inheritance. The program involves the use of a BASE class called “product” and a derived class called “BillGenerate”. The base class comprises of various functions members for perform operations like adding, modifying and displaying the product details. These functions are declared in the base class and are defined out the class. The object (an Array of products) of base class is made global so that each product data, i.e. name, batch ID, date of manufacturing and price of product.
The employee of a supermarket store have to login through his employee ID and password (A1Q123OZ Pass: 123456) through which he/she will be redirected to Main Menu screen. Here he/she can either choose the operation he wants to on the products or generate bill for the customer. The bill generation happens through the batch Id, which is unique for each product. For this to happen smoothly the batch Id of all the products is stored in an array and a searching operation is helps the employee to search the product through batch Id and append it to the bill.


Outline of the Program:

```
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

class BillGenerate : public product

{

public:

void generateBill();

void displayBill(int h,int c);

};

void product::add_products()

{

}

void product::mod_products(int srNo)

{

}

void product::display_productdetails()

{
}

void user_driven_login()

{
}

void user_drivenmenu()

{
}

int main()

{
//Initially we have 10 products
}
```
