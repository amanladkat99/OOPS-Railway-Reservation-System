/*
Railway Reservation System
OOPS CP TY BTECH

Aman Ladkat K 45
Sampada Petkar K 62
Sagar Potnis K 63
Aditya Wyawhare K 84

@VIT, Pune, India
*/
#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct trains
{
    int tr_no;
    char train_name[50];
    char start[30];
    char destiantion[30];
    int charge;
    int time_h;
    int time_m;
    trains *next;
};

struct node
{
    int priority;
    char name[50];
    int age;
    char gender;
    int num_of_seats;
    int train_num;
    float charges;
    struct node *next;
}*head=NULL;

class base_class{
public:

	int p1=0,p2=0,p3=0,p4=0,waiting=0;
    friend trains;

};

class moderator: public base_class
{
private:
    trains *head,*tail;
public:
    moderator()
    {
        head = NULL;
        tail = NULL;
    }

    void add_trains();
    void add_trains(int a, char *t, char *s, char *d, int c, int h, int m);

    void delete_train(int no);
    void deleteTrains(struct trains *head_ref, int position);
    trains* gethead()
    {
        return head;
    }

    static void display(trains *head);
};

class passenger : public base_class{
public:
    void registration();
    void registration_cancel();
    int deleten(char name[]);
    int priority(struct node *new_node);
    void insert(struct node *);
    void priorityd(struct node *new_node);
    void viewdetails();
    void charge(struct node *);
    void display();
    void status_display();
    void printticket(node *);
    void specifictrain(int);

};

void passenger :: registration()
{

    cout<<"\n\n\n\t\t\t**********************************";
    cout<<"\n\n\t\t\t\t  REGISTRATION MENU";
    cout<<"\n\n\t\t\t**********************************";
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    cout<<"\n\n\t\t\t    Enter the Name :- ";
    cin>>new_node->name;
    cout<<"\n\t\t\t    Enter the Age :- ";
    cin>>new_node->age;
    cout<<"\n\t\t\t    Enter the Gender (M/F) :- ";
    cin>>new_node->gender;
    cout<<"\n\t\t\t*********************************";
    new_node->priority=priority(new_node);
    if(new_node->priority==0)
    {
        cout<<"\n\n\t\t\t\tREGISTATION UNSUCCESSFUL";
        return;
    }

	{

		cout<<"\n-------------------------------------------------------------------------------------------------";
		cout<<"\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n";
		cout<<"-------------------------------------------------------------------------------------------------";
		cout<<"\n1001\tBanglore Rajdhani Express\tNew Delhi To Banglore\t\tRs.4500\t\t9am";
		cout<<"\n1002\tChennai Express\t\t\tMumbai To Chennai\t\tRs.3200\t\t12pm";
		cout<<"\n1003\tDehradun Shatabdi Express\tNew Delhi To Dehradun\t\tRs.2500\t\t4.30am";
		cout<<"\n1004\tDuronto Express\t\t\tJaipur To Mumbai\t\tRs.4000\t\t10.45pm";
		cout<<"\n1005\tPatna Express\t\t\tNew Delhi To Patna\t\tRs.2700\t\t7am";
		cout<<"\n1006\tJan Shatabdi Express\t\tMumbai To Aurangabad\t\tRs.1800\t\t2.30pm";
	    cout<<"\n1007\tMumbai Rajdhani Express\t\tNew Delhi To Mumbai\t\tRs.5500\t\t1.35am";
	    cout<<"\n1008\tPuri Surat Express\t\tPuri To Surat\t\t\tRs.2000\t\t4pm";
	    cout<<"\n1009\tTrivandrum Express\t\tChennai To Trivandrum\t\tRs.4900\t\t6.25am";
	    cout<<"\n1010\tKolkata Express\t\t\tMumbai To Kolkata\t\tRs.5000\t\t8.15pm";

	}
	cout<<"\n\tEnter train number ";
	cin>>new_node->train_num;
	if (new_node->train_num==1001)
	{
		cout<<"\nTrain:\t\t\tBanglore Rajdhani Express";
		cout<<"\nDestination:\t\tNew Delhi To Banglore";
		cout<<"\nDeparture:\t\t9am ";
	}
	if (new_node->train_num==1002)
	{
		cout<<"\nTrain:\t\t\tChennai Express";
		cout<<"\nDestination:\t\tMumbai To Chennai";
		cout<<"\nDeparture:\t\t12pm";
	}
	if (new_node->train_num==1003)
	{
		cout<<"\nTrain:\t\t\tDehradun Shatabdi Express";
		cout<<"\nDestination:\t\tNew Delhi To Dehradun";
		cout<<"\nDeparture:\t\t4.30am";
	}
	if (new_node->train_num==1004)
	{
		cout<<"\nTrain:\t\t\tDuronto Express";
		cout<<"\nDestination:\t\tJaipur To Mumbai";
		cout<<"\nDeparture:\t\t10.45pm ";
	}
	if (new_node->train_num==1005)
	{
		cout<<"\nTrain:\t\t\tPatna Express";
		cout<<"\nDestination:\t\tNew Delhi To Patna";
		cout<<"\nDeparture:\t\t7am";
	}
	if (new_node->train_num==1006)
	{
		cout<<"\ntrain:\t\t\tJan Shatabdi Express";
		cout<<"\nDestination:\t\tMumbai To Aurangabad";
		cout<<"\nDeparture:\t\t2.30pm ";
	}
	if (new_node->train_num==1007)
	{
		cout<<"\ntrain:\t\t\tMumbai Rajdhani Express";
		cout<<"\nDestination:\t\tNew Delhi To Mumbai";
		cout<<"\nDeparture:\t\t1.35am ";
	}
	if (new_node->train_num==1008)
	{
		cout<<"\ntrain:\t\t\tPuri Surat Express";
		cout<<"\n Destination:\t\tPuri To Surat";
		cout<<"\nDeparture:\t\t4pm ";
	}
	if (new_node->train_num==1009)
	{
		cout<<"\ntrain:\t\t\tTrivandrum Express";
		cout<<"\nDestination:\t\tChennai To Trivandrum";
		cout<<"\nDeparture:\t\t6.25am ";
	}
	if (new_node->train_num==1010)
	{
		cout<<"\ntrain:\t\t\tKolkata Express";
		cout<<"\nDestination:\t\tMumbai To Kolkata";
		cout<<"\nDeparture:\t\t8.15pm";
	}
	cout<<"\nEnter number of seats ";
	cin>>new_node->num_of_seats;
	charge(new_node);
    insert(new_node);
    cout<<"\n\n\t\t\t\tREGISTATION SUCCESSFUL";

}

