with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "r", encoding="utf-8") as f:
    text = f.read()

# Fix Money operators
text = text.replace("Money sum = m1 + m2;", "Money sum = m1.add(m2);")
text = text.replace("Money diff = m2 - m1;", "Money diff = m2.subtract(m1);")
text = text.replace("Money mult = m1 * 2.5;", "Money mult = m1.multiply(2.5);")

# Fix ContactInfo isValidPhone / isValidEmail
text = text.replace("isValidPhone()", "isValid()")
text = text.replace("isValidEmail()", "isValid()")

with open(r"d:\study\ppois\ppo-labs\lab2\tests\test_complete_coverage.cpp", "w", encoding="utf-8") as f:
    f.write(text)

print("Updated test_complete_coverage.cpp")
