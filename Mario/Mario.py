#Main Function
def main():
    # Get user building type
    inputType = getInputType()
    # Get Size of building
    size = getInputSize()
    # Build Upstairs
    if inputType == 'U' or inputType == 'u':
       upstais(size)
    # Build tower
    elif inputType == 'T' or inputType == 't':
       tower(size)
    # Build downstairs
    else:
       downstairs(size)


# Function to get building type
def getInputType():
 while True:
  inputType = input("Insert building type, U for Upstairs, D for Downstairs, T for Tower: ")
  if inputType in ['T', 't', 'U', 'u', 'D', 'd']:
     break
 return inputType



# Function to get size of building
def getInputSize():
    while True:
     size = int(input("Building Height(Max Height 8):"))
     if size >= 1 and size <= 9:
      break
    return size



# Build upstairs
def upstais(height):
  for i in range(height):
        print((height - 1 - i) * " ", end="")
        print((i + 1) * "#")



# Build downstairs
def downstairs(height):
  for i in range(height):
        print((i + 1) * "#")



# Build Tower
def tower(height):
    for i in range(height):
       print(" " * (height - i) + '#' * i + " " * 2 + i * "#")



# Declare main function
if __name__ == "__main__":
    main()