void passenger :: registration_cancel()
{
	cout<<"\n\n\n\t\t\t**********************************"<<endl;
    cout<<"\n\n\t\t\t  REGISTRATION CANCELLATION MENU"<<endl;
    cout<<"\n\n\t\t\t**********************************"<<endl;
    char name[50];
    int age;
    cout<<"\n\n\t\t\t    Enter the Name :- ";
    cin>>name;
    cout<<"\n\t\t\t    Enter the age :- ";
    cin>>age;
    cout<<"\n\t\t\t**********************************"<<endl;
    int x=deleten(name);
	if(x==1)
    cout<<"\n\n\t\t\t\tREGISTRATION CANCELLED"<<endl;
	else
	cout<<"\n\t\t\t\tNo such entry found\n"<<endl;
}

int passenger :: deleten(char name[])
{
	int o;
    struct node *temp,*p;
    temp=head;
    if(head == NULL)
    {
        cout<<"\n\n\t\t\tNO REGISTRATIONS YET"<<endl;
        return 0;
    }
    o=strcmp(name,temp->name);
    if(!o)
    {
        p=temp;
        temp=temp->next;
        head=temp;
        priorityd(p);
        free(p);
        return 1;
    }
    while(temp->next!=NULL)
    {
        o=strcmp(temp->next->name,name);
        if(!o)
        {
            p=temp;
            temp=temp->next;
            p->next=temp->next;
            priorityd(temp);
            free(temp);
            return 1;
        }
	  	temp=temp->next;
    }
	if(o)
		return 0;
	else return 1;
}

