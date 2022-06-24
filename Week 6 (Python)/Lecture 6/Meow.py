# print("Meow")
# print("Meow")
# print("Meow")

def main():
    number = int(input("How many meows?: "))

    # for i in range(number):
    #     # print("Meow")
    #     meow()

    meow(number)

# def meow():
#     print("Meow")

def meow(n):
    for i in range(n):
        print("Meow")

main()