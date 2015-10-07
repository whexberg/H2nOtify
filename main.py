import os
import Tkinter
import tkMessageBox

top = Tkinter.Tk()

def helloCallBack(mNumber, mMessage):
    os.system("./smsSend " + str(mNumber) + " " + str(mMessage))

mNumber = Tkinter.Entry(top)
mMessage = Tkinter.Entry(top)
mButton = Tkinter.Button(top, text ="Hello", command = lambda: helloCallBack(mNumber.get(),mMessage.get()))

mNumber.pack()
mMessage.pack()
mButton.pack()
top.mainloop()
