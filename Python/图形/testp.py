from DrawingPanel import *
import time
panel=DrawingPanel(400,300)
for i in range(10):
    time.sleep(1)
    panel.width+=50
panel.draw_line(0,0,100,100,"red")
panel.draw_line(50,150,0,39,"blue")