int passenger :: priority(struct node *new_node)
{
	int priority;
    if(new_node->age>=50&&(new_node->gender=='f'||new_node->gender=='F')&&p1<3)
    {
        priority=1;
        p1++;
    }
    else if(new_node->age>=50&&p2<3)
    {
        priority=2;
        p2++;
    }
    else if((new_node->gender=='f'||new_node->gender=='F')&&p3<3)
    {
        priority=3;
        p3++;
    }
    else if(p4<3)
    {
        priority=4;
        p4++;
    }
    else
    {
       cout<<"\nTrain is already full so you have to wait in the waiting list\n"<<endl;
       waiting++;
       cout<<" your waiting number is: "<<waiting<<endl;
       return 0;
    }
    return priority;
}

void passenger :: insert(struct node *new_node)
{
	if(head==NULL)
    {
       head=new_node;
       new_node->next=NULL;
       return;
    }
    struct node *tmp;
    tmp=head;
    if(tmp->priority>new_node->priority)
    {
        new_node->next=tmp;
        head=new_node;
        return;
    }
    while(tmp->next!=0)
    {
       if(tmp->next->priority > new_node->priority)
       {
            new_node->next=tmp->next;
            tmp->next=new_node;
            return;
       }
	tmp=tmp->next;
    }
    new_node->next=tmp->next;
    tmp->next=new_node;
}

void passenger :: priorityd(struct node *new_node)
{
	if(new_node->age>=50&&(new_node->gender=='f'||new_node->gender=='F'))
    {
       	p1--;
    }
    else if(new_node->age>=50)
    {
    	p2--;
    }
    else if((new_node->gender=='f'||new_node->gender=='F'))
    {
    	p3--;
    }
	else if(p4<3)
    {
       p4--;
    }
    if(waiting>0)
        waiting--;
}

void passenger :: viewdetails()
{
	cout<<"\n-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------";
	cout<<"\n1001\tBanglore Rajdhani Express\tNew Delhi To Banglore\t\tRs.4500\t\t9am"<<endl;
	cout<<"\n1002\tChennai Express\t\t\tMumbai To Chennai\t\tRs.3200\t\t12pm"<<endl;
	cout<<"\n1003\tDehradun Shatabdi Express\tNew Delhi To Dehradun\t\tRs.2500\t\t4.30am"<<endl;
	cout<<"\n1004\tDuronto Express\t\t\tJaipur To Mumbai\t\tRs.4000\t\t10.45pm"<<endl;
	cout<<"\n1005\tPatna Express\t\t\tNew Delhi To Patna\t\tRs.2700\t\t7am"<<endl;
	cout<<"\n1006\tJan Shatabdi Express\t\tMumbai To Aurangabad\t\tRs.1800\t\t2.30pm"<<endl;
    cout<<"\n1007\tMumbai Rajdhani Express\t\tNew Delhi To Mumbai\t\tRs.5500\t\t1.35am"<<endl;
    cout<<"\n1008\tPuri Surat Express\t\tPuri To Surat\t\t\tRs.2000\t\t4pm"<<endl;
    cout<<"\n1009\tTrivandrum Express\t\tChennai To Trivandrum\t\tRs.4900\t\t6.25am"<<endl;
    cout<<"\n1010\tKolkata Express\t\t\tMumbai To Kolkata\t\tRs.5000\t\t8.15pm"<<endl;
}

void passenger :: charge(struct node *head)
{
	if (head->train_num==1001)
	{
		head->charges=4500*head->num_of_seats;
	}
	if (head->train_num==1002)
	{
		head->charges=3200*head->num_of_seats;
	}
	if (head->train_num==1003)
	{
		head->charges=2500*head->num_of_seats;
	}
	if (head->train_num==1004)
	{
		head->charges=4000*head->num_of_seats;
	}
	if (head->train_num==1005)
	{
		head->charges=2700*head->num_of_seats;
	}
	if (head->train_num==1006)
	{
		head->charges=1800*head->num_of_seats;
	}
	if (head->train_num==1007)
	{
		head->charges=5500*head->num_of_seats;
	}
	if (head->train_num==1008)
	{
		head->charges=2000*head->num_of_seats;
	}
	if (head->train_num==1009)
	{
		head->charges=4900*head->num_of_seats;
	}
	if (head->train_num==1010)
	{
		head->charges=5000*head->num_of_seats;
	}
}

