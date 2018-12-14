import random
LoopVar = True;
while LoopVar == True:
   ChestItems = ["Mini Shield", "SLURP", "Chug Jug", "Half Shield", "Medkit", "Bandages", "Gold Rocket Launcher",
                 "Purple Rocket Launcher", "Gold Scar", "Purple Scar", "Gold Silenced Scar", "Purple Silenced Scar",
                 "Blue Assault Rifle", "Green Assault Rifle", "Grey Assault Rifle", "Blue Tactical Shotgun", "Green Tactical Shotgun",
                 "Grey Tactical Shotgun", "Blue SMG", "Green SMG", "Grey SMG", "Clingers", "Grenade", "Stink Bomb", "Rockets",
                 "Heavy Ammo", "Medium Ammo", "Light Ammo", "Shells"]

   ChestContent = []

   for i in range(0, 5):
       Item = random.choice(ChestItems)
       ChestItems.pop(ChestItems.index(Item))
       ChestContent.append(Item)

   print (ChestContent)

   while True:
       LoopBreaker = input("Do you want to reroll the chest? Input Y for Yes or N for No.")

       if LoopBreaker.lower() == "y":
           break
       elif LoopBreaker.lower() == "n":
           LoopVar = False
           break
       else:
           print("Your input was not recognised. Please input a Y or a N.")
