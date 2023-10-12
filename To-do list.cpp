//To-Do List
#include <iostream>>
#include <fstream>>
#include <string>
#include <cstdlib>

using namespace std;
int ID;
struct todo
{
    int id;
    string task;
};

void addtodo()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n");
    todo todo;
    cout << "\n\t Enter the new task:";
    cin.get();
    getline(cin, todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task;
    write.close();

    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "\n\t Add another task? (y/n):";
    cin >> ch;

    if(ch == 'y')
    {
        addtodo();
    }
    else
    {
        cout << "\n\t Task has been added successfully!!";
        return;
    }
}

void print(todo s)
{
    cout << "\n\t ID : " << s.id;
    cout << "\n\t Task : " << s.task;
}

void readdata()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n");
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t -----------Current task in the list--------------\n";

    while (!read.eof())
    {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

int searchdata()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n");
    int id;
    cout << "\n\t Enter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");

    while (!read.eof())
    {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if(todo.id == id)
        {
            print(todo);
            return id;
        }
    }
}

void deletedata()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n");
    int id = searchdata();
    cout << "\n\t Delete this task (y/n): ";
    char choice;
    cin >> choice;
    if(choice == 'y')
    {
        todo todo;
        ofstream tempfile;
        tempfile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof())
        {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if(todo.id != id)
            {
                tempfile << "\n" << todo.id;
                tempfile << "\n" << todo.task;
            }
        }
        read.close();
        tempfile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\t Task has been deleted!!"; 
    }
    else
    {
        cout << "\n\t Task not deleted!!";
    }
}

void updatedata()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n") << endl << endl << endl;
    int id = searchdata();
    cout << "\n\t Update this task (y/n): ";
    char choice;
    cin >> choice;
    if(choice == 'y')
    {
        todo newData;
        cout << "\n\t Enter to-do task: ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof())
        {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if(todo.id != id)
            {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else
            {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\t Task is updated!!";
    }
    else
    {
        cout << "\n\t Task not deleted!!";
    }
}

int main()
{
    system("cls");
    cout << ("\t---------------------------------------------------\n");
    cout << ("\t                    To-Do List                     \n");
    cout << ("\t---------------------------------------------------\n");
    ifstream read;
    read.open("id.txt");
    if(!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();

    while (true)
    {
        cout << endl;
        cout << "\n\t 1.Add Task";
        cout << "\n\t 2.Display Task";
        cout << "\n\t 3.Search Task";
        cout << "\n\t 4.Delete Task";
        cout << "\n\t 5.Update Task";

        int choice;
        cout << "\n\t Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addtodo();
            break;
        case 2:
            readdata();
            break;
        case 3:
            searchdata();
            break;
        case 4:
            deletedata();
            break;
        case 5:
            updatedata();
            break;
        }
    }
    
}
