import json

with open("json1.txt", "r") as file:
    data = json.load(file)

print(data)
print(data["hobbies"])  # Output: ['reading', 'gaming']
