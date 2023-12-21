//OOPM_LibMgmtSys_V01
#include <bits/stdc++.h> 
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//Base Class - 1
class LibBook
{
    static int autoBNum;
    int bno;
	string bname;
	string aname;
	//int numOfBook;
	string statusOfBook;
	int personId_bookIssued;
  public:
    LibBook();
    void create_book();
    void show_book();
    int search_book(int sBook);
    int delete_book(int sBook);
    int modify_book(int sBook);
    void Issued_Book(int BookNo);
    int Return_Book();
};
//Base Class - 2
class Person
{
    static int autoPNum;
    int pno;
    string pname;
    string pcat;
    string pdept;
    int pYr;
    int pSem;
    int pBId;//BookId_IssuedToPerson
    string statusOfPerson;
  public:
    Person();
    void create_person();
    void show_person();
    int search_person(int sPerson);
    int delete_person(int sPerson);
    int modify_person(int sPerson);
    void Issued_Book(int PersonNo);
    void return_Book();
};
//Derived Class - 1
class JN: public LibBook, public Person
{
    LibBook JNCTBook[20];
    Person JNCTHR[20];
    int bookIndex=0;
    int PersonIndex=0;
    public:
        void BookMgmtSystem();
        void PersonMgmtSystem();
        void BookIssueSysetm();
        void BookReturnSystem();
        
};
int Person :: autoPNum=1;    
int LibBook :: autoBNum=1;

//---Function Related LIbBook Base Class-1 --------
    LibBook:: LibBook()
    {
        personId_bookIssued=0;
    }
	void LibBook:: create_book()
	{
	    bno = autoBNum++;
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nAuto book no. is :";
        cout<<bno;
        cout<<"\n\nEnter The Name of The Book ";
        getline(cin,bname);
        getline(cin,bname);
        cout<<"\n\nEnter The Author's Name ";
        getline(cin,aname);
        
        cout<<"\n\nEnter The Status of Book (Active/Deleted):";
        getline(cin,statusOfBook);
        //cout<<"\n\nEnter The Number of Book ";
        //cin>>numOfBook;
        cout<<"\n\n\nBook Created..";
    }
    void LibBook:: show_book()
    {
        if (statusOfBook != "Deleted"){
           
        cout<<setw(10)<<bno<<setw(25)<<bname<<setw(25)<<aname;
        //cout<<setw(10)<<numOfBook;
        cout<<setw(10)<<statusOfBook;
        cout<<setw(10)<<personId_bookIssued<<endl;}
    }
    int LibBook:: search_book(int sBook)
    {
        if ((sBook == bno) && (statusOfBook != "Deleted"))
        {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : "<<bname;
        cout<<"\nAuthor Name :"<<aname;
        cout<<"\nStatus Of Book:"<<statusOfBook;
        if(statusOfBook == "Issued") return(2);
        return (1);
        }
        else return (0);
    }
    int LibBook:: delete_book(int sBook)
    {
        if ((sBook == bno) && (statusOfBook != "Deleted"))
        {
        statusOfBook="Deleted";
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : "<<bname;
        cout<<"\nAuthor Name :"<<aname;
        cout<<"\nAuthor Name :"<<statusOfBook;
        cout<<endl;
        return (1);
        }
        else return (0);
    }
    int LibBook:: modify_book(int sBook)
    {
        if ((sBook == bno) && (statusOfBook != "Deleted"))
        {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nNEW BOOK ENTRY...\n";
        //cout<<"\nAuto book no. is :"<<bno;
        cout<<"Old book name is:"<<bname<<endl;
        cout<<"\nEnter The New Name of The Book ";
        getline(cin,bname);
        getline(cin,bname);
        cout<<"\nOld book Author name is:"<<aname;
        cout<<"\nEnter The New Author's Name ";
        getline(cin,aname);
        cout<<"\n\n\nBook Created..";
        cout<<endl;
        return (1);
        }
        else return (0);
    }
    void LibBook:: Issued_Book(int BookNo)
    {
        personId_bookIssued = BookNo;
        //cout<<"Book No"<<personId_bookIssued<<endl;
        statusOfBook = "Issued";
    }
    int LibBook:: Return_Book()
    {
       statusOfBook = "Active";    
       int pBid_temp = personId_bookIssued;
       personId_bookIssued = 0;           
       return (pBid_temp); 
    }
