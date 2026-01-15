#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<fstream>
#include<iomanip>

using namespace std;

class Habit
{
    public:
        string name;
        int streak;
        string last_date_done;

        Habit(string s)
        {
            name = s;
            streak = 0;
            last_date_done = "";
        }
};

string get_date()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_mday;

    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);

}

void add_habit(vector<Habit> & habits);
void mark_habit(vector<Habit>& habits);
void view(const vector<Habit>& habits);
void view_not_completed(const vector<Habit>& habits);
void save(const vector<Habit>& habits);
void load(vector<Habit>& habits);

int main()
{
    
    vector<Habit> habits;
    int choice;
    
    load(habits);
    
    while(true)
    {
        cout<<"\n*********Habit Tracker*********\n";
        cout<<"Select your choice among the following :\n";
        cout<<"1. Add a new Habit\n";
        cout<<"2. Mark a habit done for today\n";
        cout<<"3. View all habits along with streaks\n";
        cout<<"4. View Habits that are not completed today\n";
        cout<<"5. Save and Exit\n\n";
        cout<<"Your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:add_habit(habits);
            break;
            
            case 2:mark_habit(habits);
            break;
            
            case 3:view(habits);
            break;
            
            case 4:view_not_completed(habits);
            break;
            
            case 5:save(habits);
            cout<<"Data saved. Exiting.........\n";
            return 0;
            
            default:
            cout<<"\n***Enter valid option from above***\n";
            cout<<"Your choice: ";
        }
    }
    return 0;
}

void add_habit(vector<Habit> & habits)
{
    string s;
    cout<<"Enter the name of the habit: ";
    cin.ignore();
    getline(cin,s);
    Habit new_habit(s);
    habits.push_back(new_habit);
    cout<<"Habit added to the tracker successfully\n";
}

void mark_habit(vector<Habit>& habits)
{
    int choice;
    int n = habits.size();
    string today = get_date();
    //Checking wheather theere are any habits
    if(n==0)
    {
        cout<<"There are no habits yet! \nPlease make sure to add your Habits\n";
        return;
    }

    cout<<"\n========= Select from your Habits =========\n";
    for( int i=0;i<n;i++)
    {
        cout<<"["<<i+1<<"] ";
        cout<<setw(12)<<left<<"Habit Name"<<" : "<<habits[i].name<<endl;
    }

    cout<<"Your choice: ";
    cin>>choice;
    while(choice<1 || choice>n)
    {
        cout<<"Select valid option among your habits\n";
        cout<<"Your choice: ";
        cin>>choice;
    }
    if(habits[choice-1].last_date_done == today)
    {
        cout<<"Habit is already marked\n";
        return;
    }
    habits[choice-1].streak++;
    habits[choice-1].last_date_done=today;

}

void view(const vector<Habit>& habits)
{
    int n = habits.size(),i;
    if(n==0)
    {
        cout<<"There are no habits yet! \nPlease make sure to add your Habits\n";
        return;
    }
    cout<<"\n========= Your Habits =========\n";
    for(i=0;i<n;i++)
    {
        cout<<"["<<i+1<<"] ";
        cout<<setw(12)<<left<<"Habit Name"<<" : "<<habits[i].name<<endl;
        cout<<"    "<<setw(12)<<left<<"Streak"<<" : "<<habits[i].streak<<endl;
        cout<<"    "<<setw(12)<<left<<"Last Done"<<" : "<<habits[i].last_date_done<<endl;
    }

}
void view_not_completed(const vector<Habit>& habits)
{
    int n = habits.size(),i;
    string today = get_date();
    if(n==0)
    {
        cout<<"There are no habits yet! \nPlease make sure to add your Habits\n";
        return;
    }
    cout<<"\n========= Your Incomplete Habits for today =========\n";
    for(i=0;i<n;i++)
    {
        if(habits[i].last_date_done != today)
        cout<<"["<<i+1<<"] ";
        cout<<setw(12)<<left<<"Habit Name"<<" : "<<habits[i].name<<endl;
        cout<<"    "<<setw(12)<<left<<"Streak"<<" : "<<habits[i].streak<<endl;
        cout<<"    "<<setw(12)<<left<<"Last Done"<<" : "<<habits[i].last_date_done<<endl;
    }
}
void save(const vector<Habit>& habits)
{
    //In progress
}
void load(vector<Habit>& habits)
{
    //In progress
}
