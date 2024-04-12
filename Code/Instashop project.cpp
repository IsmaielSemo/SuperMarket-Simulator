#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//this code is of a major project, led by me. The individual codes written by each of the members (Jana, Farouk, Mohammed, Mahmoud, and Nada) was modified and adjusted by me.

class User //By Jana Fadl and Farouk Elabd
{
private:
    struct Customer
    {
        string password;
        int id;
        string name;
        bool security_key;
        //int account_number;
        int phone_number;
        string address;
    };
    int cindex=0;
    struct Admin{
    	int id;
    	bool security_key;
    	string password;
	};
	int aindex = 0;
public:
    Customer list [100];
    Admin alist[100];
    int Initialize(){ //initializes customer file
	 	string n;
	 	int ind = 0;
	 	ifstream myFile;
	 	myFile.open("Customers.txt");
	 	while(myFile >> n){
	 		list[cindex].name = n;
	 		myFile >> list[cindex].password >> list[cindex].id >> list[cindex].phone_number >> list[cindex].address;
	 		cindex++;
		 }
		 myFile.close();
		 return cindex;
	 	
	 }
	 
	 void update(){ //updates Customer file
		ofstream myFile;
		myFile.open("Customers.txt");
		for(int i =0; i <cindex; i++){
			if(i == 0){
				myFile << list[i].name << " " << list[i].password << " " << list[i].id << " " << list[i].phone_number << " " << list[i].address;
			}
			else{
				myFile << endl << list[i].name << " " << list[i].password << " " << list[i].id <<  " " << list[i].phone_number << " " << list[i].address;
			}
		}
	}
	int Initialize1(){ //initialize admin file
	 	string n;
	 	int aindex = 0;
	 	ifstream myFile;
	 	myFile.open("Admin.txt");
	 	while(myFile >> n){
	 		alist[aindex].password = n;
	 		myFile >> alist[aindex].id; 
	 		aindex++;
		 }
		 myFile.close();
		 return aindex;
	 	
	 }	
	 void update1(){ //updates admin file
		ofstream myFile;
		myFile.open("Admin.txt");
		for(int i =0; i <aindex; i++){
			myFile << alist[i].password << " " << alist[i].id<<endl;
		}
	}
    
    User()
    {
    	cindex = Initialize();
    	aindex = Initialize1();
	}
	
	~User(){ // Deconstructor (runs at the end of the program)
		update();
		update1();
	}
    CreateC(string namee, string passwordd, int idd, int phonenumber, string addresss)
    {
        if(cindex == 100)
        	cout << "Max number of customers has been reached" << endl;
        else{
			list[cindex].name=namee;
	        list[cindex].password=passwordd;
	        list[cindex].id=idd;
	        list[cindex].security_key= false;
	        //list[cindex].account_number=accountnumber;
	        list[cindex].phone_number=phonenumber;
	    	list[cindex].address=addresss;
	        cindex++;
		}
    }
    
    CreateA(string passwordd, int idd){
    	if(aindex == 100)
    		cout << "Max number of admins has been reached" << endl;
    	else{
	    	alist[aindex].password = passwordd;
	    	alist[aindex].id = idd;
			alist[aindex].security_key = true; 
			aindex++;
		}
	}
    
    CheckIndexC(int id){
    	int i;
			for(int x =0; x < cindex; x++){
				if(id == list[x].id){
					i = x;
					return i;
				}
			}
			i=-1;
			return i;	
		}
		
		CheckIndexA(int id){
    	int i;
			for(int x =0; x < aindex; x++){
				if(id == alist[x].id){
					i = x;
					return i;
				}
			}
			i=-1;
			return i;	
		}
	

	
    bool CheckCredentialsCustomer(int idd, string passwordd)
    {
        for(int x =0; x<cindex ; x++){
			if (idd==list[x].id && passwordd==list[x].password)
	        {
	            //cout << "Login accepted" << endl;
				return true;
	        }
		}
	    //cout << "Login failed" << endl;
	    return false;
    }
    
    
    bool CheckCredentialsAdmin(int idd ,string passwordd)
    {
        for(int x =0; x<aindex ; x++){
			if (idd==alist[x].id && passwordd==alist[x].password)
	        {
	            cout << "Login accepted" << endl;
				return true;
	        }
			}
	        cout << "Login failed" << endl;
	        return false;
		}
    