//-----------------------
//---Function Related Person Base Class-2 --------    Person::Person()
    {
        pBId=0;
    }
    void Person:: create_person()
	{
	    pno = autoPNum++;
        cout<<"\nNEW PERSON ENTRY...\n";
        cout<<"\nAuto PERSON no. is :";
        cout<<pno;
        cout<<"\n\nEnter The Name of The Person ";
        getline(cin,pname);
        getline(cin,pname);
        cout<<"\n\nEnter The Person's Category ";
        getline(cin,pcat);
        cout<<"\n\nEnter The Person's Dept ";
        getline(cin,pdept);
        cout<<"\n\nEnter The Status of Person (Active/Deleted):";
        getline(cin,statusOfPerson);
        cout<<"\n\nEnter The Person's Study Year ";
        cin>>pYr;
        cout<<"\n\nEnter The Person's Study Semester ";
        cin>>pSem;
        cout<<"\n\n\nPerson Created.."<<endl;
    }
    void Person:: show_person()
    {
        if (statusOfPerson != "Deleted"){
        cout<<setw(10)<<pno<<setw(20)<<pname<<setw(20)<<pcat;
        cout<<setw(10)<<pdept<<setw(5)<<pYr<<setw(5)<<pSem<<setw(15)<<statusOfPerson;
        cout<<setw(5)<<pBId<<endl;}
    }
    int Person:: search_person(int sPerson)
    {
        if ((sPerson == pno) && (statusOfPerson != "Deleted"))
        {
        cout<<"\nPerson no. : "<<pno;
        cout<<"\nPerson Name : "<<pname;
        cout<<"\nPerson Category :"<<pcat;
        cout<<"\nPerson Dept :"<<pdept;
        cout<<"\nPerson Study Yr :"<<pYr;
        cout<<"\nPerson Study Semester :"<<pSem;
        cout<<"\nPerson Status :"<<statusOfPerson;
        cout<<endl;
        if(pBId!=0) return (2);
        return (1);
        }
        else return (0);
    }
    int Person:: delete_person(int sPerson)
    {
        if ((sPerson == pno) && (statusOfPerson != "Deleted"))
        {
        statusOfPerson="Deleted";
        cout<<"\nPerson no. : "<<pno;
        cout<<"\nPerson Name : "<<pname;
        cout<<"\nPerson Category :"<<pcat;
        cout<<"\nPerson Dept :"<<pdept;
        cout<<"\nPerson Study Yr:"<<pYr;
        cout<<"\nPerson Study Sem :"<<pSem;
        cout<<"\nPerson Status :"<<statusOfPerson;
        cout<<endl;
        return (1);
        }
        else return (0);
    }
    int Person:: modify_person(int sPerson)
    {
        if ((sPerson == pno) && (statusOfPerson != "Deleted"))
        {
        cout<<"\nPerson no. : "<<pno;
        cout<<"\nModify Person ENTRY...\n";
        //cout<<"\nAuto Person no. is :"<<bno;
        cout<<"Old Person name is:"<<pname<<endl;
        cout<<"\nEnter The New Name of The Person ";
        getline(cin,pname);
        getline(cin,pname);
        cout<<"\nOld Person Category is:"<<pcat;
        cout<<"\nEnter The New Person's Category ";
        getline(cin,pcat);
        cout<<"\nOld Person Dept is:"<<pdept;
        cout<<"\nEnter The New Person's Dept ";
        getline(cin,pdept);
        cout<<"\nEnter The New Person's Study Year ";
        cin>>pYr;
        cout<<"\nEnter The New Person's Study Semester ";
        cin>>pSem;
        cout<<"\n\n\nPerson Detail Updated..";
        cout<<endl;
        return (1);
        }
        else return (0);
    }
    void Person:: Issued_Book(int PersonNo)
    {
        pBId = PersonNo;
    }
    void Person:: return_Book()
    {
        pBId = 0;
    }
