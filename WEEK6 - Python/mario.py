
height = (input("Height: "))

while not height.isdigit() or int(height) <= 0 or int(height) >= 9:
    height = input("Height: ")

height = int(height)

for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")

    for k in range(i+1):
        print("#", end="")

    print()