    void Edit1(int id, string newname)
    {
        int p = CheckIndexC(id);
        if(p >= 0)
			list[p].name = newname;
		else
			cout << "Following ID doesn't exist" << endl;
        
    }
    
    void Edit2(int id, string newpassword)
    {
        int p = CheckIndexC(id);
        if(p >= 0)
        	list[p].password = newpassword;
        else
        	cout << "Following ID doesn't exist" << endl;
    }
    
    void Edit3(int id, int newphonenumber)
    {
        int p = CheckIndexC(id);
        if(p>=0)
			list[p].phone_number=newphonenumber;
        else
        	cout << "Following ID doesn't exist" << endl;
    }
    void Edit4(int id, string newaddress)
    {
        int p = CheckIndexC(id);
        if(p>=0)
			list[p].address = newaddress;
		else
			cout << "Following ID doesn't exist" << endl;
    
    }
    void DisplayCustDatabase() //originally it included admin id
    {
    	//int p = CheckIndexA(id);
    	//if(p>=0){
	        	for(int x =0; x<cindex; x++)
	        		cout << list[x].name << "\t" << list[x].id << "\t" << list[x].password <<"\t" << list[x].phone_number << "\t" << list[x].address << endl;
			}
		//}
		//else
			//cout << "Following admin doesn't exist" << endl;
    
    
    void DisplayAdminDatabase(){
    	for(int x =0; x<aindex; x++)
    		cout <<  alist[x].id << "\t" << alist[x].password << endl;
	}
    void DeleteUser(int id) //originally had admin ID as a second parameter (like displaydatabase)
    {
        if(cindex == 0)
	 		cout<< "No more users exist" << endl;
		else{
			//int z = CheckIndexA(aID);
			int p = CheckIndexC(id);
		 	if(p >= 0){
		 		list[p].name = "";
		 		list[p].id = 0;
		 		list[p].password = "";
		 		//list[p].account_number = 0;
		 		list[p].phone_number = 0;
		 		list[p].address = "";
		 		cindex--;
		 		if(p == cindex){
		 			for(int x =0; x< cindex; x++){
		 				list[x].name = list[x].name;
		 				list[x].id = list[x].id;
		 				list[x].password = list[x].password;
		 				//list[x].account_number = list[x].account_number;
		 				list[x].phone_number = list[x].phone_number;
		 				list[x].address = list[x].address;
					}
				 }
				else if (p == 0){
					for(int x =0; x< cindex; x++){
		 				list[x].name = list[x+1].name;
		 				list[x].id = list[x+1].id;
		 				list[x].password = list[x+1].password;
		 				//list[x].account_number = list[x+1].account_number;
		 				list[x].phone_number = list[x+1].phone_number;
		 				list[x].address = list[x+1].address;
					}
				}
				else{
					for(int x =0; x< cindex; x++){
		 				if(x < p){
		 					list[x].name = list[x].name;
		 					list[x].id = list[x].id;
		 					list[x].password = list[x].password;
		 					//list[x].account_number = list[x].account_number;
		 					list[x].phone_number = list[x].phone_number;
		 					list[x].address = list[x].address;
						 }
						else{
							list[x].name = list[x+1].name;
		 					list[x].id = list[x+1].id;
		 					list[x].password = list[x+1].password;
		 					//list[x].account_number = list[x+1].account_number;
		 					list[x].phone_number = list[x+1].phone_number;
		 					list[x].address = list[x+1].address;
						}
						
				}
				}
				
				}
			 
			else
				cout << "Following user doesn't exist" << endl;
			}
	}

};

class Product{ //By Ismaiel Sabet
	private:
		struct P{
			string Category;
			string ProductName;
			int ProductID;
			int Quantity;
			float Price;
		};
		
		
		int ind = 0;
		
	public:
		P product[1000];
		
		int Initialize(){
		 	string n;
		 	int ind = 0;
		 	ifstream myFile;
		 	myFile.open("Products.txt");
		 	while(myFile >> n){
		 		product[ind].Category = n;
		 		myFile >> product[ind].ProductName >> product[ind].ProductID >> product[ind].Quantity >> product[ind].Price;
		 		ind++;
			 }
			 myFile.close();
			 return ind;	
	 }
		void update(){
			ofstream myFile;
			myFile.open("Products.txt");
			for(int i =0; i <ind; i++){
				if(i == 0){
					myFile << product[i].Category << " " << product[i].ProductName << " " << product[i].ProductID << " " << product[i].Quantity << " "<< product[i].Price;
				}
				else{
					myFile << endl << product[i].Category << " " << product[i].ProductName << " " << product[i].ProductID << " " << product[i].Quantity << " " << product[i].Price;
				}
			}
		}
		
