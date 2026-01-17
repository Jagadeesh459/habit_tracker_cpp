#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<sstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

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
string formatted_date(int year, int month, int day)
{
    stringstream s;
    s<<setw(2)<<setfill('0')<<day<<"-"<<setw(2)<<setfill('0')<<month<<"-"<<year;

    return s.str();
}
string get_date()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_mday;

    return formatted_date(year,month,day);

}

string get_yesterday_date()
{
    time_t now = time(0);
    now -= 24*60*60;
    tm *ltm = localtime(&now);

    int year = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_mday;

    return formatted_date(year,month,day);
}
void add_habit(vector<Habit> & habits);
void mark_habit(vector<Habit>& habits);
void view(const vector<Habit>& habits);
void view_not_completed(const vector<Habit>& habits);
void save(const vector<Habit>& habits);
void load(vector<Habit>& habits);
void delete_habit(vector<Habit>& habits);

int main()
{
    
    vector<Habit> habits;
    int choice;
    
    load(habits);
    
    while(true)
    {
        cout<<"\n=============================================\n";
        cout<<BLUE<<"\t\tHABIT TRACKER"<<RESET;
        cout<<"\n=============================================\n";
        cout<<"Select your choice among the following :\n";
        cout<<CYAN<<"1. Add a new Habit\n";
        cout<<"2. Mark a habit done for today\n";
        cout<<"3. View all habits along with streaks\n";
        cout<<"4. View Habits that are not completed today\n";
        cout<<"5. Save\n";
        cout<<"6. Delete a habit\n";
        cout<<"7. Exit the tracker\n"<<RESET;
        cout<<"\n-------------------------------------\n";
        cout<<YELLOW<<"Your choice: "<<RESET;
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
            cout<<GREEN<<"Data saved.\n"<<RESET;
            break;
            
            case 6:delete_habit(habits);
            break;

            case 7:
            cout<<CYAN<<"\n\n\t Thank you for using my habit tracker";
            cout<<GREEN<<"\nExiting........."<<RESET;
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
    cout<<"Enter the name of the habit(It shouldn't be empty): ";
    cin.ignore();
    getline(cin,s);
    if(s.empty())
    {
        cout<<RED<<"\tHabit name cannot be empty\n"<<RESET;
        return;
    }
    Habit new_habit(s);
    habits.push_back(new_habit);
    cout<<GREEN<<"\n\t*** Habit added to the tracker successfully ***\n"<<RESET;
}

void mark_habit(vector<Habit>& habits)
{
    int choice;
    int n = habits.size();
    string today = get_date();
    //Checking wheather theere are any habits
    if(n==0)
    {
        cout<<RED<<"\tNo habits found.Add a habit first.\n"<<RESET;
        return;
    }

    cout<<"\n========= "<<BLUE<<"Select from your Habits"<<RESET<<" =========\n";
    for( int i=0;i<n;i++)
    {
        cout<<"["<<i+1<<"] ";
        cout<<setw(12)<<left<<CYAN<<"Habit Name"<<" : "<<habits[i].name<<RESET<<endl;
    }

    cout<<YELLOW<<"Your choice: ";
    cin>>choice;
    while(choice<1 || choice>n)
    {
        cout<<"Select valid option among your habits\n";
        cout<<"Your choice: ";
        cin>>choice;
    }
    if(habits[choice-1].last_date_done == today)
    {
        cout<<GREEN<<"Habit already completed for today.\n"<<RESET;
        return;
    }

    habits[choice-1].streak++;
    habits[choice-1].last_date_done=today;
    cout<<GREEN<<"\t**Habit marked successfully**\n"<<RESET;
}

void view(const vector<Habit>& habits)
{
    int n = habits.size(),i;
    if(n==0)
    {
        cout<<RED<<"\tNo habits found.Add a habit first\n"<<RESET;
        return;
    }
    cout<<"\n========="<<BLUE<<" Your Habits "<<RESET<<"=========\n";
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
        cout<<RED<<"\tNo habits found.Add a habit first.\n"<<RESET;
        return;
    }
    bool flag = true;
    cout<<"\n========= Your Incomplete Habits for today =========\n";
    for(i=0;i<n;i++)
    {
        if(habits[i].last_date_done != today)
        {
            flag = false;
            cout<<"["<<i+1<<"] ";
            cout<<setw(12)<<left<<"Habit Name"<<" : "<<habits[i].name<<endl;
            cout<<"    "<<setw(12)<<left<<"Streak"<<" : "<<habits[i].streak<<endl;
            cout<<"    "<<setw(12)<<left<<"Last Done"<<" : "<<habits[i].last_date_done<<endl;
        }
    }
    if(flag == true)
    cout<<GREEN<<"\n\nAll habits are completed for today\n"<<RESET;
}
void save(const vector<Habit>& habits)
{
    ofstream fout("habits.txt");
    
    if(!fout.is_open())
    {
        cout<<RED<<"ERROR : Could not open the file"<<RESET;
        return;
    }
    
    for(const Habit& h : habits)
    {
        fout<<h.name<<"|"<<h.streak<<"|"<<h.last_date_done<<"\n";
    }
    fout.close();
    
}
void load(vector<Habit>& habits)
{
    ifstream fin("habits.txt");
    if(!fin.is_open())
    {
        return;
    }
    string h,name,streak,date;
    
    while(getline(fin,h))
    {
        if(h.empty())
        continue;
        size_t p1 = h.find('|');
        size_t p2 = h.find('|',p1+1);

        name = h.substr(0,p1);
        streak = h.substr(p1+1,p2-p1-1);
        date = h.substr(p2+1);

        Habit habit(name);
        habit.streak=stoi(streak);
        habit.last_date_done=date;

        string yesterday = get_yesterday_date();
        string today = get_date();

        if(yesterday != habit.last_date_done && today != habit.last_date_done)
        habit.streak=0;
        habits.push_back(habit);

    }


}
void delete_habit(vector<Habit>& habits)
{
    if(habits.empty())
    {
        cout<<RED<<"No Habits to delete"<<RESET;
        return;
    }
    
    int choice;
    int n = habits.size();
    cout<<"\n========= "<<BLUE<<"Select from your Habits"<<RESET<<" =========\n";
    for( int i=0;i<n;i++)
    {
        cout<<"["<<i+1<<"] ";
        cout<<setw(12)<<left<<CYAN<<"Habit Name"<<" : "<<habits[i].name<<RESET<<endl;
    }
    cout<<YELLOW<<"Enter the habit that you wanted to delete\n\n";
    cout<<"Your choice: "<<RESET;
    cin>>choice;
    while(choice<1 || choice>n)
    {
        cout<<"Select valid option among your habits\n";
        cout<<YELLOW<<"Your choice: "<<RESET;
        cin>>choice;
    }
    habits.erase(habits.begin()+(choice-1));
    cout<<GREEN<<"\nHabit deleted successfully\n"<<RESET;
}