void passenger :: display()
{
	cout<<"\n\n\n\t\t\t****************************";
    cout<<"\n\n\t\t\t    DETAILS OF PASSENGERS";
    cout<<"\n\n\t\t\t****************************";
    struct node *tmp;
    tmp=head;
    int count=1;
	cout<<"\n\tSr NO.\t\tName\t\tAge\t\tGender";
    if(tmp == NULL)
    {
    	cout<<"\n\n\t\t\t NO REGISTRATIONS YET";
        cout<<"\n\n\t\t\t****************************";
        //getch();
        return;
    }
    do
    {
        cout<<"\n\n\t  :- "<<count;
        cout<<"\t\t ";
        cout<<tmp->name;
        cout<<"\t\t  "<<tmp->age;
        cout<<"\t\t  "<<tmp->gender;
        tmp=tmp->next;
        count++;
    }while(tmp!=NULL);
    cout<<"\n\n\t\t\t****************************";
    cout<<"\n\n\t\t     Number of waitings in the train is "<<waiting;
}

void passenger :: status_display()
{
	cout<<"\n\n\t\t\t   **********************************";
    cout<<"\n\n\t\t\t\tSEAT VACANCY STATUS MENU";
    cout<<"\n\n\t\t\t   *********************************";
    cout<<"\n\n\t\t\tType 1:- Having Age >= 50 and Female";
    cout<<"\n\t\t\tType 2:- Having Age >= 50";
    cout<<"\n\t\t\tType 3:- Having Gender As Female\n";
    cout<<"\n\t\t\t   **********************************";
    cout<<"\n\n\t\t\t\tRemaining Seats Status\n";
    cout<<"\n\t\t\t   **********************************";
    cout<<"\n\n\t\t\tNo. of seats available in the Type 1 :- "<<3-p1;
    cout<<"\n\t\t\tNo. of seats available in the Type 2 :- "<<3-p2;
    cout<<"\n\t\t\tNo. of seats available in the Type 3 :- "<<3-p3;
    cout<<"\n\t\t\tNo. of seats available in the General Category :- "<<3-p4;
    cout<<"\n\n\t\t\t   **********************************";
}

void passenger :: printticket(struct node *head)
{
	struct node *p=head;
	char name1[20];
	cout<<"\n Enter the name of passenger to print ticket:\n";
	 while(p)
    {
        cout<<p->name;
        p=p->next;
    }
    p=head;
    cout<<endl;
    cin>>name1;
	while(1)
	{

	if(strcmp(p->name,name1)==0)
	{
		cout<<"-------------------\n";
		cout<<"\tTICKET\n";
		cout<<"-------------------\n\n";
		cout<<"Name:\t\t\t "<<p->name;
		cout<<"\nNumber Of Seats:\t "<<p->num_of_seats;
		cout<<"\nTrain Number:\t\t "<<p->train_num;
		specifictrain(p->train_num);
		cout<<"\nTotal chages :\t\t "<<p->charges;
		break;
	}
	else

	 	if(p->next!=NULL)
            {
                p=p->next;
            }

   }
}

void passenger :: specifictrain(int train_num)
{
	if (train_num==1001)
	{
		cout<<"\nTrain:\t\t\tBanglore Rajdhani Express";
		cout<<"\nDestination:\t\tNew Delhi To Banglore";
		cout<<"\nDeparture:\t\t9am ";
	}
	if (train_num==1002)
	{
		cout<<"\nTrain:\t\t\tChennai Express";
		cout<<"\nDestination:\t\tMumbai To Chennai";
		cout<<"\nDeparture:\t\t12pm";
	}
	if (train_num==1003)
	{
		cout<<"\nTrain:\t\t\tDehradun Shatabdi Express";
		cout<<"\nDestination:\t\tNew Delhi To Dehradun";
		cout<<"\nDeparture:\t\t4.30am";
	}
	if (train_num==1004)
	{
		cout<<"\nTrain:\t\t\tDuronto Express";
		cout<<"\nDestination:\t\tJaipur To Mumbai";
		cout<<"\nDeparture:\t\t10.45pm ";
	}
	if (train_num==1005)
	{
		cout<<"\nTrain:\t\t\tPatna Express";
		cout<<"\nDestination:\t\tNew Delhi To Patna";
		cout<<"\nDeparture:\t\t7am";
	}
	if (train_num==1006)
	{
		cout<<"\ntrain:\t\t\tJan Shatabdi Express";
		cout<<"\nDestination:\t\tMumbai To Aurangabad";
		cout<<"\nDeparture:\t\t2.30pm ";
	}
	if (train_num==1007)
	{
		cout<<"\ntrain:\t\t\tMumbai Rajdhani Express";
		cout<<"\nDestination:\t\tNew Delhi To Mumbai";
		cout<<"\nDeparture:\t\t1.35am ";
	}
	if (train_num==1008)
	{
		cout<<"\ntrain:\t\t\tPuri Surat Express";
		cout<<"\n Destination:\t\tPuri To Surat";
		cout<<"\nDeparture:\t\t4pm ";
	}
	if (train_num==1009)
	{
		cout<<"\ntrain:\t\t\tTrivandrum Express";
		cout<<"\nDestination:\t\tChennai To Trivandrum";
		cout<<"\nDeparture:\t\t6.25am ";
	}
	if (train_num==1010)
	{
		cout<<"\ntrain:\t\t\tKolkata Express";
		cout<<"\nDestination:\t\tMumbai To Kolkata";
		cout<<"\nDeparture:\t\t8.15pm";
	}
}

