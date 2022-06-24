# scores = [72, 73, 33]

scores = []
for i in range(3):
    scores.append(int(input("Score: ")))

# print("Average: " + str(sum(scores) / len(scores)))
print(f"Average: {sum(scores) / len(scores)}")