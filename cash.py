while True:

    try:
        change = float(input("Change owed: "))
        if change >= 0:
            break
    except:

        pass

change = round(change * 100)

coins = 0

while change >= 25:
    change -= 25
    coins += 1

while change>= 10:
    change-= 10
    coins += 1

while change>= 5:
    change-= 5
    coins += 1

while change>= 1:
    change-= 1
    coins += 1

print(coins)
