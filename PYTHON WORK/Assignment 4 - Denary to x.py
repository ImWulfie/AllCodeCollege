def DtoB(num):
    if num > 1 & 255:
        DtoB(num // 2)
    print(num % 2, end='')
    

user=True
while user:
    number = int(input("Please enter a number between 1 & 255: "))
    print ("""

    Please choose from the list for what you would like to convert:
    1. Convert Decimal to Binary
    2. Convert Decimal to Hex
    3. Convert Binary to Hex
    4. Quit
    """)


    ans = input ("What would you like to do? ")
    if ans == "1":
        DtoB(number)
       
  #  elif ans == "2":
        

  #  elif ans == "3":
        
        
    elif ans == "4":
        exit(0)

#This is validation for whether 1-6 is not entered - it asks for input again
    else:
        print ("Invalid option, please try again")
