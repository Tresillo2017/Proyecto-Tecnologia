from re import A, T
from sys import exit
import time
import pygame
import random
import os
from arrays import *

green = (124,252,0)
white = (250,250,250)
red = (255,0,0)
turno = 0
puntuacion = 0
pygame.init()
font = pygame.font.SysFont(None, 40)

textAlignLeft = 0
textAlignRight = 1
textAlignCenter = 2
textAlignBlock = 3

# light shade of the button
color_light = (170,170,170)

# dark shade of the button
color_dark = (100,100,100)

# white color
color = (255,255,255)

# add pygame.FULLSCREEN for fullscreen
window = pygame.display.set_mode((480, 320))
"""
Start of the width and height variables
"""
# stores the width of the
# screen into a variable
width = 360 # window.get_width()

# stores the height of the
# screen into a variable
height = 500 # window.get_height()
"""
End of the width and height variables
"""
# stores the (x,y) coordinates into
# the variable as a tuple
mouse = pygame.mouse.get_pos()

smallfont = pygame.font.SysFont('Corbel',35)

# rendering a text written in
# this font
text = smallfont.render('Corregir' , True , color)



# Don't touch it (works)
def drawText(surface, text, color, rect, font, align=textAlignLeft, aa=False, bkg=None):
    lineSpacing = -2
    spaceWidth, fontHeight = font.size(" ")[0], font.size("Tg")[1]

    listOfWords = text.split(" ")
    if bkg:
        imageList = [font.render(word, 1, color, bkg) for word in listOfWords]
        for image in imageList: image.set_colorkey(bkg)
    else:
        imageList = [font.render(word, aa, color) for word in listOfWords]

    maxLen = rect[2]
    lineLenList = [0]
    lineList = [[]]
    for image in imageList:
        width = image.get_width()
        lineLen = lineLenList[-1] + len(lineList[-1]) * spaceWidth + width
        if len(lineList[-1]) == 0 or lineLen <= maxLen:
            lineLenList[-1] += width
            lineList[-1].append(image)
        else:
            lineLenList.append(width)
            lineList.append([image])

    lineBottom = rect[1]
    lastLine = 0
    for lineLen, lineImages in zip(lineLenList, lineList):
        lineLeft = rect[0]
        if align == textAlignRight:
            lineLeft += + rect[2] - lineLen - spaceWidth * (len(lineImages)-1)
        elif align == textAlignCenter:
            lineLeft += (rect[2] - lineLen - spaceWidth * (len(lineImages)-1)) // 2
        elif align == textAlignBlock and len(lineImages) > 1:
            spaceWidth = (rect[2] - lineLen) // (len(lineImages)-1)
        if lineBottom + fontHeight > rect[1] + rect[3]:
            break
        lastLine += 1
        for i, image in enumerate(lineImages):
            x, y = lineLeft + i*spaceWidth, lineBottom
            surface.blit(image, (round(x), y))
            lineLeft += image.get_width()
        lineBottom += fontHeight + lineSpacing

    if lastLine < len(lineList):
        drawWords = sum([len(lineList[i]) for i in range(lastLine)])
        remainingText = ""
        for text in listOfWords[drawWords:]: remainingText += text + " "
        return remainingText
    return ""

def botton_siguiente(indice):
    pygame.init()
    while True:
        for ev in pygame.event.get():

            if ev.type == pygame.QUIT:
                pygame.quit()

            #checks if a mouse is clicked
            if ev.type == pygame.MOUSEBUTTONDOWN:
            
                #if the mouse is clicked on the
                # button the game is terminated
                if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
                    print("Boton pulsado")
                    # siguiente()

        # fills the screen with a color
        #window.fill((60,25,60))

        # stores the (x,y) coordinates into
        # the variable as a tuple
        mouse = pygame.mouse.get_pos()
    
        # if mouse is hovered on a button it
        # changes to lighter shade 
        if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
            pygame.draw.rect(window,color_light,[width/2,height/2,140,40])
        else:
            pygame.draw.rect(window,color_dark,[width/2,height/2,140,40])
        # superimposing the text onto our button
        window.blit(text , (width/2+50,height/2))
    
        # updates the frames of the game
        pygame.display.update()

def boton(ventana,texto,x,y,width,height):
    # texto A
    textoa = smallfont.render(texto,True, color)
    botona = pygame.Rect(x,y,width,height)
    pygame.draw.rect(ventana,color_dark, botona) # 10, 140, 250, 50
        # else:
        # pygame.draw.rect(window,color_dark,[10,140,250,50]) # left, top, width, height
    # superimposing the text onto our button
    window.blit(textoa , (x+10,y+10))
    
        # updates the frames of the game
    pygame.display.flip()
    return botona


pygame.display.set_caption('Gana y Juega')
orden_preguntas = random.sample(range(0,20), 20)



textRect = pygame.Rect(50, 50, 430, 270)

# add pygame.FULLSCREEN for fullscreen
window = pygame.display.set_mode((480, 320))

run = True

for turno in range(0,20):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            break
        
    msg = preguntas[orden_preguntas[turno]]
    window.fill((255, 255, 255))
    textRect = pygame.Rect(25, 50, 430, 100)
    pygame.draw.rect(window, (255, 255, 255), textRect, 1)
    drawTextRect = textRect.inflate(-5, -5)
    drawText(window, msg, (0, 0, 0), drawTextRect, font, textAlignCenter, True)
    
    # opciones
    botona = boton(window,opcionesa[orden_preguntas[turno]],10, 140, 400, 50)
    botonb = boton(window,opcionesb[orden_preguntas[turno]],10, 200, 400, 50)
    """
    Dibujar los dos botones con las soluciones
    Entrar en un bucle comprobando los eventos
        si el raton esta pulsado
            coger la posicion del raton 
            if (boton1.collide(x,y))
                respuesta a
            elif (boton2.collide(x,y)) 
                respuesta b  
    """
    pulsacion = False
    while not pulsacion:
        for ev in pygame.event.get():

            if ev.type == pygame.QUIT:
                pygame.quit()
            
            if ev.type == pygame.MOUSEBUTTONDOWN:
                x,y = pygame.mouse.get_pos()
                if botona.collidepoint(x,y):
                    pulsacion = True
                    respuesta = "A"
                    print("pulsado a")
                elif botonb.collidepoint(x,y):
                    pulsacion = True
                    respuesta = "B"
                    print("pulsado b")
    pygame.display.flip()
    # fin de opciones
    if respuesta == "A" and ans[turno] == 1:
        puntuacion = puntuacion +1
        # Green color
        window.fill(green)
        pygame.display.flip()
        time.sleep(1)
        # default color
        window.fill(white)
        pygame.display.flip()
    elif respuesta == "B" and ans[turno] == 2:
        puntuacion = puntuacion +1
        # Green color
        window.fill(green)
        pygame.display.flip()
        time.sleep(1)
        # default color
        window.fill(white)
    else:
        print("respuesta incorrecta")
        puntuacion = puntuacion - 1
        # Red background
        window.fill(red)
        pygame.display.update()
        time.sleep(1)
        # default background
        window.fill(white)
        pygame.display.flip()
     # left, top, width, height
    # puntuacion
    
    

# if event.key == 1073741882 or 282:
# pygame.quit()
# exit()


#Limpiar la pantalla
## Escribir contador de respuestas correcta
boton(window,str(puntuacion),10,230,400,50)
pygame.display.flip()
time.sleep(5)
pygame.quit()
exit()