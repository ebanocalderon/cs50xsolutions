# Get change to be paid
def getUserInput():
    while True:
        userInput = float(input("Amount owed: "))
        # Get only positive values between 0.01 - 0.99
        if userInput > 0 and userInput < 1:
          break
    roundInput = userInput*100
    return roundInput
    
# Calculate how many pennies will be paid

def calculateChange(change):
    count = 0
    while change >= 25:
       change -= 25
       count += 1
    while change >= 10:
       change -= 10
       count += 1
    while change >= 5:
       change -= 5
       count += 1
    while change >= 1:
       change -= 1
       count += 1
    return count  
    
    
# Get user input
userInput = getUserInput()

# Show the amount of pennies owed
print(calculateChange(userInput))