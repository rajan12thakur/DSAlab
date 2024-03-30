#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    char emp_id[20];
    char name[50];
    char designation[50];
    double salary;
};

class EmployeeDatabase {
private:
    const char* filename;
    
public:
    EmployeeDatabase(const char* filename) {
        this->filename = filename;
    }
    
    void addEmployee(const Employee& employee) {
        ofstream file(filename, ios::binary | ios::app);
        file.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
        file.close();
    }
    
    bool deleteEmployee(const char* emp_id) {
        ifstream file(filename, ios::binary);
        ofstream temp("temp.dat", ios::binary | ios::app);
        Employee employee;
        bool found = false;
        
        while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
            if (strcmp(employee.emp_id, emp_id) != 0)
                temp.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
            else
                found = true;
        }
        
        file.close();
        temp.close();
        
        remove(filename);
        rename("temp.dat", filename);
        
        return found;
    }
    
    void displayEmployee(const char* emp_id) {
        ifstream file(filename, ios::binary);
        Employee employee;
        bool found = false;
        
        while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
            if (strcmp(employee.emp_id, emp_id) == 0) {
                cout << "Employee ID: " << employee.emp_id << endl;
                cout << "Name: " << employee.name << endl;
                cout << "Designation: " << employee.designation << endl;
                cout << "Salary: " << employee.salary << endl;
                found = true;
                break;
            }
        }
        
        file.close();
        
        if (!found)
            cout << "Employee not found." << endl;
    }
};

int main()
{
    EmployeeDatabase database("employee_db.bin");
    
    while (true) 
    {
        cout << "\n=== Employee Database Menu ===" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) 
        {
            case 1: {
                Employee employee;
                cout << "Enter employee ID: ";
                cin.getline(employee.emp_id, sizeof(employee.emp_id));
                cout << "Enter employee name: ";
                cin.getline(employee.name, sizeof(employee.name));
                cout << "Enter employee designation: ";
                cin.getline(employee.designation, sizeof(employee.designation));
                cout << "Enter employee salary: ";
                cin >> employee.salary;
                cin.ignore(); // Clear input buffer
                database.addEmployee(employee);
                cout << "Employee added successfully." << endl;
                break;
            }
            case 2: {
                char emp_id[20];
                cout << "Enter employee ID to delete: ";
                cin.getline(emp_id, sizeof(emp_id));
                if (database.deleteEmployee(emp_id))
                    cout << "Employee deleted successfully." << endl;
                else
                    cout << "Employee not found." << endl;
                break;
            }
            case 3: {
                char emp_id[20];
                cout << "Enter employee ID to display:";
                cin>>emp_id;
                database.displayEmployee(emp_id);
                break;
            }
            case 4: 
                {
                    break;
                }
        }
    }
}