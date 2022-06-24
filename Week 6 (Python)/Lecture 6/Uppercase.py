s = input("Before: ")

# print("After: " + s.upper())

print("After: ", end = "")
for c in s:
    print(c.upper(), end = "")
print()