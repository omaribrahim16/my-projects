from json.tool import main
from turtle import width
import matplotlib.pyplot as plt
import numpy as np
from cProfile import label
from tkinter import *
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)

#clickbutton function used when user clicks the "graph" button 
#the function checks the inputs of the user and graphs the equation

def clickbutton():
    
    # getting the input from entry fields in gui
    minstring = entrymin.get()
    if  minstring.isdigit():
        minvalue = eval(minstring)
        Labelnoerrormin=Label(top,text="                            ")
        Labelnoerrormin.pack()
        Labelnoerrormin.place(relx = 0.9,rely = 0.035, anchor ='ne')
        if type(minvalue) is not int and type(minvalue) is not float:   #checking the input
            Labelerrormin=Label(top,text="invalid input")
            Labelerrormin.pack()
            Labelerrormin.place(relx = 0.9,rely = 0.035, anchor ='ne')
            y=0
            x=0
            minvalue=0
            maxvalue=0
    else:
        Labelerrormin=Label(top,text="invalid input")
        Labelerrormin.pack()
        Labelerrormin.place(relx = 0.9,rely = 0.035, anchor ='ne')
        y=0
        x=0
        minvalue=0
        maxvalue=0

    
    maxstring = entrymax.get()
    if  maxstring.isdigit():
        maxvalue = eval(maxstring)
        Labelnoerrormax=Label(top,text="                                ")
        Labelnoerrormax.pack()
        Labelnoerrormax.place(relx = 0.9,rely = 0.07, anchor ='ne')
        if type(maxvalue) is not int and type(maxvalue) is not float:   #checking the input
            Labelerrormax=Label(top,text="invalid input")
            Labelerrormax.pack()
            Labelerrormax.place(relx = 0.9,rely = 0.07, anchor ='ne')
            y=0
            x=0
            minvalue=0
            maxvalue=0
    else:
        Labelerrormax=Label(top,text="invalid input")
        Labelerrormax.pack()
        Labelerrormax.place(relx = 0.9,rely = 0.07, anchor ='ne')
        y=0
        x=0
        minvalue=0
        maxvalue=0

    if minvalue > maxvalue:                                        #checking the min and max 
        Labelerrormin_max=Label(top,text="max input must be bigger than min input")
        Labelerrormin_max.pack()
        Labelerrormin_max.place(relx = 0.9,rely = 0.105, anchor ='ne')
        y=0
        x=0
        minvalue=0
        maxvalue=0
    elif minvalue==maxvalue==0:
        Labelnoerrormin_max=Label(top,text="                                                                      ")
        Labelnoerrormin_max.pack()
        Labelnoerrormin_max.place(relx = 0.9,rely = 0.105, anchor ='ne')
    elif minvalue==maxvalue:
        Labelerrormin_max=Label(top,text="max input must be bigger than min input")
        Labelerrormin_max.pack()
        Labelerrormin_max.place(relx = 0.9,rely = 0.105, anchor ='ne')
        y=0
        x=0
        minvalue=0
        maxvalue=0
    else:
        Labelnoerrormin_max=Label(top,text="                                                                         ")
        Labelnoerrormin_max.pack()
        Labelnoerrormin_max.place(relx = 0.9,rely = 0.105, anchor ='ne')
    
    #parsing the input eqn from user
    eqnstring = entryeqn.get()  
    eqnstring = eqnstring.replace("^","**")
    x = np.linspace(minvalue,maxvalue,1000)
    #validation of the input equation
    if "x" in eqnstring or eqnstring.isdigit():
        Labelnoerroreqn=Label(top,text="                     ")
        Labelnoerroreqn.pack()
        Labelnoerroreqn.place(relx = 0.9,rely = 0.0, anchor ='ne')
        
        eqnmath=eval(eqnstring)
        if type(eqnmath) is np.ndarray:         
            y = eqnmath
        elif type(eqnmath) is int or type(eqnmath) is float :
            y = eqnmath*np.ones(x.shape)
        
    else:
        
        Labelerroreqn=Label(top,text="invalid input")
        Labelerroreqn.pack()
        Labelerroreqn.place(relx = 0.9,rely = 0.0, anchor ='ne')
        y=0
        x=0
        minvalue=0
        maxvalue=0
        
    
        
    #clearing the previous plots and making new plot
    ax.clear()
    ax.plot(x,y)
    #placing the plot on the canvas
    canvas.draw()
    # placing the canvas on the Tkinter window
    canvas.get_tk_widget().pack()       
    

    
if __name__ == "__main__":
        #initalizing variables
        x=0
        y=0
        min=0
        max=100
        #tkinter window "top"
        top = Tk()
        top.geometry("750x550")
        
        

        #creating Entry boxes and labels for input from user 
        entryeqn=Entry(top,width=50)
        entryeqn.pack()
        entrymin=Entry(top,width=50)
        entrymin.pack()
        entrymax=Entry(top,width=50)
        entrymax.pack()
        Labeleqn=Label(top,text="equation to graph")
        Labeleqn.pack()
        Labeleqn.place(relx = 0.0,rely = 0.0, anchor ='nw')
        Labelmin=Label(top,text="min value of x")
        Labelmin.pack()
        Labelmin.place(relx = 0.0,rely = 0.035, anchor ='nw')
        Labelmax=Label(top,text="max value of x")
        Labelmax.pack()
        Labelmax.place(relx = 0.0,rely = 0.07, anchor ='nw')
        mybutton=Button(top,text="Graph",command=clickbutton)
        mybutton.pack()
        
        # the figure that will contain the plot
        fig,ax = plt.subplots()
        # creating the Tkinter canvas
        # containing the Matplotlib figure
        canvas = FigureCanvasTkAgg(fig,master = top)
        # creating the Matplotlib toolbar
        toolbar = NavigationToolbar2Tk(canvas,top)
        toolbar.update()
        # placing the toolbar on the Tkinter window
        canvas.get_tk_widget().pack() 
        
        top.mainloop()