void moderator :: add_trains(int a, char *t, char *s, char *d, int c, int h, int m)
{
        trains *tmp = new trains;
        tmp->tr_no = a;
        strcpy(tmp->train_name, t);
        strcpy(tmp->start, s);
        strcpy(tmp->destiantion, d);
        tmp->charge = c;
        tmp->time_h = h;
        tmp->time_m = m;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
}

void moderator :: add_trains()
{
    int n;
    char name[40], s[30], d[30];
    trains *tmp = new trains;
    cout<< "\t\tEnter train number: ";
    cin >> n;
    tmp->tr_no = n;
    cout<< "\t\tEnter train name: ";
    cin.ignore();
    cin.getline(name, 40);
    //cout<<name;
    strcpy(tmp->train_name, name);

    cout <<"\t\tEnter starting location:  ";
    cin.ignore();
    cin.getline(s, 30);
    strcpy(tmp->start, s);
    //cout << s;

    cout <<"\t\tEnter destination location:  ";
    cin.ignore();
    cin.getline(d, 30);
    strcpy(tmp->destiantion, d);
    //cout << d;

    cout<< "\t\tEnter fare of the train: ";
    cin >> n;
    tmp->charge = n;

    int h, m;
    cout <<"Enter the starting time of the train ( hh : mm ): ";
    cin >> h >> m;

    tmp->time_h = h;
    tmp->time_m = m;

    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}


void moderator :: display(trains *head)
{
    if(head == NULL)
    {
        cout << endl << "NULL" << endl;
    }
    else
    {

        cout << endl << head->tr_no << "\t";
        cout << head->train_name << "\t\t";
        cout << head->start << " to " << head->destiantion << "\t\tRs. ";
        cout << head->charge << "\t\t";
        cout << head->time_h << " : " << head->time_m;

        display(head->next);
    }
}

