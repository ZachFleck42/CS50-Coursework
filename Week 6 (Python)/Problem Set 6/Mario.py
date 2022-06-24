from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

blank = height - 1
block = 1

for i in range(height):
    print()
    print(" " * blank, end = "")
    print("#" * block, end = "")
    print("  ", end = "")
    print("#" * block, end = "")
    print(" " * blank, end = "")
    print()

    blank -= 1
    block += 1