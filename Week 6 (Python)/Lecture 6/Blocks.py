width = int(input("How wide should the block be?: "))
height = int(input("How tall should the block be?: "))

for i in range(height):
    for j in range(width):
        print("#", end = "")
    print()