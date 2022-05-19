import matplotlib.pyplot as plt
import numpy as np
from tkinter import *
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)

# isValidFloat function used to check if the input is a valid float
def isValidFloat(s):
    try:
        float(s)
        return True

    except ValueError:
        return False

# stringToEquation function used to convert the string input to a mathematical equation
def stringToEquation(string: str, x: np.ndarray) -> np.ndarray:
    if string == "":
        return 0

    elif '+' in string:
        a, b = string.split('+', maxsplit=1)
        return stringToEquation(a, x) + stringToEquation(b, x)

    elif '-' in string:
        a, b = string.split('-', maxsplit=1)
        return stringToEquation(a, x) - stringToEquation(b, x)

    elif '*' in string:
        a, b = string.split('*', maxsplit=1)
        return stringToEquation(a, x) * stringToEquation(b, x)

    elif '/' in string:
        a, b = string.split('/', maxsplit=1)
        return stringToEquation(a, x) / stringToEquation(b, x)
        
    elif '^' in string:
        a, b = string.split('^', maxsplit=1)
        return stringToEquation(a, x) ** stringToEquation(b, x)

    elif string == 'x':
        return x

    elif isValidFloat(string):
        return float(string)

    else:
        raise ValueError('Invalid equation')

# clickButton function used when user clicks the "graph" button 
# the function checks the inputs of the user and graphs the equation
def clickButton(*args):
    # getting the input from entry fields in gui
    minstring = entrymin.get()
    if isValidFloat(minstring):
        minvalue = float(minstring)
        LabelError.config(text="")

    else:
        LabelError.config(text="Invalid min")
        return

    maxstring = entrymax.get()
    if isValidFloat(maxstring):
        maxvalue = float(maxstring)
        LabelError.config(text="")

    else:
        LabelError.config(text="Invalid max")
        return

    if minvalue >= maxvalue: #checking the min and max 
        LabelError.config(text="Min must be less than max")
        return

    # Parsing the input eqn from user
    eqnString = entryeqn.get().lower()
    x = np.linspace(minvalue, maxvalue, 1000)
    
    # Validation of the input equation
    try:
        y = stringToEquation(eqnString, x)

        if y is not np.ndarray:
            y = y * np.ones(x.shape)

    except ValueError:
        LabelError.config(text="Invalid equation")
        return

    # Clearing the previous plots and making new plot
    ax.clear()
    ax.plot(x, y)
    ax.grid()
    
    # Placing the plot on the canvas
    canvas.draw()

    # Placing the canvas on the Tkinter window
    canvas.get_tk_widget().pack()       
    
    
if __name__ == "__main__":
        # tkinter window "top"
        top = Tk()
        top.geometry("750x550")
        top.resizable(width=False, height=False)
        
        # Creating Entry boxes and labels for input from user 
        entryeqn = Entry(top, width=50)
        entryeqn.pack()

        entrymin = Entry(top, width=50)
        entrymin.pack()

        entrymax = Entry(top, width=50)
        entrymax.pack()

        Labeleqn = Label(top, text="equation to graph")
        Labeleqn.pack()
        Labeleqn.place(relx = 0.0, rely = 0.0, anchor='nw')

        Labelmin = Label(top, text="min value of x")
        Labelmin.pack()
        Labelmin.place(relx = 0.0, rely = 0.035, anchor='nw')

        Labelmax = Label(top, text="max value of x")
        Labelmax.pack()
        Labelmax.place(relx = 0.0, rely = 0.07, anchor='nw')

        LabelError = Label(top, text="")
        LabelError.pack()
        LabelError.place(relx=0.9, rely=0.035, anchor ='ne')

        mybutton = Button(top, text="Graph", command=clickButton)
        mybutton.pack()
        
        # the figure that will contain the plot
        fig, ax = plt.subplots()

        # creating the Tkinter canvas containing the Matplotlib figure
        canvas = FigureCanvasTkAgg(fig,master = top)

        # creating the Matplotlib toolbar
        toolbar = NavigationToolbar2Tk(canvas, top)
        toolbar.update()

        # placing the toolbar on the Tkinter window
        canvas.get_tk_widget().pack() 
        
        top.mainloop()
