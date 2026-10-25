with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Guest.cpp", "r", encoding="utf-8") as f:
    text = f.read()

text = text.replace("bool Guest::operator==(const Guest& other) const { return id == other.id; }",
                    "bool Guest::operator==(const Guest& other) const { return Person::operator==(other); }")

with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Guest.cpp", "w", encoding="utf-8") as f:
    f.write(text)

with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Employee.cpp", "r", encoding="utf-8") as f:
    text2 = f.read()

text2 = text2.replace("Id Employee::getId() const { return id; }",
                      "Id Employee::getId() const { return Person::getId(); }")
text2 = text2.replace("bool Employee::operator==(const Employee& other) const { return id == other.id; }",
                      "bool Employee::operator==(const Employee& other) const { return Person::operator==(other); }")

with open(r"d:\study\ppois\ppo-labs\lab2\src\people\Employee.cpp", "w", encoding="utf-8") as f:
    f.write(text2)

print("Fixed Person::id access in Guest.cpp and Employee.cpp")