		Product(){
			ind = Initialize();
		}
		
		~Product(){
			update();
		}

		int CheckIndex(int pID) //checks the index of a product if it's ID is passed as a parameter
		{
			int i;
			for(int x =0; x < ind; x++){
				if(pID == product[x].ProductID){
					i = x;
					return i;
				}
			}
			i=-1;
			return i;	
		}
		
		int GetQuantity(int pID){
				return product[CheckIndex(pID)].Quantity;
		}
		
		void SetQuantity(int pID, int quan){
			product[pID].Quantity = quan;	
		}
		
		void SetQuantity2(int pID, int quan){
			product[pID].Quantity += quan;	
		}
		
		float GetPrice(int pID){
			return product[CheckIndex(pID)].Price;
		}
		
		 string GetName(int pID){
			 return product[CheckIndex(pID)].ProductName;
		}
		
		 string GetCategory(int pID){
			 return product[CheckIndex(pID)].Category;
		}
		
		
		int GetID(){
			return product[ind].ProductID;
		}
		SetQuantity1(int x, int quantity){ //for admin
			if(x<ind)
				product[x].Quantity = quantity;
		}
		int GetQuantity1(int x){
			if(x<ind)
				return product[x].Quantity;
			else
				return 0;
		}
		
		Add(string category, string productname, int productID, int quantity, float price){
			if(ind == 1000)
				cout << "Max number of products in the store has been reached" << endl;
			else{
				product[ind].Category = category;
				product[ind].ProductName = productname;
				product[ind].ProductID = productID;
				product[ind].Quantity = quantity;
				product[ind].Price = price;
				ind++;
			}
		}
		
		Remove(int id){
			int p = CheckIndex(id);
			if(p >= 0){
		 		product[p].Category = "";
		 		product[p].ProductName = "";
		 		product[p].ProductID = 0;
		 		product[p].Quantity = 0;
		 		product[p].Price = 0.0;
		 		ind--;
		 		if(p == ind){
		 			for(int x =0; x< ind; x++){
		 				product[x].Category = product[x].Category;
		 				product[x].ProductName = product[x].ProductName;
		 				product[x].ProductID = product[x].ProductID;
		 				product[x].Quantity = product[x].Quantity;
		 				product[x].Price = product[x].Price;
					}
				 }
				else if (p == 0){
					for(int x =0; x< ind; x++){
		 				product[x].Category = product[x+1].Category;
		 				product[x].ProductName = product[x+1].ProductName;
		 				product[x].ProductID = product[x+1].ProductID;
		 				product[x].Quantity = product[x+1].Quantity;
		 				product[x].Price = product[x+1].Price;
					}
				}
				else{
					for(int x =0; x< ind; x++){
		 				if(x < p){
		 					product[x].Category = product[x].Category;
		 					product[x].ProductName = product[x].ProductName;
		 					product[x].ProductID = product[x].ProductID;
		 					product[x].Quantity = product[x].Quantity;
		 					product[x].Price = product[x].Price;
						 }
						else{
							product[x].Category = product[x+1].Category;
		 					product[x].ProductName = product[x+1].ProductName;
		 					product[x].ProductID = product[x+1].ProductID;
		 					product[x].Quantity = product[x+1].Quantity;
		 					product[x].Price = product[x+1].Price;
						}
						
				}
				}
				
				}
			 
			else
				cout << "Following card doesn't exist" << endl;
		}
		Display(){ //displays info of Product
			for(int x = 0; x <ind; x++)
				cout << product[x].Category << "\t" << product[x].ProductName << "\t" << product[x].ProductID << "\t" << product[x].Quantity << " \t" << product[x].Price << endl;
		}
};

class Cart{ //By Mohammed Amer
	private:
		int Cid = 0;
		float total = 0;
		struct CartContent{
			string ProductCategory;
			string ProductName;
			int ProductID;
			int Quantity;
			float Price;
		};
		public:
			CartContent final[30]; //in order to create a Cart array
			
			Cart(){
				
			}
			
			void ResetTotal(){
				total = 0;
			}
			
