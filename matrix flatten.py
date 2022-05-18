import numpy as np
#matrix parameters
n=3
m=3
p=3
q=0
y=0
flatindex=0
#function to flatten the 3D matrix to a 1D vector
def make_1dmatrix(a_3d_array):      
    flat_array = a_3d_array.flatten()
    return flat_array

def changeindex(i,j,k):
    # equation to transform from 3D matrix index to 1D vector index flatindex= x + WIDTH * (y + DEPTH * z)
    flatindex= k + m * (j + p * i)
    return flatindex


if __name__ == "__main__":
    #example 3D matrix
    a_3d_array = np.array([[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 
                        [[10, 11, 12], [13, 14, 15], [16, 17, 18]],
                        [[19, 20, 21], [22, 23, 24], [25, 26, 27]] ])
    print(a_3d_array)

    
    myvector = make_1dmatrix(a_3d_array)

    print('1D Numpy Array:')
    print(myvector)
    print(a_3d_array[1][2][0])

    y = changeindex(1,2,0)

    print(myvector[y])



    