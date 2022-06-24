answer = input("Do you agree?: ")

# if answer == Y or answer == y or answer == Yes or answer == yes or answer == YES:
if answer.lower() in ["y", "yes"]:
    print("Agreed")
# elif answer == N or answer == n or answer == No or answer == no or answer == NO:
elif answer.lower() in ["n", "no"]:
    print("Not agreed")
else:
    print("Huh?")