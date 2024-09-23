from cs50 import get_string

# GETTING THE CARD NUMBER AS STRING, FOR EASIER MANIPULATION
cardnumber = get_string("cardnumber: ")

# Getting the cardnumber length as string
count = len(cardnumber)

# Get card's first digit
digit1 = int(cardnumber[0])

# Get card's second digit
digit2 = int(cardnumber[1])

# Global variables declaration
step1 = 0
step2 = 0

# # DEBUG
# print("reversed number: ", end="")

# Looping into the cardnumber digits for checksum
for i in range(1, count + 1):

    # # DEBUG
    # print(cardnumber[count - i], end="")

    # Get the actual digit for checksum
    digit = int(cardnumber[count - i])

    # Last digit treatment
    if i == 1:
        step2 += digit
        continue

    # Other numbers manipulation startint with the second dast digit
    if i % 2 == 0:
        # Checking if multiplication extrapolates 9 max digits
        if digit * 2 >= 10:
            step1 += 1 + ((digit * 2) % 10)
        else:
            step1 += digit * 2
    else:
        # Just sum up the no others digits
        step2 += digit

# # DEBUG
# print()
# print("string length = " + str(count))
# print("step1 = " + str(step1))
# print("step2 = " + str(step2))
# print("digit1 = " + digit1)
# print("digit2 = " + digit2)


# Validates the checksum
if (step1 + step2) % 10 == 0:

    # Validating AMEX number
    if digit1 == 3 and (digit2 == 4 or digit2 == 7) and count == 15:
        print("AMEX\n")
    else:
        # Validating VISA number
        if digit1 == 4 and (count == 13 or count == 16):
            print("VISA\n")
        else:
            # Validating MASTERCARD number
            if digit1 == 5 and (digit2 == 1 or digit2 == 2 or digit2 == 3 or digit2 == 4 or digit2 == 5) and count == 16:
                print("MASTERCARD\n")
            else:
                # Returning invalid if doesnt match previous cards
                print("INVALID\n")
else:
    # Returning invalid if checksum fails
    print("INVALID\n")
