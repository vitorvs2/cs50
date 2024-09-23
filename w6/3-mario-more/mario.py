from cs50 import get_int

height = int(0)

while (height <= 0 or height >= 9):
    height = get_int("height: ")

for i in range(1, height+1):

    n = int(height - i)
    while (n > 0):
        print(" ", end="")
        n = n - 1

    for j in range(i):
        print("#", end="")
        j = j + 1

    print("  ", end="")

    for j in range(i):
        print("#", end="")
        j = j - 1
    print("")
