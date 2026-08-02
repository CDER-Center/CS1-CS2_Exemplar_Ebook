import json

with open("json1.txt", "r") as file:
    data = json.load(file)

print(data)
print(data["hobbies"])  # Output: ['reading', 'gaming']


with open("json2.txt", "r") as file:
    json2 = json.load(file)
    
    
# Question 1
print(json2["person"]["firstName"])

# Question 2
print(json2["person"]["address"]["city"])

with open("json3.txt", "r") as file:
    json3 = json.load(file)
    
    
for item in json3["people"]:
    print(item["name"], item["hobbies"][0])