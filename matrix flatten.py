import numpy as np

#function to flatten the 3D matrix to a 1D vector
def make_1dmatrix(a_3d_array):      
    flat_array = a_3d_array.flatten()
    return flat_array

def changeindex(i, j, k):
    # equation to transform from 3D matrix index to 1D vector index flatindex= x + WIDTH * (y + DEPTH * z)
    flatindex = k + m * (j + p * i)
    return flatindex


if __name__ == "__main__":
    #example 3D matrix
    print("Example 3D matrix: ")
    a_3d_array = np.array([[[ 1,  2,  3], [ 4,  5,  6], [ 7,  8,  9]], 
                           [[10, 11, 12], [13, 14, 15], [16, 17, 18]],
                           [[19, 20, 21], [22, 23, 24], [25, 26, 27]]])
    print(a_3d_array)
    n, m, p = a_3d_array.shape
    myvector = make_1dmatrix(a_3d_array)

    print('1D Numpy Array:')
    print(myvector)
    
    pos = 1, 2, 0
    print(f"printing an element in 3D matrix position {pos}")
    print(a_3d_array[pos])
    y = changeindex(*pos)
    print(f"printing an element in 1D vector position {y}")
    print(myvector[y])



    
