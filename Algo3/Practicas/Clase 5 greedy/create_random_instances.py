import numpy as np  ##/*ctrl+p luego -> Python: Select Interpreter -> Python 3.10.6

np.random.seed(1337)
#"""
# for power in range(16, 27):
#     n = 2 ** power
#     f = open("inputs/input_" + str(n), "w")
#     input = np.random.randint(0,2*n,n)
#     for num in input:
#         f.write(str(num) + " ")
#     f.close()
#"""
for power in range(1,5):
    n = 5 * (10**power) #n = cant actividades, 5 50 500 5000
    f = open("inputs/input_" + str(n), "w")
    
    for num in range(n):
        input2 = np.random.randint(0,2*n)
        input1 = np.random.randint(0,input2-1)   
        f.write(str(input1) + ' ' + str(input2) + '\n')
    f.close()