			int CheckIndex(int id) //checks the index of a product in the cart if it's ID is passed as a parameter
			{
			int i;
			for(int x =0; x < Cid; x++){
				if(id == final[x].ProductID){
					i = x;
					return i;
				}
			}
			i=-1;
			return i;	
			}
			
			float GetTotal(){ //returns total price of cart
				if(Cid >0){
					for(int x =0; x <Cid; x++)
						total += (final[x].Price * final[x].Quantity);
					return total;
				}
			}
			
			AddtoCart(int id, int q, Product &a){ //adds product to cart
				if(Cid == 30) //if the cart is filled to the max, no more products will be added
					cout << "Cart is full" << endl; 
				else{
					int p = a.CheckIndex(id); //we must check if said product even exists in the Product array (we do that by passing Id or Name)
					if(p >= 0){ //if Product exists
					 	int size = a.GetQuantity(id)-q; //gets the difference between the quantity desired and the already existing quantity
					 	if(size >= 0){
					 		a.SetQuantity(p,size);
							int j = CheckIndex(id); //checks if the product we want to add already exists in final or no
							if(j >= 0){
								final[j].Quantity += q; //increases quantity of object in already existing index in final
							}
							else{
								//adds to new index in final array
								final[Cid].ProductCategory = a.GetCategory(id);
								final[Cid].ProductName = a.GetName(id);
								final[Cid].ProductID = id;
								final[Cid].Quantity = q;
								final[Cid].Price = a.GetPrice(id);
								Cid++;
							}
						 }
						else
						 	cout << "The quantity you want to add to the cart is greater than the amount in the store" << endl;
					 	
				}
					else
						cout << "The product of said ID doesn't exist in the store" << endl;
					
			}
		}
			
		
			RemoveFromCart(int id, int q, Product &a){ //removes product from cart
				if(Cid == 0)
					cout << "Cart is empty" << endl;
				else{
					int p = a.CheckIndex(id); //checks if product exists
					if(p >= 0){
						int j = CheckIndex(id); //checks if product exists in cart
						if(j >= 0){
							int size = final[j].Quantity - q;
							if(q == final[j].Quantity){
								final[j].ProductCategory = "";
								final[j].ProductName = "";
								final[j].ProductID = 0;
								final[j].Quantity = 0;
								final[j].Price = 0.0;
								Cid--;
								if(j == Cid){
		 							for(int x =0; x< Cid; x++){
		 								final[x].ProductCategory= final[x].ProductCategory; 
										final[x].ProductName= final[x].ProductName; 
										final[x].ProductID= final[x].ProductID;
										final[x].Quantity = final[x].Quantity;
										final[x].Price = final[x].Price;
									}
				 }
								else if (j == 0){
									for(int x =0; x< Cid; x++){
		 								final[x].ProductCategory= final[x+1].ProductCategory ; 
										final[x].ProductName= final[x+1].ProductName ; 
										final[x].ProductID= final[x+1].ProductID;
										final[x].Quantity = final[x+1].Quantity;
										final[x].Price = final[x+1].Price;
								}
				}
								else{
									for(int x =0; x< Cid; x++){
		 								if(x < j){
		 									final[x].ProductCategory= final[x].ProductCategory; 
											final[x].ProductName= final[x].ProductName; 
											final[x].ProductID= final[x].ProductID;
											final[x].Quantity = final[x].Quantity;
											final[x].Price = final[x].Price;
						 			}
										else{
											final[x].ProductCategory= final[x+1].ProductCategory ; 
											final[x].ProductName= final[x+1].ProductName ; 
											final[x].ProductID= final[x+1].ProductID;
											final[x].Quantity = final[x+1].Quantity;
											final[x].Price = final[x+1].Price;
									}
						
								}		
			}
							
							a.SetQuantity2(p,q);
								
						}
						else if(q < final[j].Quantity){
							final[j].Quantity -= q;
							a.SetQuantity2(p,q); 
						}
						else if(q > final[j].Quantity)
							cout << "You can't remove quantity greater than the amount in the cart" << endl;
						
					}
						else
							cout << "Product doesn't exist in the cart" << endl;
				
				}
				else
						cout << "Product doesn't exist in the store" << endl;
			}
		}
			
			
			DisplayCart(){ //displays cart and total price of cart
				for(int x = 0; x<Cid; x++)
					cout << final[x].ProductCategory << "\t" << final[x].ProductName << "\t" << final[x].ProductID << "\t" << final[x].Quantity << "\t" << final[x].Price << endl;
				cout << "Your total is : " << GetTotal() << endl;
				ResetTotal();
			}
			
