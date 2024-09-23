from cs50 import get_float

change = 0
while change <= 0:
    change = get_float("Change owed: ")

quarters = int(change * 100 / 25)
change = change * 100 % 25

dimes = int(change / 10)
change = change % 10

nickels = int(change / 5)
change = change % 5

pennies = int(change / 1)

# print ("quarters:   " + str(quarters))
# print ("dimes:      " + str(dimes))
# print ("nickels:    " + str(nickels))
# print ("pennies:    " + str(pennies))
# print ("total:      " + str(quarters + dimes + nickels + pennies))
print(quarters + dimes + nickels + pennies)