//-----------------------
//---Function Related JN Derived Class-1 ----------
void JN:: BookMgmtSystem()
    {
        //LibBook JNCTBook[20];
        //int bookIndex=0;
        int BNum = 1;
        int LibBookMgmtCode;
        
        //int BookNo;
        do{
            cout << "Book Mgmt System Welcome to All" << endl;
            cout << "Menu Drive System.."<< endl;
            cout << "|---------------------|"<<endl;
            cout << "| 1. Create Book......|"<< endl;
            cout << "| 2. Delete Book......|"<< endl;
            cout << "| 3. Modify Book......|"<< endl;
            cout << "| 4. Search Book......|"<< endl;
            cout << "| 5. List All Book....|"<< endl;
            cout << "| 6. Exit.............|"<< endl;
            cout << "|---------------------|"<<endl;
            cout << "Enter Code:"; cin >> LibBookMgmtCode;
            switch(LibBookMgmtCode){
               case 1: cout<<"1. Create Book.."<< endl;
                        JNCTBook[bookIndex].create_book();
                        bookIndex++;
                        break;
                case 2: cout<<"2. Delete Book"<< endl;
                        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
                        else{
                        int BookNo;
                        cout<<"Enter Book Number to be deleted:";cin>>BookNo;
                        for(int k=0;k<bookIndex;k++)
                        {
                            if (JNCTBook[k].delete_book(BookNo)==1)
                            {
                                cout<<"Book has been deleted."<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 3: cout<<"3. Modify Book"<< endl;
                        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
                        else{
                        int BookNo;
                        cout<<"Enter Book Number:";cin>>BookNo;
                        for(int k=0;k<bookIndex;k++)
                        {
                            if (JNCTBook[k].modify_book(BookNo)==1)
                            {
                                cout<<"Book has been modified."<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 4: cout<<"4. Search Book by Book Number"<< endl;
                        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
                        else{
                        int BookNo;
                        cout<<"Enter Book Number:";cin>>BookNo;
                        for(int k=0;k<bookIndex;k++)
                        {
                            if (JNCTBook[k].search_book(BookNo)>=1)
                            {
                                cout<<"Found Book"<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 5: cout<<"5. List All Book.."<< endl;
                        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
                        else{
                        cout<<setw(10)<<"SNo"<<setw(25)<<"Book Name"<<setw(25)<<"Author Name";
                        //cout<<setw(10)<<"numOfBook"
                        cout<<setw(15)<<"statusOfBook"<<setw(10)<<"Issued To"<<endl;
                        //cout<<"SNo"<<" "<<"Book Name"<<" "<<"title"<<endl;
                        
                        for(int j=0;j<bookIndex;j++)
                            JNCTBook[j].show_book();
                        cout<<endl;
                        }
                        break; 
                case 6: cout<<"Closing Book Mgmt System..";break;
                default: cout<<"Error Code"<<endl;
            }
        }while(LibBookMgmtCode!=6);
        
    }
    void JN:: PersonMgmtSystem()
    {
        //Person JNCTHR[20];
        //int PersonIndex=0;
        int PNum = 1;
        int PerMgmtCode;
        int PersonIndexIndex=0;
        //int BookNo;
        do{
            cout << "Person Mgmt System Welcome to All" << endl;
            cout << "Menu Drive System.."<< endl;
            cout << "|-----------------------|"<<endl;
            cout << "| 1. Create Person......|"<< endl;
            cout << "| 2. Delete Person......|"<< endl;
            cout << "| 3. Modify Person......|"<< endl;
            cout << "| 4. Search Person......|"<< endl;
            cout << "| 5. List All Person....|"<< endl;
            cout << "| 6. Exit...............|"<< endl;
            cout << "|-----------------------|"<<endl;
            cout << "Enter Code:"; cin >> PerMgmtCode;
            switch(PerMgmtCode){
               case 1: cout<<"1. Create Person.."<< endl;
                        JNCTHR[PersonIndex].create_person();
                        PersonIndex++;
                        break;
                case 2: cout<<"2. Delete Person"<< endl;
                        if (PersonIndex==0) cout<<"Empty Person List.."<<endl<<endl;
                        else{
                        int PersonNo;
                        cout<<"Enter Person Number to be deleted:";cin>>PersonNo;
                        for(int k=0;k<PersonIndex;k++)
                        {
                            if (JNCTHR[k].delete_person(PersonNo)==1)
                            {
                                cout<<"Person has been deleted."<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 3: cout<<"3. Modify Person"<< endl;
                        if (PersonIndex==0) cout<<"Empty Person List.."<<endl<<endl;
                        else{
                        int PersonNo;
                        cout<<"Enter Person Number:";cin>>PersonNo;
                        for(int k=0;k<PersonIndex;k++)
                        {
                            if (JNCTHR[k].modify_person(PersonNo)==1)
                            {
                                cout<<"Person Details has been modified."<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 4: cout<<"4. Search Person by Person Id"<< endl;
                        if (PersonIndex==0) cout<<"Empty Person List.."<<endl<<endl;
                        else{
                        int PersonNo;
                        cout<<"Enter Person Number:";cin>>PersonNo;
                        for(int k=0;k<PersonIndex;k++)
                        {
                            if (JNCTHR[k].search_person(PersonNo)>=1)
                            {
                                cout<<"Found Person"<<endl<<endl;
                                break;
                            }
                            else cout<<"Not Found.."<<endl<<endl;
                        }
                        }
                        break;
                case 5: cout<<"5. List All Person.."<< endl;
                        if (PersonIndex==0) cout<<"Empty Person List.."<<endl<<endl;
                        else{
                        //cout<<setw(10)<<"PNo"<<setw(25)<<"Person Name"<<setw(25)<<"Person Cat";
                        //cout<<setw(10)<<"pdept"<<setw(15)<<"statusOfPerson"<<endl;
                        //cout<<"SNo"<<" "<<"Book Name"<<" "<<"title"<<endl;
                        cout<<setw(10)<<"pno"<<setw(20)<<"pname"<<setw(20)<<"pcat";
                        cout<<setw(10)<<"pdept"<<setw(5)<<"pYr"<<setw(5)<<"pSem"<<setw(15)<<"statusOfPerson";
                        cout<<setw(5)<<"pBId"<<endl;
                        for(int j=0;j<PersonIndex;j++)
                            JNCTHR[j].show_person();
                        cout<<endl;
                        }
                        break;
                case 6: cout<<"Closing Book Mgmt System.."<<endl;break;
                default: cout<<"Error Code"<<endl;
            }
        }while(PerMgmtCode!=6);
    }    
    void JN:: BookIssueSysetm()
    {
        int BookSearchStatus=0;
        int PersonReuestStatus=0;
        int BookNo;
        int PersonNo;
        int BookLoc;
        int PersonLoc;
        cout<<"Request for Issuing Book by Book Number"<< endl;
        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
        else{
            
            cout<<"Enter Book Number:";cin>>BookNo;
            for(int k=0;k<bookIndex;k++)
                {
                    BookSearchStatus = JNCTBook[k].search_book(BookNo);
                    if (BookSearchStatus==2)
                        {
                            cout<<"\nBook Found but Issued"<<endl<<endl;
                            break;
                        }
                    else if (BookSearchStatus==1)
                        {
                            cout<<"\nFound Book"<<endl<<endl;
                            BookLoc=k;
                            
                            //From Person
                            cout<<"Request for Book from Person by Person Id"<< endl;
                            if (PersonIndex==0) cout<<"Empty Person List.."<<endl<<endl;
                            else{
                            
                            cout<<"Enter Person Number:";cin>>PersonNo;
                            for(int k=0;k<PersonIndex;k++)
                            {
                                PersonReuestStatus = JNCTHR[k].search_person(PersonNo);
                                if (PersonReuestStatus==2)
                                {
                                    cout<<"\nPerson already have a Book"<<endl;
                                    cout<<"First Return Issued Book then Issue New Book"<<endl<<endl;
                                    break;
                                }
                                else if (PersonReuestStatus==1)
                                {
                                    cout<<"Found Person"<<endl<<endl;
                                    PersonLoc=k;
                                    break;
                                }
                                else cout<<"Not Found.."<<endl<<endl;
                                }
                            }
                            break;
                        }
                        else cout<<"\nNot Found.."<<endl<<endl;
                    }
        }
        
        
        if (BookSearchStatus == 1 && PersonReuestStatus == 1)
            {cout<<"Book Has been Issued Properly.."<<endl;
             JNCTHR[PersonLoc].Issued_Book(BookNo);
             JNCTBook[BookLoc].Issued_Book(PersonNo);}
             
        else
            if (BookSearchStatus > 2 )
                cout<<"Reqested Book is not Avilable in Library Database."<<endl;
            else 
                if (PersonReuestStatus > 2)
                    cout<<"Reqested Person is not Avilable in HR Database."<<endl;
    }    
    void JN:: BookReturnSystem()
    {
        int BookSearchStatus=0;
        int PersonReuestStatus=0;
        int BookNo;
        int PersonNo;
        int BookLoc;
        int PersonLoc;
        cout<<"Request for Returning Book by Book Number"<< endl;
        if (bookIndex==0) cout<<"Empty Book List.."<<endl<<endl;
        else{
            
            cout<<"Enter Book Number:";cin>>BookNo;
            for(int k=0;k<bookIndex;k++)
                {
                    BookSearchStatus = JNCTBook[k].Return_Book();
                    if (BookSearchStatus>0)
                        {
                            cout<<"\nBook Found Converted Issued to Active"<<endl<<endl;
                            
                            //From Person
                            JNCTHR[k].return_Book();
                            break;
                        }
                }
        }
    }
//-----Driver Function------
int main() {
        JN JNCT; 	
        int mainCode;
        do{
            cout << "JNCT Mgmt System Welcome to All" << endl;
            cout << "Menu Drive System.."<< endl;
            cout << "|-----------------------|"<<endl;
            cout << "| 1. Lib Mgmt System....|"<< endl;
            cout << "| 2. Person Mgmt System.|"<< endl;
            cout << "| 3. Book Issue.........|"<< endl;
            cout << "| 4. Book Return........|"<< endl;
            cout << "| 5. Exit...............|"<< endl;
            cout << "|-----------------------|"<<endl;
            cout << "Enter Code:"; cin >> mainCode;
            switch(mainCode){
                case 1: JNCT.BookMgmtSystem(); break;
                case 2: JNCT.PersonMgmtSystem();break;
                case 3: JNCT.BookIssueSysetm();break;
                case 4: JNCT.BookReturnSystem();break;
                case 5: cout<<"Closing Main Function.."<<endl;break;
                default: cout<<"Error Code..";cout<<endl;
            }
        }while(mainCode!=5);
    return 0;
}


