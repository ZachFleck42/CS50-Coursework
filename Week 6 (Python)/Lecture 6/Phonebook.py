people = {
    "Zach" : "+1-513-850-3668",
    "Michelle" : "+1-765-771-0100"
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")