			ResetCart(){
				for (int i=0;i<Cid;i++){
					final[i].ProductCategory = final[Cid].ProductCategory;
					final[i].ProductName= final[Cid].ProductName; 
					final[i].ProductID= final[Cid].ProductID;
					final[i].Quantity = final[Cid].Quantity;
					final[i].Price = final[Cid].Price;
			}
			Cid = 0;
		}
			

};

class wallet{ //By Mahmoud H. El Ganainy and Nada Minisy
	private:
	int ind = 0;	
	struct Card{
		int number;
		int funds;
		string name;
	};
	
Card CC[1000]; //array of cards so that each user can have multiple cards
int cash=0;
 public:
 	
	 int Initialize(){ //creates wallet/credit card file;
	 	int Acc;
	 	int ind = 0;
	 	ifstream myFile;
	 	myFile.open("CreditCards.txt");
	 	while(myFile >> Acc){
	 		CC[ind].number = Acc;
	 		myFile >> CC[ind].funds >> CC[ind].name;
	 		ind++;
		 }
		 myFile.close();
		 return ind;
	 	
	 }
	 
	void update(){ //updates wallet/credit card file
		ofstream myFile;
		myFile.open("CreditCards.txt");
		for(int i =0; i <ind; i++){
			if(i == 0){
				myFile << CC[i].number << " " << CC[i].funds << " " << CC[i].name;
			}
			else{
				myFile << endl << CC[i].number << " " << CC[i].funds << " " << CC[i].name;
			}
		}
	}
	 wallet(){
 		ind = Initialize();
	 }
	 
	 ~wallet(){ //run at the end of the program (it is a destructor)
	 	update();
	 }
	 CheckIndex(string name){
	 	int i;
			for(int x =0; x < ind; x++){
				if(name == CC[x].name){
					i = x;
					return i;
				}
			}
			i=-1;
			return i;	
		}
	
	int GetCash(){
		return cash;
	}
 	AddCard(int numb, int f, string nname){ //adds a card to the array
 		if(ind == 1000)
		 	cout << "Max number of credit cards has been reached" << endl;
		 else{
			CC[ind].number=numb; CC[ind].funds=f; CC[ind].name=nname;
 			ind++;
 		}
	 }
	 
	 RemoveCard(string name){
	 	
	 	if(ind == 0)
	 		cout<< "No credit cards exist" << endl;
		else{
			int p = CheckIndex(name);
		 	if(p >= 0){
		 		CC[p].number = 0;
		 		CC[p].funds = 0;
		 		CC[p].name = "";
		 		ind--;
		 		if(p == ind){
		 			for(int x =0; x< ind; x++){
		 				CC[x].number= CC[x].number; 
						CC[x].funds= CC[x].funds; 
						CC[x].name= CC[x].name;
					}
				 }
				else if (p == 0){
					for(int x =0; x< ind; x++){
		 				CC[x].number= CC[x+1].number ; 
						CC[x].funds= CC[x+1].funds ; 
						CC[x].name= CC[x+1].name;
					}
				}
				else{
					for(int x =0; x< ind; x++){
		 				if(x < p){
		 					CC[x].number= CC[x].number; 
							CC[x].funds= CC[x].funds; 
							CC[x].name= CC[x].name;
						 }
						else{
							CC[x].number= CC[x+1].number ; 
							CC[x].funds= CC[x+1].funds ; 
							CC[x].name= CC[x+1].name;
						}
						
				}
				}
				
				}
			 
			else
				cout << "Following card doesn't exist" << endl;
			}
		}
	 
 	IncreaseCash(int x){ //adds cash to wallet
 			cash = cash + x;
		 } 
	IncreaseCard(string CardName, int c){ //adds money to a card
		 	int p = CheckIndex(CardName); 
		 	if(p>=0){
		 		CC[p].funds= CC[p].funds + c;
			 }
			 else{
			 	cout << "Following card doesn't exist" << endl;
			 }
		 }
	
