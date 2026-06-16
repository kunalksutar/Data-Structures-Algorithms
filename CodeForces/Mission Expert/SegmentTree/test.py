"""You are given an integer array coins representing coins of 
different denominations and an integer amount representing a 
total amount of money. Return the fewest number of coins that 
you need to make up that amount. If that amount cannot be made 
up by any combination of the coins, return -1

coins = [1, 2, 5]
amount = 11
print(coin_change(coins, amount))  

# Output: 3 (11 = 5 + 5 + 1)

"""

coins = [1, 2, 5]
amount = 11

coins.sort(reverse=True)

"""5 2 1"""

ans=0
index=0

arr=[]

while(amount and index < len(arr)):
    ans+=int(amount/coins[index])
    
    if amount>=coins[index]:
        amount=amount%coins[index]
    
    for i in range(0,int(amount/coins[index])):
        arr.append(coins[index])
    
    index+=1
    
print(arr)



