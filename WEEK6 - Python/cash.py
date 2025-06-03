change = input("Change: ")

# Validate input
while True:
    try:
        change = float(change)
        if change >= 0:
            break
        else:
            change = input("Change: ")
    except ValueError:
        change = input("Change: ")

change = float(change)

change = round(change * 100)
coins = 0

while change > 0:
    if change >= 25:
        coins += 1
        change -= 25
    elif change >= 10:
        coins += 1
        change -= 10
    elif change >= 5:
        coins += 1
        change -= 5
    elif change >= 1:
        coins += 1
        change -= 1

print(f"{coins}")