	Displayfunds(){ //displays all funds
		 	cout << "Cash = " << cash << endl;
		 	for (int i = 0; i<ind; i++){
		 		cout << "Card " << i << " = " << CC[i].funds << endl;
			 }
		}
	Displaycash() //displays cash only
			 {
			 	cout << "Cash = " << cash << endl;
			 }
	Displayfundscard(){ //displays all credit cards' funds
			for (int l = 0; l<ind; l++){
		 		cout << "Card " << l << " = " << CC[l].funds << endl;
			 }
		}
	Displayfundscard(string name){
			 	int p = CheckIndex(name);
			 	if(p>= 0){
			 		cout << "Card funds = " << CC[p].funds << endl;
				 }
				 else{
				 	cout << "Card doesn't exist" << endl;
				 }
		}
		 
 	Paymentcard(string name, Cart &a){ //pays with a credit card
 			 int p = CheckIndex(name);
 			 if(p>=0){
 			 	if (CC[p].funds >= a.GetTotal()){
 					cout << "Transaction completed" << endl;
 					CC[p].funds = CC[p].funds - a.GetTotal();
 					a.ResetCart();
			  }
			 	else {
			 		cout << "Transaction failed" << endl;
			 	}
		}
			  else
			  	cout << "Card doesn't exist" << endl;
			 
			}
		
	Paymentcash(Cart &a){ //pays with cash
 			if (cash >= a.GetTotal()){
 				cout << "Transaction completed" << endl ;
				cash = cash - a.GetTotal();
				a.ResetCart();
				}
 				 else{
			 	cout << "Transaction failed" << endl;
			 }
 		}
	 };
	 
