import binascii
import math
import time


#This function converts the inputted vallue down to 0 or 1, printing out each remainder at each stage.
def DtoB(num):
    if num > 1 & 255:
        DtoB(num // 2)
    print(num % 2, end='')
    time.sleep (1)


def DtoH(n):
    if (n < 0):
        print(0)
    elif (n<=1):
        print (math.floor(n)),
    else:
        DtoH( n // 16 )
        x =(n%16)
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

def BtoH(n):
    bstr = n.replace(' ', '')
    hstr = '%0*X' % ((len(bstr) + 3) // 4, int(bstr, 2))
    print (hstr)

def BtoD(binary):
    binary = int(binary)
    decimal, i, n = 0, 0, 0
    while(binary != 0):
        dec = binary % 10
        decimal = decimal + dec * pow(2, i)
        binary = binary // 10
        i+= 1
    print(decimal)
    print ("The value above has been converted")


def __GetDecDigit(digit):
   digits=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
   for x in range(len(digits)):
       if digit == digits[x]:
           return x

def HtoD(hexNum):
    decNum = 0
    power = 0
    for digit in range(len(hexNum), 0, -1):
        decNum = decNum + 16 ** power * __GetDecDigit(hexNum[digit-1])
        power+=1
    return decNum
    
    


user=True
while user:
#Here the program outputs the menu to the user where an option can be selected.
    print ("")
    print ("""

    Please choose from the list for what you would like to convert:
    1. Convert Decimal to Binary
    2. Convert Decimal to Hex
    3. Convert Binary to Hex
    4. Convert Binary to Decimal
    5. Convert Hex to Decimal
    6. Convert Hex to Binary
    7. Quit
    """)


    ans = input ("What would you like to do? ")
    if ans == "1":
        #This calls the Denary to Binary function above
        number = int(input("Please enter a number between 1 & 255: "))
        print("")
        DtoB(number)

    #This is converting Denary to Hex
    elif ans == "2":
        number = int(input("Please enter a number between 1 & 255: "))
        DtoH(number)
        
    #This is converting Binary to Hex
    elif ans == "3":
        Binary = (input("Please enter a value in Binary: "))
        BtoH(Binary)
        
    #This is converting Binary to Decimal
    elif ans == "4":
        Binary = (input("Please enter a value in Binary: "))
        BtoD(Binary)
        
    #This is converting Hex to Denary
    elif ans == "5":
        Hex = (input("Please enter a value in Hex - this must be entered in Uppercase: "))
        print(HtoD(Hex))

    #This is converting Hex to Binary
    elif ans == "6":
        Hex = (input("Please enter a value in Hex - this must be entered in Uppercase: "))
        HtoD(Hex)
        DtoB(HtoD(Hex))
 
        
    #If 7 is entered then the program will close. 
    elif ans == "7":
        exit(0)

#This is validation for whether 1-6 is not entered - it asks for input again
    else:
        print ("Invalid option, please try again")
