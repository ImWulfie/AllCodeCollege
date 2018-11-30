## This is used to define where the inputted data will be stored
## For instance when the employee name will be saved under "self.name"
class Users():

    def __init__(self):
        self.name = ""
        self.cars_sold = 0

    def add_employee(self):
        self.name = input("Please enter the employees name ")
        self.cars_sold = int(input("Please enter the amount of cars sold by this employee "))

    def GetEmployee(self):
        return(f'Employee Name: {self.name} | Total Cars Sold: {self.cars_sold}')


employee_list = []

# This is a simple bubblesort function which
# is used and needed to meet 1 of the client requirements
def bubbleSort(cars_sold):
            for passnum in range(len(cars_sold)-1,0,-1):
                if cars_sold[i]>cars_sold[i+1]:
                    temp = cars_sold[i]
                    cars_sold[i] = cars_sold[i+1]
                    cars_sold[i+1] = temp

TotalCarsSold = 0

##This is the menu system for the application
##Here all the user requirements are met

user=True
while user:
    
    print ("""
    1. Add a Employee
    2. View Employee List
    3. Export Employee List
    4. Sort Employee List - Total Cars Sold
    5. Display the total sales for the week
    6. Quit
    """)

#Here te program checks to see what the user has inputted - it then calls on the corresponding function
    ans = input ("What would you like to do? ")
    if ans == "1":
        employee = Users()
        employee.add_employee()
        employee_list.append(employee)

    elif ans == "2":
        if len(employee_list) == 0:
            print("No Employees, press 1 to add an employee! - Then make sure to press 3 to export contents!")
        else: 
            for item in employee_list:
                print(item.GetEmployee())

    #Here the program opens and writes to the .txt file based upon what was entered in "1"   
    elif ans == "3":
        if len(employee_list) == 0:
            print("No Employees, press 1 to add an employee! - Then make sure to press 3 to export contents!")
        else:
            f = open('employee_cars.txt', 'w')
            for item in employee_list:
                f.write(f"Employee Name: {item.name} Total Cars Sold: {item.cars_sold}\n")
            f.close()
            print ("Write successful!")
            
    #Here this calls on the bubblesort function that is defined above
    elif ans == "4":
        if len(employee_list) == 0:
            print("No Employees, press 1 to add an employee! - Then make sure to press 3 to export contents!") 
        else:
          for item in employee_list:
                bubbleSort({item.cars_sold})
                print({item.cars_sold})

    elif ans == "5":
        for item in employee_list:
            TotalCarsSold += item.cars_sold
        print (TotalCarsSold)

    elif ans == "6":
        exit(0)

#This is validation for whether 1-6 is not entered - it asks for input again
    else:
        print ("Invalid option, please try again")
