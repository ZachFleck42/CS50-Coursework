from cs50 import get_float

while True:
    money = get_float("Change owed: ")
    if money > 0:
        break

money = int(money * 100)
coinCount = 0

while money >= 25:
    money -= 25
    coinCount += 1
    # print(f"Minus 0.25! Money is now {money}")

while money >= 10:
    money -= 10
    coinCount += 1
    # print(f"Minus 0.10! Money is now {money}")

while money >= 5:
    money -= 5
    coinCount += 1
    # print(f"Minus 0.05! Money is now {money}")

while money >= 1:
    money -= 1
    coinCount += 1
    # print(f"Minus 0.01! Money is now {money}")

print(coinCount)