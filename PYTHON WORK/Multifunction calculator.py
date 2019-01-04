import time
import math

def Base10toBinary(num):
    if num > 1 & 255:
        Base10toBinary(num // 2)
    print(num % 2, end='')
    time.sleep(1)

def Base10toHex(n):
    if (n < 0):
        print(0)
    elif (n<=1):
        print (math.floor(n)),
    else:
        Base10toHex( n // 16 )
        x = (n%16)
        if (x < 10):
            print(x), 
        if (x == 10):
            print("A"),
        if (x == 11):
            print("B"),
        if (x == 12):
            print("C"),
        if (x == 13):
            print("D"),
        if (x == 14):
            print("E"),
        if (x == 15):
            print ("F"), 

user = True
while user:
    print ("")
    print ("""

    Please choose from the list below for which calculation
                     you would like to use
    
                 1. Add two numbers together
               2. Multiply two numbers together
                    3. Divide two numbers
           4. Divide two numbers without reaminders
            5. Convert a base 10 number to Binary
          6. Convert a base 10 number to Hexadecimal
                    7. Quit application
    """)

    ans = input ("What would you like to do? ")

    if ans == "1":
        number = int(input("Please enter the first number: "))
        number_2 = int(input("Please enter the second number: "))
        number_3 = number + number_2
        print (number_3)
        time.sleep(1.5)
        

    elif ans == "2":
        number =  int(input("Please enter the first number: "))
        number_2 = int(input("Please enter the second number: "))
        number_3 = number * number_2
        print (number_3)
        time.sleep(1.5)
        

    elif ans == "3":
        number = int(input("Please enter the first number: "))
        number_2 = int(input("Please enter the second number: "))
        number_3 = number / number_2
        print(number_3)
        time.sleep(1.5)
     

    elif ans == "4":
        number = int(input("Please enter the first number: "))
        number_2 = int(input("Please enter the second number: "))
        number_3 = number // number_2
        print(math.floor(number_3))
        time.sleep(1.5)

    elif ans == "5":
        number = int(input("Please enter a number between 1 & 255: "))
        Base10toBinary(number)


    elif ans == "6":
        number = int(input("Please enter a number between 1 & 255: "))
        Base10toHex(number)
        
        
        
