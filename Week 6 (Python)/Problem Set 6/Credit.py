from cs50 import get_int

def main():
# Obtain credit card number from user
    while True:
        number = get_int("Number: ")
        if number > 1000000000000 and number < 9999999999999999:
            break
        else:
            print("INVALID")
            return 1

    number = str(number)
    numberLength = len(number)
    sum1 = 0
    sum2 = 0

    for i in range(len(number) - 2, -1, -2):
        temp = 2 * int(number[i])
        if temp >= 10:
            temp = temp % 10
            sum1 += 1 + temp
        else:
            sum1 += temp


    for i in range(len(number) - 1, -1, -2):
        sum2 += int(number[i])

    sum3 = sum1 + sum2

    print(f"sum3: {sum3}")

    if sum3 % 10 != 0:
        print("INVALID")
        return 1

    if len(number) == 15 and int(number[0]) == 3 and (int(number[1]) == 4 or int(number[1]) == 7):
        print("AMEX")
    elif len(number) == 16 and int(number[0]) == 5 and (int(number[1]) > 0 and int(number[1]) < 6):
        print("MASTERCARD")
    elif (len(number) == 13 or len(number) == 16) and int(number[0]) == 4:
        print("VISA")
    else:
        print("INVALID")

    return 0

main()