void moderator :: delete_train(int pos)
{

    struct trains *h = head;
    struct trains *p;
    while(head->tr_no == pos)
    {
        head = head->next;
    }

    p = head ->next ->next;
    free(h->next);
    head->next = p;
    cout <<"Train with train number " << pos << " is deleted" << endl;
}
void moderator :: deleteTrains(struct trains *head_ref, int position)
{

   if (head_ref == NULL)
      return;


   struct trains* temp = head_ref;

    if (position == 0)
    {
        head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;


    if (temp == NULL || temp->next == NULL)
         return;

    struct trains *next = temp->next->next;
    free(temp->next);
    temp->next = next;

}

int main()
{
    base_class b1;
    passenger p1;
    moderator a;
    int cmd, n;

    a.add_trains(1001, "Banglore Rajdhani Express", "New Delhi", "Banglore", 4500, 9, 0);
    a.add_trains(1002, "Chennai Express", "Mumbai", "Chennai", 3200, 23, 59);
    a.add_trains(1003, "Dehradun Shatabdi Express", "New Delhi", "Dehradun", 2500, 4, 30);
    a.add_trains(1004, "Duronto Express", "Jaipur", "Mumbai", 4000, 22, 45);
    a.add_trains(1005, "Patna Express", "New Delhi", "Patna", 2700, 7, 0);
    a.add_trains(1006, "Jan Shatabdi Express", "Mumbai", "Aurangabad", 1800, 14, 30);
    a.add_trains(1007, "Mumbai Rajdhani Express", "New Delhi", "Mumbai", 5500, 1, 35);
    a.add_trains(1008, "Puri Surat Express", "Puri", "Surat", 2000, 16, 0);
    a.add_trains(1009, "Trivandrum Express", "Chennai", "Trivendram", 4900, 6, 25);
    a.add_trains(1010, "Kolkata Express", "Mumbai", "Kolkata", 5000, 20, 15);

    cout<<"\n\n\n\n\n\n\t\t\t**********************************";
    cout<<"\n\n\t\t\t\t   WELCOME TO \n\n\t\t\t    RAILWAY RESERAVTION SYSTEM";
    cout<<"\n\n\t\t\t**********************************";

    cout << "\n\t\t\tAre you 1. Moderator or 2. Passenger? : ";
    int cs;
    cin >> cs;
    if(cs == 1)
    {
        while(1)
        {
            cout<<"\n\n\n\t\t\t**********************************";
            cout<<"\n\n\t\t\t\t  MODERATION MENU";
            cout<<"\n\n\t\t\t**********************************";
            cout<<"\n\n\t\t\t1. Display Trains \n\t\t\t2. Add Train\n\t\t\t3. Delete Train\n\t\t4. Exit\n";
            cout<<"\n\t\t\t*********************************";
            cout<<"\n\n\t\tPlease enter which operation you want to perform :- ";
            cin>>cmd;
            switch(cmd)
            {
            case 1:
                cout <<"Train details: " << endl;
                cout<<"\n-------------------------------------------------------------------------------------------------";
                cout<<"\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n";
                cout<<"-------------------------------------------------------------------------------------------------";

                moderator::display(a.gethead());
                break;

            case 2:
                a.add_trains();

                cout <<"Train details: " << endl;
                cout<<"\n-------------------------------------------------------------------------------------------------";
                cout<<"\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n";
                cout<<"-------------------------------------------------------------------------------------------------";

                moderator::display(a.gethead());
                break;

            case 3:
                cout <<"\nEnter the train number to delete: ";
                cin >> n;
                a.deleteTrains(a.gethead(), n - 1001);
                cout <<"train deleted"<<endl;
                cout << endl << endl;
                cout <<"Train details: " << endl;
                cout<<"\n-------------------------------------------------------------------------------------------------";
                cout<<"\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n";
                cout<<"-------------------------------------------------------------------------------------------------";

                moderator::display(a.gethead());
                break;

            case 4:
                exit(0);

            default:
                cout<<"\n\n\t\t\tYou have enter a invalid input";
            }
        }
    }
    else if(cs == 2)
    {
        while(1)
        {

            cout<<"\n\n\n\t\t\t**********************************";
            cout<<"\n\n\t\t\t\t  RESERVATION MENU";
            cout<<"\n\n\t\t\t**********************************";
            cout<<"\n\n\t\t\t1. Register for the Reservation \n\t\t\t2. Cancellation of the Reserve Seat\n\t\t\t3. Display the Passenger List \n\t\t\t4. Check Vacancy Status \n\t\t\t5. View details\n\t\t\t6. Specifictrain\n\t\t\t7. Print ticket\n\t\t\t8. Exit\n";
            cout<<"\n\t\t\t*********************************";
            cout<<"\n\n\t\tPlease enter which operation you want to perform :- ";
            cin>>cmd;
            switch(cmd)
            {
                case 1:
                        p1.registration();
                        break;
                case 2:
                        p1.registration_cancel();
                        break;
                case 3:
                        p1.display();
                        break;
                case 4:
                        p1.status_display();
                        break;
                case 5:
                        p1.viewdetails();
                        break;
                case 6:
                        cout <<"\t\tEnter train number: ";
                        int temmp;
                        cin >> temmp;
                        p1.specifictrain(temmp);
                        break;
                case 7:
                        p1.printticket(head);
                        break;
                case 8:
                        exit(0);
                default:
                cout<<"\n\n\t\t\tYou have enter a invalid input";
            }
        }
    }
    else
        cout << "Enter right choice";

    return 0;
}
