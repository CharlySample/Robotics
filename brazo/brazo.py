
# Este programa se ejecuta en la consola Python de FreeCAD con el comando "execfile(/carpeta/*.py)". Este archivo en particular permite mover los componentes con las funciones de la libreria C++

import FreeCAD as App
import FreeCADGui as Gui
from PyQt4 import QtCore, QtGui
import math

# execfile("/home/carlos/Documents/Universidad/Robotica/programas/brazo/brazo.py")
FreeCAD.open("/home/carlos/Documents/Universidad/Robotica/programas/brazo/brazo.fcstd")
App.setActiveDocument("brazo")
App.ActiveDocument=App.getDocument("brazo")
Gui.ActiveDocument=Gui.getDocument("brazo")
import sys
sys.path.append('/home/carlos/Documents/Universidad/Robotica/programas/brazo/')
import MoveModule

move=MoveModule.pMovement()
PI = 3.14159
w0=0
t=0
def Leonardo():
     global PI, move, w0, w1, t,phi1,phi2,phi3,d1	

     if t > 30:
         t = 0
     t+=1

     #move.brazo(t)
     phi1 =    45 #move.phi1
     #d1=move.d1
     phi2 = 20
     phi3 = 0
     #primero base
     App.getDocument("brazo").Part__Feature001.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(phi1,0,0), App.Vector(0,0,0))
     #primera extension
     App.getDocument("brazo").Part__Feature002.Placement=App.Placement(App.Vector(160.83*math.cos(math.radians(phi1)),160.83*math.sin(math.radians(phi1)),0), App.Rotation(phi1,0,0), App.Vector(0,0,0))
     #articulacion
     App.getDocument("brazo").Part__Feature003.Placement=App.Placement(App.Vector(361.16*math.cos(math.radians(phi1)),361.16*math.sin(math.radians(phi1)),0), App.Rotation(0,0,0), App.Vector(0,0,0))
     #segunda base
     App.getDocument("brazo").Part__Feature004.Placement=App.Placement(App.Vector(363*math.cos(math.radians(phi1)),363*math.sin(math.radians(phi1)),0), App.Rotation(phi1+phi2,0,0), App.Vector(0,0,0))
     #segunda extension
     App.getDocument("brazo").Part__Feature005.Placement=App.Placement(App.Vector((500*math.cos(math.radians(phi1)))-137*math.cos(math.radians(phi1)),(500*math.sin(math.radians(phi1)))+137*math.sin(math.radians(phi1)),0),App.Rotation(phi1+phi2,0,0), App.Vector(0,0,0))
     #articulacion
     App.getDocument("brazo").Part__Feature006.Placement=App.Placement(App.Vector(701*math.cos(math.radians(phi1+phi2)),701*math.sin(math.radians(phi1+phi2)),0), App.Rotation(0,0,0), App.Vector(0,0,0))
     #pinza
     App.getDocument("brazo").Part__Feature007.Placement=App.Placement(App.Vector(701.54*math.cos(math.radians(phi1+phi2+phi3)),701.54*math.sin(math.radians(phi1+phi2+phi3)),0), App.Rotation(phi1+phi2+phi3,0,0), App.Vector(0,0,0))

     if t > 30:
          t=0

timer=QtCore.QTimer()
timer.timeout.connect(Leonardo)
timer.start(10)


