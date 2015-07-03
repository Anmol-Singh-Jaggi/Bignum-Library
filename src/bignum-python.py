import os

def main():
    testCases = 0
    testCases = int(input())
    
    add = 1
    subtract = 2
    multiply = 3
    divide = 4
    mod = 5
    power = 6
    powerInt = 7
    
    while testCases:
        num1, num2, option = map(int, input().split(" "))
        result = 0
        if(option == add):
            result = num1 + num2
        elif(option == subtract):
            result = abs(num1 - num2)
        elif(option == multiply):
            result = num1 * num2
        elif(option == divide):
            result = num1 / num2
        elif(option == mod):
            result = num1 % num2
        elif(option == power):
            result = num1 ** num2
        elif(option == powerInt):
            result = num1 ** num2
        else:
            print("Invalid Option!!")
            os.exit(-1)
            
        result = int(result)
        print(result)
        
        testCases -= 1
        
if __name__ == "__main__":
    main()
