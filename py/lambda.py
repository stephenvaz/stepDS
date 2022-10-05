x = lambda a : (True if a>200 else False)
# print(x(300))

for i in range(10):
    print("Enter price of item", i+1, ": ", end="")
    print(x(int(input())))
