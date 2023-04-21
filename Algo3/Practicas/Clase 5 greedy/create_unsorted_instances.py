import numpy as np

# for power in range(16, 27):
#     n = 2 ** power
#     f = open("inputs/input_" + str(n), "w")
#     input = range(0, n-1)
#     f.write(str(n-1) + " ")
#     for num in input:
#         f.write(str(num) + " ")
#     f.close()

for power in range(1,5):
    n = 5 * (10**power) #n = cant actividades, 5 50 500 5000
    f = open("inputs/input_" + str(n), "w")
    
    anterior = 2*n

    for num in range(n):
        input2 = np.random.randint(0,anterior)
        input1 = np.random.randint(0,input2-1)
        
        anterior = input2
        f.write(str(input1) + ' ' + str(input2) + '\n')
    f.close()

