import FreeCAD as App
import FreeCADGui as Gui
import time
from FreeCAD import Base
from PyQt4 import QtCore, QtGui

# execfile("/home/judypaws/Simulacion/MecSpring.py")
FreeCAD.open("/home/judypaws/Simulacion/Spring.fcstd")
App.setActiveDocument("Spring") 
App.ActiveDocument=App.getDocument("Spring")
Gui.ActiveDocument=Gui.getDocument("Spring")

pitch1 = pitch2 = FreeCAD.getDocument("Spring").getObject("Helix001").Pitch.Value
height1 = ib = FreeCAD.getDocument("Spring").getObject("Helix001").Height.Value

pas = 1

#def mover():

for ii2 in range(int(60)):
    if pas == 0:
        if pitch1 > pitch2-1:
            pas = 1
        else:
            pitch1 += 1
            height1 = (pitch1 * 10)
    else:
        if pitch1 < 2:
            pas = 0
        else:
            pitch1 -= 1
            height1 = (pitch1 * 10)
   
    FreeCAD.getDocument("Spring").getObject("Helix001").Pitch.Value = pitch1
    FreeCAD.getDocument("Spring").getObject("Helix001").Height.Value = height1
    App.Console.PrintMessage(str(ii2)+"  " + str(pitch1)+"  " + str(height1)+"  " + str(pas) +"\n")
    Gui.updateGui()
    time.sleep(0.1) # modify the time here
#FreeCAD.getDocument("Spring").getObject("Helix001").Pitch = iib
#FreeCAD.getDocument("Spring").getObject("Helix001").Height = ib 