int main(){
	char answer;
	int productid;
	int quantity;
	string cardname;
	int cardnumber;
	float funds;
	int amount;
	string pcat;
	string pname;
	int pquan;
	float pprice;
	int id;
	string password; 
	int a;
	string name;
	int phone;
	string address;
	wallet w1;
	User u1;
	Product p1;
	Cart c1;
	do{
	do{
		cout << "Welcome to Instashop, Please select one of the following: \n 1)Log-in \n 2)Sign-up" << endl;
		cin >> a;
		if(a == 1){
			cout << "Would you like to log in as Customer (1) or Admin (2)?" << endl;
			cin >> a;
			if(a ==1){
				cout << "Enter your id and password : " << endl;
				cin >> id;
				cin >> password;
				if(u1.CheckCredentialsCustomer(id,password) == true){
					cout << "Credentials accepted!" << endl;
					do{
					cout << "What operation would you like to carry out: \n 1) Edit User Info \n 2) Display Store \n 3)Check Wallet " << endl;
					cin >> a;
					if(a == 1){
						cout << "What would you like to edit: \n 1) Name \n 2) Password \n 3) Phone Number \n 4) Address" << endl;
						cin >> a;
						if(a == 1){
							cout << "Enter new name: " << endl;
							cin >> name;
							u1.Edit1(id,name);
						}
						else if(a == 2){
							cout << "Enter new password: " << endl;
							cin >> password;
							u1.Edit2(id, password);
						}
						else if(a == 3){
							cout << "Enter new phone number: " << endl;
							cin >> phone;
							u1.Edit3(id,phone);
						}
						else if(a == 4){
							cout << "Enter new address: " << endl;
							cin >>address;
							u1.Edit4(id,address);
						}
						else{
							cout << "Invalid input" << endl;
						}
					}
					else if(a == 2){
						p1.Display();
						cout << "What would you like to do : \n 1) Add Product to Cart \n 2) Remove Product from Cart \n 3) Display Cart" << endl;
						cin >> a;
						if(a == 1){
							cout << "Enter id of product you want to add to Cart and how much from that product : " << endl;
							cin >> productid;
							cin >> quantity;
							c1.AddtoCart(productid, quantity,p1);
						}
						else if(a == 2){
							cout << "Enter id of product you want to remove from Cart and how much from that product : " << endl;
							cin >> productid;
							cin >> quantity;
							c1.RemoveFromCart(productid, quantity,p1);
						}
						else if(a == 3){
							c1.DisplayCart();
						}
						else{
							cout << "Invalid input" << endl;
						}
					}
					else if(a == 3){
						c1.DisplayCart();
						cout << "What would you like to do : \n 1) View Cash \n 2) View All Credit Cards \n 3) View A Specific Credit Card \n 4) Add A Credit Card \n 5) Remove A Credit Card \n 6) Increase Cash \n 7) Increase Funds in Card" << endl;
						cin >> a;
						if(a == 1){
							cout <<w1.GetCash() << endl;
						}
						else if(a == 2){
							w1.Displayfundscard();
						}
						else if(a == 3){
							cout << "Enter the name of the card : " << endl;
							cin >> cardname;
							w1.Displayfundscard(cardname);
						}
						else if(a == 4){
							cout << "Please enter a credit card number, amount of funds, and credit card name : " <<endl;
							cin >> cardnumber;
							cin >> funds;
							cin >> cardname;
							w1.AddCard(cardnumber, funds, cardname);
						}
						else if(a == 5){
							cout << "Enter name of card you want to remove : " << endl;
							cin >> cardname;
							w1.RemoveCard(cardname);
						}
						else if(a == 6){
							cout << "Enter amount of cash that you want to add : " << endl;
							cin >> amount;
							w1.IncreaseCash(amount);
						}
						else if(a == 7){
							cout << "Enter name of card and amount of funds you want to add : " << endl;
							cin >> cardname;
							cin >> funds;
							w1.IncreaseCard(cardname,funds);
						}
						else{
							cout << "Invalid input" << endl;
						}
					}
					else{
						cout << "Invalid input" << endl;
					}
					cout << "Do you want to continue customer operations Y/N ?" << endl;
					cin >> answer;
				}while(answer == 'Y' || answer == 'y');
			}
				else{
					cout << "Incorrect Credentials" << endl;
				}
			}
			else if(a == 2){
				cout << "Enter your id and password : " << endl;
				cin >> id;
				cin >> password;
				if(u1.CheckCredentialsAdmin(id,password) == true){
					cout << "Credentials accepted!" << endl;
					do{
					cout << "What operation would you like to do: \n 1) Show Customer Database \n 2) Delete Customer \n 3) Add New Product \n 4) Remove Product" << endl;
					cin >>a;
					if(a == 1){
						u1.DisplayCustDatabase();
					}
					else if(a == 2){
						cout << "Enter id of the customer you want to delete : " << endl;
						cin >> id;
						u1.DeleteUser(id);
					}
					else if(a == 3){
						cout << "Enter the following : \n 1) Product Category \n 2) Product Name \n 3) Product ID \n 4) Quantity \n 5) Price" << endl;
						cin >> pcat;
						cin >> pname;
						cin >> productid;
						cin >> pquan;
						cin >> pprice;
						p1.Add(pcat,pname,productid,pquan,pprice);
					}
					else if(a == 4){
						cout << "Enter ID of product that you want to remove : " << endl;
						cin >> productid;
						p1.Remove(productid);
					}
					else{
						cout << "Invalid input" << endl;
					}
					cout << "Do you want to continue as Admin Y/N?" << endl;
					cin >> answer;
				}while(answer == 'Y' || answer == 'y');
				}
				else{
					cout << "Incorrect Credentials" << endl;
				}
			}
			else{
				cout << "Invalid input" << endl;
			}
		}
		else if(a == 2){
			cout << "Do you want to create a Customer account (1), an Admin account (2)" << endl;
			cin >> a;
			if(a == 1){
				cout << "Enter the following (in this order): \n Name \n Password \n Id \n Phone Number \n Address" << endl;
				cin >> name;
				cin >> password;
				cin >> id;
				cin >> phone;
				cin >> address;
				u1.CreateC(name, password, id, phone, address);
			}
			else if(a == 2){
				cout << "Enter the following (in this order)): \n Password \n Id " << endl;
				cin >> password;
				cin >> id;
				u1.CreateA(password,id);
			}
			else{
				cout << "Invalid input" << endl;
			}
		}
		else{
			cout << "Invalid input" << endl;
		}
		cout << "Do you want to continue Y/N ? ";
		cin >> answer;
		if(answer!='y' && answer!='Y')
		{
			cout << "Would you to like pay cash (1) or credit (2) ?" << endl;
							cin >> a;
							if(a == 1){
								w1.Paymentcash(c1);
							}
							else if(a == 2){
								cout << "Enter the name of the card you want to pay with :" << endl;
								cin >> cardname;
								w1.Paymentcard(cardname,c1);
							}
							else{
								cout << "Invalid input" << endl;
							}
		}
	}while(answer == 'Y' || answer == 'y');
	cout << "Do you want to exit Instashop Y/N ?" << endl;
	cin >> answer;
}while(answer !='Y' && answer != 'y');
	
	cout << "Thank you for using Instashop!" << endl;

	
}

