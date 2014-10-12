/* emreyo */
#include <iostream>
#include <string>
#include "Linkedlist.h"

using namespace std;

class item                                                 								//item class
{
      private:
              string name;
              char category_letter;
              int id;
              int bid_counter;
              int bid_price;
              int min_price;
      public:
             item();
             void add_item();
             char get_category(){return category_letter;}
             bool operator == (item item2){return (name == item2.name);}
             void update(int);
             int get(int);
             void update_counter(){bid_counter++;}
             void set_name(string cname){name=cname;}
             friend ostream& operator << (ostream&, item&);
};



                                                                                 //returns
int item::get(int control)
{                                                                                  //bid_counter for 1
    if(control == 1)                                                               //bid_price for 2
    		return bid_counter;                                                       //min_price for 3
    else if(control == 2)
         return bid_price;
    else if(control == 3)
         return min_price;  // if there's an error on this function, return 0; can be enough to get rid of that error.
}                           //no error on borland, but there's an error in dev-cpp


item::item()                                   //constructor to initialize data members bid_counter and bid_price to 0
{
            bid_counter = bid_price = 0;
}

ostream& operator << (ostream &print, item &current)            //overloaded << operator to print this values
{
         print << endl << "Name: " << current.name << endl << "Category: " << current.category_letter
            << endl << "Id: " << current.id << endl << "Bid Counter: " << current.bid_counter << endl
            << "Bid_price: " << current.bid_price << endl << "Min_price: " << current.min_price << endl;
   return print;
}

void item::add_item()                          //add_item() func to add item
{
     cout << "Enter name: ";
     cin >> name;

     do
     {
      cout << "Enter category: ";
      cin >> category_letter;
     
     
                                                 //if category_letter has a problem, loops until there's no problem
     }while(category_letter != 'B' && category_letter != 'E' && category_letter != 'M' && category_letter != 'V' &&
            category_letter != 'b' && category_letter != 'e' && category_letter != 'm' && category_letter != 'v');
     
     cout << "Enter Min_price: ";
     cin >> min_price;
     
     srand(time(0));                     //4-digit random number generation
     id = rand() % 10000;
     
     cout << endl << "Item inserted to category " << category_letter << " with id " << id << endl;

     if (id < 1000)                                   //if our 4-digit random number is less than 1000, I mean has 3-digit,
        cout << "0" << id << "..." << endl;           //put a 0 before that 3-digit when printing on the screen
}

void item::update(int up_bid_price)             //updates bid_price
{
     bid_price = up_bid_price;
}

Linkedlist <item> a[4];
main()
{

      int op_code;

      do                           //exit on 5, loop on the values smaller than 0, or bigger than 5
      {
          cout << "\n1 Add_item" << endl << "2 Bid" << endl << "3 List_items" << endl
           << "4 Search_item" << endl << "5 Exit" << endl << endl << "Select operation:";
           cin >> op_code;
      
          switch(op_code)                   //switch for adding, bidding, listing...
          {
          	case 1:                         //inserting
            {
            	item it;
               it.add_item();
					switch(it.get_category())   //category switch(to understand which LL of array to insert)
               {
               	case 'B':
                  case 'b':
                  	a[0].insertlast(it);
                     break;
                  case 'E':
                  case 'e':
                     a[1].insertlast(it);
                     break;
                  case 'M':
                  case 'm':
                     a[2].insertlast(it);
                     break;
                  case 'V':
                  case 'v':
                     a[3].insertlast(it);
                     break;
                }
             }
             break;

             case 2:                           //bidding
             {
             	int up_bp;
               item current_item;
     				string current_name;


     				cout << "Insert name: ";
     				cin >> current_name;

     				current_item.set_name(current_name);       //set name..

     				node <item> *p;

     				p = a[0].search(current_item);                    //loop until you find it..

     				if(p == NULL)
               	p = a[1].search(current_item);
     				if(p == NULL)
               	p = a[2].search(current_item);
     				if(p == NULL)
          			p = a[3].search(current_item);

     				cout << "Insert bid price:";
     				cin >> up_bp;
                  if(up_bp > p->info.get(3))
                  {
               		if(p->info.get(1) != 5)
                  	{
   	               	p->info.update(up_bp);
      	            	cout << "Accepted" << endl;
                     	p->info.update_counter();

                        if(p->info.get(1) == 5)
                        	cout << "Congratulations..You won..";
         	      	}
                  	else
                  		cout << "Sorry.. Not accepted" << endl;

                  }


            


            }break;
                         case 3:
                              {

      char category;
     cout << "Enter Category: ";
     cin >> category;
            switch(category)
            {
                            case 'B':
                                 cout << a[0];             //usage of overloaded << operators for printing the data members of a[]'s
                                 break;                    //															 a[0], a[1], a[2], and a[3]
                            case 'E':
                                 cout << a[1];
                                 break;
                            case 'M':
                                 cout << a[2];
                                 break;
                            case 'V':
                                 cout << a[3];
                                 break;
            }

                              }break;
                         case 4:
                              {

     item current;
     string cname;
     char ccategory;


               cout<<"Enter Name: ";
        	   cin>>cname;

            cout<<"Enter Category: ";
            cin>>ccategory;

            current.set_name(cname);

            node <item> *p;

            switch(ccategory)
            {
              	case 'B':
               	p = a[0].search(current);
               	cout << p->info;
               break;
                  case 'E':
               	p = a[1].search(current);
               	cout << p->info;
               break;
                  case 'M':
               	p = a[2].search(current);
               	cout << p->info;
               break;
                  case 'V':
               	p = a[3].search(current);
               	cout << p->info;
               break;


                              }

                              break;

          }
      }}while(op_code!=5 || op_code > 5 || op_code < 1);
}
